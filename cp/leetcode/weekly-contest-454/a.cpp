#include <bits/stdc++.h>
#include <cctype>
using namespace std;
class Solution {
public:
  string generateTag(string caption) {
    string ret = "#";
    int n = caption.size();
    for (int i = 0; i < n; i++) {
      if (caption[i] == ' ' && i < n - 1 && isalpha(caption[i + 1])) {
        ret.push_back((char)toupper(caption[i + 1]));
        i += 1;
        continue;
      }
      if (isalpha(caption[i])) {
        ret.push_back((char)tolower(caption[i]));
      }
    }
    if (ret.size() > 1) {
      ret[1] = tolower(ret[1]);
    }
    return ret.substr(0, min(100, (int)ret.size()));
  }
};
