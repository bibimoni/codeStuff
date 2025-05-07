#include <bits/stdc++.h>

using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll randint(ll l, ll r) {
    return uniform_int_distribution<ll> (l,r) (rng);
}

signed main(signed argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << 1 << endl;
    
    int n = randint(1,10);
    for (int i = 0; i < n; i++) {
        cout << char(randint(0,25) + 'a');
    }
    cout << endl;
    cout << randint(1,10);

    // generate test cases with same format as given in problem

    return 0;
}