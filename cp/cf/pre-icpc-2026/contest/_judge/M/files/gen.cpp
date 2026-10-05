#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using Case = tuple<int, int, long long>;
const long long LIM = 1000000000000000000LL;

static void printCases(const vector<Case>& tests) {
    cout << tests.size() << '\n';
    for (auto [n, m, k] : tests) cout << n << ' ' << m << ' ' << k << '\n';
}

static long long chooseK(int style) {
    if (style == 0) return 1;
    if (style == 1) return rnd.next(1LL, 1000LL);
    if (style == 2) return rnd.next(999999999999000000LL, LIM);
    return rnd.next(1LL, LIM);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = argv[1];
    vector<Case> tests;

    if (mode == "sample1") {
        tests = {{3, 1, 1}, {3, 1, 2}, {4, 0, 1}, {4, 6, 2}};
    } else if (mode == "sample2") {
        tests = {{4, 3, 1}, {4, 3, 6}, {5, 5, 10}, {1, 0, 2}};
    } else if (mode == "edges") {
        int v = opt<int>(2);
        if (v == 0) {
            for (int n = 1; n <= 16; ++n) {
                int mx = n * (n - 1) / 2;
                tests.emplace_back(n, 0, 1);
                tests.emplace_back(n, mx, 1);
            }
        } else if (v == 1) {
            for (int n : {2, 3, 4, 5, 8, 13, 21, 34, 55, 89}) {
                int mx = n * (n - 1) / 2;
                tests.emplace_back(n, min(1, mx), 2);
            }
        } else if (v == 2) {
            tests = {{300, 0, LIM}};
        } else {
            tests = {{299, 44551, 1}, {1, 0, LIM}};
        }
    } else if (mode == "tiny") {
        int v = opt<int>(2);
        int used = 0;
        while (used < 300) {
            int n = rnd.next(1, min(9, 300 - used));
            int mx = n * (n - 1) / 2;
            int m = (v == 0 ? rnd.next(0, mx) : (v == 1 ? min(mx, rnd.next(0, 2)) :
                    (v == 2 ? max(0, mx - rnd.next(0, 2)) : rnd.next(0, mx))));
            tests.emplace_back(n, m, chooseK(v));
            used += n;
        }
    } else if (mode == "rand") {
        int pattern = opt<int>(2);
        int variant = opt<int>(3);
        int used = 0;
        while (used < 300) {
            int remaining = 300 - used;
            int limit = min(remaining, 70 + 10 * (variant % 4));
            int n = remaining <= 100 ? remaining : rnd.next(20, min(limit, remaining - 20));
            int mx = n * (n - 1) / 2;
            int m;
            if (pattern == 0) m = rnd.next(0, mx);
            else if (pattern == 1) m = rnd.next(0, min(mx, n + variant));
            else if (pattern == 2) m = mx - rnd.next(0, min(mx, n + variant));
            else if (pattern == 3) m = max(0, min(mx, mx / 2 + rnd.next(-n, n)));
            else m = rnd.next(0, mx);
            tests.emplace_back(n, m, chooseK((pattern + variant) % 4));
            used += n;
        }
    } else if (mode == "max") {
        int v = opt<int>(2);
        int n = 300, mx = n * (n - 1) / 2;
        int m = (v == 0 ? mx / 2 : v == 1 ? mx / 3 : v == 2 ? 2 * mx / 3 : v == 3 ? n : mx - n);
        tests.emplace_back(n, m, v == 4 ? LIM : (v % 2 ? 1 : 999999999999999937LL));
    } else if (mode == "split") {
        int v = opt<int>(2);
        int parts = (v == 0 ? 2 : v == 1 ? 3 : v == 2 ? 6 : 10);
        int n = 300 / parts;
        for (int i = 0; i < parts; ++i) {
            int mx = n * (n - 1) / 2;
            int m = (i % 3 == 0 ? mx / 2 : i % 3 == 1 ? rnd.next(0, min(mx, n)) : mx - rnd.next(0, min(mx, n)));
            tests.emplace_back(n, m, chooseK((i + v) % 4));
        }
    } else if (mode == "many") {
        for (int i = 0; i < 300; ++i) tests.emplace_back(1, 0, (i % 3 == 0 ? 1 : LIM));
    } else {
        quitf(_fail, "unknown mode");
    }

    int sum = 0;
    for (auto [n, m, k] : tests) sum += n;
    ensuref(!tests.empty() && tests.size() <= 300 && sum <= 300, "generator produced invalid aggregate size");
    printCases(tests);
}
