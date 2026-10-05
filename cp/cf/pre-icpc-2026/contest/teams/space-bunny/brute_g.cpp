// brute force for G: O(n^2) segment pair check
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> d(n); for(auto&v:d) scanf("%lld",&v);
        vector<ll> x0(n),y0(n),x1(n),y1(n); ll x=0,y=0;
        for(int i=0;i<n;i++){
            ll nx=x,ny=y;
            if(i%4==0) ny=y+d[i]; else if(i%4==1) nx=x-d[i]; else if(i%4==2) ny=y-d[i]; else nx=x+d[i];
            x0[i]=x;y0[i]=y;x1[i]=nx;y1[i]=ny; x=nx;y=ny;
        }
        auto segint=[&](int i,int j)->bool{
            if(abs(i-j)<=1) return false;
            ll lx=min(x0[i],x1[i]),rx=max(x0[i],x1[i]),ly=min(y0[i],y1[i]),ry=max(y0[i],y1[i]);
            ll lx2=min(x0[j],x1[j]),rx2=max(x0[j],x1[j]),ly2=min(y0[j],y1[j]),ry2=max(y0[j],y1[j]);
            bool vertI = (x0[i]==x1[i]), vertJ = (x0[j]==x1[j]);
            if(vertI && vertJ) return (lx==lx2) && (ly<=ry2 && ly2<=ry);
            if(!vertI && !vertJ) return (ly==ly2) && (lx<=rx2 && lx2<=rx);
            if(vertI) return (lx2<=lx && lx<=rx2) && (ly<=ly2 && ly2<=ry);
            return (lx<=lx2 && lx2<=rx) && (ly2<=ly && ly<=ry2);
        };
        bool inter=false;
        for(int i=0;i<n&&!inter;i++) for(int j=i+1;j<n;j++) if(segint(i,j)){inter=true;break;}
        printf("%s\n", inter?"Yes":"No");
    }
}
