#include <bits/stdc++.h>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    int t = stoi(line);
    while (t--) {
        getline(cin, line);
        int m = stoi(line);
        while (m--) {
            getline(cin, line);
            reverse(line.begin(), line.end());
            puts(line.c_str());
        }
    }
    return 0;
}
