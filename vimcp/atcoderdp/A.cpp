/**
 * File              : A.cpp
 * Author            : distiled
 * Date              : 17.08.2023
 * Last Modified Date: 17.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxN (long long) 1e6 + 5
#define mod 1000000007
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, dp[maxN] = {0}, h[maxN];

signed main() {
    fast
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    dp[1] = 0; dp[2] = abs(h[1] - h[2]);
    for(int i = 3; i <= n; i++) {
        dp[i] = min({dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2])});
    }
    cout << dp[n];

    
}

