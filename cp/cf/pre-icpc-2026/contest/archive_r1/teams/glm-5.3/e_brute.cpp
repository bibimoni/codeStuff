// Brute force for E: enumerate orientations of flexible edges, count LEs by permutation DFS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<array<int,3>> edges; // u, v, w
long long countLE(vector<pair<int,int>>& cons){ // cons: (a before b)
    // count permutations of 1..n satisfying all
    vector<int> perm(n); iota(perm.begin(), perm.end(), 1);
    long long cnt = 0;
    do {
        vector<int> pos(n+1);
        for(int i = 0; i < n; i++) pos[perm[i]] = i;
        bool ok = true;
        for(auto& pr : cons) if(pos[pr.first] > pos[pr.second]){ ok = false; break; }
        if(ok) cnt++;
    } while(next_permutation(perm.begin(), perm.end()));
    return cnt;
}

int main(int argc, char** argv){
    unsigned seed = argc > 1 ? atoi(argv[1]) : 1;
    mt19937 rng(seed);
    int T = 400;
    long long bad = 0;
    for(int t = 0; t < T; t++){
        n = 1 + rng() % 7;
        edges.clear();
        for(int i = 2; i <= n; i++){
            int u = 1 + rng() % (i-1); // random parent -> tree
            int v = i;
            int w = rng() % 3;
            if(rng() & 1) edges.push_back({u, v, w});
            else edges.push_back({v, u, w});
        }
        // brute: sum over flexible orientations
        vector<pair<int,int>> strict;
        vector<int> flexIdx;
        for(int i = 0; i < (int)edges.size(); i++){
            auto& e = edges[i];
            if(e[2] == 1) strict.push_back({e[0], e[1]});
            else if(e[2] == 2) strict.push_back({e[1], e[0]});
            else flexIdx.push_back(i);
        }
        long long total = 0;
        for(int mask = 0; mask < (1 << flexIdx.size()); mask++){
            auto cons = strict;
            for(int b = 0; b < (int)flexIdx.size(); b++){
                auto& e = edges[flexIdx[b]];
                if(mask >> b & 1) cons.push_back({e[0], e[1]});
                else cons.push_back({e[1], e[0]});
            }
            total += countLE(cons);
        }
        // write input to file, run ./e
        char fname[64]; sprintf(fname, "e_t_%u.in", seed);
        FILE* f = fopen(fname, "w");
        fprintf(f, "%d\n", n);
        for(auto& e : edges) fprintf(f, "%d %d %d\n", e[0], e[1], e[2]);
        fclose(f);
        char cmd[128]; sprintf(cmd, "./e < %s", fname);
        FILE* p = popen(cmd, "r");
        ll mine; fscanf(p, "%lld", &mine); pclose(p);
        if(mine != total){ bad++; printf("MISMATCH seed=%u t=%d n=%d brute=%lld mine=%lld\n", seed, t, n, total, mine);
            for(auto& e : edges) printf("  %d %d %d\n", e[0], e[1], e[2]);
            if(bad > 2) return 1; }
    }
    printf("done, bad=%lld\n", bad);
    return 0;
}
