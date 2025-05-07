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

#define int            long long
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define sz(x)          (int) x.size()
#define endl           '\n'
#define MULTI          int tt;cin>>tt;while(tt--)
inline int nxt() { int n; cin >> n; return n; }

const int N = 2011, INF = 2e9 + 111;

vector<int> genKMP(string s) {
  int n = sz(s);
  vector<int> pi(n);
  for(int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while(j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if(s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, m, d; cin >> n >> m >> d;
  int a[n + 1], b[n + 1]; a[0] = b[0] = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  string strip; cin >> strip;
  auto pre = genKMP(strip);
  int cntRed = 0, cntBlue = 0, //used for pattern 
    same = 0, ans = -INF;
  for(int i = 0; i <= n; i++) {
    int pts = d * i; 
    //loop through all combinations the remainning red and blue and find the max score with those
    for(int red = cntRed; red <= n - cntBlue; red++) {
      int blue = n - red;
      int curr = pts - a[red] - b[blue];
      ans = max(ans, curr);
    }
    for(int i = same; i < m; i++) {
      cntRed += strip[i] == 'R';
      cntBlue += strip[i] == 'B';
    }
    same = pre[m - 1];
    if(cntRed + cntBlue > n) break;
  }
  cout << ans << endl;
  cntRed = 0, cntBlue = 0, same = 0;
  for(int i = 0; i <= n; i++) {
    int pts = d * i;
    for(int red = cntRed; red <= n - cntBlue; red++) {
      int blue = n - red;
      int curr = pts - a[red] - b[blue];
      if(curr == ans) {
        string res = "";
        for(int j = 1; j <= i; j++) {
          if(j == 1) res += strip;
          else {
            for(int j = pre[m - 1]; j < m; j++) {
              res += strip[j];
            }
          }
        }
        for(int r = 1; r <= red - cntRed; r++) res += 'R';
        for(int b = 1; b <= blue - cntBlue; b++) res += 'B';
        cout << res;
        return 0;
      }
    }
    for(int i = same; i < m; i++) {
      cntRed += strip[i] == 'R';
      cntBlue += strip[i] == 'B';
    }
    same = pre[m - 1];
    if(cntRed + cntBlue > n) break;
  }
}


