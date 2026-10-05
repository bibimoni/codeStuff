#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<long long> a(n); for(auto&x:a) scanf("%lld",&x);
        long long cnt=0;
        for(int mask=0; mask<(1<<(n-1)); mask++){
            vector<long long> pieces; long long part=0;
            for(int i=0;i<n;i++){
                part+=a[i];
                if(mask>>i&1){ pieces.push_back(part); part=0; }
            }
            pieces.push_back(part);
            bool ok=true;
            for(long long x:pieces) if(x!=pieces[0]) ok=false;
            if(ok) cnt++;
        }
        printf("%d\n",(int)(cnt%1000000007));
    }
}
