#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d",&n);
    vector<string> names(n); vector<int> h(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){ char buf[16]; scanf("%s %d",buf,&h[i]); names[i]=buf; cnt[h[i]]++; }
    int dh=-1;
    for(auto&kv:cnt) if(kv.second==7){ dh=kv.first; break; }
    for(int i=0;i<n;i++) if(h[i]==dh) printf("%s\n", names[i].c_str());
    return 0;
}
