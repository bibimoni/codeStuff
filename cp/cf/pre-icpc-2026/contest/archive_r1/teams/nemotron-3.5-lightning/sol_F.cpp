#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<pair<string, int>> men(n);
    map<int, vector<string>> height_to_names;
    
    for (int i = 0; i < n; i++) {
        cin >> men[i].first >> men[i].second;
        height_to_names[men[i].second].push_back(men[i].first);
    }
    
    // Find the height that appears exactly 7 times
    int dwarf_height = -1;
    for (auto &p : height_to_names) {
        if (p.second.size() == 7) {
            dwarf_height = p.first;
            break;
        }
    }
    
    // Output the names in input order
    for (string name : height_to_names[dwarf_height]) {
        cout << name << "\n";
    }
    
    return 0;
}