#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<long long> d(n);
        for(auto&v:d) scanf("%lld",&v);
        bool ans=false;
        for(int i=3;i<n;i++){
            // seg i vs seg i-3
            if(d[i]>=d[i-2] && d[i-1]<=d[i-3]) ans=true;
            // seg i vs seg i-4 (collinear overlap/touch)
            if(i>=4 && d[i-1]==d[i-3] && d[i]+d[i-4]>=d[i-2]) ans=true;
            // seg i vs seg i-5
            if(i>=5 && d[i-2]>=d[i-4] && d[i]+d[i-4]>=d[i-2] && d[i-1]<=d[i-3] && d[i-1]+d[i-5]>=d[i-3]) ans=true;
        }
        puts(ans?"Yes":"No");
    }
}
