#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

#define double long double
#define ll long long

const ll N = 3e5 + 5;
const ll INF = 1e18;

ll n;
int p;
ll a[N];

const double EPS = 1e-15;

bool good(double x) {
    double sum = 0;
    double mmin = (double)INF;

    ll l, r;

    for (int i = 1; i <= p - 1; i++) {
        //mmin = min(mmin, sum - ((double)(i) - 1)*x);
        double tt = sum - ((double)i - 1) * x;
        if (mmin > tt) {
            mmin = tt;
            l = i;
        }
        sum += a[i];
    }

    sum = 0;
    for (int i = 1; i <= p; i++) sum += a[i];

    for (int i = p + 1; i <= n; i++) {
        sum += a[i];
        double tt = sum -(x * (double)(i)) - mmin;
        if (tt >= 0 || abs(tt) <= EPS) {
            r = i;
//            cerr << l << " " << r << endl;
            return true;
        }
    }

    return false;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 2; i <= n - 1; i++) {
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            p = i;
            break;
        }
    }

//    cerr << p << endl;

    double res = -1;
    double l = 1, r = max(a[1], a[n]);
    int L = 100;
      while (L-- && r >= l && abs(r - l) > EPS) {
          double mid = (l + r) / 2;
          // dbg(mid);
          if (good(mid)) {
              res = mid;
              l = mid + EPS;
          } else r = mid - EPS;
      }

    cout << fixed << setprecision(12) << res << endl;

//    cout << good(1);
}

int main() {
   //  freopen("input.txt", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
