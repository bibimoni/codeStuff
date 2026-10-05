#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
int main(int argc,char**argv){
    srand(atoi(argv[1]));
    int TRIALS=4000;
    for(int tc=0;tc<TRIALS;tc++){
        int n=1+rand()%12;
        vector<ll> a(n);
        for(auto&x:a) x=rand()%7-3; // -3..3, includes zeros/negatives
        // brute: subsets of n-1 cut positions
        ll expect=0;
        for(int mask=0;mask<(1<<max(0,n-1));mask++){
            vector<ll> sums; ll cur=0;
            for(int i=0;i<n;i++){ cur+=a[i]; if(i<n-1 && (mask>>i&1)){ sums.push_back(cur); cur=0; } }
            sums.push_back(cur);
            bool eq=all_of(sums.begin()+1,sums.end(),[&](ll v){return v==sums[0];});
            if(eq) expect=(expect+1)%MOD;
        }
        ofstream f("/tmp/j_in.txt"); f<<"1\n"<<n<<"\n"; for(auto x:a) f<<x<<" "; f<<"\n"; f.close();
        system("./j < /tmp/j_in.txt > /tmp/j_out.txt");
        ll got; { ifstream in("/tmp/j_out.txt"); in>>got; }
        if(got!=expect){ printf("MISMATCH tc=%d n=%d a=[",tc,n); for(auto x:a) printf("%lld ",x); printf("] expect=%lld got=%lld\n",expect,got); return 1; }
    }
    printf("all ok\n");
    return 0;
}
