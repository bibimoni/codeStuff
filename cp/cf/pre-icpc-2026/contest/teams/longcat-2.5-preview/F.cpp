#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<pair<string,int>> v(n);
    map<int,int> cnt;
    for(auto&[s,h]:v){ char buf[16]; scanf("%15s",buf); scanf("%d",&h); s=buf; cnt[h]++; }
    int dh=-1;
    for(auto&[h,c]:cnt) if(c==7) dh=h;
    for(auto&[s,h]:v) if(h==dh) printf("%s\n", s.c_str());
}
