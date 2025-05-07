/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 18.05.2023
 * Last Modified Date: 18.08.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include </home/distiled/templates/debug.h>
#else
#define dbg(x...)
#endif

#define int           long long
#define all(x)        x.begin(), x.end()
#define rall(x)       x.rbegin(), x.rend()
#define sz(x)         (int) x.size()
#define __lcm(a, b)   (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES           cout << "YES\n";
#define NO            cout << "NO\n";
#define mod           1000000007
#define endl          '\n'
#define TLE           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI         int t;cin>>t;while(t--)
#define INF           (int) 1e18
#define MAXN          (int) 1e6 + 5

int nxt() {int n; cin >> n; return n;}
int st[MAXN<<2],a[MAXN],ans[MAXN],l,r,q,n;
void update(int node,int l,int r,int pos,int val){
    if (l==r){
        st[node] = val;
        return;
    }
    int mid = (l+r)>>1;
    if (pos<=mid) update(node<<1,l,mid,pos,val);
    else update(node<<1|1,mid+1,r,pos,val);
    st[node] = min(st[node<<1],st[node<<1|1]);
}
int get(int node,int l,int r,int u,int v){
    if (l==r) return l;
    int mid = (l+r)>>1;
    if (st[node]>=u) return -1;
    if (st[node<<1] < u) return get(node<<1,l,mid,u,v);
    else return get(node<<1|1,mid+1,r,u,v);
}
vector<pair<int, int>> ending[MAXN];
signed main()
{
    TLE;
    //freopen(TASKNAME".inp","r",stdin);
    //freopen(TASKNAME".out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        ending[r].pb({i,l});
    }
    for(int i=1;i<=n;i++){
        update(1,1,n+1,a[i],i);
        for(auto x: ending[i]){
            ans[x.first] = get(1,1,n+1,x.second,i);
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
}

