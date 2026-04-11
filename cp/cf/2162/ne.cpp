#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
/**
 * @brief Counts all palindromic subarrays in a given array of integers.
 * * This function uses Manacher's algorithm for linear time complexity O(N).
 * * @param s The input array of integers.
 * @return The total number of palindromic subarrays.
 */
long long count_palindromic_subarrays(const std::vector<int> &s) {
  int n = s.size();
  if (n == 0) {
    return 0;
  }

  // Transform the array to handle even-length palindromes.
  // e.g., {1, 2, 1} -> {0, 1, 0, 2, 0, 1, 0}
  // We use 0 as a separator since problem constraints state a_i >= 1.
  std::vector<int> t(2 * n + 1, 0);
  for (int i = 0; i < n; ++i) {
    t[2 * i + 1] = s[i];
  }

  int new_n = t.size();
  std::vector<int> p(
      new_n, 0); // p[i] stores the radius of the palindrome centered at i
  int center = 0, right_boundary = 0;

  for (int i = 1; i < new_n; ++i) {
    int mirror = 2 * center - i;
    if (i < right_boundary) {
      p[i] = std::min(right_boundary - i, p[mirror]);
    }

    // Attempt to expand palindrome centered at i
    int a = i + (1 + p[i]);
    int b = i - (1 + p[i]);
    while (a < new_n && b >= 0 && t[a] == t[b]) {
      p[i]++;
      a++;
      b--;
    }

    // If palindrome centered at i expands past the right_boundary,
    // adjust the center and right_boundary.
    if (i + p[i] > right_boundary) {
      center = i;
      right_boundary = i + p[i];
    }
  }

  long long total_palindromes = 0;
  for (int radius : p) {
    // Each radius contributes (radius + 1) / 2 palindromes in the original
    // array
    total_palindromes += (radius + 1) / 2;
  }
  return total_palindromes;
}

/**
 * @brief Solves a single test case for the Beautiful Palindromes problem.
 */
void solve() {
  int n;
  long long k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  std::vector<int> reversed_a = a;
  std::reverse(reversed_a.begin(), reversed_a.end());

  // --- Strategy 1: "Follow" strategy ---
  // Append the first k elements of the reversed array 'a'.
  std::vector<int> s1;
  for (int i = 0; i < k; ++i) {
    s1.push_back(reversed_a[i]);
  }
  // Cost = k (for k spanning palindromes) + internal palindromes in s1.
  long long cost1 = k + count_palindromic_subarrays(s1);

  // --- Strategy 2: "Avoid" strategy ---
  // Append a simple non-palindromic sequence like 1, 2, 3, 1, 2, 3...
  std::vector<int> s2;
  for (int i = 0; i < k; ++i) {
    s2.push_back((i % 3) + 1);
  }

  // Count the number of prefixes of s2 that are also prefixes of reversed_a.
  long long matches = 0;
  bool prefix_match_ok = true;
  for (int len = 1; len <= std::min((long long)k, (long long)n); ++len) {
    if (!prefix_match_ok) {
      break; // If a shorter prefix failed, longer ones will too.
    }
    if (s2[len - 1] != reversed_a[len - 1]) {
      prefix_match_ok = false;
    }
    if (prefix_match_ok) {
      matches++;
    }
  }
  // Cost = k (for k single-element palindromes) + spanning palindromes
  // (matches).
  long long cost2 = k + matches;

  dbg(s1, s2);
  // --- Decision and Output ---
  // Choose the strategy with the minimum cost.
  if (cost1 <= cost2) {
    for (int i = 0; i < k; ++i) {
      std::cout << s1[i] << (i == k - 1 ? "" : " ");
    }
    std::cout << "\n";
  } else {
    for (int i = 0; i < k; ++i) {
      std::cout << s2[i] << (i == k - 1 ? "" : " ");
    }
    std::cout << "\n";
  }
}

int main() {
  // Fast I/O
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
