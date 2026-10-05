#include <bits/stdc++.h>
using namespace std;
typedef bitset<6008> BS;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, Q;
    if(!(cin >> N >> M >> Q)) return 0;
    vector<BS> rows(N);
    for(int i = 0; i < N; i++){ rows[i][i] = 1; rows[i][N + i] = 1; }
    for(int e = 0; e < M; e++){
        int u, v; cin >> u >> v; u--; v--;
        rows[u][v] = 1; rows[v][u] = 1;
    }
    int rank = 0;
    vector<int> pivotCol;
    for(int c = 0; c < N && rank < N; c++){
        int sel = -1;
        for(int i = rank; i < N; i++) if(rows[i][c]){ sel = i; break; }
        if(sel < 0) continue;
        swap(rows[rank], rows[sel]);
        for(int i = 0; i < N; i++)
            if(i != rank && rows[i][c]) rows[i] ^= rows[rank];
        pivotCol.push_back(c);
        rank++;
    }
    string out;
    for(int q = 0; q < Q; q++){
        string bits; bits.reserve(N);
        while((int)bits.size() < N){
            string tok;
            if(!(cin >> tok)) break;
            for(char ch : tok) if(ch == '0' || ch == '1') bits.push_back(ch);
        }
        BS bExt;
        for(int i = 0; i < N; i++) if(bits[i] == '0') bExt[N + i] = 1;
        vector<int> cj(N, 0);
        bool ok = true;
        for(int j = 0; j < N; j++){
            int par = (int)((rows[j] & bExt).count()) & 1;
            cj[j] = par;
            if(j >= rank && par) ok = false;
        }
        if(!ok){ out += "-1\n"; continue; }
        vector<int> xs;
        for(int j = 0; j < rank; j++) if(cj[j]) xs.push_back(pivotCol[j] + 1);
        out += to_string(xs.size());
        for(int v : xs){ out += ' '; out += to_string(v); }
        out += '\n';
    }
    fputs(out.c_str(), stdout);
    return 0;
}
