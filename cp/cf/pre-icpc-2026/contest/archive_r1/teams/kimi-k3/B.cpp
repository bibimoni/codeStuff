#include <bits/stdc++.h>
using namespace std;
const int MAXW = 6010; // 2N bits
typedef bitset<MAXW> bs;
int N, M, Q;
vector<bs> rows; // [B | U]
int main(){
    scanf("%d %d %d",&N,&M,&Q);
    rows.assign(N, bs());
    for(int i=0;i<M;i++){ int u,v; scanf("%d %d",&u,&v); u--; v--; rows[u].set(v); rows[v].set(u); }
    for(int i=0;i<N;i++){ rows[i].set(i); rows[i].set(N+i); }
    vector<int> pivcol;
    int cur=0;
    for(int col=0; col<N && cur<N; col++){
        int r=-1;
        for(int i=cur;i<N;i++) if(rows[i][col]){ r=i; break; }
        if(r<0) continue;
        swap(rows[r], rows[cur]);
        for(int i=0;i<N;i++) if(i!=cur && rows[i][col]) rows[i]^=rows[cur];
        pivcol.push_back(col);
        cur++;
    }
    int rank=cur;
    // per query
    string line;
    for(int q=0;q<Q;q++){
        bs bvec;
        for(int i=0;i<N;i++){ char c; do{ int ch=getchar(); if(ch==EOF){c=0;break;} if(ch=='0'||ch=='1'){c=(char)ch;break;} }while(1); if(c==0) break; if(c=='0') bvec.set(i); }
        bs bvecX; for(int j=0;j<N;j++) if(bvec[j]) bvecX.set(N+j);
        vector<int> y(N,0);
        bool ok=true;
        for(int i=0;i<N;i++){
            int v = (int)((rows[i] & bvecX).count() & 1);
            y[i]=v;
            if(i>=rank && v) ok=false;
        }
        if(!ok){ printf("-1\n"); continue; }
        vector<int> xs;
        for(int i=0;i<rank;i++) if(y[i]) xs.push_back(pivcol[i]);
        printf("%d",(int)xs.size());
        for(int x: xs) printf(" %d", x+1);
        printf("\n");
    }
    return 0;
}
