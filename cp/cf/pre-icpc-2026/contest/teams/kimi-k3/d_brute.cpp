#include <bits/stdc++.h>
using namespace std;
// f(n): player to move with product p< n needs to reach >=n; n>=2 real game.
// f(n) = exists k in 2..9 such that ceil(n/k) is losing (or <=1 => immediate win)
map<long long,bool> memo;
bool f(long long n){
    if(n<=9) return true; // can multiply by n..9 to exceed
    auto it=memo.find(n); if(it!=memo.end()) return it->second;
    bool win=false;
    for(int k=2;k<=9;k++){ long long m=(n+k-1)/k; if(!f(m)){win=true;break;} }
    return memo[n]=win;
}
int main(){
    for(long long n=2;n<=200000;n++){
        bool b=f(n);
        long long x=n; while(x>18) x=(x+17)/18;
        bool formula=(x<=9);
        if(b!=formula){ printf("MISMATCH n=%lld brute=%d formula=%d\n",n,b,formula); return 1; }
    }
    printf("all ok up to 200000\n");
    return 0;
}
