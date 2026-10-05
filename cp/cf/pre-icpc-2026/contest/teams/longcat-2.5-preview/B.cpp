#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
int n, m, q;
bitset<2*MAXN> a[MAXN];
int where[MAXN];
vector<int> Z, F;

int z, f;
vector<bitset<2*MAXN>> krow;
vector<int> kwhere;
vector<int> KZ;

int main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i=0;i<n;i++){ a[i][i] = 1; a[i][n+i] = 1; }
    for(int i=0;i<m;i++){
        int u,v; scanf("%d %d",&u,&v); --u;--v;
        a[u][v] = a[u][v]^1;
        a[v][u] = a[v][u]^1;
    }
    for(int col=0;col<n;col++) where[col] = -1;
    int r = 0;
    for(int col=0; col<n && r<n; col++){
        int sel = -1;
        for(int i=r;i<n;i++) if(a[i][col]){ sel=i; break; }
        if(sel<0) continue;
        swap(a[sel], a[r]);
        for(int i=0;i<n;i++) if(i!=r && a[i][col]) a[i] ^= a[r];
        where[col] = r;
        r++;
    }
    for(int i=r;i<n;i++) Z.push_back(i);
    for(int col=0;col<n;col++) if(where[col]<0) F.push_back(col);
    z = Z.size(); f = F.size();

    krow.assign(z, bitset<2*MAXN>());
    for(int i=0;i<z;i++){
        for(int j=0;j<f;j++) krow[i][j] = a[Z[i]][F[j]];
        krow[i][f+i] = 1;
    }
    kwhere.assign(f, -1);
    if(z>0){
        int rk = 0;
        for(int col=0; col<f && rk<z; col++){
            int sel = -1;
            for(int i=rk;i<z;i++) if(krow[i][col]){ sel=i; break; }
            if(sel<0) continue;
            swap(krow[sel], krow[rk]);
            for(int i=0;i<z;i++) if(i!=rk && krow[i][col]) krow[i] ^= krow[rk];
            kwhere[col] = rk;
            rk++;
        }
        for(int i=rk;i<z;i++) KZ.push_back(i);
    }

    while(q--){
        string s;
        s.reserve(n);
        int c;
        while((int)s.size()<n){
            c = getchar();
            if(c=='0'||c=='1') s.push_back((char)c);
        }
        bitset<2*MAXN> b;
        for(int i=0;i<n;i++) if(s[i]=='0') b[i] = 1;
        vector<int> y(n, 0);
        for(int i=0;i<n;i++) y[i] = (int)((a[i] >> n) & b).count() & 1;
        bitset<2*MAXN> yZ;
        for(int i=0;i<z;i++) yZ[f+i] = y[Z[i]];
        vector<int> y2(z, 0);
        for(int i=0;i<z;i++) y2[i] = (int)(krow[i] & yZ).count() & 1;
        bool ok = true;
        for(int i:KZ) if(y2[i]){ ok=false; break; }
        if(!ok){ printf("-1\n"); continue; }
        vector<int> beta(f, 0);
        for(int j=0;j<f;j++) if(kwhere[j]>=0) beta[j] = y2[kwhere[j]];
        bitset<2*MAXN> betaBs;
        for(int j=0;j<f;j++) if(beta[j]) betaBs[F[j]] = 1;
        vector<int> x(n, 0);
        for(int j=0;j<f;j++) x[F[j]] = beta[j];
        for(int col=0;col<n;col++){
            if(where[col]>=0) x[col] = y[where[col]] ^ (int)(a[where[col]] & betaBs).count() & 1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++) if(x[i]) ans.push_back(i+1);
        printf("%d", (int)ans.size());
        for(int v:ans) printf(" %d", v);
        printf("\n");
    }
}
