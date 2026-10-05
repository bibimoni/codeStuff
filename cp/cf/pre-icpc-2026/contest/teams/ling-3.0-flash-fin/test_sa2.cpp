#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int target[55];

bool check(const char* s) {
    int sa[55];
    for (int i = 0; i < n; i++) sa[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            bool sw = false;
            for (int l = 0; l < n; l++) {
                char a = (sa[i]+l < n) ? s[sa[i]+l] : 0;
                char b = (sa[j]+l < n) ? s[sa[j]+l] : 0;
                if (a < b) { sw = true; break; }
                if (a > b) { sw = false; break; }
            }
            if (sw) { int t = sa[i]; sa[i] = sa[j]; sa[j] = t; }
        }
    }
    for (int i = 0; i < n; i++) printf("sa[%d]=%d ", i, sa[i]);
    printf("\n");
    for (int i = 0; i < n; i++) if (sa[i] != target[i]) return false;
    return true;
}

int main() {
    n = 4;
    target[0]=3; target[1]=0; target[2]=1; target[3]=2; // p = [4,1,2,3] 0-indexed
    
    char s[] = {'a','b','b','a',0};
    printf("abba:\n");
    check(s);
    
    char s2[] = {'a','a','b','b',0};
    printf("aabb:\n");
    check(s2);
    
    char s3[] = {'b','a','a','b',0};
    printf("baab:\n");
    check(s3);
    
    return 0;
}
