#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    static char nm[105][16];
    static int hh[105];
    static int cnt[1001];
    for(int i=0;i<n;i++){ scanf("%15s %d", nm[i], &hh[i]); cnt[hh[i]]++; }
    int H=0; for(int i=1;i<=1000;i++) if(cnt[i]==7) H=i;
    for(int i=0;i<n;i++) if(hh[i]==H) printf("%s\n", nm[i]);
    return 0;
}
