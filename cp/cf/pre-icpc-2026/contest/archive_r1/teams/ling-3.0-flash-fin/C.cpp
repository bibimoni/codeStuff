#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        // Find depth d by going left repeatedly
        int d = 0;
        while(true){
            printf("? L\n");
            fflush(stdout);
            int resp;
            scanf("%d", &resp);
            if(resp == 0) break;
            d++;
        }
        // d is the number of left moves from root
        // Levels 0..d-1 are fully filled, level d has k nodes
        // N = 2^d - 1 + k, 1 <= k <= 2^d
        
        if(d == 0){
            // Only root
            printf("! 1\n");
            fflush(stdout);
            continue;
        }
        
        // Go back to root
        for(int i = 0; i < d; i++){
            printf("? B\n");
            fflush(stdout);
            int resp;
            scanf("%d", &resp);
        }
        
        // Binary search for k (number of nodes at level d)
        // j-th node at level d (1-indexed) exists iff j <= k
        // Path to j-th node: binary representation of (j-1) with d bits
        // MSB -> first move (0=left, 1=right)
        
        long long lo = 1, hi = 1LL << d;
        while(lo < hi){
            long long mid = (lo + hi + 1) / 2;
            // Check if mid-th node at level d exists
            // Navigate from root
            long long j = mid - 1; // 0-indexed
            bool exists = true;
            for(int bit = d-1; bit >= 0; bit--){
                if((j >> bit) & 1){
                    printf("? R\n");
                } else {
                    printf("? L\n");
                }
                fflush(stdout);
                int resp;
                scanf("%d", &resp);
                if(resp == 0){
                    exists = false;
                    break;
                }
            }
            // Go back to root
            for(int i = 0; i < d; i++){
                printf("? B\n");
                fflush(stdout);
                int resp;
                scanf("%d", &resp);
            }
            if(exists){
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        long long k = lo;
        long long N = (1LL << d) - 1 + k;
        printf("! %lld\n", N);
        fflush(stdout);
    }
    return 0;
}
