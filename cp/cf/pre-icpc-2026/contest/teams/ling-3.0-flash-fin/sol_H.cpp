#include <cstdio>
#include <list>
#include <unordered_map>
using namespace std;

int bit[400002];
int B;
void upd(int i, int v) { for (; i <= B; i += i&-i) bit[i] += v; }
int qry(int i) { int s=0; for (; i>0; i -= i&-i) s += bit[i]; return s; }

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d %d", &n, &q);
        B = n + q;
        for (int i = 0; i <= B; i++) bit[i] = 0;
        
        list<int> order;
        unordered_map<int, pair<int, int>> cache; // key -> {value, timestamp}
        unordered_map<int, list<int>::iterator> where;
        int tmr = 0;
        
        for (int i = 1; i <= n; i++) {
            ++tmr;
            order.push_front(i);
            where[i] = order.begin();
            cache[i] = {0, tmr};
            upd(tmr, 1);
        }
        
        int total = n;
        while (q--) {
            int type;
            scanf("%d", &type);
            if (type == 1) {
                int a, b;
                scanf("%d %d", &a, &b);
                if (cache.count(a)) {
                    cache[a].first = b;
                    int old_t = cache[a].second;
                    upd(old_t, -1);
                    ++tmr;
                    cache[a].second = tmr;
                    upd(tmr, 1);
                    order.erase(where[a]);
                    order.push_front(a);
                    where[a] = order.begin();
                } else {
                    int lru_t = cache[order.back()].second;
                    upd(lru_t, -1);
                    total--;
                    cache.erase(order.back());
                    where.erase(order.back());
                    order.pop_back();
                    
                    ++tmr;
                    order.push_front(a);
                    where[a] = order.begin();
                    cache[a] = {b, tmr};
                    upd(tmr, 1);
                    total++;
                }
            } else {
                int a;
                scanf("%d", &a);
                if (cache.count(a)) {
                    int val = cache[a].first;
                    int t = cache[a].second;
                    int rank = total - qry(t) + 1;
                    printf("%d %d\n", val, rank);
                    int old_t = t;
                    upd(old_t, -1);
                    ++tmr;
                    cache[a].second = tmr;
                    upd(tmr, 1);
                    order.erase(where[a]);
                    order.push_front(a);
                    where[a] = order.begin();
                } else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
