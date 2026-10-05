#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
 int T; cin>>T; while(T--){ long long n; cin>>n; bool first=n!=1;
  for(long long l=10;l<=n;l=18*l-17) if(n>=l&&n<=2*l-2) first=false;
  cout<<(first?"La premiere joueuse gagne.":"La deuxieme joueuse gagne.")<<'\n';
 }
}
