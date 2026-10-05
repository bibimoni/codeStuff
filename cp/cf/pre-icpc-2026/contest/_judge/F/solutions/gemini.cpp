#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Person {
    string name;
    int height;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Person> people(n);
    map<int, int> count_height;

    for (int i = 0; i < n; ++i) {
        cin >> people[i].name >> people[i].height;
        count_height[people[i].height]++;
    }

    // Tìm chiều cao xuất hiện đúng 7 lần
    int dwarf_height = -1;
    for (auto const& [height, count] : count_height) {
        if (count == 7) {
            dwarf_height = height;
            break;
        }
    }

    // In ra tên 7 chú lùn theo thứ tự input
    for (int i = 0; i < n; ++i) {
        if (people[i].height == dwarf_height) {
            cout << people[i].name << "\n";
        }
    }

    return 0;
}