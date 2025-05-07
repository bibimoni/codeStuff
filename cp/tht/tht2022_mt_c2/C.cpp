/**
 * File              : C.cpp
 * Author            : distiled
 * Date              : 29.05.2023
 * Last Modified Date: 29.05.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
 
using namespace std;
 
int w;
long long dot[5000005],sx[5000005];
long long sum[5000005];
long long res;
 
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        res = LLONG_MAX;
        string s;
        cin >> s;
        cin >> w;
        if (w==0) {cout << 0 << '\n'; continue;}
        dot[-1] = 0;
        sx[-1] = 0;
        for (int i = 0; i < s.length(); i++)
       {
            if (s[i]=='.') {dot[i] = dot[i-1] + 1; sx[i] = sx[i-1];}     //dot[i] la so dau . trong khoang [1...i]
            else {dot[i] = dot[i-1]; sx[i] = sx[i-1] + 1;} //sx[i] la so dau X trong khoan [1...i] 
        }
        sum[-1] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]=='.') sum[i] = sum[i-1];
            else sum[i] = sum[i-1] + dot[i];
        }
        if (w==1&&dot[0]==1)  {cout << 0 << '\n'; continue;}
        for (int i = 1; i < s.length();i++)
        {
            if (dot[i] < w) continue;
            long long t;
            int j = upper_bound(dot,dot+i,dot[i]-w) - dot;
            int v = upper_bound(dot+j,dot+i+1,(dot[i]+dot[j-1])/2) - dot-1;
            t = dot[i]*(sx[i]-sx[v]) - (sum[i] - sum[v]) + (sum[v] - sum[j-1]) - dot[j-1]*(sx[v]-sx[j-1]);
            res=min(res,t);
        }
        cout << res << '\n'; 
    }
}
