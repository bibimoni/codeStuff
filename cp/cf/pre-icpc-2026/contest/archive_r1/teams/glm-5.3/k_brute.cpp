// BFS brute for K: values in 1..3, n<=5.
// reachable value vectors via free ops; answer = min over reachable vectors of
//   k==1: min component;  else min over p<q, q-p>=k-1 of V[p]+V[q].
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; if(scanf("%d",&t)!=1) return 0;
    while(t--){
        int n,k; scanf("%d %d",&n,&k);
        vector<int> a(n); for(auto&x:a) scanf("%d",&x);
        // encode state as vector
        map<vector<int>,int> dist;
        queue<vector<int>> Q;
        vector<int> st = a;
        dist[st]=0; Q.push(st);
        long long best = LLONG_MAX;
        auto consider=[&](const vector<int>&V){
            if(k==1){ for(int x:V) best=min(best,(long long)x); }
            else{
                for(int p=0;p<n;p++)for(int q=p+k-1;q<n;q++) best=min(best,(long long)V[p]+V[q]);
            }
        };
        consider(st);
        while(!Q.empty()){
            auto V=Q.front(); Q.pop();
            for(int l=0;l<n;l++)for(int m=l+1;m<n;m++)for(int r=m+1;r<n;r++){
                auto W=V;
                W[m]=max(V[l],V[r]);
                if(!dist.count(W)){ dist[W]=1; consider(W); Q.push(W); }
            }
        }
        printf("%lld\n", best);
    }
}
