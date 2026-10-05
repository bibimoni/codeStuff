#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
const int N = 1e5 + 3;
const int INF = 1e9 + 7;

int n, a[N];
int pos[N];

signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen("suffixarray.inp", "r", stdin);
	//freopen("suffixarray.out", "w", stdout);

	cin >> n;
	FOR(i, 1, n){
		cin >> a[i];
		pos[a[i]] = i;
	} 

	int ans = n;
	FOR(i, 1, n - 1) if (pos[a[i] + 1] < pos[a[i + 1] + 1])
		ans--;

	cout << ans;

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}