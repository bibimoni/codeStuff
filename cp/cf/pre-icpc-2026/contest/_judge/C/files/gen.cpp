#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = opt<int>(1);
    long long L = opt<long long>(2);
    long long R = opt<long long>(3);

    cout << T << '\n';

    for (int i = 0; i < T; ++i) {
        cout << rnd.next(L, R) << '\n';
    }

    return 0;
}