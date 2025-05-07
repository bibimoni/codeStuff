#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define endl '\n'
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MULTI int t;cin>>t;while(t--)

int nxt() {int n; cin >> n; return n;}

int constrRange(int L, int R) {
    return (R - L + 1) * (R - L + 2) / 2;
}

signed main() {
    FAST;
    int n = nxt();
    int res = 0;
    vector<int> posP(n + 1);
    vector<int> posQ(n + 1);
    for(int i = 1; i <= n; i++) posP[nxt()] = i;
    for(int i = 1; i <= n; i++) posQ[nxt()] = i;
    vector<int> minLP(n + 1); minLP[1] = posP[1];
    vector<int> maxRP(n + 1); maxRP[1] = posP[1];
    vector<int> minLQ(n + 1); minLQ[1] = posQ[1];
    vector<int> maxRQ(n + 1); maxRQ[1] = posQ[1];
    //update L, R array for P and Q
    for(int i = 2; i <= n; i++) {
        minLP[i] = min(posP[i], minLP[i - 1]);
        maxRP[i] = max(posP[i], maxRP[i - 1]);
        minLQ[i] = min(posQ[i], minLQ[i - 1]);
        maxRQ[i] = max(posQ[i], maxRQ[i - 1]);
    }
    for(int i = 1; i < n; i++) {
        int lp = minLP[i], lq = minLQ[i];
        int rp = maxRP[i], rq = maxRQ[i];
        int left = min(lp, lq), right = max(rp, rq);
        int a = min(posP[i + 1], posQ[i + 1]), b = max(posP[i + 1], posQ[i + 1]);
        int sizeLeft = 0, sizeRight = 0;
        // -- a -- b (-- L) -- (R --)
        if(b < left) {
            sizeLeft = left - b;
            sizeRight = n + 1 - right;
        }
        // (-- L) -- (R --) a -- b --
        else if(a > right) {
            sizeLeft = left;
            sizeRight = a - right;
        }
        // -- a (-- L) -- (R --) b --
        else if(a < left && b > right) {
            sizeLeft = left - a;
            sizeRight = b - right;
        }
        res += sizeLeft * sizeRight;
    }
    res += min(posP[1], posQ[1]) * (min(posP[1], posQ[1]) - 1) / 2;
    res += (n - max(posP[1], posQ[1])) * (n - max(posP[1], posQ[1]) + 1) / 2;
    res += abs(posP[1] - posQ[1]) * (abs(posP[1] - posQ[1]) - 1) / 2;
    res++;
    cout << res;
}

