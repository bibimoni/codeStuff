#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerInteraction(argc, argv);

    const int QUERY_LIMIT = 8000;
    const long long MAX_N = 1'000'000'000'000'000'000LL;

    int T = inf.readInt(1, 100);

    vector<long long> N(T);

    for (int i = 0; i < T; ++i) {
        N[i] = inf.readLong(1LL, MAX_N);
    }

    // Only T is visible to the contestant.
    cout << T << endl;

    for (int tc = 0; tc < T; ++tc) {
        setTestCase(tc + 1);

        long long current = 1;
        int queries = 0;

        while (true) {
            string op = ouf.readToken();

            if (op == "?") {
                ++queries;

                if (queries > QUERY_LIMIT) {
                    quitf(
                        _wa,
                        "Query limit exceeded: used %d queries, limit is %d",
                        queries,
                        QUERY_LIMIT
                    );
                }

                string dir = ouf.readToken();

                if (dir == "L") {
                    long long nxt = current * 2;

                    if (nxt <= N[tc]) {
                        current = nxt;
                        cout << 1 << endl;
                    } else {
                        cout << 0 << endl;
                    }
                }
                else if (dir == "R") {
                    long long nxt = current * 2 + 1;

                    if (nxt <= N[tc]) {
                        current = nxt;
                        cout << 1 << endl;
                    } else {
                        cout << 0 << endl;
                    }
                }
                else if (dir == "B") {
                    if (current != 1) {
                        current /= 2;
                        cout << 1 << endl;
                    } else {
                        cout << 0 << endl;
                    }
                }
                else {
                    quitf(
                        _wa,
                        "Invalid direction '%s'. Expected L, R, or B",
                        dir.c_str()
                    );
                }
            }
            else if (op == "!") {
                long long answer = ouf.readLong(1LL, MAX_N);

                if (answer != N[tc]) {
                    quitf(
                        _wa,
                        "Wrong answer: expected %lld, found %lld",
                        N[tc],
                        answer
                    );
                }

                break;
            }
            else {
                quitf(
                    _wa,
                    "Invalid command '%s'. Expected '?' or '!'",
                    op.c_str()
                );
            }
        }
    }

    quitf(_ok, "All test cases solved correctly.");
}