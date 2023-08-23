/**
 * File              : anbuffet.cpp
 * Author            : distiled
 * Date              : 24.05.2023
 * Last Modified Date: 24.05.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int n, maxWeight, minWeight, v[33], w[33], w_min[33], w_max[33], suffix_value[33]; 
int res = 0;

void Try(int i, int currWeight, int currValue) {
	if(currWeight > maxWeight) return;
	if(currWeight <= maxWeight and currWeight >= minWeight) {
		res = max(res, currValue);
	}
	if(i == n) {
		if(currWeight <= maxWeight and currWeight >= minWeight) {
			currValue = max(res, currValue);
		}
		return;
	}
	if(i < n && suffix_value[i] + currValue < res) {
		return;
	}
	if(i < n && currWeight + w_max[i] * (n - i) < minWeight) {
		return;
	}
	if(i < n && currWeight + w_min[i] > maxWeight) {
		return;
	}
	Try(i + 1, currWeight, currValue);
	Try(i + 1, currWeight + w[i], currValue + v[i]);
}

signed main() {
    FAST;
    cin >> n >> minWeight >> maxWeight;
    for(int i = 0; i < n; i++) {
    	cin >> w[i] >> v[i];
    }
    w_min[n - 1] = w[n - 1];
    w_max[n - 1] = w[n - 1];
    suffix_value[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--) {
    	suffix_value[i] = suffix_value[i + 1] + v[i];
    	w_min[i] = min(w_min[i + 1], w[i]);
    	w_max[i] = max(w_max[i + 1], w[i]);
    }
    Try(0, 0, 0);
    cout << res;
}
    
