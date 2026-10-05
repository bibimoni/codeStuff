#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define endl '\n'
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
const int N = 4000 + 3;
const int INF = 1e9 + 7;
const int mod = 998244353;

int n;
vector <pair<int,int>> g[N];

int C[N][N];
int dp[N][N];
// nghiệm khi xét cây con gốc u, nút u ở vị trí j trong hoán vị
int sum[N], f[2][N];
int sz[N];

void add(int &cur, int val){
	cur += val; if (cur >= mod) cur -= mod;
}
void dfs(int u, int par){
	
	for(pair<int,int> tmp : g[u]) if (tmp.first != par) dfs(tmp.first, u);

	sz[u] = 1; f[0][1] = 1;
	int cur = 0;
 	for(pair<int,int> tmp : g[u]){
		int v = tmp.first, w = tmp.second;
		if (v == par) continue;
		cur = 1 - cur;

		FOR(i, 1, sz[v]){
			sum[i] = sum[i - 1] + dp[v][i];
			if (sum[i] >= mod) sum[i] -= mod;
		}

		FOR(i, 1, sz[u] + sz[v]) f[cur][i] = 0;
		FOR(pu, 1, sz[u]) FOR(c, 0, sz[v]){
			// xét u ở vị trí pu trong hoán vị ban đầu (chưa xét nhánh v)
			// xét chọn c thằng trong cây con gốc v để chèn trước vị trí của u, sz[v] - c thằng đứng sau u
			// => u ở vị trí pu + c trong hoán vị sz[u] + sz[v]

			int val = 1ll * C[pu + c - 1][c] * C[sz[u] + sz[v] - pu - c][sz[v] - c] % mod; 
			// chèn c thằng vào trước u => có pu + c - 1 vị trí để chèn
			// chèn sz[v] - c thằng vào sau u => có sz[u] + sz[v] - pu - c vị trí để chèn

			int sl = 0;
			if (w == 1) sl = (sum[sz[v]] - sum[c] + mod) % mod;
			else if (w == 2) sl = sum[c];
			else sl = sum[sz[v]];
			// xét v đứng trước hay đứng sau u

			add(f[cur][pu + c], 1ll * f[1 - cur][pu] * val % mod * sl % mod);
		}

		sz[u] += sz[v];
	}

	FOR(i, 1, sz[u]) dp[u][i] = f[cur][i];
}
signed main(){
	#define uwu "topo"
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen(uwu".inp","r",stdin);
	// freopen(uwu".out","w",stdout);

	cin >> n;
	FOR(i, 1, n - 1){
		int u, v, w; cin >> u >> v >> w;

		if (w == 0){
			g[u].pb(make_pair(v, 0));
			g[v].pb(make_pair(u, 0));
		} else{
			int nw = w == 1 ? 2 : 1;
			g[u].pb(make_pair(v, w));
			g[v].pb(make_pair(u, nw));
		}
	}

	FOR(i, 0, n){
		C[i][0] = 1;
		FOR(j, 1, i){
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= mod) C[i][j] -= mod;
		}
	}

	dfs(1, 0);

	int res = 0;
	FOR(j, 1, n) add(res, dp[1][j]);
	cout << res;

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}