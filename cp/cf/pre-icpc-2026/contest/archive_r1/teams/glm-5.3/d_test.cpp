#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(ll n){
    ll t = 9; bool stan = true;
    while(n > t){ t = stan ? t*2 : t*9; stan = !stan; }
    return stan;
}

int main(){
    // brute force game DP for small n
    for(ll n = 1; n <= 3000; n++){
        // W[p] = mover wins at p (p < n), memo
        vector<int> W(n*9+10, -1);
        function<int(ll)> rec = [&](ll p) -> int {
            if(p >= n) return 0; // shouldn't happen
            if(W[p] != -1) return W[p];
            int res = 0;
            for(ll k = 2; k <= 9; k++){
                if(p*k >= n){ res = 1; break; }
                if(rec(p*k) == 0){ res = 1; break; }
            }
            return W[p] = res;
        };
        int brute = (n == 1) ? 1 : rec(1);
        int mine = solve(n);
        if(brute != mine){ printf("MISMATCH n=%lld brute=%d mine=%d\n", n, brute, mine); return 1; }
    }
    printf("all match 1..3000\n");
    // samples
    printf("n=9: %d (want 1)\nn=18: %d (want 0)\nn=27: %d (want 1)\n", solve(9), solve(18), solve(27));
    return 0;
}
