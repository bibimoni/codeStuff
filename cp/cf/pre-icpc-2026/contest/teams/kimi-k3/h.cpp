#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ost_t;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,q; scanf("%d %d",&n,&q);
        unordered_map<long long,pair<long long,long long>> mp; // key -> (val, ts)
        unordered_map<long long,long long> tsk; // ts -> key
        mp.reserve(n*2+64); tsk.reserve(n*2+64);
        ost_t ost;
        long long counter=n;
        for(int i=1;i<=n;i++){ mp[i]={0,i}; tsk[i]=i; ost.insert(i); }
        while(q--){
            int type; scanf("%d",&type);
            if(type==1){
                long long a,b; scanf("%lld %lld",&a,&b);
                auto it=mp.find(a);
                if(it!=mp.end()){
                    ost.erase(it->second.second);
                    tsk.erase(it->second.second);
                    long long nts=++counter;
                    it->second={b,nts};
                    ost.insert(nts); tsk[nts]=a;
                } else {
                    long long oldts=*ost.begin();
                    ost.erase(ost.begin());
                    mp.erase(tsk[oldts]); tsk.erase(oldts);
                    long long nts=++counter;
                    mp[a]={b,nts};
                    ost.insert(nts); tsk[nts]=a;
                }
            } else {
                long long a; scanf("%lld",&a);
                auto it=mp.find(a);
                if(it==mp.end()){ printf("-1\n"); }
                else {
                    long long val=it->second.first, ts=it->second.second;
                    long long r=(long long)ost.size()-(long long)ost.order_of_key(ts+1)+1;
                    printf("%lld %lld\n",val,r);
                    ost.erase(ts); tsk.erase(ts);
                    long long nts=++counter;
                    it->second.second=nts;
                    ost.insert(nts); tsk[nts]=a;
                }
            }
        }
    }
    return 0;
}
