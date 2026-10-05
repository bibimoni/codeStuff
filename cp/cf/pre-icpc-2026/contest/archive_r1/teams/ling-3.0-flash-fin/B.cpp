#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001;

int N, M, Q;
bitset<MAXN> rrefA[MAXN], Tmat[MAXN];
int pivot_col_arr[MAXN], pivot_row_arr[MAXN];
int rank_A;

void build(bool adj[MAXN][MAXN]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj[i][j]) rrefA[i].set(j);
        }
        Tmat[i].set(i);
    }
    memset(pivot_col_arr, -1, sizeof(pivot_col_arr));
    memset(pivot_row_arr, -1, sizeof(pivot_row_arr));
    rank_A = 0;
    for (int c = 0; c < N; c++) {
        int r = -1;
        for (int i = rank_A; i < N; i++) {
            if (rrefA[i][c]) { r = i; break; }
        }
        if (r == -1) continue;
        swap(rrefA[rank_A], rrefA[r]);
        swap(Tmat[rank_A], Tmat[r]);
        pivot_col_arr[c] = rank_A;
        pivot_row_arr[rank_A] = c;
        for (int i = 0; i < N; i++) {
            if (i != rank_A && rrefA[i][c]) {
                rrefA[i] ^= rrefA[rank_A];
                Tmat[i] ^= Tmat[rank_A];
            }
        }
        rank_A++;
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    
    static bool adj[MAXN][MAXN];
    memset(adj, false, sizeof(adj));
    for (int i = 0; i < N; i++) adj[i][i] = true;
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u][v] = true;
        adj[v][u] = true;
    }
    
    build(adj);
    
    for (int q = 0; q < Q; q++) {
        bitset<MAXN> b;
        for (int i = 0; i < N; i++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '0') b.set(i);
        }
        
        bitset<MAXN> bp;
        for (int i = 0; i < N; i++) {
            bp[i] = (Tmat[i] & b).count() % 2;
        }
        
        bool consistent = true;
        for (int i = rank_A; i < N; i++) {
            if (bp[i]) { consistent = false; break; }
        }
        
        if (!consistent) {
            printf("-1\n");
        } else {
            vector<int> result;
            for (int i = 0; i < N; i++) {
                if (pivot_col_arr[i] != -1) {
                    int r = pivot_col_arr[i];
                    if (bp[r]) result.push_back(i + 1);
                }
            }
            printf("%d", (int)result.size());
            for (int v : result) printf(" %d", v);
            printf("\n");
        }
    }
    return 0;
}
