#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d", &T);
    while(T--){
        long long n; scanf("%lld", &n);
        long long b = 9; bool stan = true;
        while(b < n){ b *= stan ? 2 : 9; stan = !stan; }
        puts(stan ? "La premiere joueuse gagne." : "La deuxieme joueuse gagne.");
    }
    return 0;
}
