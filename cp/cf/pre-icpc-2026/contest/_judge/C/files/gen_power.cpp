#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int k = opt<int>(1);

    long long p = 1LL << k;

    vector<long long> a;

    if (p - 1 >= 1)
        a.push_back(p - 1);

    a.push_back(p);

    if (p + 1 <= 1'000'000'000'000'000'000LL)
        a.push_back(p + 1);

    cout << a.size() << '\n';

    for (long long x : a)
        cout << x << '\n';

    return 0;
}