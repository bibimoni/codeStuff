#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

void sol() {
    ll n, k;
    cin >> n >> k;
    multiset<ll>st;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        auto xx = st.find(x);
        if(xx == st.end())
            st.insert(x);
        else {
            st.erase(xx);
        }
    }
    dbg(st);
    unordered_map<ll, vector<ll>>mp;
    for(auto it = st.begin(); it != st.end(); it++) {
        mp[(*it)%k].push_back(*it);
    }
    ll nums = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if((*it).second.size()%2 == 1) {
            nums++;
        }
        if(nums > 1) {
            cout << -1;
            return;
        }
        sort((*it).second.begin(),(*it).second.end());
    }

    ll res = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if((*it).second.size()%2 == 0) {

            for(int i = 0; i < (*it).second.size()-1; i+=2) {
                res += ((*it).second[i+1]-(*it).second[i])/k;
            }

        }
        else {
            ll tem1 = 0;
            for(int j = 1; j < (*it).second.size(); j+=2) {
                tem1 += ((*it).second[j+1]-(*it).second[j])/k;
            }
            ll tem = tem1;
            for(int j = 1; j < (*it).second.size(); j+=1) {
                if(j%2 == 0) {
                    tem1 -= ((*it).second[j]-(*it).second[j-1])/k;
                }
                else {
                    tem1 += ((*it).second[j]-(*it).second[j-1])/k;
                }
                tem = min(tem,tem1);
            }
            res += tem;
        }
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        sol();
        cout << endl;
    }
}
