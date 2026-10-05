#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> p(n+1), r(n+2);
    for(int i=1;i<=n;i++){ scanf("%d",&p[i]); r[p[i]]=i; }
    r[n+1]=0;
    int ans=1;
    for(int i=2;i<=n;i++) if(r[p[i-1]+1] > r[p[i]+1]) ans++;
    printf("%d\n", ans);
}
