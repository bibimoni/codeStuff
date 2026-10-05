#include <bits/stdc++.h>
using namespace std;

int bit[400005];
int BITSZ;

void bit_update(int i, int v) { for (; i <= BITSZ; i += i&(-i)) bit[i] += v; }
int bit_query(int i) { int s = 0; for (; i > 0; i -= i&(-i)) s += bit[i]; return s; }

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        
        BITSZ = n + q + 2;
        for (int i = 0; i <= BITSZ; i++) bit[i] = 0;
        
        unordered_map<int, int> val, ts; // key -> value, key -> timestamp
        set<pair<int,int>> lru; // (timestamp, key), ordered ascending
        
        int tmr = 0;
        for (int i = 1; i <= n; i++) {
            val[i] = 0;
            ts[i] = ++tmr;
            bit_update(ts[i], 1);
            lru.insert({ts[i], i});
        }
        
        int total = n;
        
        while (q--) {
            int type;
            scanf("%d", &type);
            if (type == 1) {
                int a, b;
                scanf("%d %d", &a, &b);
                if (ts.count(a)) {
                    // Key exists: update value, move to most recent
                    int old_t = ts[a];
                    bit_update(old_t, -1);
                    lru.erase({old_t, a});
                    ts[a] = ++tmr;
                    bit_update(ts[a], 1);
                    lru.insert({ts[a], a});
                    val[a] = b;
                } else {
                    // Evict LRU
                    auto it = lru.begin();
                    int lru_key = it->second;
                    int lru_t = it->first;
                    bit_update(lru_t, -1);
                    lru.erase(it);
                    ts.erase(lru_key);
                    val.erase(lru_key);
                    total--;
                    
                    // Insert new key
                    val[a] = b;
                    ts[a] = ++tmr;
                    bit_update(ts[a], 1);
                    lru.insert({ts[a], a});
                    total++;
                }
            } else {
                int a;
                scanf("%d", &a);
                if (ts.count(a)) {
                    int v = val[a];
                    int t_key = ts[a];
                    // rank = 1 + total - prefix_sum(t_key)
                    int rank = 1 + total - bit_query(t_key);
                    printf("%d %d\n", v, rank);
                    
                    // Move to most recent
                    bit_update(t_key, -1);
                    lru.erase({t_key, a});
                    ts[a] = ++tmr;
                    bit_update(ts[a], 1);
                    lru.insert({ts[a], a});
                } else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
