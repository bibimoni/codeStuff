#include <bits/stdc++.h>
using namespace std;

static vector<long long> smooth;
static int sidx[6000][10]; // index of smooth[i]*k in smooth, -1 if > 1e9
static const int SM = 5300;
static bitset<SM> W[6000];
static bitset<SM> lowmask[6000];
static char ans[6000]; // ans[j] = does first player win when #states = j (j>=1)

int main() {
    {
        set<long long> s;
        function<void(long long)> gen = [&](long long p) {
            if (p > 1000000000LL || s.count(p)) return;
            s.insert(p);
            for (int k = 2; k <= 9; k++) gen(p * k);
        };
        gen(1);
        smooth.assign(s.begin(), s.end());
        int S = (int)smooth.size();
        unordered_map<long long, int> pos;
        pos.reserve(S * 2);
        for (int i = 0; i < S; i++) pos[smooth[i]] = i;
        for (int i = 0; i < S; i++)
            for (int k = 2; k <= 9; k++) {
                long long v = smooth[i] * k;
                sidx[i][k] = (v > 1000000000LL) ? -1 : pos[v];
            }
        // lowmask[j]: bits 0..j set
        for (int j = 0; j < S; j++) {
            if (j > 0) lowmask[j] = lowmask[j - 1];
            lowmask[j].set(j);
        }
        // W[i] bit j (j>=1) = first player wins from p=smooth[i] when state set = smooth[0..j-1]
        for (int i = S - 1; i >= 0; i--) {
            bitset<SM> res;
            for (int k = 2; k <= 9; k++) {
                int c = sidx[i][k];
                if (c < 0) { res.set(); break; }
                res |= (~W[c]) | lowmask[c];
                if (res.all()) break;
            }
            W[i] = res;
        }
        ans[0] = 1; // n == 1
        for (int j = 1; j <= S; j++) ans[j] = W[0][j];
    }
    int T; scanf("%d", &T);
    static vector<char> out;
    out.clear();
    out.reserve(T * 40);
    const char* win_s = "La premiere joueuse gagne.";
    const char* lose_s = "La deuxieme joueuse gagne.";
    while (T--) {
        long long n; scanf("%lld", &n);
        int m = (int)(lower_bound(smooth.begin(), smooth.end(), n) - smooth.begin());
        const char* s = ans[m] ? win_s : lose_s;
        while (*s) out.push_back(*s++);
        out.push_back('\n');
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
