#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        long long n; cin>>n;
        while(n>18) n=(n+17)/18;
        if(n<=9) cout<<"La premiere joueuse gagne.\n";
        else cout<<"La deuxieme joueuse gagne.\n";
    }
    return 0;
}
