Problem: original 

Given array a of positive integer with size of n (n >= 1) and an integer k (k <= n). 
Has 2 operations:
Turn a_i to 0 cost a_i
pick l < m < r  turn a_m = max(a_l, a_r) cost 0 

Find smallest cost to create a contiguous segment of size at least k where all element are 0

Condition: n <= 2e5, a_i <= 1e9

Solution: min_cost = min(a_i + a_j) where j >= i && j - i + 1 >= k
