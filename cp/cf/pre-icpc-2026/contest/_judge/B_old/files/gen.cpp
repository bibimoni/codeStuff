#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int test_type = rnd.next(1, 100);
    int type = 0;
    if (test_type <= 10) type = 1;       // 10%: Line graph
    else if (test_type <= 20) type = 2;  // 10%: Star graph
    else if (test_type <= 40) type = 3;  // 20%: Grid graph
    else if (test_type <= 70) type = 4;  // 30%: Dense graph
    else type = 5;                       // 30%: Random graph

    int max_N = 3000;
    int max_M = 3000;
    int max_Q = 500;

    int n, m, q;
    vector<pair<int, int>> edges;

    if (type == 1) { // 1. Line graph
        n = rnd.next(2, max_N);
        m = n - 1;
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[i] = i + 1;
        shuffle(p.begin(), p.end());
        
        for (int i = 0; i < n - 1; i++) {
            edges.push_back({p[i], p[i+1]});
        }
    } 
    else if (type == 2) { // 2. Star graph
        n = rnd.next(2, max_N);
        m = n - 1;
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[i] = i + 1;
        shuffle(p.begin(), p.end());
        
        for (int i = 1; i < n; i++) {
            edges.push_back({p[0], p[i]});
        }
    } 
    else if (type == 3) { // 3. Grid graph
        n = rnd.next(4, 1500);
        vector<int> divisors;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) divisors.push_back(n / i);
            }
        }
        
        int r, c;
        if (divisors.empty()) {
            n = (n / 2) * 2;
            r = 2;
            c = n / 2;
        } else {
            // Sửa lỗi size_t -> int để tránh ambiguous
            int idx = rnd.next((int)divisors.size());
            r = divisors[idx];
            c = n / r;
        }
        
        vector<int> p(n);
        for (int i = 0; i < n; i++) p[i] = i + 1;
        shuffle(p.begin(), p.end());
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int u = i * c + j;
                if (j + 1 < c) edges.push_back({p[u], p[u + 1]});
                if (i + 1 < r) edges.push_back({p[u], p[u + c]});
            }
        }
        m = (int)edges.size();
    } 
    else if (type == 4) { // 4. Dense graph (N nhỏ, M lớn)
        n = rnd.next(20, 80);
        int max_edges_possible = n * (n - 1) / 2;
        m = rnd.next(n - 1, min(max_M, max_edges_possible));
        
        set<pair<int, int>> edge_set;
        while ((int)edge_set.size() < m) {
            int u = rnd.next(1, n);
            int v = rnd.next(1, n);
            if (u > v) swap(u, v);
            if (u != v) edge_set.insert({u, v});
        }
        edges.assign(edge_set.begin(), edge_set.end());
    } 
    else { // 5. Random graph
        n = rnd.next(2, max_N);
        long long max_possible_edges = 1LL * n * (n - 1) / 2;
        // Sửa lỗi đồng nhất kiểu long long cho 1LL và min
        long long max_m_ll = min((long long)max_M, max_possible_edges);
        m = (int)rnd.next(1LL, max_m_ll);
        
        set<pair<int, int>> edge_set;
        while ((int)edge_set.size() < m) {
            int u = rnd.next(1, n);
            int v = rnd.next(1, n);
            if (u > v) swap(u, v);
            if (u != v) edge_set.insert({u, v});
        }
        edges.assign(edge_set.begin(), edge_set.end());
    }

    q = rnd.next(1, max_Q);
    
    shuffle(edges.begin(), edges.end());
    for (auto& e : edges) {
        if (rnd.next(2)) swap(e.first, e.second);
    }

    println(n, m, q);
    
    for (auto e : edges) {
        println(e.first, e.second);
    }

    for (int i = 0; i < q; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = rnd.next(0, 1);
        }
        println(a); // testlib tự động in các phần tử trong vector cách nhau bởi dấu cách
    }

    return 0;
}