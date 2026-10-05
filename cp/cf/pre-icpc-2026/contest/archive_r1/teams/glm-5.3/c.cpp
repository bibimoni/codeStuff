#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int T;
    if(scanf("%d", &T) != 1) return 0;
    while(T--){
        ll cur = 1;
        int h = 0;
        while(true){
            printf("? L\n"); fflush(stdout);
            int r; if(scanf("%d", &r) != 1) return 0;
            if(r == 1){ h++; cur <<= 1; }
            else break;
        }
        if(h == 0){ printf("! 1\n"); fflush(stdout); continue; }
        ll lo = 1LL << h, hi = (1LL << (h+1)) - 1;
        while(lo < hi){
            ll mid = lo + (hi - lo + 1) / 2;
            int dcur = 64 - __builtin_clzll((ull)cur) - 1; // path length of cur
            // common prefix of path(cur) and path(mid): compare bits j=1..min(dcur,h)
            int Lc = 0;
            int jmax = min(dcur, h);
            for(int j = 1; j <= jmax; j++){
                int cb = (int)((cur >> (h - j)) & 1);
                int bb = (int)((mid >> (h - j)) & 1);
                if(cb == bb) Lc++;
                else break;
            }
            for(int j = 0; j < dcur - Lc; j++){
                printf("? B\n"); fflush(stdout);
                int r; if(scanf("%d", &r) != 1) return 0;
                cur >>= 1;
            }
            bool ok = true;
            for(int j = Lc + 1; j <= h; j++){
                int bb = (int)((mid >> (h - j)) & 1);
                printf(bb ? "? R\n" : "? L\n"); fflush(stdout);
                int r; if(scanf("%d", &r) != 1) return 0;
                if(r == 1){ cur = cur*2 + bb; }
                else { ok = false; break; }
            }
            if(ok) lo = mid; else hi = mid - 1;
        }
        printf("! %lld\n", lo); fflush(stdout);
    }
    return 0;
}
