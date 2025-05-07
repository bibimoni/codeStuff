/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int int64_t

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout.flush();
    vector<vector<int>> xor_bits;
    vector<int> pos;
    const int BITS = 13;
    vector<int> mark(n + BITS + 5, -1);
    for (int j = 0; j < BITS; j++) {
      if ((int(1) << j) > n + BITS) {
        break;
      }
      mark[int(1) << j] = -2;
    }

    int bound = 0;
    for (int i = 1, cnt = 0; i <= n + BITS; i++) {
      if (mark[i] == -1) {
        cnt += 1;
      }
      if (cnt == n) {
        bound = i;
        break;
      }
    }

    for (int j = 0; j < BITS; j++) {
      if ((int(1) << j) > n + BITS) {
        break;
      }
      pos.push_back(int(1) << j);
      vector<int> tmp;
      for (int i = 1; i <= bound; i++) {
        if ((int(1) << j) != i && ((i >> j) & 1)) {
          tmp.push_back(i);
        }
      }
      if (tmp.size() == 0) {
        break;
      }
      xor_bits.push_back(tmp);
    }

    int c = xor_bits.size();
    cout << "? " << c << '\n';
    cout.flush();
    for (int j = 0; j < c; j++) {
      cout << "? " << pos[j] << ' ' << xor_bits[j].size() << ' ';
      for (int i : xor_bits[j]) {
        cout << i << ' ';
      }
      cout << '\n';
      cout.flush();
    }

    vector<int> nm(n + c + 1);
    for (int i = 1; i <= n + c; i++) {
      cin >> nm[i];
    }
    
    int ans = 0;
    for (int j = 0; j < c; j++) {
      int cur = nm[pos[j]];
      for (int i : xor_bits[j]) {
        cur ^= nm[i];
      }
      if (cur) {
        ans |= int(1) << j;
      }
    }
    cout << "! " << ans << '\n';
    cout.flush(); 
  }
}

