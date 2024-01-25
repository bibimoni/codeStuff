#include <bits/stdc++.h>

#define ll long long
#define ii pair<long long, long long>
#define fi first
#define se second
#define x first
#define y second
#define MP make_pair
#define sz(x) (long long)(x.size())
#define all(x) x.begin(), x.end()
#define mmax(a, b) a = max(a, b)
#define mmin(a, b) a = min(a, b)
#define For(i,l,r) for (int i = (l); i <= (r); i++)
#define Ford(i,l,r) for (int i = (r); i >= (l); i--)

using namespace std;

const ll INF = 1e18;
const int iINF = 1e9;
const ll MOD = 1e9 + 7;//998244353

//Necessary function
ll mul(ll a, ll b){return (a%MOD)*(b%MOD)%MOD;}
ll add(ll a, ll b){return ((a+MOD)%MOD + (b+MOD)%MOD)%MOD;}
ll fpow(ll a, ll b){
    ll res=1;
    while (b){
        if (b & 1) res=mul(res,a);
        b>>=1;
        a=mul(a,a);
    }
    return res;
}
ll inv(ll a) {return fpow(a,MOD-2);}

const int N = 2e5 + 5;

int k, q;

void solve() {
    cin >> k >> q;

    bool ca = true;

    deque<int> dq1, dq2;

    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            ll x; cin >> x;

            dq2.push_back(x);

            if (dq1.size() < k) {
                if (ca) {
                    dq1.push_back(dq2.front());
                } else dq1.push_front(dq2.front());

                dq2.pop_front();
            }
        }

        if (type == 2) {
            if (!dq1.size()) {
                cout << -1 << endl;
                continue;
            }

            if (ca) {
                cout << dq1.front() << endl;
                dq1.pop_front();
                if (dq2.size()) {
                    dq1.push_back(dq2.front());
                    dq2.pop_front();
                }
            } else {
                cout << dq1.back() << endl;
                dq1.pop_back();
                if (dq2.size()) {
                    dq1.push_front(dq2.front());
                    dq2.pop_front();
                }
            }
        }

        if (type == 3) {
            if (dq1.size() == k) ca = !ca;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    //freopen("main.inp", "r", stdin);
    //freopen("main.out", "w", stdout);
    #endif

    cout << fixed << setprecision(8);
  ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}


/*
Check before submitting:
+ use fastio
+ check input output type (stdin or file)
+ Array bounds ( segmentation fault)
+ int or long long
+ reset all the variables (multiple tests)
+ is the graph connected (may have > 1 connected components)
+ reindex the string => s = "#" + s;
+ use 1ll << x, not 1 << x
+ while using board, be careful with m and n
*/
