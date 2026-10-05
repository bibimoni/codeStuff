// Generator. Modes:
//   sample
//   edgepack <kind> <seed>
//   rand <n> <q> <wlo> <whi> <updPct> <seed>
//   trap <n> <q> <seed>            pinned unique mixed-orientation optimum
//   maxrand|maxquery|maxupd|maxneg|maxhub|maxmix|maxmono <seed>
//   sumpack <seed> | tmax <seed> | biganswer
#include "testlib.h"
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll W = 1000000000LL;
const int MX = 300000;

struct Ev { int tp; int x; ll y; };
struct Test { int n; vector<ll> a, b; vector<Ev> ev; };

void emit(const vector<Test>& ts) {
    printf("%d\n", (int)ts.size());
    for (const auto& T : ts) {
        printf("%d %d\n", T.n, (int)T.ev.size());
        for (int i = 0; i < T.n; i++) printf("%lld%c", T.a[i], i + 1 < T.n ? ' ' : '\n');
        for (int i = 0; i < T.n; i++) printf("%lld%c", T.b[i], i + 1 < T.n ? ' ' : '\n');
        for (auto& e : T.ev) printf("%d %d %lld\n", e.tp, e.x, e.y);
    }
}

Ev rndQuery(int n) {
    int s, t;
    do { s = rnd.next(1, n + 1); t = rnd.next(1, n + 1); } while (s == t);
    if (s > t) swap(s, t);
    return {1, s, t};
}

Test mkRand(int n, int q, ll wlo, ll whi, int updPct) {
    Test T; T.n = n; T.a.resize(n); T.b.resize(n);
    for (auto& v : T.a) v = rnd.next(wlo, whi);
    for (auto& v : T.b) v = rnd.next(wlo, whi);
    for (int e = 0; e < q; e++) {
        if (rnd.next(0, 99) < updPct) {
            int x = rnd.next(1, n);
            ll w = rnd.next(wlo, whi);
            T.ev.push_back({rnd.next(0, 1) ? 2 : 3, x, w});
        } else T.ev.push_back(rndQuery(n));
    }
    return T;
}

