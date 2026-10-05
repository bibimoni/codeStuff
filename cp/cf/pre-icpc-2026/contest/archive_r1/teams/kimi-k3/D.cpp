#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        long long n; scanf("%lld",&n);
        long long a=n; int i=0; bool firstWins=true;
        while(true){
            if(i%2==0) a=(a+8)/9; else a=(a+1)/2;
            if(a<=1){ firstWins = (i%2==0); break; }
            i++;
        }
        puts(firstWins? "La premiere joueuse gagne." : "La deuxieme joueuse gagne.");
    }
    return 0;
}
