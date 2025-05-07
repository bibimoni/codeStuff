// time-limit: 3000
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif
#define int            long long
vector<pair<int, int>> ans;
int l, r;
int cnt;
void Try (int lt, int rt) {
	// dbg(cnt);
	if(lt >= rt || cnt >= r - l + 1) {
		return;
	}
	if(lt + 1 == rt) {
		cnt += 2;
		ans.push_back({lt, rt});
		return;
	}
	int i = 0;
	while(rt - lt + 1 >= (1ll << (i + 1))) {
		int j = lt / (1ll << (i + 1)) + (lt % (1ll << (i + 1)) != 0);
		if((1ll << (i + 1)) * j >= lt && (1ll << (i + 1)) * (j + 1) <= rt) {
			i++;
		}
		else {
			break;
		}
	}
	// dbg(lt, rt);
	int j = lt / (1ll << i) + (lt % (1ll << i) != 0);
	ans.push_back({(1ll << i) * j, (1ll << i) * (j + 1)});
	cnt += (1ll << i);
	Try(lt, ((1ll << i) * j));
	Try((1ll << i) * (j + 1), rt);
};
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  cin >> l >> r;
  cnt = 0;
 	Try(l, r);
 	cout << ans.size() << '\n';
 	sort(ans.begin(), ans.end());
 	for(auto [f, s] : ans) {
 		cout << f << ' ' << s << '\n';
 	}
}


