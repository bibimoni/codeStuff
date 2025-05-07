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
#define int long long

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto ask = [&] (vector<int> x) -> pair<int, int> {
    cout << "? ";
    for(int i : x) {
      cout << i << ' ';
    }
    cout << '\n';
    cout.flush();
    int pos, aPos;
    cin >> pos >> aPos;
    return {pos, aPos};
  };
  // 4 2 3 0 | 5 7 5 1, k = 3 m = 2
  // ? 2 3 4 -> 3 3 
  // ? 1 3 4 -> 3 3
  // ? 1 2 4 -> 2 2
  // ? 1 2 3 -> 2 2
  
  // 0 2 3 4

  multiset<int> save;
  for(int i = 1; i <= k + 1; i++) {
    vector<int> p(k + 1);
    iota(p.begin(), p.end(), 1);
    p.erase(p.begin() + i - 1);
    auto [_, aPos] = ask(p);
    if(!save.size() || aPos > *save.begin()) {
      save.clear();
      save.insert(aPos);
    }
    else if(aPos == *save.begin())
      save.insert(aPos);
  }
  cout << "! " << save.size() << '\n';
  cout.flush();
}

