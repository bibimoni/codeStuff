// verify b.cpp output on a given input: simulate toggles
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    // argv[1] = input file, argv[2] = output file
    ifstream in(argv[1]), out(argv[2]);
    int N, M, Q; in >> N >> M >> Q;
    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++){ int u,v; in >> u >> v; u--; v--; adj[u].push_back(v); adj[v].push_back(u); }
    vector<string> states(Q);
    for(auto &s : states){ s = ""; int cnt = 0; while(cnt < N){ string t; in >> t; for(char c: t) if(c=='0'||c=='1'){ s += c; cnt++; } } }
    for(int q = 0; q < Q; q++){
        int K; 
        if(!(out >> K)){ printf("query %d: missing output\n", q); return 1; }
        if(K == -1){ printf("query %d: -1 (unverified)\n", q); continue; }
        string st = states[q];
        vector<int> used(N, 0);
        for(int i = 0; i < K; i++){
            int x; out >> x; x--;
            if(x < 0 || x >= N){ printf("query %d: bad index\n", q); return 1; }
            if(used[x]){ printf("query %d: duplicate %d\n", q, x+1); return 1; }
            used[x] = 1;
            st[x] = (st[x]=='0') ? '1' : '0';
            for(int y : adj[x]) st[y] = (st[y]=='0') ? '1' : '0';
        }
        bool all1 = true; for(char c : st) if(c != '1') all1 = false;
        printf("query %d: K=%d allOnline=%d\n", q, K, (int)all1);
        if(!all1) return 1;
    }
    return 0;
}
