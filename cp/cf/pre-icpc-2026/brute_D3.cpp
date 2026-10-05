#include <bits/stdc++.h>
using namespace std;

bool W(long long p, long long n) {
    for (int k = 2; k <= 9; k++) {
        if (p * k >= n) return true;
    }
    for (int k = 2; k <= 9; k++) {
        if (p * k < n && !W(p * k, n)) return true;
    }
    return false;
}

int main() {
    // Find ranges where first player loses
    vector<pair<int,int>> ranges;
    int start = -1;
    for (int n = 1; n <= 2000; n++) {
        bool lose = !W(1, n);
        if (lose && start == -1) start = n;
        if (!lose && start != -1) {
            ranges.push_back({start, n-1});
            start = -1;
        }
    }
    if (start != -1) ranges.push_back({start, 2000});
    
    printf("Losing ranges:\n");
    for (auto [a,b] : ranges) printf("[%d, %d]  gap=%d  width=%d\n", a, b, a - (ranges.empty() || &ranges[0]==&a ? 0 : ranges[&(&a-ranges)-&ranges[0]-1].second+1), b-a+1);
    
    // Print ratios
    printf("\nFirst elements: ");
    for (auto [a,b] : ranges) printf("%d ", a);
    printf("\n");
    printf("Second elements: ");
    for (auto [a,b] : ranges) printf("%d ", b);
    printf("\n");
    
    return 0;
}
