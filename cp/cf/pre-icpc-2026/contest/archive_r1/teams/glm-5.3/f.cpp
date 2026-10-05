#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; 
    if(scanf("%d", &n) != 1) return 0;
    static char names[105][16];
    static int h[105];
    static int cnt[1001];
    for(int i = 0; i < n; i++){ scanf("%s %d", names[i], &h[i]); cnt[h[i]]++; }
    int H = 0;
    for(int v = 1; v <= 1000; v++) if(cnt[v] == 7) H = v;
    string out;
    for(int i = 0; i < n; i++) if(h[i] == H){ out += names[i]; out += '\n'; }
    fputs(out.c_str(), stdout);
    return 0;
}
