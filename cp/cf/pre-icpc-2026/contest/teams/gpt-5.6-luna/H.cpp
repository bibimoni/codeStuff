#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int T;cin>>T; while(T--){int n,q;cin>>n>>q; vector<array<long long,3>> qs(q); vector<long long> keys;
  for(auto &z:qs){cin>>z[0]>>z[1];if(z[0]==1)cin>>z[2];keys.push_back(z[1]);}
  sort(keys.begin(),keys.end());keys.erase(unique(keys.begin(),keys.end()),keys.end());
  vector<int> bit(n+q+2); auto add=[&](int x,int v){for(;x<(int)bit.size();x+=x&-x)bit[x]+=v;};auto sum=[&](int x){int r=0;for(;x;x-=x&-x)r+=bit[x];return r;};
  unordered_map<long long,array<long long,2>> mp; set<pair<int,long long>> active; int timer=n; for(int x=1;x<=n;x++){mp[x]={0,x};active.insert({x,x});add(x,1);}
  auto rank=[&](int tm){return sum(timer+1)-sum(tm)+1;};
  for(auto z:qs){long long typ=z[0],a=z[1];auto it=mp.find(a);if(typ==1){long long b=z[2];if(it!=mp.end()){active.erase({it->second[1],a});add(it->second[1],-1);it->second[0]=b;}else{if((int)mp.size()==n){auto old=active.begin();long long key=old->second;int tm=old->first;active.erase(old);mp.erase(key);add(tm,-1);}it=mp.emplace(a,array<long long,2>{b,++timer}).first;}if(it->second[1]!=timer){it->second[1]=++timer;}active.insert({(int)it->second[1],a});add(it->second[1],1);
   }else if(it==mp.end())cout<<-1<<'\n';else{cout<<it->second[0]<<' '<<rank(it->second[1])<<'\n';active.erase({it->second[1],a});add(it->second[1],-1);it->second[1]=++timer;active.insert({(int)timer,a});add(timer,1);}
  }
 }
}
