// brute force for M: enumerate permutations, group by inversion count
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; long long m,k; cin>>n>>m>>k;
        vector<vector<long long>> cls(n*(n-1)/2+1);
        vector<int> p(n); iota(p.begin(),p.end(),1);
        do {
            int inv=0; for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(p[i]>p[j]) inv++;
            cls[inv].push_back(0);
        } while(next_permutation(p.begin(),p.end()));
        // regenerate in lex order and count occurrences
        vector<long long> cnt(n*(n-1)/2+1,0);
        iota(p.begin(),p.end(),1);
        do { int inv=0; for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(p[i]>p[j]) inv++; cnt[inv]++; } while(next_permutation(p.begin(),p.end()));
        if(m>=cnt.size()||cnt[m]<k){ cout<<-1<<"\n"; continue; }
        long long r=k; iota(p.begin(),p.end(),1);
        do { int inv=0; for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(p[i]>p[j]) inv++;
            if(inv==m){ if(--r==0){ for(int i=0;i<n;i++) cout<<p[i]<<(i+1==n?'\n':' '); break; } }
        } while(next_permutation(p.begin(),p.end()));
    }
}
