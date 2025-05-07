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
#define int long long

vector<pair<int, int>> sw;

int partition(vector<int> &arr, int start, int end) {
  int pivot = arr[start];
  int count = 0;
  for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot)
      count++;
  } 
  int pivotIndex = start + count;
  if(pivotIndex != start)
    sw.push_back({pivotIndex, start});
  swap(arr[pivotIndex], arr[start]);
  int i = start, j = end;
  while (i < pivotIndex && j > pivotIndex) {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i < pivotIndex && j > pivotIndex) {
      if(i != j) 
        sw.push_back({i, j});
      swap(arr[i++], arr[j--]);
    }
  }
  return pivotIndex;
}
 
void quickSort(vector<int> &arr, int start, int end) {
  if (start >= end)
    return;
  int p = partition(arr, start, end);
  quickSort(arr, start, p - 1);
  quickSort(arr, p + 1, end);
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    sw.clear();
    vector<int> a(n + 2);
    vector<int> idx(n + 1, -1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      idx[a[i]] = i;
    }
    auto b = a;
    quickSort(b, 1, n);
    vector<pair<int, int>> op;
    auto move = [&] (int x, int y) -> void {
      // op.push_back({idx[x], n + 1});
      // swap(a[idx[x]], a[n + 1]);
      // op.push_back({idx[y], idx[x]});
      // swap(a[idx[y]], a[idx[x]]);
      // op.push_back({n + 1, idx[y]});
      // swap(a[n + 1], a[idx[y]]);
      op.push_back({x, n + 1});
      swap(a[x], a[n + 1]);
      op.push_back({y, x});
      swap(a[y], a[x]);
      op.push_back({n + 1, y});
      swap(a[n + 1], a[y]);
    };
    // vector<int> v(50, 0);
    // iota(v.begin(), v.end(), 1);
    // std::random_device rd;
    // std::mt19937 g(rd());
    // std::shuffle(v.begin(), v.end(), g);
    // dbg(v);
    // for(int i = 1; i <= n; i++) {
    //   int t = idx[i];
    //   for(int j = 0; j < t - 1; j++) {
    //     int id = idx[i];
    //     // dbg(id);
    //     if(id == i)
    //       continue;
    //     move(a[id - 1], i);
    //     // dbg(a);
    //     idx[i] = id - 1;
    //     idx[a[id]] = id;
    //   }
    // }
    dbg(sw);
    dbg(a);
    for(auto [u, v] : sw) {
      if(u > v)
        swap(u, v);
      move(u, v);
      dbg(a);
    }
    cout << op.size() << '\n';
    for(auto [u, v] : op) {
      cout << u << ' ' << v << '\n';
    }
  }
}


