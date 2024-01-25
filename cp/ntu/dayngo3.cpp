#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[100005], pre[100005];

ll cur[100005];

pair<ll,ll> bit[100005];

pair<ll,ll> b[100005];

void update(ll i,ll n,ll v){
    while (i <= n){
        bit[i].first += v;
        bit[i].second += 1;
        i += (i & (-i));
    }
}
pair<ll,ll> get(ll i){
    pair<ll,ll> res = {0LL,0LL};
    while (i > 0){
        res.first += bit[i].first;
        res.second += bit[i].second;
        i -= (i & (-i));
    }
    return res;
}
int main(){
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0;i < s.size();++i){
        if (s[i] == '('){a[i + 1] = 1;}
        else{a[i + 1] = -1;}
    }
    for (int i = 1;i <= n;++i){
        pre[i] = pre[i - 1] + a[i];
        b[i] = {pre[i],i};
        cur[i] = pre[i];
    }
    sort(b + 1,b + 1 + n);
    for (int i = 1;i <= n;++i){
        pre[b[i].second] = i;
    }

    ll ans = 0;
    for (int i = 1;i <= n;++i){
         pair<ll,ll> p = get(pre[i]);
         ans += p.second * cur[i] - p.first;
         if (cur[i] > 0){ans += cur[i];}
         update(pre[i],n,cur[i]);
    }
    cout << ans;

}
