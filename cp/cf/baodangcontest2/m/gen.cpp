#include <bits/stdc++.h>
 
using namespace std;
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    vector<vector<int>> perm;
    int n = 1000;
    int cnt = 0;
    int len = 1;
    vector<int> t;
    bool ok = true;
    while(cnt <= n) {
        if(len > 100) {
            break;
        }
        if(n == 1000) {
            len += rnd(0, 2);
            t.push_back(len);
        }
        if(n == 200000) {
            int add = rnd(9, 9);
            for(int j = 0; j < add; j++) {
                len += rnd(0, 500);
                t.push_back(len);
            }
        }
        if(!ok) {
            break;
        }
        do {
            perm.push_back(t);
            if(cnt + t.size() > n || perm.size() >= 1000) {
                ok = false;
                break;
            }
            cnt += t.size();
        } while(next_permutation(t.begin(), t.end()));
    }
    dbg(cnt);
    cout << perm.size() << '\n';
    for(auto p : perm) {
        cout << p.size() << '\n';
        for(int i : p) {
          cout << i << ' ';
        }
        cout << '\n';
    }
}
