/**
 * File              : tongmang.cpp
 * Author            : distiled
 * Date              : 13.06.2023
 * Last Modified Date: 13.06.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

unsigned long long a = 1, x;
int main() {
  FAST;
  while(cin >> x) {
    a += x - 1;
  }
  cout << a;
}
