#include <bits/stdc++.h>

int maximize(int a, int b, int c);

int main() {
  int a = 6, b = 8, c = 11;
  std::cout << maximize(a, b, c);
}

int maximize(int a, int b, int c) {
  return std::max({a, b, c});
}
