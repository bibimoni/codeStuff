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
#define int int64_t

string get_string_inside(string s, int cnt) {
    if (s[0] == ')') {
        cnt -=1;
        if (cnt == 0) {
            return "";
        }
    }
    if (s[0] == '(') {
        cnt += 1;
        if (cnt == 1) {
            return get_string_inside(s.substr(1), cnt);
        }
    }
    return s[0] + get_string_inside(s.substr(1), cnt);
}
string repeat_str(int cnt, string s) {
    if (cnt == 0) {
        return "";
    }
    return s + repeat_str(cnt - 1, s);
}
string expand(string s) {
    // cerr << "str: " << s << '\n';
    if (s.size() == 1) {
        return string(1, s[0]);
    }
    if (s[0] <= '9' && s[0] >= '0') {
        string inside = get_string_inside(s.substr(1), 0);
        // cerr << "inside: " << inside << '\n';
        string inside_rep = repeat_str(s[0] - '0', inside);
        s.erase(0, inside.size() + 3);
        s.insert(0, inside_rep);
    }
    return s[0] + expand(s.substr(1));
}



signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cout << expand("2(x0(y))3(z)") << "\n";
  return 0;
}

