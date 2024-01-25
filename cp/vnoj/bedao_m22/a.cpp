// time-limit: 3000
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
#define all(x)         x.begin(), x.end()

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  double p[5][11];
  for(int i = 0; i < 5; i++) 
    for(int j = 0; j < 11; j++) 
      cin >> p[i][j];
  double pob[11] = {};
  for(int a = 0; a <= 10; a++) {
    for(int b = 0; b <= 10; b++) {
      for(int c = 0; c <= 10; c++) {
        for(int d = 0; d <= 10; d++) {
          for(int e = 0; e <= 10; e++) {
            int x = ceil((a + b + c + d + e) / 5.0);
            double tp = (p[0][a] * p[1][b] * p[2][c] * p[3][d] * p[4][e]) / 100e5;
            pob[x] += tp;
          }
        }
      }
    }
  }
  cout << fixed << setprecision(9);
  for(int i = 0; i < 11; i++)
    cout << pob[i] / 10<< ' ';
}