// Two pinned -W spokes k1<k2; ring all zeros. Optimum for queries that cover
// exactly one pin is -W via that region's pair; only MIXED-orientation hub
// detours reach -2W. Updates keep |w|<=3 on a[] so trap survives.
Test mkTrap(int n, int q) {
    Test T; T.n = n; T.a.assign(n, 0); T.b.assign(n, 0);
    int k1 = rnd.next(2, max(2, n / 2 - 1));
    int k2 = rnd.next(max(k1 + 2, n / 2 + 1), max(k1 + 2, n - 1));
    T.b[k1 - 1] = -W; T.b[k2 - 1] = -W;
    for (int e = 0; e < q; e++) {
        int r = rnd.next(0, 99);
        if (r < 40) { // left trap: k1 in [s,t], k2 outside
            int s = rnd.next(1, k1), t = rnd.next(k1 + 1, k2 - 1);
            T.ev.push_back({1, s, t});
        } else if (r < 75) { // right trap: k2 in [s,t], k1 outside; s < t strictly
            int s = rnd.next(k1 + 1, k2 - 1), t = rnd.next(k2, n);
            T.ev.push_back({1, s, t});
        } else if (r < 90) {
            T.ev.push_back(rndQuery(n));
        } else if (r < 95) {
            T.ev.push_back({2, rnd.next(1, n), (ll)rnd.next(-3, 3)});
        } else { // touch only non-pinned spokes gently
            int x = rnd.next(1, n);
            if (T.b[x - 1] == -W) x = x % n + 1;
            T.ev.push_back({3, x, (ll)rnd.next(-3, 3)});
        }
    }
    return T;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);

    if (mode == "sample") {
        Test T; T.n = 3; T.a = {4, -2, 5}; T.b = {3, 7, 1};
        T.ev = {{1,1,3},{2,2,6},{1,1,3},{3,1,-4},{1,1,3},{1,1,4}};
        emit({T});
        return 0;
    }
    if (mode == "biganswer") {
        Test T; T.n = MX; T.a.assign(MX, -W); T.b.assign(MX, W);
        T.ev = {{1, 1, MX + 1}, {1, 1, MX}, {1, MX, MX + 1}, {2, MX / 2, -W}, {1, 2, MX - 1}};
        emit({T});
        return 0;
    }
    if (mode == "edgepack") {
        int kind = opt<int>(2); int seed = opt<int>(3);
        rnd.setSeed(seed);
        vector<Test> ts;
        if (kind == 0) {
            ts.push_back({2, {W, -W}, {-W, W}, {{1,1,2},{1,1,3},{1,2,3},{2,1,-W},{1,1,2},{3,2,W},{1,2,3}}});
            ts.push_back({2, {-1, -1}, {-1, -1}, {{1,1,2},{1,2,3},{1,1,3}}});
            ts.push_back({3, {5, 5, 5}, {5, 5, 5}, {{1,1,3},{1,1,4},{1,2,4}}});
            ts.push_back({4, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {{1,1,4},{1,2,5},{3,4}}});
            ts.push_back({5, {3, -1, 4, -2, 6}, {2, -3, 1, 5, -4}, {{1,2,4}}}); // q=1
            ts.push_back({4, {1, 2, 3, 4}, {5, 6, 7, 8}, {{2,1,-9},{3,3,9},{2,2,0},{3,4,-1000000000LL},{2,4,7},{3,1,-1}}}); // no queries
            ts.push_back({2, {W, W}, {W, -W}, {{1,1,2},{3,1,-1},{1,1,3},{2,2,-W},{1,2,3},{1,1,2},{3,2,4},{1,1,3},{2,1,-W},{1,2,3},{1,1,2}}});
        } else if (kind == 1) { // hub-heavy tiny
            for (int tn : {2, 3, 5}) {
                Test T; T.n = tn;
                for (int i = 0; i < tn; i++) { T.a.push_back(rnd.next(-4, 4)); T.b.push_back(rnd.next(-4, 4)); }
                for (int e = 0; e < 12; e++) {
                    int r = rnd.next(0, 99);
                    if (r < 60) T.ev.push_back({1, rnd.next(1, tn), (ll)tn + 1});
                    else if (r < 75) T.ev.push_back(rndQuery(tn));
                    else if (r < 88) T.ev.push_back({3, rnd.next(1, tn), (ll)rnd.next(-4, 4)});
                    else T.ev.push_back({2, rnd.next(1, tn), (ll)rnd.next(-4, 4)});
                }
                ts.push_back(T);
            }
        } else { // n=2 chaos, extreme values
            for (int rep = 0; rep < 2; rep++) {
                Test T; T.n = 2;
                for (int i = 0; i < 2; i++) {
                    T.a.push_back(rnd.next(0, 1) ? W : -W);
                    T.b.push_back(rnd.next(0, 1) ? 1 : -1);
                }
                for (int e = 0; e < 25; e++) {
                    int r = rnd.next(0, 99);
                    if (r < 50) {
                        int s = rnd.next(1, 3), t;
                        do { t = rnd.next(1, 3); } while (t == s);
                        if (s > t) swap(s, t);
                        T.ev.push_back({1, s, (ll)t});
                    } else {
                        int x = rnd.next(1, 2);
                        ll wv = (ll)rnd.next(0, 1) ? W : -W;
                        T.ev.push_back({rnd.next(0, 1) ? 2 : 3, x, wv});
                    }
                }
                ts.push_back(T);
            }
        }
        emit(ts);
        return 0;
    }
    if (mode == "rand") {
        rnd.setSeed(opt<int>(7));
        emit({mkRand(opt<int>(2), opt<int>(3), (ll)opt<long long>(4), (ll)opt<long long>(5), opt<int>(6))});
        return 0;
    }
    if (mode == "trap") {
        rnd.setSeed(opt<int>(4));
        emit({mkTrap(opt<int>(2), opt<int>(3))});
        return 0;
    }
    if (mode == "sumpack") {
        rnd.setSeed(opt<int>(2));
        vector<Test> ts;
        for (int i = 0; i < 10; i++) ts.push_back(mkRand(MX / 10, MX / 10, -W, W, i % 2 ? 70 : 20));
        emit(ts);
        return 0;
    }
    if (mode == "tmax") {
        rnd.setSeed(opt<int>(2));
        vector<Test> ts;
        for (int i = 0; i < 99991; i++) ts.push_back(mkRand(2, 2, -9, 9, 50));
        emit(ts);
        return 0;
    }
    // max-* presets
    int seed = opt<int>(2);
    rnd.setSeed(seed);
    if (mode == "maxrand") emit({mkRand(MX, MX, -W, W, 50)});
    else if (mode == "maxquery") emit({mkRand(MX, MX, -W, W, 5)});
    else if (mode == "maxupd") emit({mkRand(MX, MX, -W, W, 95)});
    else if (mode == "maxneg") emit({mkRand(MX, MX, -W, -1, 30)});
    else if (mode == "maxhub") {
        Test T = mkRand(MX, 0, -W, W, 0);
        for (int e = 0; e < MX; e++) {
            if (e % 10 == 9) T.ev.push_back({3, rnd.next(1, MX), (ll)rnd.next(-W, W)});
            else T.ev.push_back({1, rnd.next(1, MX), (ll)MX + 1});
        }
        emit({T});
    }
    else if (mode == "maxmix") {
        Test T; T.n = MX; T.a.resize(MX); T.b.resize(MX);
        for (int i = 0; i < MX; i++) T.a[i] = (i % 2 ? W : -W);
        for (int i = 0; i < MX; i++) T.b[i] = (i % 97 == 0 ? -W : rnd.next(-5, 9)); // clustered minima
        for (int e = 0; e < MX; e++) {
            if (rnd.next(0, 99) < 30) T.ev.push_back({rnd.next(0, 1) ? 2 : 3, rnd.next(1, MX), (ll)rnd.next(-9, 9)});
            else T.ev.push_back(rndQuery(MX));
        }
        emit({T});
    }
    else if (mode == "maxmono") {
        Test T; T.n = MX; T.a.resize(MX); T.b.resize(MX);
        ll v = -W; ll step = 2 * W / MX;
        for (int i = 0; i < MX; i++) T.a[i] = v + 1LL * i * step - 0LL, T.b[i] = -T.a[i] / 2;
        for (int e = 0; e < MX; e++) {
            if (rnd.next(0, 99) < 20) T.ev.push_back({rnd.next(0, 1) ? 2 : 3, rnd.next(1, MX), (ll)rnd.next(-W, W)});
            else T.ev.push_back(rndQuery(MX));
        }
        emit({T});
    }
    else quitf(_fail, "unknown mode %s", mode.c_str());
    return 0;
}
