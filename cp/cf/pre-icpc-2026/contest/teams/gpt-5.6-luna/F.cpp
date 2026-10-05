#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int n; cin>>n; map<int,vector<string>> g; vector<pair<string,int>> a(n);
 for(auto &[s,h]:a){cin>>s>>h;g[h].push_back(s);}
 for(auto &[h,v]:g) if(v.size()==7) for(string &s:v) cout<<s<<'\n';
}
