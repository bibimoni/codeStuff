#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n): n(n), tree(n+1, 0) {}
    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) tree[idx] += delta;
    }
    int sum(int idx) {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx) s += tree[idx];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        int BIT_SIZE = n + q + 5;
        BIT bit(BIT_SIZE);
        
        for (int i = 1; i <= n; i++) {
            int pos = q + n - i + 1;
            bit.add(pos, 1);
        }
        
        int next_front = q;
        
        unordered_map<int, pair<int, int>> cache;  // key -> (value, bit_position)
        // Also map key to list iterator for O(1) find
        unordered_map<int, list<int>::iterator> it_map;
        list<int> recency;  // front = most recent, back = LRU
        
        for (int i = n; i >= 1; i--) {
            recency.push_back(i);
            it_map[i] = prev(recency.end());  // iterator to this key
            cache[i] = {0, q + n - i + 1};
        }
        
        for (int i = 0; i < q; i++) {
            int type;
            cin >> type;
            
            if (type == 1) {
                int a, b;
                cin >> a >> b;
                
                if (cache.count(a)) {
                    // Key exists: update value, move to front
                    cache[a].first = b;
                    int old_pos = cache[a].second;
                    bit.add(old_pos, -1);
                    bit.add(next_front, 1);
                    cache[a].second = next_front;
                    next_front--;
                    // Move to front in list using iterator
                    recency.erase(it_map[a]);
                    recency.push_front(a);
                    it_map[a] = recency.begin();
                } else {
                    // Key not in cache: discard LRU (back of list)
                    int lru = recency.back();
                    int lru_pos = cache[lru].second;
                    bit.add(lru_pos, -1);
                    cache.erase(lru);
                    it_map.erase(lru);
                    recency.pop_back();
                    
                    // Insert new key at front
                    bit.add(next_front, 1);
                    cache[a] = {b, next_front};
                    next_front--;
                    recency.push_front(a);
                    it_map[a] = recency.begin();
                }
            } else {  // type == 2
                int a;
                cin >> a;
                
                if (cache.count(a)) {
                    int val = cache[a].first;
                    int r = bit.sum(cache[a].second);
                    cout << val << " " << r << "\n";
                    // Move to front
                    int old_pos = cache[a].second;
                    bit.add(old_pos, -1);
                    bit.add(next_front, 1);
                    cache[a].second = next_front;
                    next_front--;
                    // Move to front in list using iterator
                    recency.erase(it_map[a]);
                    recency.push_front(a);
                    it_map[a] = recency.begin();
                } else {
                    cout << "-1\n";
                }
            }
        }
    }
    
    return 0;
}
