#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        ll n; scanf("%lld",&n);
        ll a=9;
        while(n > 2*a) a*=18;
        bool lose = (n > a);
        printf("%s\n", lose?"La deuxieme joueuse gagne.":"La premiere joueuse gagne.");
    }
}
