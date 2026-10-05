#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int query(char c){
    printf("? %c\n", c);
    fflush(stdout);
    int r; scanf("%d",&r);
    return r;
}
void goRoot(){
    while(query('B')==1){}
}
bool exists(ll x){
    goRoot();
    int hb = 63 - __builtin_clzll((unsigned long long)x);
    for(int b = hb-1; b >= 0; b--){
        int r = query((x>>b)&1 ? 'R' : 'L');
        if(!r) return false;
    }
    return true;
}
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int H = 1;
        while(query('L')==1) H++;
        goRoot();
        ll ans;
        if(H == 1) ans = 1;
        else {
            ll lo = 1LL << (H-1), hi = (1LL << H) - 1;
            while(lo < hi){
                ll mid = lo + (hi - lo + 1)/2;
                if(exists(mid)) lo = mid;
                else hi = mid - 1;
            }
            ans = lo;
        }
        printf("! %lld\n", ans);
        fflush(stdout);
    }
}
