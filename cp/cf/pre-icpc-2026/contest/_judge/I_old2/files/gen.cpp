#include "testlib.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

// Cell value = bitmask of openings: 1=U, 2=R, 4=D, 8=L; 0 = empty;
// popcount 1 is forbidden. Strikes: distinct junction cells, 1-indexed output.
//
// Modes:
//   gen sample1 | sample2 | edge | tmax <seed> | sumpack <seed> | maxdense <seed>
//   gen mini <seed>                              (~150 tiny random tests)
//   gen maze <n> <m> <ord> <seed>                (perfect maze: forest, all answers 0)
//   gen rand <n> <m> <density> <pattern> <ord> <seed>
// pattern: 0 uniform valid types  1 all-15  2 perfect maze  3 maze + extra openings
// ord:     0 shuffle all struck   1 row-major all struck    2 shuffle, half struck
// density: permille of cells that hold a junction (ignored by maze patterns)

static const int DR[4] = {-1, 0, 1, 0};
static const int DC[4] = {0, 1, 0, -1};
static const int VALID[11] = {3, 5, 6, 9, 10, 12, 7, 11, 13, 14, 15};

struct T {
    int n, m;
    vector<vector<int>> g;
    vector<pair<int,int>> strikes; // 0-indexed internally
};

static void emit(const vector<T>& ts) {
    println(ts.size());
    for (auto& tc : ts) {
        ostringstream hdr;
        hdr << tc.n << ' ' << tc.m;
        println(hdr.str());
        ostringstream line;
        for (int i = 0; i < tc.n; i++) {
            line.str("");
            for (int j = 0; j < tc.m; j++) {
                if (j) line << ' ';
                line << tc.g[i][j];
            }
            println(line.str());
        }
        println(tc.strikes.size());
        for (auto& s : tc.strikes) {
            ostringstream sl;
            sl << s.first + 1 << ' ' << s.second + 1;
            println(sl.str());
        }
    }
}

static vector<pair<int,int>> pipesOf(const vector<vector<int>>& g) {
    vector<pair<int,int>> p;
    for (int i = 0; i < (int)g.size(); i++)
        for (int j = 0; j < (int)g[i].size(); j++)
            if (g[i][j]) p.push_back({i, j});
    return p;
}

static vector<pair<int,int>> orderStrikes(vector<pair<int,int>> p, int ord) {
    if (ord == 0 || ord == 2) shuffle(p.begin(), p.end());
    if (ord == 2) p.resize(p.size() / 2);
    return p;
}

// perfect maze on all cells; then fix popcount-1 dead ends with a harmless
// extra opening (points at a non-tree neighbour or off-grid: never adds an
// edge), then optionally add random extra openings (pattern 3: adds loops).
static vector<vector<int>> genMazeGrid(int n, int m, int extraPct) {
    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<vector<char>> vis(n, vector<char>(m, 0));
    vector<pair<int,int>> st = {{0, 0}};
    if (n * m > 0) vis[0][0] = 1;
    while (!st.empty()) {
        auto rc = st.back();
        int r = rc.first, c = rc.second;
        int dirs[4] = {0, 1, 2, 3};
        shuffle(dirs, dirs + 4);
        bool adv = false;
        for (int d : dirs) {
            int nr = r + DR[d], nc = c + DC[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc]) continue;
            g[r][c] |= 1 << d;
            g[nr][nc] |= 1 << (d ^ 2);
            vis[nr][nc] = 1;
            st.push_back({nr, nc});
            adv = true;
            break;
        }
        if (!adv) st.pop_back();
    }
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++) {
            int v = g[r][c];
            if (extraPct > 0 && v && rnd.next(100) < extraPct) {
                int missing[4], cnt = 0;
                for (int d = 0; d < 4; d++)
                    if (!(v >> d & 1)) missing[cnt++] = d;
                if (cnt) v |= 1 << missing[rnd.next(cnt)];
            }
            if (__builtin_popcount(v) == 1) {
                // add a safe opening: prefer in-grid non-tree neighbour (it
                // provably does not open back); else any off-grid direction
                int inGrid[4], offGrid[4], ci = 0, co = 0;
                for (int d = 0; d < 4; d++) {
                    if (v >> d & 1) continue;
                    int nr = r + DR[d], nc = c + DC[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) offGrid[co++] = d;
                    else inGrid[ci++] = d;
                }
                if (ci) v |= 1 << inGrid[rnd.next(ci)];
                else v |= 1 << offGrid[rnd.next(co)];
            }
            g[r][c] = v;
        }
    return g;
}

