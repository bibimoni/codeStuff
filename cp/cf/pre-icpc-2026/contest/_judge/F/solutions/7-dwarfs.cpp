/* fan cung Bui Hong Duc 20 nam */
#include <bits/stdc++.h>
using namespace std;
#define uwu "7-dwarfs"
typedef long long ll;
#define pb push_back
#define endl '\n'
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i>=b;i--)
const int N=1e2+3;
const int INF=1e9+7;

int n;
string s; int h;
vector <string> a[1002];

void input(){
	cin >> n;
	FOR(i, 1, n){
		cin >> s >> h;
		a[h].pb(s);
	}
}
void solve(void){
	int ans = -1;
	FOR(i, 1, 1000) if ((int) a[i].size() == 7) ans = i;
	//sort(a[ans].begin(), a[ans].end());
	for(string x : a[ans]) cout << x << '\n'; 
}
signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(uwu".inp", "r")){
	   freopen(uwu".inp","r",stdin);
	   freopen(uwu".out","w",stdout);
	}

	input(); solve();

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}
