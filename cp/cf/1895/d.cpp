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

const int N = (int) 31;
struct Node {
  Node *child[2];
};
Node *root = new Node();
void add(int x) {
  Node *curr = root;
  for(int i = N; i >= 0; i--) {
    int bi = (x >> i) & 1;
    if(curr -> child[bi] == nullptr) {
      curr -> child[bi] = new Node();
    }
    curr = curr -> child[bi];
  }
}

//find max value of x ^ (a1 ^ a2 ^ ... ^ ai) {1 <= i <= n}
int get(int x) {
  Node *curr = root;
  int res = 0;
  for(int i = N; i >= 0; i--) {
    int bi = (x >> i) & 1;
    if(curr -> child[bi ^ 1] == nullptr) {
      curr = curr -> child[bi];
    }
    else {
      res += (1 << i);
      curr = curr -> child[bi ^ 1];
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n; cin >> n;
  int a[n + 1], b[n + 1], pre[n + 1];
  pre[0] = 0;
  for(int i = 1; i < n; i++) {
    cin >> a[i]; 
    pre[i] = pre[i - 1] ^ a[i];
    add(pre[i]);
  }
  for(int i = 0; i < n; i++) {
    if(get(i) < n) {
      b[1] = i;
      break;
    }
  }
  cout << b[1] << ' ';
  for(int i = 2; i <= n; i++) {
    b[i] = (b[i - 1] ^ a[i - 1]);
    cout << b[i] << ' ';
  }
  cout << endl;
  
}



