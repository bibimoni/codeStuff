#include "testlib.h"

using namespace std;
using int64 = long long;

const int SUM_N = 200000;

void emit(const vector<vector<int64>>& tests) {
    int total = 0;
    for (const auto& d : tests) total += (int)d.size();
    ensuref(total <= SUM_N, "sum of n = %d exceeds %d", total, SUM_N);
    println((int)tests.size());
    for (const auto& d : tests) {
        println((int)d.size());
        for (int i = 0; i < (int)d.size(); ++i) {
            if (i) cout << ' ';
            cout << d[i];
        }
        cout << '\n';
    }
}

// d[i] = i+1 for i <= n-4, then {n, 1, n}: the only crossing is the very
// last segment hitting segment n-3 (pattern "growing then folding across").
vector<int64> lateCross1(int n) {
    ensuref(n >= 4 && n <= SUM_N, "latecross1 needs 4 <= n <= %d", SUM_N);
    vector<int64> d(n);
    for (int i = 0; i <= n - 4; ++i) d[i] = i + 1;
    d[n - 3] = n;
    d[n - 2] = 1;
    d[n - 1] = n;
    return d;
}

// d[i] = i+1 for i <= n-5, then {n-3, n-2, n-3, n-3}: touching collision
// pinned at the final segment only (the d[i-1]==d[i-3] family).
vector<int64> lateCross2(int n) {
    ensuref(n >= 8 && n <= SUM_N, "latecross2 needs 8 <= n <= %d", SUM_N);
    vector<int64> d(n);
    for (int i = 0; i <= n - 5; ++i) d[i] = i + 1;
    d[n - 4] = n - 3;
    d[n - 3] = n - 2;
    d[n - 2] = n - 3;
    d[n - 1] = n - 3;
    return d;
}

// d[i] = i+1 for i <= n-5, then {n-2, n-3, 3, n-4}: the only crossing is the
// final segment passing the segment 5 moves back (the deep-spiral family;
// invisible to both shallower patterns).
vector<int64> lateCross3(int n) {
    ensuref(n >= 10 && n <= SUM_N, "latecross3 needs 10 <= n <= %d", SUM_N);
    vector<int64> d(n);
    for (int i = 0; i <= n - 5; ++i) d[i] = i + 1;
    d[n - 4] = n - 2;
    d[n - 3] = n - 3;
    d[n - 2] = 3;
    d[n - 1] = n - 4;
    return d;
}

// Strictly increasing or strictly decreasing steps never self-cross.
vector<int64> nonCrossing(int n) {
    vector<int64> d(n);
    if (rnd.next(0, 1)) {
        d[0] = rnd.next(1, 5);
        for (int i = 1; i < n; ++i) d[i] = min(1000000000LL, d[i - 1] + rnd.next(1, 5));
        ensuref(d[n - 1] <= 1000000000LL, "increasing steps overflow");
    } else {
        d[0] = min(1000000000LL, (int64)3 * n + rnd.next(1, 100));
        for (int i = 1; i < n; ++i) d[i] = d[i - 1] - rnd.next(1, 3);
        ensuref(d[n - 1] >= 1, "decreasing steps underflow");
    }
    return d;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    if (mode == "sample") {
        emit({{2, 1, 1, 2}, {1, 2, 3, 4}, {1, 1, 1, 1, 1}});
    } else if (mode == "small") {
        // Handcrafted edges: minimal n, minimal crossing (n=4), the two
        // sneaky collision families at minimal size, max-value corners.
        emit({{1}, {1, 1}, {1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 2},
              {1, 2, 3, 4}, {1, 1, 2, 1, 1}, {3, 2, 1, 2, 3}, {5, 1, 5, 1},
              {1, 2, 2, 2, 1}, {3, 3, 4, 3, 1},
              {1000000000LL, 1, 1, 1000000000LL},
              {1000000000LL, 1000000000LL, 1000000000LL, 1000000000LL, 1},
              {1000000000LL, 999999999LL, 999999998LL, 999999997LL, 999999996LL,
               999999995LL, 999999994LL, 999999993LL, 999999992LL, 999999991LL},
              lateCross1(10), lateCross2(10), lateCross3(12)});
    } else if (mode == "rand") {
        int count = opt<int>(2);
        int nMax = opt<int>(3);
        int64 dMax = opt<long long>(4);
        vector<vector<int64>> tests;
        int budget = SUM_N;
        for (int tc = 0; tc < count && budget > 0; ++tc) {
            int n = rnd.next(1, min(nMax, budget));
            budget -= n;
            vector<int64> d(n);
            for (int i = 0; i < n; ++i) d[i] = rnd.next(1LL, dMax);
            tests.push_back(d);
        }
        emit(tests);
    } else if (mode == "single") {
        string kind = opt<string>(2);
        int n = opt<int>(3);
        ensuref(n >= 1 && n <= SUM_N, "bad n");
        vector<int64> d(n);
        if (kind == "inc") {
            for (int i = 0; i < n; ++i) d[i] = i + 1;
        } else if (kind == "dec") {
            for (int i = 0; i < n; ++i) d[i] = (int64)3 * n - 3 * i;
        } else if (kind == "const") {
            for (int i = 0; i < n; ++i) d[i] = 1000000000LL;
        } else if (kind == "randbig") {
            for (int i = 0; i < n; ++i) d[i] = rnd.next(1LL, 1000000000LL);
        } else {
            quitf(_fail, "unknown kind: %s", kind.c_str());
        }
        emit({d});
    } else if (mode == "noncross") {
        int count = opt<int>(2);
        int n = opt<int>(3);
        vector<vector<int64>> tests;
        int budget = SUM_N;
        for (int tc = 0; tc < count && budget >= n; ++tc) {
            budget -= n;
            tests.push_back(nonCrossing(n));
        }
        emit(tests);
    } else if (mode == "latecross1" || mode == "latecross2" || mode == "latecross3") {
        int n = opt<int>(2);
        int count = opt<int>(3, 1);
        vector<vector<int64>> tests;
        int budget = SUM_N;
        for (int tc = 0; tc < count && budget >= n; ++tc) {
            budget -= n;
            if (mode == "latecross1") tests.push_back(lateCross1(n));
            else if (mode == "latecross2") tests.push_back(lateCross2(n));
            else tests.push_back(lateCross3(n));
        }
        emit(tests);
    } else if (mode == "mix-tiny") {
        int count = opt<int>(2);
        int n = opt<int>(3);
        int64 dMax = opt<long long>(4);
        vector<vector<int64>> tests;
        int budget = SUM_N;
        for (int tc = 0; tc < count && budget >= n; ++tc) {
            budget -= n;
            vector<int64> d(n);
            for (int i = 0; i < n; ++i) d[i] = rnd.next(1LL, dMax);
            tests.push_back(d);
        }
        emit(tests);
    } else {
        quitf(_fail, "unknown mode: %s", mode.c_str());
    }
}
