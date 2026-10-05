// Brute force checker for A: for each permutation of 1..n, find min distinct chars
// by trying strings over alphabet size 1..n (values 0..k-1), all k^n strings.
// Also verifies greedy construction produces SA == p.
#include <bits/stdc++.h>
using namespace std;

vector<int> buildSA(const vector<int>& s){
    int n = s.size();
    vector<int> suf(n);
    iota(suf.begin(), suf.end(), 0);
    auto cmp = [&](int u, int v){
        while(u < n && v < n){
            if(s[u] != s[v]) return s[u] < s[v];
            u++; v++;
        }
        return u == n && v != n; // u exhausted first -> u smaller
    };
    sort(suf.begin(), suf.end(), cmp);
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i] = suf[i]+1;
    return p;
}

int greedyAns(const vector<int>& p){
    int n = p.size();
    vector<int> pos(n+2, -1);
    for(int i=0;i<n;i++) pos[p[i]] = i+1;
    int forced = 0;
    for(int i=1;i<n;i++){
        int a = p[i-1], b = p[i];
        bool f;
        if(b == n) f = true;
        else if(a == n) f = false;
        else f = (pos[a+1] > pos[b+1]);
        if(f) forced++;
    }
    return forced + 1;
}

// construct greedy string, verify SA
bool greedyVerify(const vector<int>& p){
    int n = p.size();
    vector<int> pos(n+2, -1);
    for(int i=0;i<n;i++) pos[p[i]] = i+1;
    vector<int> s(n+1, 0);
    s[p[0]] = 0;
    int cur = 0;
    for(int i=1;i<n;i++){
        int a = p[i-1], b = p[i];
        bool f;
        if(b == n) f = true;
        else if(a == n) f = false;
        else f = (pos[a+1] > pos[b+1]);
        if(f) cur++;
        s[b] = cur;
    }
    vector<int> str(s.begin()+1, s.end());
    return buildSA(str) == p;
}

int bruteAns(const vector<int>& p){
    int n = p.size();
    for(int k = 1; k <= n; k++){
        // enumerate all strings over 0..k-1
        long long total = 1;
        for(int i=0;i<n;i++) total *= k;
        for(long long mask = 0; mask < total; mask++){
            long long m = mask;
            vector<int> s(n);
            for(int i=0;i<n;i++){ s[i] = m % k; m /= k; }
            if(buildSA(s) == p) return k;
        }
    }
    return -1;
}

int main(){
    for(int n = 1; n <= 7; n++){
        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        int cnt = 0, bad = 0;
        do {
            cnt++;
            int g = greedyAns(p);
            int b = bruteAns(p);
            if(g != b){ bad++; printf("MISMATCH n=%d p=", n); for(int x: p) printf("%d ", x); printf(" greedy=%d brute=%d\n", g, b); }
            if(!greedyVerify(p)){ bad++; printf("VERIFY-FAIL n=%d p=", n); for(int x: p) printf("%d ", x); printf("\n"); }
        } while(next_permutation(p.begin(), p.end()));
        printf("n=%d perms=%d bad=%d\n", n, cnt, bad);
        fflush(stdout);
    }
    // samples
    printf("sample1: %d (want 2)\n", greedyAns({4,1,2,3}));
    printf("sample2: %d (want 1)\n", greedyAns({4,3,2,1}));
    printf("sample3: %d (want 4)\n", greedyAns({4,3,1,2,6,7,5}));
    return 0;
}
