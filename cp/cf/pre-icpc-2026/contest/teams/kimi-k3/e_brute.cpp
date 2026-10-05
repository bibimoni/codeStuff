#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
int main(int argc,char**argv){
    srand(atoi(argv[1]));
    int TRIALS=300;
    for(int tc=0;tc<TRIALS;tc++){
        int n=1+rand()%7; // 1..7
        vector<array<int,3>> edges;
        // random tree on n nodes
        for(int v=2;v<=n;v++){
            int u=1+rand()%(v-1);
            int w=rand()%3;
            edges.push_back({u,v,w});
        }
        // brute: enumerate orientations of flexible edges, for each count LE, sum mod P
        vector<int> flex;
        for(int i=0;i<n-1;i++) if(edges[i][2]==0) flex.push_back(i);
        ll tot=0;
        int nf=flex.size();
        for(int mask=0;mask<(1<<nf);mask++){
            // directed constraints
            vector<pair<int,int>> cons;
            for(int i=0;i<n-1;i++){
                int u=edges[i][0], v=edges[i][1], w=edges[i][2];
                if(w==1) cons.push_back({u,v});
                else if(w==2) cons.push_back({v,u});
                else {
                    int bit=(mask>>(find(flex.begin(),flex.end(),i)-flex.begin()))&1;
                    if(bit) cons.push_back({u,v}); else cons.push_back({v,u});
                }
            }
            // count permutations respecting cons
            vector<int> perm(n); iota(perm.begin(),perm.end(),1);
            do{
                // check
                bool okk=true;
                static int pos[9];
                for(int i=0;i<n;i++) pos[perm[i]]=i;
                for(auto&c:cons) if(pos[c.first]>=pos[c.second]){ okk=false; break; }
                if(okk) tot=(tot+1)%P;
            }while(next_permutation(perm.begin(),perm.end()));
        }
        // run solution
        ofstream f("/tmp/e_in.txt"); f<<n<<"\n"; for(auto&e:edges) f<<e[0]<<" "<<e[1]<<" "<<e[2]<<"\n"; f.close();
        system("./e < /tmp/e_in.txt > /tmp/e_out.txt");
        ll got; { ifstream in("/tmp/e_out.txt"); in>>got; }
        if(got!=tot){ printf("MISMATCH tc=%d n=%d expect=%lld got=%lld\n  edges:\n",tc,n,tot,got); for(auto&e:edges)printf("   %d %d %d\n",e[0],e[1],e[2]); return 1; }
    }
    printf("all ok\n");
    return 0;
}
