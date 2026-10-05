// tempting mistake: reverse the order of the lines, not the lines themselves
#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    int t = stoi(line);
    while (t--) {
        getline(cin, line);
        int m = stoi(line);
        vector<string> ls(m);
        for (auto& s : ls) getline(cin, s);
        for (int i = m - 1; i >= 0; i--) puts(ls[i].c_str());
    }
    return 0;
}
