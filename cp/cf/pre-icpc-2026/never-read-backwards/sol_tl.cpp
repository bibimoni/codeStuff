// correct but slow: recursion + substr copies, O(|s|^2) with heavy allocation churn
#include <bits/stdc++.h>
using namespace std;
string rev(const string& s) {
    if (s.empty()) return "";
    return rev(s.substr(1)) + s.front();
}
int main() {
    string line;
    getline(cin, line);
    int t = stoi(line);
    while (t--) {
        getline(cin, line);
        int m = stoi(line);
        while (m--) {
            getline(cin, line);
            puts(rev(line).c_str());
        }
    }
    return 0;
}
