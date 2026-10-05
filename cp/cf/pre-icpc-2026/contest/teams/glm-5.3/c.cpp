#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    if(scanf("%d",&T)!=1) return 0;
    while(T--){
        auto Q=[&](char c)->int{
            printf("? %c\n", c); fflush(stdout);
            int r; if(scanf("%d",&r)!=1) exit(0);
            return r;
        };
        int d=0;
        while(Q('L')) d++;
        for(int i=0;i<d;i++) Q('B');
        long long lo=1, hi=(1LL<<d)+1;
        while(lo<hi){
            long long mid=(lo+hi)/2;
            long long bits=mid-1;
            int depth=0;
            bool ok=true;
            for(int b=d-1;b>=0;b--){
                if(Q((bits>>b)&1 ? 'R':'L')) depth++;
                else { ok=false; for(int j=0;j<depth;j++) Q('B'); break; }
            }
            if(ok){ for(int j=0;j<depth;j++) Q('B'); lo=mid+1; }
            else hi=mid;
        }
        long long k=lo-1;
        long long N=(1LL<<d)-1+k;
        printf("! %lld\n", N); fflush(stdout);
    }
    return 0;
}
