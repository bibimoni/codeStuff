/**
 * File              : pair.cpp
 * Author            : distiled
 * Date              : 14.07.2023
 * Last Modified Date: 14.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

/*
 7 1
 9 1 2 4 5 6 8
 1 2 4 5 6 8 9
*/
int nxt() {int n; cin >> n; return n;}
int n, d; 
int res = 1;
//for debuging
vector<pair<int, int>> db1;

void solve(int S, vector<int> a) {
    /*
    DEBUG
     */
    vector<pair<int, int>> db;
    //cout << "current Sum: " << S << endl;
    map<int, vector<int>> f; 
    vector<bool> visited(n, false);
    int cnt = 0; 
    for(int i = 0; i < n; i++) {
        //check if (S + 1 - a[i]) is in the set and a[i] haven't been found
       if(
          d != 0 
        && f[S + 1 - a[i]].size()
        && !visited[i]
        && !visited[f[S + 1 - a[i]].back()]
         ) {
            cnt++;
            visited[f[S + 1 - a[i]].back()] = true;
            f[S + 1 - a[i]].pop_back();
            visited[i] = true;
            //debug
            //db.push_back({a[i], S + 1 - a[i]});
            //cout << "{" << a[i] << ", " << S + 1 - a[i] << "}" << endl;
        }
        if(
          f[S - a[i]].size()
        && !visited[i]
        && !visited[f[S - a[i]].back()] 
          ) {
            cnt++;
            visited[f[S - a[i]].back()] = true; 
            f[S - a[i]].pop_back();
            visited[i] = true;
            //debug
            //db.push_back({a[i], S - a[i]}); 
            //cout << "{" << a[i] << ", " << S - a[i] << "}" << endl;
        }
        f[a[i]].push_back(i);
    }

    //debug
    /*
    if(res < cnt) {
        db1 = db;
    } 
    cout << "cnt is: " << cnt << endl;
    */
    //update the result
    res = max(res, cnt);
}

signed main() {
    FAST;
    freopen("PAIR.INP", "r", stdin);
    freopen("PAIR.OUT", "w", stdout);

    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    //ai + aj = [S, S + 1]
    sort(a.begin(), a.end());
    
    set<int> S;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {            
            if(S.find(a[i] + a[j]) == S.end()) solve(a[i] + a[j], a);
        }
    }
    cout << res;
    //debug
    /*
    cout << endl;
    for(auto &i : db1) {
        cout << "{" << i.first << ", " << i.second << "}" << endl;
    }
    */
}

