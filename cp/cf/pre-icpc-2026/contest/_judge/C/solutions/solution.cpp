#include <bits/stdc++.h>
using namespace std;

int ask(char dir) {
    cout << "? " << dir << endl;

    int res;
    if (!(cin >> res)) exit(0);

    return res;
}

int height(char first) {
    if (!ask(first))
        return 0;

    int h = 1;

    while (ask('L')) {
        ++h;
    }

    for (int i = 0; i < h; ++i) {
        ask('B');
    }

    return h;
}

long long countNodes() {
    int left = height('L');
    int right = height('R');

    // Leaf
    if (left == 0 && right == 0)
        return 1;

    if (left == right) {
        int ok = ask('R');

        if (!ok)
            exit(0);

        return (1LL << left) + countNodes();
    }
    else {
        int ok = ask('L');

        if (!ok)
            exit(0);

        return (1LL << right) + countNodes();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N = countNodes();

        cout << "! " << N << endl;
    }

    return 0;
}