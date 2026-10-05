#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// brute: enumerate all simple paths via DFS with visited mask
int n; ll A[9], B_[9];
ll best;
void dfs(int u,int t,int mask,ll cost){
    if(u==t){ best=min(best,cost); return; }
    int hub=n+1;
    if(u==hub){
        for(int j=1;j<=n;j++) if(!(mask>>j&1)) dfs(j,t,mask|(1<<j),cost+B_[j]);
        return;
    }
    int nxt=u%n+1, prv=(u+n-2)%n+1;
    if(!(mask>>nxt&1)) dfs(nxt,t,mask|(1<<nxt),cost+A[u]);
    if(!(mask>>prv&1)) dfs(prv,t,mask|(1<<prv),cost+A[prv]);
    if(!(mask>>hub&1)) dfs(hub,t,mask|(1<<hub),cost+B_[u]);
}
int main(int argc,char**argv){
    srand(atoi(argv[1]));
    int TRIALS=60;
    for(int tc=0;tc<TRIALS;tc++){
        n=2+rand()%6;
        vector<array<ll,3>> ops;
        for(int i=1;i<=n;i++){ A[i]=rand()%21-10; B_[i]=rand()%21-10; }
        ll sav[9], sbv[9]; memcpy(sav,A,sizeof(A)); memcpy(sbv,B_,sizeof(B_));
        // build test: ops ~ 25
        ofstream f("/tmp/l_in.txt");
        int nq=25;
        // first write test case with original a,b
        f<<"1\n"<<n<<" "<<nq<<"\n";
        for(int i=1;i<=n;i++) f<<A[i]<<" "; f<<"\n";
        for(int i=1;i<=n;i++) f<<B_[i]<<" "; f<<"\n";
        vector<tuple<int,int,int>> evs;
        for(int i=0;i<nq;i++){
            int c=rand()%3+1;
            if(c==1){ int s=1+rand()%n; int t=s+1+rand()%(n+1-s); evs.push_back({1,s,t}); f<<"1 "<<s<<" "<<t<<"\n"; }
            else { int x=1+rand()%n; int w=rand()%21-10; evs.push_back({c,x,w}); f<<c<<" "<<x<<" "<<w<<"\n"; }
        }
        f.close();
        system("./l < /tmp/l_in.txt > /tmp/l_out.txt");
        ifstream in("/tmp/l_out.txt");
        // replay with brute
        memcpy(A,sav,sizeof(A)); memcpy(B_,sbv,sizeof(B_));
        for(auto&e:evs){
            int c=get<0>(e);
            if(c==1){
                int s=get<1>(e), t=get<2>(e);
                best=(ll)4e18;
                dfs(s,t,1<<s,0);
                ll got; if(!(in>>got)){ printf("PARSE FAIL\n"); return 1; }
                if(got!=best){ printf("MISMATCH tc=%d n=%d s=%d t=%d expect=%lld got=%lld\n",tc,n,s,t,best,got);
                    printf("a:"); for(int i=1;i<=n;i++)printf("%lld ",A[i]); printf("\nb:"); for(int i=1;i<=n;i++)printf("%lld ",B_[i]); printf("\n");
                    return 1; }
            } else if(c==2){ A[get<1>(e)]=get<2>(e); }
            else { B_[get<1>(e)]=get<2>(e); }
        }
    }
    printf("all ok\n");
    return 0;
}
