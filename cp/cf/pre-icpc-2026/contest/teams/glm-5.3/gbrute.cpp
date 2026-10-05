#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> d(n);
        for(auto &x:d) scanf("%lld",&x);
        vector<ll> x1(n),y1(n),x2(n),y2(n);
        vector<int> typ(n);
        ll px=0,py=0;
        static const int dx[4]={0,-1,0,1}, dy[4]={1,0,-1,0};
        for(int i=0;i<n;i++){
            int dir=i%4;
            ll nx=px+dx[dir]*d[i], ny=py+dy[dir]*d[i];
            x1[i]=min(px,nx); x2[i]=max(px,nx);
            y1[i]=min(py,ny); y2[i]=max(py,ny);
            typ[i]=(dir%2==0)?1:0;
            px=nx; py=ny;
        }
        auto inter=[&](int i,int j)->bool{
            // closed axis-aligned segments intersect?
            if(typ[i]==typ[j]) return false; // perpendicular only in brute
            int h = typ[i]==0 ? i : j;
            int v = typ[i]==0 ? j : i;
            return max(x1[h],x1[v]) <= min(x2[h],x2[v]) && max(y1[h],y1[v]) <= min(y2[h],y2[v]);
        };
        // general pair intersect incl. parallel overlap:
        auto interAny=[&](int i,int j)->bool{
            if(typ[i]!=typ[j]) return inter(i,j);
            if(typ[i]==0){ // both horizontal
                if(y1[i]!=y1[j]) return false;
                return max(x1[i],x1[j]) <= min(x2[i],x2[j]);
            } else {
                if(x1[i]!=x1[j]) return false;
                return max(y1[i],y1[j]) <= min(y2[i],y2[j]);
            }
        };
        bool yes=false;
        for(int i=0;i<n && !yes;i++)
            for(int j=i+1;j<n;j++){
                if(j==i+1) continue; // adjacent pairs excluded
                if(interAny(i,j)){ yes=true; break; }
            }
        puts(yes?"Yes":"No");
    }
}
