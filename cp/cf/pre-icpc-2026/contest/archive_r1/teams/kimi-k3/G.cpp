#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<long long> d(n);
        for(int i=0;i<n;i++) scanf("%lld",&d[i]);
        bool cross=false;
        for(int i=3;i<n && !cross;i++){
            if(d[i]>=d[i-2] && d[i-1]<=d[i-3]) cross=true;
            else if(i>=4 && d[i-1]==d[i-3] && d[i]+d[i-4]>=d[i-2]) cross=true;
            else if(i>=5 && d[i-2]>=d[i-4] && d[i]+d[i-4]>=d[i-2] && d[i-1]<=d[i-3] && d[i-1]+d[i-5]>=d[i-3]) cross=true;
        }
        puts(cross?"Yes":"No");
    }
    return 0;
}
