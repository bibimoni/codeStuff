#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T; 
    if(scanf("%d", &T) != 1) return 0;
    while(T--){
        ll n; scanf("%lld", &n);
        ll t = 9; bool stan = true;
        while(n > t){ t = stan ? t*2 : t*9; stan = !stan; }
        puts(stan ? "La premiere joueuse gagne." : "La deuxieme joueuse gagne.");
    }
    return 0;
}
