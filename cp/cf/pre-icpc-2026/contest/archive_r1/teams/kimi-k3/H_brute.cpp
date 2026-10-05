#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; scanf("%d",&tc);
    while(tc--){
        int n,q; scanf("%d %d",&n,&q);
        deque<int> dq; unordered_map<int,long long> val;
        for(int i=n;i>=1;i--) dq.push_back(i); // dq[0]=MRU
        for(int i=1;i<=n;i++) val[i]=0;
        while(q--){
            int ty; scanf("%d",&ty);
            if(ty==2){
                int a; scanf("%d",&a);
                auto it=find(dq.begin(),dq.end(),a);
                if(it==dq.end()){ printf("-1\n"); continue; }
                int r=it-dq.begin()+1;
                printf("%lld %d\n", val[a], r);
                dq.erase(it); dq.push_front(a);
            } else {
                int a,b; scanf("%d %d",&a,&b);
                auto it=find(dq.begin(),dq.end(),a);
                if(it!=dq.end()){ dq.erase(it); }
                else { val.erase(dq.back()); dq.pop_back(); }
                dq.push_front(a); val[a]=b;
            }
        }
    }
    return 0;
}
