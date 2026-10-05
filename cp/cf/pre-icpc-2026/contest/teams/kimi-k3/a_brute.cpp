#include <bits/stdc++.h>
using namespace std;
// exhaustive: for each permutation p of [1..n], min alphabet over all strings = formula?
int n;
vector<int> saOf(const vector<int>& s){ // s: chars 0.. (1-indexed positions)
    vector<int> idx(n); iota(idx.begin(),idx.end(),1);
    stable_sort(idx.begin(),idx.end(),[&](int x,int y){
        int i=x,j=y;
        while(i<=n&&j<=n){ if(s[i]!=s[j]) return s[i]<s[j]; i++;j++; }
        if(i>n&&j>n) return false; // equal suffixes impossible (distinct starts)
        return i>n; // shorter (i ran out) is smaller
    });
    return idx;
}
int formula(const vector<int>& p){
    vector<int> rk(n+2,-1);
    for(int i=0;i<n;i++) rk[p[i]]=i;
    int brk=0;
    for(int i=0;i+1<n;i++) if(rk[p[i]+1]>rk[p[i+1]+1]) brk++;
    return brk+1;
}
vector<int> perm;
bool checkStrings(int pos, int alpha, vector<int>& s, const vector<int>& target){
    if(pos==n+1){ return saOf(s)==target; }
    for(int c=0;c<alpha;c++){ s[pos]=c; if(checkStrings(pos+1,alpha,s,target)) return true; }
    return false;
}
void go(int idx){
    if(idx==n){
        vector<int> p=perm; // candidate SA
        // find min alpha for which some string has SA==p
        int best=-1;
        for(int alpha=1;alpha<=n;alpha++){
            vector<int> s(n+1);
            if(checkStrings(1,alpha,s,p)){ best=alpha; break; }
        }
        int f=formula(p);
        if(best!=f){
            printf("MISMATCH n=%d p=",n);
            for(int x:p) printf("%d ",x);
            printf(" brute=%d formula=%d\n",best,f);
            exit(1);
        }
        return;
    }
    for(int v=1;v<=n;v++){
        if(count(perm.begin(),perm.begin()+idx,v)) continue;
        perm[idx]=v; go(idx+1);
    }
}
int main(int argc,char**argv){
    n=atoi(argv[1]);
    perm.assign(n,0);
    go(0);
    printf("n=%d all ok\n",n);
    return 0;
}
