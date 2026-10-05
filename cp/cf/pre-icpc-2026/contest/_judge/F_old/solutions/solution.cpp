#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<string, int>> people(n);
    map<int, int> count;

    for (int i = 0; i < n; i++) {
        cin >> people[i].first >> people[i].second;
        count[people[i].second]++;
    }

    int dwarf_height = 0;
    for (auto [height, cnt] : count) {
        if (cnt == 7) {
            dwarf_height = height;
            break;
        }
    }

    for (auto [name, height] : people) {
        if (height == dwarf_height) {
            cout << name << "\n";
        }
    }

    return 0;
}