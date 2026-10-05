#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){long long n,x=1;cin>>n;bool first;while(true){x*=9;if(n<=x){first=true;break;}x*=2;if(n<=x){first=false;break;}}cout<<(first?"La premiere joueuse gagne.\n":"La deuxieme joueuse gagne.\n");}}
