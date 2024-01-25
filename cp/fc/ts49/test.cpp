/**
 * File              : test.cpp
 * Author            : distiled
 * Date              : 06.05.2023
 * Last Modified Date: 06.05.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);  cout.tie(nullptr)
#define endl '\n'

signed main()
{
    fast; 
    int n ;
    cin >> n;
    int d = 0;
    cin >> d;
    int x; cin >> x;
    d = x - d;
    for(int i = 1; i <= n - 2; i ++){
        int y;cin >> y;
        if(x + d != y){
            cout << "NO";
            return 0;
        }
        x = y;
    }
    cout << "YES";
    
}
