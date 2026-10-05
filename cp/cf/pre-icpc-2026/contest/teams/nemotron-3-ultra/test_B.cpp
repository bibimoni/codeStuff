#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3000;
const int WORDS = (MAXN + 63) / 64;

struct Bitset {
    uint64_t w[WORDS];
    Bitset() { memset(w, 0, sizeof(w)); }
    bool get(int i) const { return (w[i >> 6] >> (i & 63)) & 1; }
    void set(int i) { w[i >> 6] |= 1ULL << (i & 63); }
    void flip(int i) { w[i >> 6] ^= 1ULL << (i & 63); }
    void xor_with(const Bitset& other) {
        for (int k = 0; k < WORDS; ++k) w[k] ^= other.w[k];
    }
    int count() const {
        int c = 0;
        for (int k = 0; k < WORDS; ++k) c += __builtin_popcountll(w[k]);
        return c;
    }
    int parity_with(const Bitset& other) const {
        int p = 0;
        for (int k = 0; k < WORDS; ++k) p ^= __builtin_parityll(w[k] & other.w[k]);
        return p;
    }
};

int main() {
    Bitset a, b;
    a.set(0); a.set(2);
    b.set(0); b.set(1);
    cout << "a: " << a.count() << endl;
    cout << "b: " << b.count() << endl;
    cout << "parity: " << a.parity_with(b) << endl; // should be 1 (bit 0 common)
    
    Bitset p;
    p.set(0); p.set(2);
    Bitset bb;
    bb.set(0); bb.set(1); bb.set(2);
    cout << "p: " << p.count() << ", bb: " << bb.count() << endl;
    cout << "parity: " << p.parity_with(bb) << endl; // bits 0,2 common -> 2 -> parity 0
}
