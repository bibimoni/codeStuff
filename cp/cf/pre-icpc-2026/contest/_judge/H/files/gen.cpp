#include "testlib.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Modes:
//   gen sample                   (statement sample)
//   gen edge                     (handcrafted edge bundle, incl. no-refresh trap)
//   gen queryonly                (type-2 rank churn on the initial keys)
//   gen mini <seed>              (200 tiny random tests)
//   gen rand <t> <nLo> <nHi> <qLo> <qHi> <keymax> <addpct> <seed>
//   gen storm <n> <q> <seed>     (all type-1, distinct fresh keys: evict every add)
//   gen churn <n> <q> <seed>     (all type-2 on keys 1..n: max rank work, no evictions)
//   gen maxt                     (200000 tests of n=1, q=1)
//   gen medsum <seed>            (200 tests of n=1000, q=1000)

struct Q { int type; long long a, b; };
struct T { int n; vector<Q> qs; };

static Q add(long long a, long long b) { return Q{1, a, b}; }
static Q get(long long a) { return Q{2, a, 0}; }
static T mk(int n, vector<Q> qs) { return T{n, qs}; }

static void emit(const vector<T>& ts) {
    println(ts.size());
    ostringstream line;
    for (auto& tc : ts) {
        line.str(""); line.clear();
        line << tc.n << ' ' << tc.qs.size();
        println(line.str());
        for (auto& x : tc.qs) {
            line.str(""); line.clear();
            if (x.type == 1) line << "1 " << x.a << ' ' << x.b;
            else line << "2 " << x.a;
            println(line.str());
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    vector<T> ts;

    if (mode == "sample") {
        ts = { mk(3, {get(2), get(5), add(4,10), get(1), get(4), add(2,7),
                      get(2), add(9,1), get(3), get(9), add(4,8), get(2)}),
               mk(1, {get(1), add(5,3), get(1), get(5)}),
               mk(2, {get(1), add(3,6), get(2), get(1), get(3)}) };
    } else if (mode == "edge") {
        ts = { mk(1, {get(1)}),                                    // initial key hit
               mk(1, {get(7)}),                                    // miss
               mk(1, {add(1,5), get(1)}),                          // value update of existing key
               mk(1, {add(9,5), get(1), get(9)}),                  // capacity-1 eviction
               mk(2, {get(1), add(3,5), get(1), get(2)}),          // query-refresh saves key 1
               mk(2, {add(2,4), add(2,6), get(2)}),                // update twice
               mk(3, {add(4,7), add(5,8), add(6,9),
                      get(1), get(4), get(6)}),                    // evict initial keys in order
               mk(5, {get(3), get(1), get(5)}),                    // rank churn, no adds
               mk(4, {add(10,1000000000LL), get(10)}),             // max value
               mk(2, {get(2), get(2)}) };                          // repeated MRU query
    } else if (mode == "queryonly") {
        ts = { mk(6, {get(3), get(1), get(2), get(6), get(4), get(8),
                      get(8), get(5), get(1), get(2), get(6), get(3)}) };
    } else if (mode == "mini") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        for (int i = 0; i < 200; i++) {
            int n = rnd.next(1, 6), q = rnd.next(1, 12);
            vector<Q> qs;
            for (int j = 0; j < q; j++) {
                if (rnd.next(0, 99) < 55) qs.push_back(add(rnd.next(1, 9), rnd.next(1, 100)));
                else qs.push_back(get(rnd.next(1, 9)));
            }
            ts.push_back(mk(n, qs));
        }
    } else if (mode == "maxt") {
        for (int i = 0; i < 200000; i++) ts.push_back(mk(1, {get(i % 2 ? 1 : 2)}));
    } else if (mode == "medsum") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        for (int i = 0; i < 200; i++) {
            vector<Q> qs;
            for (int j = 0; j < 1000; j++) {
                if (rnd.next(0, 99) < 50) qs.push_back(add(rnd.next(1, 1050), rnd.next(1LL, 1000000000LL)));
                else qs.push_back(get(rnd.next(1, 1050)));
            }
            ts.push_back(mk(1000, qs));
        }
    } else if (mode == "rand") {
        int t = opt<int>(2), nLo = opt<int>(3), nHi = opt<int>(4);
        int qLo = opt<int>(5), qHi = opt<int>(6), addpct = opt<int>(8);
        long long keymax = opt<long long>(7);
        int seed = opt<int>(9);
        rnd.setSeed(seed);
        for (int i = 0; i < t; i++) {
            int n = rnd.next(nLo, nHi), q = rnd.next(qLo, qHi);
            vector<Q> qs;
            for (int j = 0; j < q; j++) {
                if (rnd.next(0, 99) < addpct)
                    qs.push_back(add(rnd.next(1LL, keymax), rnd.next(1LL, 1000000000LL)));
                else qs.push_back(get(rnd.next(1LL, keymax)));
            }
            ts.push_back(mk(n, qs));
        }
    } else if (mode == "storm") {
        int n = opt<int>(2), q = opt<int>(3), seed = opt<int>(4);
        rnd.setSeed(seed);
        vector<Q> qs;
        for (int i = 1; i <= q; i++) qs.push_back(add((long long)n + i, rnd.next(1LL, 1000000000LL)));
        ts.push_back(mk(n, qs));
    } else if (mode == "churn") {
        int n = opt<int>(2), q = opt<int>(3), seed = opt<int>(4);
        rnd.setSeed(seed);
        vector<Q> qs;
        for (int i = 0; i < q; i++) qs.push_back(get(rnd.next(1, n)));
        ts.push_back(mk(n, qs));
    } else {
        quitf(_fail, "unknown mode '%s'", mode.c_str());
    }

    emit(ts);
    return 0;
}
