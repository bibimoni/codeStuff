#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;if(!(cin>>T))return 0;while(T--){int h=0,r;while(true){cout<<"? L\n"<<flush;cin>>r;if(!r)break;h++;}for(int i=0;i<h;i++){cout<<"? B\n"<<flush;cin>>r;}
 auto exists=[&](ll j){int moved=0;for(int b=h-1;b>=0;b--){char c=(((j-1)>>b)&1)?'R':'L';cout<<"? "<<c<<'\n'<<flush;cin>>r;if(!r){for(int z=0;z<moved;z++){cout<<"? B\n"<<flush;cin>>r;}return false;}moved++;}for(int z=0;z<moved;z++){cout<<"? B\n"<<flush;cin>>r;}return true;};
 ll lo=1,hi=1LL<<h;while(lo<hi){ll mid=(lo+hi+1)/2;if(exists(mid))lo=mid;else hi=mid-1;}ll ans=(1LL<<h)-1+lo;cout<<"! "<<ans<<'\n'<<flush;
 }
}
