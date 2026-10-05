#include <bits/stdc++.h>
using namespace std;
int main(int argc, char**argv){
    // read n and p, brute force over strings
    int n; scanf("%d",&n);
    vector<int> p(n);
    for(auto &x:p){ scanf("%d",&x); x--; }
    auto brute=[&]()->int{
        for(int K=1;K<=n;K++){
            long long tot=1; for(int i=0;i<n;i++) tot*=K; if(tot>8'000'000) return -2;
            for(long long mask=0; mask<tot; mask++){
                vector<int> s(n); long long mm=mask;
                for(int i=0;i<n;i++){ s[i]=mm%K; mm/=K; }
                // ensure all K used
                vector<int> seen(K,0); for(int x:s) seen[x]=1;
                bool allK=true; for(int x:seen) if(!x) allK=false;
                if(!allK) continue;
                vector<int> idx(n); iota(idx.begin(),idx.end(),0);
                vector<string> suf(n);
                string str(n,' ');
                for(int i=0;i<n;i++) str[i]='a'+s[i];
                for(int i=0;i<n;i++) suf[i]=str.substr(i);
                sort(idx.begin(), idx.end(), [&](int x,int y){return suf[x]<suf[y];});
                bool ok=true;
                for(int i=0;i<n;i++) if(idx[i]!=p[i]){ok=false;break;}
                if(ok) return K;
            }
        }
        return -1;
    };
    printf("%d\n", brute());
    return (void)argc, 0;
}
