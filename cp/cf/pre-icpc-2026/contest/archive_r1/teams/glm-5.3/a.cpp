#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    if(!(cin >> n)) return 0;
    vector<int> p(n);
    for(auto &x : p) cin >> x;
    vector<int> pos(n+2, -1);
    bool ok = (n >= 1);
    for(int i=0;i<n;i++){
        if(p[i] < 1 || p[i] > n || pos[p[i]] != -1) ok = false;
        else pos[p[i]] = i+1;
    }
    if(!ok){ cout << -1 << "\n"; return 0; }
    int forced = 0;
    for(int i=1;i<n;i++){
        int a = p[i-1], b = p[i];
        bool f;
        if(b == n) f = true;
        else if(a == n) f = false;
        else f = (pos[a+1] > pos[b+1]);
        if(f) forced++;
    }
    cout << forced + 1 << "\n";
    return 0;
}
