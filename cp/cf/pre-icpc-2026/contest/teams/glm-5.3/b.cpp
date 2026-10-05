#include <bits/stdc++.h>
using namespace std;
const int MAXN=3002;
bitset<MAXN> A[3005];
bitset<MAXN> L[3005];
int piv[3005];
int main(){
    int n,m,q;
    if(scanf("%d %d %d",&n,&m,&q)!=3) return 0;
    for(int i=0;i<n;i++) A[i][i]=1;
    for(int i=0;i<m;i++){ int u,v; scanf("%d %d",&u,&v); u--; v--; A[u][v]=A[v][u]=1; }
    for(int i=0;i<n;i++) L[i][i]=1;
    int rank=0;
    for(int col=0; col<n && rank<n; col++){
        int sel=-1;
        for(int r=rank;r<n;r++) if(A[r][col]){ sel=r; break; }
        if(sel<0) continue;
        swap(A[sel],A[rank]); swap(L[sel],L[rank]);
        for(int r=0;r<n;r++) if(r!=rank && A[r][col]){ A[r]^=A[rank]; L[r]^=L[rank]; }
        piv[rank]=col; rank++;
    }
    { int c; while((c=getchar())!='\n' && c!=EOF); }
    string line;
    while(q--){
        if(!getline(cin,line)) break;
        bitset<MAXN> b;
        int idx=0;
        for(char ch: line){ if(ch=='0'||ch=='1'){ b[idx++]=(ch=='0'); } }
        bool ok=true;
        for(int r=rank;r<n;r++){
            if((L[r]&b).count()&1){ ok=false; break; }
        }
        if(!ok){ printf("-1\n"); continue; }
        bitset<MAXN> x;
        for(int r=0;r<rank;r++) x[piv[r]] = (L[r]&b).count()&1;
        int cnt=0;
        for(int i=0;i<n;i++) if(x[i]) cnt++;
        printf("%d", cnt);
        for(int i=0;i<n;i++) if(x[i]) printf(" %d", i+1);
        printf("\n");
    }
    return 0;
}
