#include "testlib.h"
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// Modes:
//   gen sample1 | sample2                      (statement samples)
//   gen tiny | keqn | keq1 | alleq | mono | farmin | ones   (handcrafted edges)
//   gen mini <seed>                            (200 random tiny cases)
//   gen rand <t> <nLo> <nHi> <pattern> <kMode> <vmax> <seed>
// pattern: 0 uniform[1..vmax], 1 increasing, 2 decreasing, 3 all vmax,
//          4 ends=1 rest vmax, 5 center adjacent pair=1 rest vmax, 6 alternating 1/vmax
// kMode:   0 uniform[1..n], 1 k=1, 2 k=n, 3 k in [max(1,n-2)..n], 4 k in [1..min(n,5)]

struct T { int n, k; vector<long long> a; };

static void emit(const vector<T>& ts) {
    println(ts.size());
    for (auto& tc : ts) {
        ostringstream line;
        line << tc.n << ' ' << tc.k;
        println(line.str());
        line.str("");
        for (int i = 0; i < tc.n; i++) { if (i) line << ' '; line << tc.a[i]; }
        println(line.str());
    }
}

static T mk(int n, int k, vector<long long> a) { return T{n, k, a}; }
static vector<long long> rep(long long v, int n) { return vector<long long>(n, v); }

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    vector<T> ts;

    if (mode == "sample1") {
        ts = { mk(5,3,{1,4,2,3,5}), mk(3,3,{10,20,30}), mk(1,1,{7}), mk(4,2,{5,1,1,5}) };
    } else if (mode == "sample2") {
        ts = { mk(6,1,{9,3,8,1,10,2}), mk(5,4,{8,2,7,1,9}) };
    } else if (mode == "tiny") {
        ts = { mk(1,1,{1000000000}), mk(2,1,{9,7}), mk(2,2,{9,7}),
               mk(3,2,{9,1,9}), mk(3,3,{5,1,5}), mk(3,1,{8,2,6}),
               mk(5,3,{10,1,10,10,10}),  // user case: min behind a wall, pair right -> 11
               mk(2,2,{1,1}), mk(1,1,{1}) };
    } else if (mode == "keqn") {  // k = n: answer must be a[1]+a[n]
        ts = { mk(2,2,{5,9}), mk(5,5,{3,1,4,1,5}),
               mk(6,6,{1000000000,1,1,1,1,1000000000}),
               mk(4,4,{1,100,100,1}), mk(7,7,{9,8,7,1,2,3,4}), mk(3,3,{2,1,2}) };
    } else if (mode == "keq1") {  // k = 1: answer is the bare minimum
        ts = { mk(5,1,{5,3,8,2,9}), mk(4,1,rep(1000000000,4)), mk(6,1,rep(7,6)),
               mk(1,1,{999999937}), mk(3,1,{2,1,2}) };
    } else if (mode == "alleq") {  // 64-bit answer traps: 2*1e9 and 1e9
        ts = { mk(10,5,rep(1000000000,10)), mk(10,1,rep(1000000000,10)),
               mk(10,10,rep(1000000000,10)), mk(8,4,rep(1,8)) };
    } else if (mode == "mono") {  // sorted both ways: optimal pair sits at extremes
        ts = { mk(10,3,{1,2,3,4,5,6,7,8,9,10}), mk(10,3,{10,9,8,7,6,5,4,3,2,1}),
               mk(10,9,{10,9,8,7,6,5,4,3,2,1}), mk(9,8,{1,2,3,4,5,6,7,8,9}) };
    } else if (mode == "farmin") {  // minima far apart / adjacent-center trap
        ts = { mk(11,2,{1,9,9,9,9,9,9,9,9,9,1}),
               mk(11,6,{9,9,9,9,1,1,9,9,9,9,9}),
               mk(11,6,{1,9,9,9,9,9,9,9,9,9,1}),
               mk(5,3,{1,1,1,1,1}) };
    } else if (mode == "ones") {
        ts = { mk(5,3,rep(1,5)), mk(7,1,rep(1,7)), mk(6,6,rep(1,6)),
               mk(4,2,rep(1,4)), mk(9,5,rep(1,9)), mk(3,2,rep(1,3)) };
    }
    else if (mode == "mini") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        for (int i = 0; i < 200; i++) {
            int n = rnd.next(1, 6);
            vector<long long> a(n);
            for (auto& x : a) x = rnd.next(1, 20);
            ts.push_back(mk(n, rnd.next(1, n), a));
        }
    } else if (mode == "trap") {
        // Pinned unique optimum: exactly two 1s at (L, R), L = R - k + 1 - off,
        // rest = 1e9. Sweeps of R / off / k defeat: point index skips, distance
        // bands (off > B), strides (off % W != 0), tail/head cutoffs.
        // Answer of every sub-test: 2 (except v6, answer 1e9 + 1).
        int variant = opt<int>(2), seed = opt<int>(3);
        rnd.setSeed(seed);
        auto pin = [&](int n, int k, int L, int R) {
            vector<long long> a(n, 1000000000);
            a[L] = 1; a[R] = 1;
            ts.push_back(mk(n, k, a));
        };
        if (variant == 3) {                 // single max-size test, R = seed arg
            int R = seed, k = R / 2 + 1;
            pin(200000, k, R - k + 1, R);
        } else if (variant == 4) {          // pinned R sweeping near the END (kills tail cuts)
            int kc[4] = {2, 5, 50, 700};
            for (int rep = 0; rep < 100; rep++) {
                int n = 2000, R = n - 1 - rep * 7;
                int k = kc[rep % 4], off = rep % 5;
                int L = R - k + 1 - off;
                if (L < 0) { k = 2; L = R - 1; }
                pin(n, k, L, R);
            }
        } else if (variant == 5) {          // pinned L sweeping near the START, large k
            int kc[2] = {500, 900};
            for (int rep = 0; rep < 70; rep++) {
                int L = 100 + rep * 10;
                int k = kc[rep % 2], off = rep % 3;
                int R = L + k - 1 + off;
                pin(R + rnd.next(1, 30), k, L, R);
            }
        } else if (variant == 7) {          // ends-pinned max single, k=2: kills distance bands of any width
            pin(200000, 2, 0, 199999);
        } else if (variant == 6) {          // clustered minima: kills top-D-by-value filters for D <= 620
            for (int rep = 0; rep < 20; rep++) {
                int c = 50 + rep * 30, n = 2 * c + 50, k = c + 5;
                vector<long long> a(n, 1000000000);
                for (int i = 0; i < c; i++) a[i] = 1;   // cluster(span c-1 < k-1) can't pair with itself
                ts.push_back(mk(n, k, a));
            }
        } else {                            // v1/v2: central + wide R sweeps with distance offsets
            int reps, base, step; int kcycle[5];
            if (variant == 1) { reps = 100; base = 460; step = 1; kcycle[0]=2; kcycle[1]=3; kcycle[2]=7; kcycle[3]=100; kcycle[4]=500; }
            else              { reps = 60;  base = 97;  step = 31; kcycle[0]=2; kcycle[1]=11; kcycle[2]=101; kcycle[3]=503; kcycle[4]=769; }
            for (int rep = 0; rep < reps; rep++) {
                int R = base + rep * step;
                int k = kcycle[rep % 5], off = rep % 3;
                if (R - k + 1 - off < 0) { k = 2; off = 0; }
                pin(R + rnd.next(1, 30), k, R - k + 1 - off, R);
            }
        }
    } else if (mode == "rand") {
        int t = opt<int>(2), nLo = opt<int>(3), nHi = opt<int>(4);
        int pattern = opt<int>(5), kMode = opt<int>(6);
        int vmax = opt<int>(7), seed = opt<int>(8);
        rnd.setSeed(seed);
        for (int i = 0; i < t; i++) {
            int n = rnd.next(nLo, nHi);
            vector<long long> a(n);
            switch (pattern) {
                case 0: for (auto& x : a) x = rnd.next(1, vmax); break;
                case 1: for (auto& x : a) x = rnd.next(1, vmax);
                        sort(a.begin(), a.end()); break;
                case 2: for (auto& x : a) x = rnd.next(1, vmax);
                        sort(a.rbegin(), a.rend()); break;
                case 3: a = rep(vmax, n); break;
                case 4: a = rep((long long)vmax, n);
                        if (n >= 2) a[0] = a[n-1] = 1; break;
                case 5: a = rep((long long)vmax, n);
                        if (n >= 2) a[(n-1)/2] = a[n/2] = 1; break;
                case 6: for (int j = 0; j < n; j++) a[j] = (j % 2 ? vmax : 1); break;
            }
            int k;
            switch (kMode) {
                case 0: k = rnd.next(1, n); break;
                case 1: k = 1; break;
                case 2: k = n; break;
                case 3: k = rnd.next(max(1, n-2), n); break;
                default: k = rnd.next(1, min(n, 5)); break;
            }
            ts.push_back(mk(n, k, a));
        }
    } else {
        quitf(_fail, "unknown mode '%s'", mode.c_str());
    }

    emit(ts);
    return 0;
}
