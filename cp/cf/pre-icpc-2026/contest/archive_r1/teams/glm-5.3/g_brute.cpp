#include <bits/stdc++.h>
using namespace std;

struct Seg{ long long a1,a2,b; bool hor; };

bool inter(const Seg&p,const Seg&q){
    if(p.hor!=q.hor){
        const Seg*h=p.hor?&p:&q; const Seg*v=p.hor?&q:&p;
        return min(h->a1,h->a2)<=v->b && v->b<=max(h->a1,h->a2)
            && min(v->a1,v->a2)<=h->b && h->b<=max(v->a1,v->a2);
    }
    if(p.b!=q.b) return false;
    return max(min(p.a1,p.a2),min(q.a1,q.a2)) <= min(max(p.a1,p.a2),max(q.a1,q.a2));
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<long long> d(n);
        for(auto&v:d) scanf("%lld",&v);
        // simulate
        vector<Seg> s;
        long long x=0,y=0;
        int dx[4]={0,-1,0,1}, dy[4]={1,0,-1,0};
        for(int i=0;i<n;i++){
            long long nx=x+dx[i%4]*d[i], ny=y+dy[i%4]*d[i];
            bool hor = (dy[i%4]==0);
            Seg sg;
            if(hor){ sg.a1=x; sg.a2=nx; sg.b=ny; } else { sg.a1=y; sg.a2=ny; sg.b=nx; }
            sg.hor=hor;
            s.push_back(sg);
            x=nx; y=ny;
        }
        bool ans=false;
        for(int i=0;i<n && !ans;i++)
            for(int j=i+3;j<n;j++)
                if(inter(s[i],s[j])){ ans=true; break; }
        puts(ans?"Yes":"No");
    }
}
