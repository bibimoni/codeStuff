#include <bits/stdc++.h>
using namespace std;
struct CustomHash {
    static uint64_t splitmix64(uint64_t x){ x+=0x9e3779b97f4a7c15ULL; x=(x^(x>>30))*0xbf58476d1ce4e5b9ULL; x=(x^(x>>27))*0x94d049bb133111ebULL; return x^(x>>31);}
    size_t operator()(uint64_t x) const { static const uint64_t FIXED = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x+FIXED);}
};
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; long long q; scanf("%d %lld",&n,&q);
        int total = n + (int)q + 2;
        vector<int> fen(total+1, 0);
        int fensz = total;
        auto add=[&](int i,int v){ for(; i<=fensz; i+=i&-i) fen[i]+=v; };
        auto qsum=[&](int i){ int r=0; for(; i>0; i-=i&-i) r+=fen[i]; return r; };
        auto findFirst=[&](){ // smallest slot with count
            int pos=0;
            for(int pw=1<<20; pw>0; pw>>=1) if(pos+pw<=fensz && fen[pos+pw]==0) pos+=pw;
            return pos+1;
        };
        int ts=0;
        vector<int> slotKey(total+1, 0);
        unordered_map<int,pair<int,int>,CustomHash> mp;
        mp.reserve(2*(n+(int)q));
        // init: key i (1..n) value 0; key 1 = LRU (smallest slot), key n MRU
        for(int i=1;i<=n;i++){ int slot=++ts; slotKey[slot]=i; add(slot,1); mp[i]={slot,0}; }
        auto touch=[&](int key){
            auto it=mp.find(key);
            int slot=it->second.first;
            add(slot,-1);
            int ns=++ts; add(ns,1);
            it->second.first=ns; slotKey[ns]=key;
        };
        int curSize=n;
        while(q--){
            int tp; scanf("%d",&tp);
            if(tp==1){
                int a; long long b; scanf("%d %lld",&a,&b);
                auto it=mp.find(a);
                if(it!=mp.end()){ it->second.second=(int)b; touch(a); }
                else{
                    int s=findFirst(); int key=slotKey[s];
                    add(s,-1); mp.erase(key);
                    int ns=++ts; add(ns,1); slotKey[ns]=a;
                    mp[a]={ns,(int)b};
                }
            } else {
                int a; scanf("%d",&a);
                auto it=mp.find(a);
                if(it==mp.end()) printf("-1\n");
                else{
                    int slot=it->second.first;
                    int r = curSize - qsum(slot) + 1;
                    printf("%d %d\n", it->second.second, r);
                    touch(a);
                }
            }
        }
    }
    return 0;
}
