#include <bits/stdc++.h>
using namespace std;
static int par_[200005];
int find(int x){ while(par_[x]>=0){ if(par_[par_[x]]>=0) par_[x]=par_[par_[x]]; x=par_[x]; } return x; }
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n,m; scanf("%d %d",&n,&m);
        int N=n*m;
        vector<int> g(N);
        for(int i=0;i<N;i++) scanf("%d",&g[i]);
        vector<char> alive(N,0);
        for(int i=0;i<N;i++) if(g[i]!=0) alive[i]=1;
        int q; scanf("%d",&q);
        vector<int> cell(q);
        for(int i=0;i<q;i++){
            int r,c; scanf("%d %d",&r,&c); r--; c--;
            cell[i]=r*m+c;
            alive[cell[i]]=0;
        }
        for(int i=0;i<N;i++) par_[i]=-1;
        vector<char> inDSU(N,0);
        long long cycles=0;
        static const int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
        static const int needSelf[4]={1,2,4,8}, needNbr[4]={4,8,1,2};
        auto insert=[&](int id){
            inDSU[id]=1;
            int r=id/m, c=id%m;
            for(int dir=0;dir<4;dir++){
                if(!(g[id]&needSelf[dir])) continue;
                int rr=r+dr[dir], cc=c+dc[dir];
                if(rr<0||rr>=n||cc<0||cc>=m) continue;
                int nb=rr*m+cc;
                if(!inDSU[nb]) continue;
                if(!(g[nb]&needNbr[dir])) continue;
                int a=find(id), b=find(nb);
                if(a==b) cycles++;
                else{
                    if(par_[a]>par_[b]) swap(a,b);
                    par_[a]+=par_[b]; par_[b]=a;
                }
            }
        };
        for(int i=0;i<N;i++) if(alive[i]) insert(i);
        vector<long long> res(max(q,1),0);
        if(q>0) res[q-1]=cycles;
        for(int k=q-1;k>=1;k--) insert(cell[k]), res[k-1]=cycles;
        for(int i=0;i<q;i++) printf("%lld ", res[i]);
        printf("\n");
    }
    return 0;
}
