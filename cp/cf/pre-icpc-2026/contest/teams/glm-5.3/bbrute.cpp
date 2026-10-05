// brute: for small graphs try all 2^N button subsets, verify same solvability
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q; if(scanf("%d %d %d",&n,&m,&q)!=3) return 0;
    vector<int> mask(n,0);
    for(int i=0;i<n;i++) mask[i]|=1<<i;
    for(int i=0;i<m;i++){ int u,v; scanf("%d %d",&u,&v); u--; v--; mask[u]|=1<<v; mask[v]|=1<<u; }
    { int c; while((c=getchar())!='\n'&&c!=EOF); }
    string line;
    while(q--){
        if(!getline(cin,line)) break;
        string st; for(char ch:line) if(ch=='0'||ch=='1') st+=ch;
        int b=0; for(int i=0;i<n;i++) if(st[i]=='0') b|=1<<i;
        bool found=false;
        for(int x=0;x<(1<<n);x++){
            int cur=0;
            for(int i=0;i<n;i++) if(x>>i&1) cur^=mask[i];
            if(cur==b){ found=true; break; }
        }
        printf(found?"+\n":"-\n");
    }
}
