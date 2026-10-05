#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<int> p(n);
    for(auto &x:p){ scanf("%d",&x); x--; }
    vector<int> r(n);
    for(int i=0;i<n;i++) r[p[i]]=i;
    vector<int> c(n);
    int cur=1; c[p[0]]=1;
    for(int i=1;i<n;i++){
        int a=p[i-1], b=p[i];
        bool strict;
        if(b==n-1) strict=true;
        else if(a==n-1) strict=false;
        else strict = (r[a+1] > r[b+1]);
        if(strict) ++cur;
        c[b]=cur;
    }
    // verify
    string s(n,' ');
    for(int i=0;i<n;i++) s[i]=(char)(unsigned char)('a'+c[i]-1);
    vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
    vector<string> suf(n);
    for(int i=0;i<n;i++) suf[i]=s.substr(i);
    sort(idx.begin(), idx.end(), [&](int x,int y){return suf[x]<suf[y];});
    bool ok=true;
    for(int i=0;i<n;i++) if(idx[i]!=p[i]){ ok=false; break; }
    printf("%d\n", ok?cur:-1);
    return 0;
}
