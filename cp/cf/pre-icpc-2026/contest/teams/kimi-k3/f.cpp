#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<pair<string,int>> v(n);
    int cnt[1001]={0};
    for(auto&p:v){ char s[16]; int h; scanf("%15s %d",s,&h); p={s,h}; cnt[h]++; }
    int target=-1;
    for(int h=1;h<=1000;h++) if(cnt[h]==7){ target=h; break; }
    for(auto&p:v) if(p.second==target) printf("%s\n",p.first.c_str());
    return 0;
}
