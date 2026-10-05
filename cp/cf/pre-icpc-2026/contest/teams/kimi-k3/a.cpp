#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> p(n),rk(n+2,-1);
    for(int i=0;i<n;i++){ scanf("%d",&p[i]); rk[p[i]]=i; }
    int brk=0;
    for(int i=0;i+1<n;i++){
        // pair (p[i],p[i+1]): same char allowed iff rk[p[i]+1] < rk[p[i+1]+1]
        if(rk[p[i]+1] > rk[p[i+1]+1]) brk++;
    }
    printf("%d\n",brk+1);
    return 0;
}
