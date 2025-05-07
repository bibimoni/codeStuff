/**
 * File              : E_2.cpp
 * Author            : distiled
 * Date              : 18.08.2023
 * Last Modified Date: 18.08.2023
 * Last Modified By  : distiled
 */
#include <bits/stdc++.h>
using namespace std;

// A class for MEX data structure
class MEX {
    // A struct for segment tree node
    struct Node {
        int mex; // The MEX value of the segment
        int lazy; // The lazy value of the segment
        Node(int m = 0, int l = 0) : mex(m), lazy(l) {} // Constructor
    };

    int n; // The size of the array
    vector<Node> tree; // The segment tree

    // A function to build the segment tree from an array
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) { // Leaf node
            tree[node].mex = arr[start]; // Store the array element
        }
        else { // Internal node
            int mid = (start + end) / 2; // Find the middle point
            build(arr, 2 * node + 1, start, mid); // Build left subtree
            build(arr, 2 * node + 2, mid + 1, end); // Build right subtree
            tree[node].mex = min(tree[2 * node + 1].mex, tree[2 * node + 2].mex); // Store the minimum MEX value of left and right subtrees
        }
    }

    // A function to propagate the lazy value to the children nodes
    void propagate(int node, int start, int end) {
        if (tree[node].lazy != 0) { // If there is a lazy value
            tree[node].mex += tree[node].lazy; // Update the MEX value with the lazy value
            if (start != end) { // If not a leaf node
                tree[2 * node + 1].lazy += tree[node].lazy; // Propagate the lazy value to left child
                tree[2 * node + 2].lazy += tree[node].lazy; // Propagate the lazy value to right child
            }
            tree[node].lazy = 0; // Reset the lazy value
        }
    }

    // A function to update a range of elements by adding a value
    void update(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end); // Propagate the lazy value if any
        if (start > end || start > r || end < l) return; // Out of range
        if (start >= l && end <= r) { // Within range
            tree[node].mex += val; // Update the MEX value with val
            if (start != end) { // If not a leaf node
                tree[2 * node + 1].lazy += val; // Mark the left child as lazy with val
                tree[2 * node + 2].lazy += val; // Mark the right child as lazy with val
            }
            return;
        }
        int mid = (start + end) / 2; // Find the middle point
        update(2 * node + 1, start, mid, l, r, val); // Update left subtree
        update(2 * node + 2, mid + 1, end, l, r, val); // Update right subtree
        tree[node].mex = min(tree[2 * node + 1].mex, tree[2 * node + 2].mex); // Update the MEX value with the minimum MEX value of left and right subtrees
    }

    // A function to query the MEX value of a range of elements
    int query(int node, int start, int end, int l, int r) {
        propagate(node, start, end); // Propagate the lazy value if any
        if (start > end || start > r || end < l) return INT_MAX; // Out of range
        if (start >= l && end <= r) return tree[node].mex; // Within range
        int mid = (start + end) / 2; // Find the middle point
        int left = query(2 * node + 1, start, mid, l, r); // Query left subtree
        int right = query(2 * node + 2, mid + 1, end, l, r); // Query right subtree
        return min(left, right); // Return the minimum MEX value of left and right subtrees
    }

public:
    // A constructor that takes an array as input and builds the segment tree
    MEX(vector<int>& arr) {
        n = arr.size(); // Get the size of the array
        tree.resize(4 * n); // Resize the tree vector to 4 times the size of the array
        build(arr, 0, 0, n - 1); // Build the segment tree from the array
    }

    // A function that assigns val into x in the array
    void assign(int x, int val) {
        update(0, 0, n - 1, x - 1, x - 1, val - query(0, 0, n - 1, x - 1, x - 1)); // Update the segment tree by adding val - arr[x] to x. Subtract 1 from x to convert from one-based indexing to zero-based indexing.
    }

    // A function that finds MEX from L to R in the array
    int find(int L, int R) {
        return query(0, 0, n - 1, L - 1, R - 1); // Query the segment tree for the MEX value from L to R. Subtract 1 from L and R to convert from one-based indexing to zero-based indexing.
    }
};
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  MEX mex(a);
  int q; cin >> q;
  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int x, y; cin >> x >> y;
      mex.assign(x, y);
    }
    if(type == 2) {
      int l, r; cin >> l >> r;
      cout << mex.find(l, r) << endl;
    }
  }
}
