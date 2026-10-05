#include "testlib.h"
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;

// Modes:
//   gen sample1 | tiny | zeros | eq | antitl | divmax | maxpairs | tmax
//   gen mini <seed>                      (200 tiny random tests, vals in [-3,3])
//   gen pinned <seed>                    (all-ones 2*prime sweep, medium)
//   gen pinnedone <q>                    (single all-ones test, n = 2*q)
//   gen sumpack <seed>                   (20 tests of n=5000, mixed patterns)
//   gen reset <seed>                     (50000 tests of n=2, sums 0/+-1 heavy:
//                                         kills solutions leaking state across tests)
//   gen rand <t> <nLo> <nHi> <pattern> <vmax> <seed>
// pattern: 0 uniform[-v,v]  1 uniform[1..v]  2 zero-sum pairs +-v
//          3 all equal to +-v  4 uniform{-1,0,1}  5 cluster {0,1,2}
//          6 a_i = 1 + (i mod 10)  7 alternating +v,-v

struct T { int n; vector<ll> a; };

static void emit(const vector<T>& ts) {
    println(ts.size());
    for (auto& tc : ts) {
        println(tc.n);
        ostringstream line;
        for (int i = 0; i < tc.n; i++) { if (i) line << ' '; line << tc.a[i]; }
        println(line.str());
    }
}

static T mk(int n, vector<ll> a) { return T{n, a}; }
static vector<ll> rep(ll v, int n) { return vector<ll>(n, v); }

