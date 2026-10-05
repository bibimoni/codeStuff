#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int p[55];

int sa[55];
bool cmp(int a, int b, const char* s) {
    for (int l = 0; l < n; l++) {
        char ca = (a+l < n) ? s[a+l] : 0;
        char cb = (b+l < n) ? s[b+l] : 0;
        if (ca != cb) return ca < cb;
    }
    return false;
}

bool check(const char* s) {
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-i-1; j++)
            if (!cmp(sa[j], sa[j+1], s)) { int t=sa[j]; sa[j]=sa[j+1]; sa[j+1]=t; }
    for (int i = 0; i < n; i++) if (sa[i] != p[i]) return false;
    return true;
}

char s[55];
int k;
bool found;

void gen(int pos) {
    if (found) return;
    if (pos == n) { if (check(s)) found = true; return; }
    for (int c = 0; c < k; c++) { s[pos]=c; gen(pos+1); if(found)return; }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { int x; scanf("%d", &x); p[i] = x-1; }
    k = 4;
    found = false;
    gen(0);
    if (found) {
        for (int i = 0; i < n; i++) putchar('a'+s[i]);
        putchar('\n');
    } else {
        printf("not found\n");
    }
    return 0;
}
