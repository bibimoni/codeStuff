#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct H {
    size_t operator()(ll x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x += FIXED_RANDOM + 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
};

struct Fenw {
    int n; vector<int> b;
    void init(int n_){ n=n_; b.assign(n+2,0); }
    void add(int i,int d){ for(;i<=n;i+=i&-i) b[i]+=d; }
    int sum(int i){ int s=0; for(;i>0;i-=i&-i) s+=b[i]; return s; }
    int kth1(){ // smallest i with sum(i)>=1; assumes total>=1
        int idx=0;
        for(int d=31-__builtin_clz(n); d>=0; d--){
            int ni = idx + (1<<d);
            if(ni<=n && b[ni]<1){ idx=ni; }
        }
        return idx+1;
    }
};

int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n,q; scanf("%d %d",&n,&q);
        int captot = n+q+2;
        Fenw fw; fw.init(captot+1);
        vector<int> who(captot+2, -1); // counter -> key index in keys list
        vector<ll> keyOf; // dense list of keys by internal id
        unordered_map<ll,int,H> kid; kid.reserve(2*captot);
        vector<ll> val(captot+2); vector<int> cnt(captot+2);
        for(int i=1;i<=n;i++){
            int id = keyOf.size(); keyOf.push_back(i);
            kid[i]=id; val[id]=0; cnt[id]=i; who[i]=id; fw.add(i,1);
        }
        int c=n;
        while(q--){
            int ty; scanf("%d",&ty);
            if(ty==2){
                ll a; scanf("%lld",&a);
                auto it=kid.find(a);
                if(it==kid.end()){ printf("-1\n"); continue; }
                int id=it->second;
                int r = n - fw.sum(cnt[id]-1);
                printf("%lld %d\n", val[id], r);
                fw.add(cnt[id],-1);
                ++c; cnt[id]=c; who[c]=id; fw.add(c,1);
            } else {
                ll a,b; scanf("%lld %lld",&a,&b);
                auto it=kid.find(a);
                ++c;
                if(it!=kid.end()){
                    int id=it->second; val[id]=b;
                    fw.add(cnt[id],-1); cnt[id]=c; who[c]=id; fw.add(c,1);
                } else {
                    int lc = fw.kth1(); int lid = who[lc];
                    kid.erase(keyOf[lid]);
                    fw.add(lc,-1);
                    int id = keyOf.size(); keyOf.push_back(a);
                    kid[a]=id; val[id]=b; cnt[id]=c; who[c]=id; fw.add(c,1);
                }
            }
        }
    }
    return 0;
}
