#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    vector<int> p(n), r(n + 2, -1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        r[p[i]] = i;
    }
    // equal chars allowed between consecutive suffixes p[k-1], p[k]
    // iff suffix(p[k-1]+1) is already smaller than suffix(p[k]+1)
    int ans = 1;
    for (int k = 1; k < n; k++) {
        if (r[p[k - 1] + 1] > r[p[k] + 1]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
