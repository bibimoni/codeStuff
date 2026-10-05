#include <bits/stdc++.h>
using namespace std;
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n=0){ init(n); }
    void init(int n_){ n=n_; f.assign(n+1, 0); }
    void add(int i, int d){ for(; i<=n; i+=i&-i) f[i]+=d; }
    int sum(int i){ int s=0; for(; i>0; i-=i&-i) s+=f[i]; return s; }
};
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,q; scanf("%d %d",&n,&q);
        Fenwick fw(n+q+5);
        unordered_map<long long, pair<int,int>> val;
        val.reserve(n+q+5);
        set<pair<int,long long>> ord;
        int T = n;
        for(int i=1;i<=n;i++){
            val[i] = {0, i};
            ord.insert({i, i});
            fw.add(i, 1);
        }
        while(q--){
            int type; scanf("%d",&type);
            if(type==1){
                long long a; int b; scanf("%lld %d",&a,&b);
                auto it = val.find(a);
                if(it != val.end()){
                    int oldts = it->second.second;
                    fw.add(oldts, -1);
                    ord.erase({oldts, a});
                    it->second = {b, ++T};
                    fw.add(T, 1);
                    ord.insert({T, a});
                } else {
                    auto ev = ord.begin();
                    long long ek = ev->second;
                    fw.add(ev->first, -1);
                    val.erase(ek);
                    ord.erase(ev);
                    val[a] = {b, ++T};
                    fw.add(T, 1);
                    ord.insert({T, a});
                }
            } else {
                long long a; scanf("%lld",&a);
                auto it = val.find(a);
                if(it == val.end()){ printf("-1\n"); continue; }
                int ts = it->second.second;
                int more = fw.sum(T) - fw.sum(ts);
                printf("%d %d\n", it->second.first, more + 1);
                fw.add(ts, -1);
                ord.erase({ts, a});
                it->second.second = ++T;
                fw.add(T, 1);
                ord.insert({T, a});
            }
        }
    }
}
