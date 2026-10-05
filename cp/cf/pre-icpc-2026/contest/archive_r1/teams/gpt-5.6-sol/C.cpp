#include <bits/stdc++.h>
using namespace std;
int ask(char c){cout<<"? "<<c<<endl;int x;if(!(cin>>x)||x<0)exit(0);return x;}
int main(){int T;cin>>T;while(T--){int h=0;while(ask('L'))h++;for(int i=0;i<h;i++)ask('B');if(h==0){cout<<"! 1"<<endl;continue;}auto exists=[&](unsigned long long off){int moved=0;bool ok=true;for(int i=h-1;i>=0;i--){if(!ask((off>>i&1)?'R':'L')){ok=false;break;}moved++;}while(moved--)ask('B');return ok;};unsigned long long lo=0,hi=(1ULL<<h)-1;while(lo<hi){auto mid=lo+(hi-lo+1)/2;if(exists(mid))lo=mid;else hi=mid-1;}unsigned long long n=(1ULL<<h)-1+lo+1;cout<<"! "<<n<<endl;}}
