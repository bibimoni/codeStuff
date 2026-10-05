#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int p[55];

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
    // Print SA
    for (int i = 0; i < n; i++) printf("%d ", sa[i]);
    printf("\n");
    for (int i = 0; i < n; i++) if (sa[i] != p[i]) return false;
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { int x; scanf("%d", &x); p[i] = x-1; }
    
    // Test with s = "abba"
    char s[] = {'a','b','b','a',0};
    n = 4;
    printf("Testing s=abba:\n");
    check(s);
    
    // Test with s = "aabb"
    char s2[] = {'a','a','b','b',0};
    printf("Testing s=aabb:\n");
    check(s2);
    
    // Test with s = "baab"
    char s3[] = {'b','a','a','b',0};
    printf("Testing s=baab:\n");
    check(s3);
    
    return 0;
}
