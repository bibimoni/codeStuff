#include <cstdio>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long d[200001];
        for (int i = 0; i < n; i++) scanf("%lld", &d[i]);
        bool bad = false;
        for (int i = 3; i < n && !bad; i++) {
            if (i >= 3 && d[i] >= d[i-2] && d[i-1] <= d[i-3]) bad = true;
            if (i >= 4 && d[i-1] == d[i-3] && d[i] + d[i-4] >= d[i-2]) bad = true;
            if (i >= 5 && d[i-2] > d[i-4] && d[i] + d[i-4] >= d[i-2] && d[i-1] + d[i-5] >= d[i-3] && d[i-1] <= d[i-3]) bad = true;
        }
        puts(bad ? "Yes" : "No");
    }
    return 0;
}
