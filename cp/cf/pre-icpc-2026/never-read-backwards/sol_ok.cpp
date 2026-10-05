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
            string r;
            for (int i = (int)line.size() - 1; i >= 0; i--) r += line[i];
            fwrite(r.c_str(), 1, r.size(), stdout);
            putchar('\n');
        }
    }
    return 0;
}