static T mkRandTest(int n, int m, int density, int pattern, int ord) {
    T t;
    t.n = n; t.m = m;
    if (pattern == 2) t.g = genMazeGrid(n, m, 0);
    else if (pattern == 3) t.g = genMazeGrid(n, m, 12);
    else {
        t.g.assign(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (rnd.next(1000) >= density) continue;
                t.g[i][j] = (pattern == 1) ? 15 : VALID[rnd.next(11)];
            }
    }
    t.strikes = orderStrikes(pipesOf(t.g), ord);
    return t;
}

static T mk(int n, int m, vector<vector<int>> g, vector<pair<int,int>> s) {
    return T{n, m, g, s};
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    if (mode == "mini" || mode == "tmax" || mode == "sumpack" || mode == "maxdense" || mode == "edge"
        || mode == "sample1" || mode == "sample2") {
        if (mode != "edge" && mode != "sample1" && mode != "sample2")
            rnd.setSeed(opt<long long>(2));
    } else if (mode == "maze") {
        rnd.setSeed(opt<long long>(5));
    } else { // rand
        rnd.setSeed(opt<long long>(7));
    }

    vector<T> ts;

    if (mode == "sample1") {
        ts.push_back(mk(2, 3, {{15,15,15},{15,15,15}}, {{0,0},{0,1},{1,1}}));
        ts.push_back(mk(3, 3, {{6,10,12},{5,10,5},{3,10,9}}, {{1,1},{0,1}}));
        ts.push_back(mk(1, 3, {{5,6,5}}, {{0,1},{0,2}}));
        ts.push_back(mk(1, 1, {{0}}, {}));
    } else if (mode == "sample2") {
        ts.push_back(mk(4, 5, {{6,10,12,6,12},{5,10,5,5,5},{3,10,9,3,9},{0,0,0,0,0}},
                         {{1,1},{0,1},{1,4},{0,4},{2,0},{1,3}}));
    } else if (mode == "edge") {
        ts.push_back(mk(1, 1, {{0}}, {}));                       // no junctions at all
        ts.push_back(mk(1, 1, {{15}}, {{0,0}}));                 // isolated, destroyed
        ts.push_back(mk(1, 1, {{3}}, {{0,0}}));                  // openings off-grid
        ts.push_back(mk(1, 2, {{6, 9}}, {{0,0},{0,1}}));         // connected pair
        ts.push_back(mk(1, 2, {{5, 5}}, {{0,1}}));               // never facing
        ts.push_back(mk(2, 2, {{15,15},{15,15}}, {{0,0},{0,1},{1,0},{1,1}})); // 1 loop, raze it
        ts.push_back(mk(2, 2, {{15,15},{15,15}}, {{1,0}}));      // 1 loop, survive
        ts.push_back(mk(2, 2, {{6,12},{3,9}}, {{1,1},{0,0}}));   // 4-cycle of corners
        ts.push_back(mk(2, 3, {{15,15,15},{15,15,15}}, {{0,0}}));// 2 loops -> 1
        ts.push_back(mk(2, 3, {{15,15,15},{15,15,15}},
                         {{0,0},{1,0},{0,1},{1,1},{0,2},{1,2}}));// destroy everything
        ts.push_back(mk(3, 3, {{6,10,12},{5,10,5},{3,10,9}},
                         {{0,0},{2,2},{1,0},{0,2}}));            // ring, cut at corner
        for (int v : VALID) ts.push_back(mk(1, 1, {{v}}, {{0,0}})); // every type alone
        ts.push_back(mk(3, 2, {{3,3},{9,9},{5,5}},
                         {{2,0},{0,1},{2,1}}));                  // vertical mismatch chain
    } else if (mode == "mini") {
        for (int tc = 0; tc < 150; tc++) {
            int n = rnd.next(1, 4), m = rnd.next(1, 4);
            ts.push_back(mkRandTest(n, m, rnd.next(300, 1001), rnd.next(3), rnd.next(3)));
        }
    } else if (mode == "tmax") {
        for (int i = 0; i < 200000; i++) {
            int v = rnd.next(4) ? 15 : 0;
            ts.push_back(mk(1, 1, {{v}}, v ? vector<pair<int,int>>{{0,0}} : vector<pair<int,int>>{}));
        }
    } else if (mode == "sumpack") {
        for (int tc = 0; tc < 100; tc++) ts.push_back(mkRandTest(40, 50, 900, 3, 0));
    } else if (mode == "maxdense") {
        ts.push_back(mkRandTest(400, 500, 1000, 1, 0));
    } else if (mode == "maze") {
        int n = opt<int>(2), m = opt<int>(3), ord = opt<int>(4);
        ts.push_back(mkRandTest(n, m, 1000, 2, ord));
    } else { // rand
        int n = opt<int>(2), m = opt<int>(3), density = opt<int>(4);
        int pattern = opt<int>(5), ord = opt<int>(6);
        ts.push_back(mkRandTest(n, m, density, pattern, ord));
    }

    emit(ts);
    return 0;
}
