#include <bits/stdc++.h>
using namespace std;
// per-query full Gaussian elimination on [M|b], small N; verify any solution returned
int N,M,Q;
bool solve(vector<bitset<32>>& eq, vector<int>& xout){
    int n=N;
    int r=0; vector<int> piv(n,-1);
    for(int c=0;c<n && r<n;c++){
        int sel=-1; for(int i=r;i<n;i++) if(eq[i][c]){sel=i;break;}
        if(sel<0) continue;
        swap(eq[sel],eq[r]);
        for(int j=0;j<n;j++) if(j!=r && eq[j][c]) eq[j]^=eq[r];
        piv[c]=r; r++;
    }
    for(int i=r;i<n;i++) if(eq[i][n]) return false;
    xout.assign(n,0);
    for(int c=0;c<n;c++) if(piv[c]>=0) xout[c]=eq[piv[c]][n];
    return true;
}
int main(int argc,char**argv){
    srand(atoi(argv[1]));
    int TRIALS=200;
    for(int tc=0;tc<TRIALS;tc++){
        N=1+rand()%12; M=rand()%min(20,N*max(0,N-1)/2+1); Q=1+rand()%6;
        vector<pair<int,int>> edges; set<pair<int,int>> seen;
        while((int)edges.size()<M){ int u=rand()%N, v=rand()%N; if(u==v) continue; if(u>v) swap(u,v); if(seen.count({u,v})) continue; seen.insert({u,v}); edges.push_back({u,v}); }
        vector<string> qs(Q);
        for(auto&s:qs){ s.clear(); for(int i=0;i<N;i++) s.push_back('0'+rand()%2); }
        // write input file
        ofstream f("/tmp/bb_in.txt");
        f<<N<<" "<<M<<" "<<Q<<"\n";
        for(auto&e:edges) f<<e.first+1<<" "<<e.second+1<<"\n";
        for(auto&s:qs) f<<s<<"\n";
        f.close();
        system("./b < /tmp/bb_in.txt > /tmp/bb_out.txt");
        ifstream fin("/tmp/bb_out.txt");
        // adjacency
        vector<vector<int>> mat(N,vector<int>(N,0));
        for(int i=0;i<N;i++) mat[i][i]=1;
        for(auto&e:edges){ mat[e.first][e.second]=1; mat[e.second][e.first]=1; }
        // brute check each answer line
        for(int qi=0;qi<Q;qi++){
            int kv; if(!(fin>>kv)){ printf("PARSE FAIL tc=%d q=%d\n",tc,qi); return 1; }
            if(kv==-1){
                // verify impossible via brute exponential
                bool any=false;
                for(int mask=0;mask<(1<<N);mask++){
                    bool okk=true;
                    for(int i=0;i<N;i++){ int s=qs[qi][i]-'0'; for(int j=0;j<N;j++) if(mask>>j&1) s^=mat[i][j]; if(s!=1){okk=false;break;} }
                    if(okk){any=true;break;}
                }
                if(any){ printf("FALSE -1 tc=%d q=%d\n",tc,qi); return 1; }
            } else {
                vector<int> x(N,0);
                for(int z=0;z<kv;z++){ int idx; fin>>idx; x[idx-1]=1; }
                for(int i=0;i<N;i++){ int s=qs[qi][i]-'0'; for(int j=0;j<N;j++) if(x[j]) s^=mat[i][j]; if(s!=1){ printf("BAD SOLUTION tc=%d q=%d i=%d\n",tc,qi,i); return 1; } }
            }
        }
    }
    printf("all ok\n");
    return 0;
}
