#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll CAP = (ll)2e18;
const int MAXN = 300, MAXM = 300*299/2;
static ll cnt[MAXN+1][MAXM+1];
static bool init = false;
void precompute(){
    cnt[0][0]=1;
    for(int n=1;n<=MAXN;n++){
        int lim=n*(n-1)/2;
        ll win=0; bool sat=false;
        // Mahonian numbers: symmetric, strictly increasing on [0, lim/2];
        // once the exact window reaches CAP it stays >= CAP through the half: pin it.
        for(int m=0;m<=lim/2;m++){
            if(!sat){
                win += cnt[n-1][m];
                if(m-n>=0) win -= cnt[n-1][m-n];
                if(win>=CAP) sat=true;
            }
            cnt[n][m] = sat ? CAP : win;
        }
        for(int m=lim/2+1;m<=lim;m++) cnt[n][m]=cnt[n][lim-m];
    }
}
int main(){
    precompute();
    int t; scanf("%d",&t);
    while(t--){
        int n; ll m,k; scanf("%d %lld %lld",&n,&m,&k);
        if(cnt[n][m]<k){ printf("-1\n"); continue; }
        vector<int> avail(n); iota(avail.begin(),avail.end(),1);
        ll rem=m;
        vector<int> ans;
        for(int pos=0;pos<n;pos++){
            int nn=n-pos; // remaining count
            for(size_t c=0;c<avail.size();c++){
                if((ll)c>rem) break;
                ll ways = cnt[nn-1][rem-c];
                if(k>ways){ k-=ways; continue; }
                ans.push_back(avail[c]); avail.erase(avail.begin()+c); rem-=c; break;
            }
        }
        for(int i=0;i<n;i++) printf("%d%c", ans[i], i+1<n?' ':'\n');
    }
    return 0;
}
