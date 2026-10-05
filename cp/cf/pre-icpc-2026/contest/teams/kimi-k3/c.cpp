#include <bits/stdc++.h>
using namespace std;
int ask(char c){
    printf("? %c\n",c); fflush(stdout);
    int r; if(scanf("%d",&r)!=1) exit(0);
    return r;
}
int H;
// check node at position p (0-indexed) on level H; returns to root
bool existsNode(long long p){
    int d=0; bool ok=true;
    for(int i=H-1;i>=0;i--){
        char c=((p>>i)&1)?'R':'L';
        if(ask(c)) d++;
        else { ok=false; break; }
    }
    for(int i=0;i<d;i++) ask('B'); // climb back; parent always exists (d>0 nodes)
    return ok;
}
int main(){
    int T; if(scanf("%d",&T)!=1) return 0;
    while(T--){
        int h=0;
        while(ask('L')) h++;
        H=h;
        for(int i=0;i<h;i++) ask('B'); // back to root
        if(h==0){ printf("! 1\n"); fflush(stdout); continue; }
        long long lo=0, hi=(1LL<<h)-1; // lo exists (leftmost)
        while(lo<hi){
            long long mid=(lo+hi+1)/2;
            if(existsNode(mid)) lo=mid; else hi=mid-1;
        }
        long long total=(1LL<<h)-1 + lo + 1;
        printf("! %lld\n",total); fflush(stdout);
    }
    return 0;
}