static int nextPrime(int x) {
    for (int p = max(2, x); ; p++) {
        bool pr = true;
        for (int i = 2; (ll)i * i <= p; i++) if (p % i == 0) { pr = false; break; }
        if (pr) return p;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    vector<T> ts;

    if (mode == "sample1") {
        ts = { mk(4,{1,2,1,2}), mk(4,{1,-1,1,-1}), mk(2,{1,1}),
               mk(1,{5}), mk(2,{-1,-1}), mk(6,{1,2,3,0,2,4}) };
    } else if (mode == "tiny") {
        ts = { mk(1,{0}), mk(1,{1000000000}), mk(1,{-1000000000}), mk(1,{7}),
               mk(2,{1,1}), mk(2,{1,-1}), mk(2,{-1,-1}), mk(2,{0,0}),
               mk(3,{-2,-2,-2}), mk(3,{3,3,3}), mk(5,{0,0,0,0,0}),
               mk(3,{1,0,1}),          // pre 1,1,2 -> k=2 gets 2 chains
               mk(5,{5,-5,5,-5,5}),    // pn=5 but prefix 1 absent -> only k=1
               mk(5,{2,-1,-1,2,-2}),   // pn=0, c=1 -> 2
               mk(5,{-4,2,4,-3,-2}),   // ORDERING TRAP: answer 1, unordered product says 2
               mk(5,{2,2,-4,1,1}),     // pn=2 -> 2
               mk(2,{1000000000,1000000000}), mk(2,{1000000000,-1000000000}),
               mk(4,{1,2,-3,0}),       // pn=0, pre 1,3,0 -> c=1 -> 2
               mk(7,{1,3,-2,-1,-4,2,1}) }; // pn=0, c=2 (pre=0 at i=3? 1,4,2,1,-3,-1 -> c=1... worth 2)
    } else if (mode == "zeros") {
        // pn == 0 constructions of various shapes; answers are powers of two.
        ts.push_back(mk(10,{3,-3,1,-1,7,-7,1000000000,-1000000000,5,-5})); // c=5 -> 32
        ts.push_back(mk(100,rep(0,100)));      // c=99
        ts.push_back(mk(1000,rep(0,1000)));    // c=999
        ts.push_back(mk(3,{-1,2,-1}));
        vector<ll> a;
        for (int i = 0; i < 20; i++) { a.push_back(1 + i); a.push_back(-(ll)(1 + i)); }
        ts.push_back(mk(40, a));               // pairs, c=20
        a = {5, -5, 0, 0, 2, -2};
        ts.push_back(mk(6, a));                // c=5 (pre:5,0,0,0,2,0 -> i<n zero cnt=4): 16
        a.assign(30, 0); a[0] = 1000000000; a[29] = -1000000000;
        ts.push_back(mk(30, a));               // c=28
    } else if (mode == "eq") {
        // all-equal arrays: answer = tau(n); divisor-overlap traps
        int ns[] = {2, 3, 60, 360, 5040, 72072};
        for (int i = 0; i < 6; i++) {
            static ll cs[] = {1, -3, 7, 1000000000, -1000000000, 12345};
            ts.push_back(mk(ns[i], rep(cs[i], ns[i])));
        }
    } else if (mode == "antitl") {
        // n=98280: highly composite (tau=128, sigma=403200) -> TL does ~4e10 ops
        ts.push_back(mk(98280, rep(1, 98280)));   // answer tau(98280)=128
    } else if (mode == "divmax") {
        // pn = 6.98e13 with 1721 divisors <= n; 64-bit |pn| near the 1e14 cap
        ts.push_back(mk(100000, rep(698377680LL, 100000)));
    } else if (mode == "maxpairs") {
        vector<ll> a(100000);
        for (int i = 0; i < 50000; i++) { a[2*i] = 1000000000; a[2*i+1] = -1000000000; }
        ts.push_back(mk(100000, a));            // pn=0, c=49999 -> 2^49999 mod
    } else if (mode == "tmax") {
        static ll vals[5] = {0, 1, -1, 1000000000, -1000000000};
        for (int i = 0; i < 100000; i++) ts.push_back(mk(1, {vals[i % 5]}));
    } else if (mode == "sumpack") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        for (int rep = 0; rep < 20; rep++) {
            int n = 5000, p = rep % 5;
            vector<ll> a(n);
            if (p == 0) a.assign(n, 7);
            else if (p == 1) {
                for (int i = 0; i < n / 2; i++) { ll v = rnd.next(1, 100); a[2*i] = v; a[2*i+1] = -v; }
            } else if (p == 2) {
                for (auto& x : a) x = rnd.next(-1000000000, 1000000000);
            } else if (p == 3) {
                a.assign(n, 1);                 // all ones, pn=5000
            } else {
                for (auto& x : a) x = rnd.next(-1, 1);
            }
            ts.push_back(mk(n, a));
        }
    } else if (mode == "reset") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        // pairs with total 0 or +-1 (plus a few +-2): prefix-colliding cases
        // that corrupt answers if any per-test structure leaks across tests
        static const ll P[10][2] = {{1,-1},{-1,1},{1,1},{-1,-1},{2,-1},
                                    {-1,2},{1,-2},{-2,1},{2,-2},{-2,2}};
        for (int i = 0; i < 50000; i++) {
            int p = rnd.next(0, 9);
            ts.push_back(mk(2, {P[p][0], P[p][1]}));
        }
    } else if (mode == "mini") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        for (int i = 0; i < 200; i++) {
            int n = rnd.next(1, 8);
            vector<ll> a(n);
            for (auto& x : a) x = rnd.next(-3, 3);
            ts.push_back(mk(n, a));
        }
    } else if (mode == "pinned") {
        // all-ones with n = 2*prime: answer = 3 (k in {1,2,q}); the k=2 chain
        // pins the cut exactly at index q, the k=q chain needs EVERY even index.
        // Any single skipped index in [2, 2q-2] with the right parity changes
        // the answer -> point-index hacks die. q sweeps the mid range.
        int seed = opt<int>(2);
        (void)seed;
        int budget = 90000, start = 547;
        while (budget > 0) {
            int q = nextPrime(start);
            int n = 2 * q;
            if (n > budget) break;
            ts.push_back(mk(n, rep(1, n)));
            budget -= n;
            start = q + 283;
        }
    } else if (mode == "pinnedone") {
        int q = opt<int>(2);
        int n = 2 * q;
        ts.push_back(mk(n, rep(1, n)));
    } else if (mode == "rand") {
        int t = opt<int>(2), nLo = opt<int>(3), nHi = opt<int>(4);
        int pattern = opt<int>(5);
        ll vmax = opt<ll>(6);
        int seed = opt<int>(7);
        rnd.setSeed(seed);
        for (int tc = 0; tc < t; tc++) {
            int n = rnd.next(nLo, nHi);
            vector<ll> a(n);
            if (pattern == 0) {
                for (auto& x : a) x = rnd.next(-vmax, vmax);
            } else if (pattern == 1) {
                for (auto& x : a) x = rnd.next(1LL, vmax);
            } else if (pattern == 2) {
                if (n % 2) n--;
                a.resize(n);
                for (int i = 0; i < n / 2; i++) {
                    ll v = rnd.next(1LL, vmax);
                    a[2*i] = v; a[2*i+1] = -v;
                }
            } else if (pattern == 3) {
                ll v = vmax;
                if (rnd.next(0, 1)) v = -v;
                a.assign(n, v);
            } else if (pattern == 4) {
                for (auto& x : a) x = rnd.next(-1, 1);
            } else if (pattern == 5) {
                for (auto& x : a) x = rnd.next(0, 2);
            } else if (pattern == 6) {
                for (int i = 0; i < n; i++) a[i] = 1 + (i % 10);
            } else { // 7: alternating +v,-v
                ll v = vmax;
                for (int i = 0; i < n; i++) a[i] = (i % 2 == 0) ? v : -v;
            }
            ts.push_back(mk(n, a));
        }
    } else {
        fprintf(stderr, "unknown mode %s\n", mode.c_str());
        return 1;
    }
    emit(ts);
    return 0;
}
