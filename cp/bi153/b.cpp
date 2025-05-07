class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    int n = s.size();
    s = "1" + s;
    vector<int> cnt_l(n + 1);
    int cnt_1 = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') {
        cnt_l[i] = 0;
        cnt_1 += 1;
      } else {
        cnt_l[i] += cnt_l[i - 1] + 1;
      }
    }
    vector<int> cnt_r(n + 2);
    for (int i = n; i >= 1; i--) {
      if (s[i] == '1') {
        cnt_r[i] = 0;
      } else {
        cnt_r[i] += cnt_r[i + 1] + 1;
      }
    }
    int ans = cnt_1;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '0') {
        continue;
      }
      int j = i;
      while (j + 1 <= n && s[j + 1] == '1') {
        j += 1;
      }
      if (cnt_l[i - 1] != 0 && cnt_r[j + 1] != 0) {
        ans = max(ans, cnt_l[i - 1] + cnt_r[j + 1] + cnt_1);
      }
      i = j;
    }
    return ans;
  }
};
