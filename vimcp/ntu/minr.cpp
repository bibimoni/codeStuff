/**
 * File              : minr.cpp
 * Author            : distiled
 * Date              : 15.07.2023
 * Last Modified Date: 15.07.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod (int)1e9 + 7
#define endl '\n'
#define MAXN (int) 1e5 + 5
#define LG (int) 20

int sp[LG][MAXN];
int lg[MAXN];

int query(int l, int r) {
	int k = lg[r - l + 1];
	return min(sp[k][l], sp[k][r - (1 << k) + 1]);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for(int i = 0; i < n; i++) cin >> sp[0][i];
	lg[1] = 0;
	for(int i = 2; i <= n; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for(int i = 1; i < LG; i++) {
		for(int j = 0; j + (1 << i) - 1 < n; j++) {
			sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
		}
	}
	while(m--) {
		int l, r; cin >> l >> r;
		l--; r--;
		cout << query(l, r) << endl;
	}
}
