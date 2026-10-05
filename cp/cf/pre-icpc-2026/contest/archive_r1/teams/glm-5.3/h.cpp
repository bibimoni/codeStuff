#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long,long long>, null_type, less<pair<long long,long long>>, rb_tree_tag, tree_order_statistics_node_update> ordtree;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long n,q; scanf("%lld %lld",&n,&q);
        ordtree tr;
        unordered_map<long long, pair<long long,long long>> mp; // key -> (pos, val)
        mp.reserve(2*(n+q)+4);
        for(long long k=1;k<=n;k++){
            tr.insert({k,k});
            mp[k] = {k, 0};
        }
        long long pos = n;
        for(long long i=0;i<q;i++){
            int type; scanf("%d",&type);
            if(type==1){
                long long a,b; scanf("%lld %lld",&a,&b);
                auto it = mp.find(a);
                if(it!=mp.end()){
                    tr.erase({it->second.first,a});
                    pos++;
                    tr.insert({pos,a});
                    it->second = {pos, b};
                } else {
                    if((long long)tr.size()==n){
                        auto lu = *tr.begin();
                        tr.erase(lu);
                        mp.erase(lu.second);
                    }
                    pos++;
                    tr.insert({pos,a});
                    mp[a] = {pos, b};
                }
            } else {
                long long a; scanf("%lld",&a);
                auto it = mp.find(a);
                if(it==mp.end()) puts("-1");
                else {
                    long long p = it->second.first;
                    long long cnt_less = tr.order_of_key({p,a});
                    printf("%lld %lld\n", it->second.second, (long long)tr.size() - cnt_less);
                    tr.erase({p,a});
                    pos++;
                    tr.insert({pos,a});
                    it->second.first = pos;
                }
            }
        }
    }
}
