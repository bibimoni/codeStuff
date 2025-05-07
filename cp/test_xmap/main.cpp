/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#include "xMap.h" 

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  xMap<int, int> mp(&xMap<int, int>::intKeyHash);
  // mp.put(1, 2);
  // mp.put(2, 2);
  // mp.put(11, 2);
  // int k1 = 3, k2 = 2;
  // cout << "contains key: " << k1 << " " << mp.containsKey(k1) << '\n';
  // cout << "contains key: " << k2 << " " << mp.containsKey(k2) << '\n';
  // mp.println();
  // int k3 = 11, v3 = 2;
  // cout << mp.remove(k3, v3) << '\n';
  // mp.println();
  // int num = 20;
  // vector<pair<string, int>> name{
  //   {"apple", 1}, {"banana", 2}, {"cherry", 3}, {"date", 4},
  //   {"elderberry", 5}, {"fig", 6}, {"grape", 7}, {"honeydew", 8},
  //   {"kiwi", 9}, {"lemon", 10}, {"mango", 11}, {"nectarine", 12},
  //   {"orange", 13}, {"papaya", 14}, {"quince", 15}, {"raspberry", 16},
  //   {"strawberry", 17}, {"tangerine", 18}, {"ugli", 19}, {"watermelon", 20},
  //   {"apricot", 21}, {"blackberry", 22}, {"blueberry", 23}, {"cantaloupe", 24},
  //   {"cranberry", 25}, {"dragonfruit", 26}, {"elderflower", 27}, {"figberry", 28},
  //   {"grapefruit", 29}, {"huckleberry", 30}, {"jackfruit", 31}, {"kumquat", 32},
  //   {"lime", 33}, {"mulberry", 34}, {"nectar", 35}, {"olive", 36},
  //   {"peach", 37}, {"pineapple", 38}, {"plum", 39}, {"pomegranate", 40},
  //   {"prune", 41}, {"raisin", 42}, {"soursop", 43}, {"starfruit", 44},
  //   {"tomato", 45}, {"uglifruit", 46}, {"vanilla", 47}, {"yam", 48},
  //   {"zucchini", 49}, {"avocado", 50}, {"boysenberry", 51}, {"casaba", 52},
  //   {"coconut", 53}, {"cucumber", 54}, {"damson", 55}, {"dewberry", 56},
  //   {"eggplant", 57}, {"feijoa", 58}, {"gooseberry", 59}, {"guava", 60},
  //   {"honeyberry", 61}, {"jaboticaba", 62}, {"jostaberry", 63}, {"kiwiberry", 64},
  //   {"lychee", 65}, {"mangosteen", 66}, {"miraclefruit", 67}, {"nectarberry", 68},
  //   {"orangelime", 69}, {"passionfruit", 70}, {"pawpaw", 71}, {"persimmon", 72},
  //   {"physalis", 73}, {"plantain", 74}, {"pomelo", 75}, {"redcurrant", 76},
  //   {"rowanberry", 77}, {"salak", 78}, {"sapodilla", 79}, {"satsuma", 80},
  //   {"sugarapple", 81}, {"surinamcherry", 82}, {"tamarillo", 83}, {"tamarind", 84},
  //   {"tangelo", 85}, {"thornberry", 86}, {"whitecurrant", 87}, {"whortleberry", 88},
  //   {"yellowpassionfruit", 89}, {"youngberry", 90}, {"zabala", 91}, {"zambo", 92},
  //   {"zantecurrant", 93}, {"zozberry", 94}, {"azuki", 95}, {"bilberry", 96},
  //   {"burdock", 97}, {"camu", 98}, {"ceriman", 99}, {"salmonberry", 100}
  // };
  // vector<string> a;
  // for (auto [p, _] : name) {
  //   a.push_back(p);
  // }
  // // for (int i = 0; i < num; i++) {
  //   // mp.put(rnd(1, 100), rnd(1, 100));
  // // }
  // int n = name.size();
  int n = 1e9;
  int t = 1e5;
  for (int i = 0; i < t; i++) {
    mp.put(rnd(0, n - 1),rnd(0, n - 1));
  }
  mp.println();
  // vector<string> b;
  // for (auto p : mp.keys()) {
  //   b.push_back(p);
  // }
  // sort(a.begin(), a.end());
  // sort(b.begin(), b.end());
  // if (a == b) {
  //   cout << "--eq--\n";
  // } else {
  //   cout << "--err--\n";
  // }
  // mp.remove("blueberry", 5);
  // mp.println();
}



