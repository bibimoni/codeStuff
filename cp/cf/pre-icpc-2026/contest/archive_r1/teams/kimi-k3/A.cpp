#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    vector<int> p(n), rk(n+2,0);
    for(int i=0;i<n;i++){ scanf("%d",&p[i]); rk[p[i]]=i+1; }
    int chars=1;
    for(int i=1;i<n;i++){
        int a=p[i-1]+1, b=p[i]+1;
        int ra = a<=n? rk[a]:0;
        int rb = b<=n? rk[b]:0;
        if(ra>rb) chars++;
    }
    printf("%d\n",chars);
    return 0;
}
