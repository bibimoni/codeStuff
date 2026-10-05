#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
int n;
vector<vector<array<int,3>>> adj;
vector<int> fact, invfact;

ll C(int n, int k){
    if(k<0||k>n) return 0;
    return (ll)fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

vector<int> dfs(int u, int p){
    vector<int> f = {0, 1};
    int sz = 1;
    for(auto& e : adj[u]){
        int v = e[0], w = e[1], first = e[2];
        if(v == p) continue;
        vector<int> fc = dfs(v, u);
        int szc = (int)fc.size() - 1;
        int type;
        if(w == 0) type = 0;
        else if(first) type = (w == 1) ? 1 : 2;
        else type = (w == 1) ? 2 : 1;
        vector<int> W(szc+1);
        if(type == 0){
            int LC = 0;
            for(int s=1;s<=szc;s++) LC = (LC + fc[s]) % MOD;
            for(int k=0;k<=szc;k++) W[k] = LC;
        } else if(type == 1){
            vector<int> SC(szc+2, 0);
            for(int s=szc;s>=1;s--) SC[s] = (SC[s+1] + fc[s]) % MOD;
            for(int k=0;k<=szc;k++) W[k] = SC[k+1];
        } else {
            int pref = 0;
            for(int k=0;k<=szc;k++){
                if(k >= 1) pref = (pref + fc[k]) % MOD;
                W[k] = pref;
            }
        }
        vector<int> nf(sz + szc + 1, 0);
        for(int r=1;r<=sz;r++){
            if(!f[r]) continue;
            for(int k=0;k<=szc;k++){
                if(!W[k]) continue;
                int i = r + k;
                ll ways = (ll)f[r]*W[k]%MOD * C(r+k-1, k)%MOD * C(sz - r + szc - k, szc - k) % MOD;
                nf[i] = (nf[i] + ways) % MOD;
            }
        }
        f = move(nf);
        sz += szc;
    }
    return f;
}

int main(){
    scanf("%d",&n);
    adj.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back({v,w,1});
        adj[v].push_back({u,w,0});
    }
    fact.resize(n+1);
    invfact.resize(n+1);
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=(ll)fact[i-1]*i%MOD;
    auto powmod=[](ll a,ll e){ll r=1;while(e){if(e&1)r=r*a%MOD;a=a*a%MOD;e>>=1;}return r;};
    invfact[n]=powmod(fact[n], MOD-2);
    for(int i=n-1;i>=0;i--) invfact[i]=(ll)invfact[i+1]*(i+1)%MOD;
    vector<int> f = dfs(1, 0);
    int ans = 0;
    for(int r=1;r<(int)f.size();r++) ans = (ans + f[r]) % MOD;
    printf("%d\n", ans);
}
