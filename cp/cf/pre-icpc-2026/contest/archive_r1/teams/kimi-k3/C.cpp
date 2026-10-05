#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int curDepth;

int qmove(char c){
    printf("? %c\n", c);
    fflush(stdout);
    int r;
    if(scanf("%d",&r)!=1) exit(0);
    return r;
}

void toRoot(){
    while(curDepth>0){ int r=qmove('B'); if(r) curDepth--; else break; }
}

// probe node x at depth d: 1 if exists (ends at x), 0 if not (stops on path)
int probe(ll x, int d){
    toRoot();
    for(int i=d-1;i>=0;i--){
        char c = ((x>>i)&1) ? 'R' : 'L';
        int r = qmove(c);
        if(!r) return 0;
        curDepth++;
    }
    return 1;
}

int main(){
    int T;
    if(scanf("%d",&T)!=1) return 0;
    while(T--){
        curDepth=0;
        int d=0;
        while(qmove('L')){ d++; curDepth++; }
        if(d==0){ printf("! 1\n"); fflush(stdout); continue; }
        ll lo=1LL<<d, hi=(1LL<<(d+1))-1, ans=lo;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(probe(mid,d)){ ans=mid; lo=mid+1; }
            else hi=mid-1;
        }
        printf("! %lld\n", ans);
        fflush(stdout);
    }
    return 0;
}
