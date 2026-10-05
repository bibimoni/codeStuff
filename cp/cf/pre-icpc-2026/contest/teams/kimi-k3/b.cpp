#include <bits/stdc++.h>
using namespace std;
// solve (A+I)x = b over GF(2), N<=3000, Q<=500
const int MAXN=3000;
static bitset<6005> rows[MAXN]; // [M | I]
static bitset<3001> Tmat[MAXN]; // transformation after Gauss-Jordan
int pivRowOfCol[MAXN];
int main(){
    int N,M,Q; scanf("%d %d %d",&N,&M,&Q);
    for(int i=0;i<N;i++){ rows[i].reset(); rows[i].set(i); rows[i].set(N+i); }
    for(int i=0;i<M;i++){ int u,v; scanf("%d %d",&u,&v); u--; v--; rows[u].set(v); rows[v].set(u); }
    // Gauss-Jordan
    int r=0;
    memset(pivRowOfCol,-1,sizeof(pivRowOfCol));
    vector<int> pivRowList; // pivot rows in order
    for(int c=0;c<N && r<N;c++){
        int sel=-1;
        for(int i=r;i<N;i++) if(rows[i][c]){ sel=i; break; }
        if(sel<0) continue;
        if(sel!=r) swap(rows[sel],rows[r]);
        for(int j=0;j<N;j++) if(j!=r && rows[j][c]) rows[j]^=rows[r];
        pivRowOfCol[c]=r;
        pivRowList.push_back(r);
        r++;
    }
    int nzero=N-r;
    for(int i=0;i<N;i++){
        Tmat[i].reset();
        for(int j=0;j<N;j++) if(rows[i][N+j]) Tmat[i].set(j);
    }
    static char buf[3005];
    static bitset<3001> bb, tmp;
    vector<int> out;
    while(Q--){
        // robust: accumulate chars until N collected (handles spaced/unspaced)
        string s; s.reserve(N);
        while((int)s.size()<N){ scanf("%3000s",buf); for(char*p=buf;*p&& (int)s.size()<N;p++) s.push_back(*p); }
        bb.reset();
        for(int j=0;j<N;j++) if(s[j]=='0') bb.set(j); // need flips
        // c = T*b
        static int cc[MAXN];
        bool ok=true;
        for(int i=0;i<N;i++){
            tmp = Tmat[i] & bb;
            cc[i]=tmp.count()&1;
        }
        for(int i=N-nzero;i<N;i++) if(cc[i]){ ok=false; }
        // wait: zero rows are r..N-1 = N-nzero..N-1
        if(!ok){ printf("-1\n"); continue; }
        out.clear();
        for(int c=0;c<N;c++) if(pivRowOfCol[c]>=0 && cc[pivRowOfCol[c]]) out.push_back(c+1);
        printf("%d",(int)out.size());
        for(int x:out) printf(" %d",x);
        printf("\n");
    }
    return 0;
}
