#include <bits/stdc++.h>
using namespace std;

int ask(char move) {
    cout << "? " << move << endl;
    int answer;
    if (!(cin >> answer) || answer < 0) exit(0);
    return answer;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int depth = 0;
        while (ask('L')) ++depth;
        for (int i = 0; i < depth; ++i) ask('B');

        auto exists = [&](unsigned long long index) {
            int moved = 0;
            bool ok = true;
            for (int bit = depth - 1; bit >= 0; --bit) {
                if (!ask((index >> bit & 1) ? 'R' : 'L')) {
                    ok = false;
                    break;
                }
                ++moved;
            }
            while (moved--) ask('B');
            return ok;
        };

        unsigned long long low = 0, high = 1ULL << depth;
        while (low < high) {
            auto mid = low + (high - low) / 2;
            if (exists(mid)) low = mid + 1;
            else high = mid;
        }
        cout << "! " << ((1ULL << depth) - 1 + low) << endl;
    }
}
