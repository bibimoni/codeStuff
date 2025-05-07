#include<bits/stdc++.h>

using namespace std;

long long safe_pow(long long a,long long b){
  long long res=1;
  for(long long i=0;i<b;i++){
    double dres=res;
    dres*=a;
    if(dres>2e18){return 2e18;}
    res*=a;
  }
  return res;
}

long long sqrt_floor(long long x){
  long long l=0,r=2e9;
  while(l<=r){
    long long t=(l+r)/2;
    if(t*t>x){r=t-1;}
    else{l=t+1;}
  }
  return r;
}

int main(){
  long long n;
  cin >> n;
  set<long long> st;
  for(long long b=3;b<60;b++){
    for(long long a=2;;a++){
      long long x=safe_pow(a,b);
      if(x>n){break;}
      long long s=sqrt_floor(x);
      if(s*s!=x){st.insert(x);}
    }
  }
  long long res=st.size();
  res+=sqrt_floor(n);
  cout << res << "\n";
  return 0;
}
