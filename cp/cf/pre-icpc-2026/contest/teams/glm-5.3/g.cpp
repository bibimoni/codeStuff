#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<ll> d(n);
        for(auto &x:d) scanf("%lld",&x);
        // build segments
        vector<ll> x1(n), y1(n), x2(n), y2(n), xcur(3), ycur(3);
        vector<int> typ(n); // 0 = horizontal, 1 = vertical
        ll px=0, py=0;
        static const int dx[4]={0,-1,0,1}, dy[4]={1,0,-1,0}; // N W S E
        for(int i=0;i<n;i++){
            int dir=i%4;
            ll nx=px+dx[dir]*d[i], ny=py+dy[dir]*d[i];
            x1[i]=min(px,nx); x2[i]=max(px,nx);
            y1[i]=min(py,ny); y2[i]=max(py,ny);
            typ[i]= (dir%2==0)?1:0; // N,S vertical; W,E horizontal
            px=nx; py=ny;
        }
        const char *ANS=nullptr;
        // H x H
        {
            vector<array<ll,3>> hs; // y, xlo, xhi
            for(int i=0;i<n;i++) if(typ[i]==0) hs.push_back({y1[i], x1[i], x2[i]});
            sort(hs.begin(), hs.end());
            for(size_t i=1;i<hs.size();i++)
                if(hs[i][0]==hs[i-1][0] && hs[i][1] <= hs[i-1][2]){ ANS="Yes"; break; }
        }
        // V x V
        if(!ANS){
            vector<array<ll,3>> vs;
            for(int i=0;i<n;i++) if(typ[i]==1) vs.push_back({x1[i], y1[i], y2[i]});
            sort(vs.begin(), vs.end());
            for(size_t i=1;i<vs.size();i++)
                if(vs[i][0]==vs[i-1][0] && vs[i][1] <= vs[i-1][2]){ ANS="Yes"; break; }
        }
        // H x V sweep
        if(!ANS){
            // events: (x, kind, payload) kind: 0=enter H, 1=query V, 2=exit H
            struct Ev{ ll x; int kind; int id; };
            vector<Ev> evs;
            for(int i=0;i<n;i++){
                if(typ[i]==0){
                    evs.push_back({x1[i],0,i});
                    evs.push_back({x2[i],2,i});
                } else {
                    evs.push_back({x1[i],1,i});
                }
            }
            sort(evs.begin(), evs.end(), [](const Ev&a, const Ev&b){
                if(a.x!=b.x) return a.x<b.x;
                if(a.kind!=b.kind) return a.kind<b.kind;
                return a.id<b.id;
            });
            set<pair<ll,int>> act; // (y, id) of active H
            for(auto &e: evs){
                if(e.kind==0) act.insert({y1[e.id], e.id});
                else if(e.kind==2) act.erase({y1[e.id], e.id});
                else {
                    int vid=e.id;
                    ll ylo=y1[vid], yhi=y2[vid];
                    auto it=act.lower_bound({ylo, INT_MIN});
                    while(it!=act.end() && it->first<=yhi){
                        int hid=it->second;
                        if(abs(hid-vid)==1){ ++it; continue; }
                        ANS="Yes"; break;
                    }
                    if(ANS) break;
                }
                if(ANS) break;
            }
        }
        puts(ANS?ANS:"No");
    }
    return 0;
}
