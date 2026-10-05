#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; long long seed;
    if(scanf("%d %lld",&n,&seed)!=2) return 0;
    mt19937 rng(seed);
    int mx;
    scanf("%d",&mx);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        int v = 1 + (int)(rng()%mx);
        printf("%d%c",v,i==n-1?'\n':' ');
    }
}
