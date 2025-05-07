#include <bits/stdc++.h>

using namespace std;

#define ll long long

int toadd[200111];


int main() {
    if (fopen("main.inp", "r")) freopen("main.inp", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        string s; int n, k;
        cin >> s >> k;
        n = s.size();
        if (k == 1) {
            cout << "OH NO!\n";
            continue;

        }
//        cout << s << " " << k << endl;

        int cnt[30]; for (int i = 0; i < 30; i++) cnt[i] = 0;

        for (char c : s) ++cnt[c - 'a'];

        string res = "";
        int cur = 0;

        bool ok = true;

        for (int i = 0; i < 26; i++) {
            if (!ok) break;
            while (cnt[i]) {
                if (!res.size() || char(i + 'a') != res.back() || cur < k - 1) {
                    //cur += !res.size() || char(i + 'a') == res.back();
                    if (res.size() && char(i + 'a') == res.back()) ++cur;
                    else cur = 1;

                    res = res + char(i + 'a');
                    --cnt[i];
                } else {
                    int ptr = i + 1;
                    while (ptr < 26 && !cnt[ptr]) ++ptr;

                    if (ptr == 26) {
                        ok = false;
                        break;
                    }

                    --cnt[ptr];
                    res = res + char(ptr + 'a');
                    cur = 1;
                }

//                cout << res << endl;
            }
        }

        char c = 'a';
        for (int i = 0; i < res.size(); i++) toadd[i] = 0;

        if (!ok) {
            ok = true;

            while (!cnt[c - 'a']) c++;
            int tz = cnt[c - 'a'];

//            cout << c << " " << tz << endl;

            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i] == c) continue;

                int mm = min(tz, k - 1 - bool(i && res[i - 1] == c));

                toadd[i] = mm;
                tz -= mm;
            }

            if (tz) ok = false;
        }

        if (ok) {
            for (int i = 0; i < res.size(); i++) {
                while (toadd[i]--) {
                    cout << c;
                }
                cout << res[i];
            }
            cout << endl;
        } else {
            cout << "OH NO!\n";
        }
    }
}