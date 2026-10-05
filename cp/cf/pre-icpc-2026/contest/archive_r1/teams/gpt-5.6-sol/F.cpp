#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int n;if(!(cin>>n))return 0;vector<string>s(n);vector<int>h(n);int c[1001]={};for(int i=0;i<n;i++){cin>>s[i]>>h[i];c[h[i]]++;}int want=0;for(int x=1;x<=1000;x++)if(c[x]==7)want=x;for(int i=0;i<n;i++)if(h[i]==want)cout<<s[i]<<'\n';}
