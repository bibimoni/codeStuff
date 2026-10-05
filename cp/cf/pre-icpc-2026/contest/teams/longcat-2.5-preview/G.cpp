#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Seg {
    ll x1, y1, x2, y2;
    bool vert() const { return x1 == x2; }
};
static bool intersect(const Seg& a, const Seg& b){
    if(a.vert() && !b.vert()){
        ll ymin = min(a.y1, a.y2), ymax = max(a.y1, a.y2);
        ll xmin = min(b.x1, b.x2), xmax = max(b.x1, b.x2);
        return b.y1 >= ymin && b.y1 <= ymax && a.x1 >= xmin && a.x1 <= xmax;
    }
    if(!a.vert() && b.vert()){
        ll xmin = min(a.x1, a.x2), xmax = max(a.x1, a.x2);
        ll ymin = min(b.y1, b.y2), ymax = max(b.y1, b.y2);
        return b.x1 >= xmin && b.x1 <= xmax && a.y1 >= ymin && a.y1 <= ymax;
    }
    if(a.vert()){
        if(a.x1 != b.x1) return false;
        ll a1 = min(a.y1,a.y2), a2 = max(a.y1,a.y2);
        ll b1 = min(b.y1,b.y2), b2 = max(b.y1,b.y2);
        return max(a1,b1) <= min(a2,b2);
    }
    if(a.y1 != b.y1) return false;
    ll a1 = min(a.x1,a.x2), a2 = max(a.x1,a.x2);
    ll b1 = min(b.x1,b.x2), b2 = max(b.x1,b.x2);
    return max(a1,b1) <= min(a2,b2);
}
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<Seg> s(n);
        ll x = 0, y = 0;
        for(int i=0;i<n;i++){
            ll d; scanf("%lld",&d);
            ll nx = x, ny = y;
            int dir = i % 4;
            if(dir==0) ny += d;
            else if(dir==1) nx -= d;
            else if(dir==2) ny -= d;
            else nx += d;
            s[i] = {x, y, nx, ny};
            x = nx; y = ny;
        }
        bool cross = false;
        for(int i=0;i<n && !cross;i++){
            for(int j=i-3;j>=0 && j>=i-5; j--){
                if(intersect(s[i], s[j])){ cross = true; break; }
            }
        }
        printf(cross ? "Yes\n" : "No\n");
    }
}
