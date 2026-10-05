#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    
    // p is 1-indexed suffix array
    // Convert to 0-indexed
    vector<int> sa(n);
    for (int i = 0; i < n; i++) sa[i] = p[i] - 1;
    
    // Construct the string that produces this suffix array
    // with minimum number of distinct characters
    
    // The key insight: for consecutive entries sa[i] and sa[i+1] in the suffix array,
    // the suffix starting at sa[i] is lexicographically smaller than the suffix starting at sa[i+1].
    // 
    // We need to assign characters to positions 0..n-1 such that:
    // 1. The suffix array of the resulting string is exactly sa[]
    // 2. The number of distinct characters is minimized
    
    // Approach: 
    // Rank[i] = position of position i in the suffix array
    // rank[sa[i]] = i
    // 
    // For the suffix array to be valid, we need:
    // For each i, the suffix starting at sa[i] < suffix starting at sa[i+1]
    // 
    // The minimum number of distinct characters is determined by the "constraints"
    // between consecutive suffixes.
    
    // Let's think about it differently.
    // We have rank[sa[i]] = i.
    // For consecutive suffixes in the SA: sa[i] and sa[i+1]
    // The suffix at sa[i] < suffix at sa[i+1]
    // This means either:
    //   s[sa[i]] < s[sa[i+1]], OR
    //   s[sa[i]] == s[sa[i+1]] AND the suffix at sa[i]+1 < suffix at sa[i+1]+1
    //     which means rank[sa[i]+1] < rank[sa[i+1]+1] (if both are valid positions)
    
    // So we can determine the minimum number of characters by:
    // Assign char 0 to position sa[0].
    // For i from 1 to n-1:
    //   If rank[sa[i]+1] < rank[sa[i-1]+1] (or sa[i]+1 >= n while sa[i-1]+1 < n),
    //   then s[sa[i]] > s[sa[i-1]], so we need a new character.
    //   Otherwise, s[sa[i]] == s[sa[i-1]].
    
    // Wait, let me think more carefully.
    // The condition for the suffix array to be valid:
    // suffix(sa[i]) < suffix(sa[i+1]) for all i.
    // This is equivalent to:
    // s[sa[i]] < s[sa[i+1]], OR (s[sa[i]] == s[sa[i+1]] AND suffix(sa[i]+1) < suffix(sa[i+1]+1))
    // 
    // The second condition (when chars are equal) requires:
    // rank[sa[i]+1] < rank[sa[i+1]+1] (where rank is the suffix array rank)
    // 
    // So: if rank[sa[i]+1] < rank[sa[i+1]+1], we CAN have s[sa[i]] == s[sa[i+1]].
    // If rank[sa[i]+1] > rank[sa[i+1]+1], we MUST have s[sa[i]] < s[sa[i+1]].
    // If sa[i]+1 >= n, the suffix is empty, so the comparison is trivial (empty suffix is smallest).
    // If sa[i+1]+1 >= n, the suffix at sa[i+1]+1 is empty.
    
    // Algorithm:
    // rank[sa[i]] = i
    // char_assign[sa[0]] = 0
    // for i = 1 to n-1:
    //   int j = sa[i-1], k = sa[i]
    //   // Check if we can have s[j] == s[k] or must have s[j] < s[k]
    //   // We can have s[j] == s[k] iff:
    //   //   (j+1 < n AND k+1 < n AND rank[j+1] < rank[k+1]) OR
    //   //   (j+1 >= n AND k+1 < n) -- suffix at j+1 is empty < suffix at k+1
    //   //   Actually if j+1 >= n, suffix at j+1 is empty, and suffix at k+1 is either empty or non-empty
    //   //   If k+1 >= n too, both suffixes are empty, so s[j] == s[k] is fine.
    //   //   If k+1 < n, suffix at k+1 is non-empty > empty suffix at j+1, so s[j] == s[k] is fine.
    //   //   If j+1 < n AND k+1 >= n, suffix at j+1 is non-empty > empty suffix at k+1, so s[j] < s[k] required.
    //   //   If j+1 < n AND k+1 < n, need rank[j+1] < rank[k+1].
    //   
    //   bool can_equal = false;
    //   if (j+1 >= n || (k+1 < n && rank[j+1] < rank[k+1])) can_equal = true;
    //   if (can_equal) char_assign[k] = char_assign[j];
    //   else char_assign[k] = char_assign[j] + 1;
    //   
    //   But also, we need s[sa[i]] >= s[sa[i-1]] for the SA to be valid... wait, no.
    //   Actually, we need suffix(sa[i-1]) < suffix(sa[i]). If we can have s[sa[i-1]] == s[sa[i]], great.
    //   Otherwise, s[sa[i-1]] < s[sa[i]].
    
    // Hmm wait, I need to reconsider. The suffix at sa[i] starts at position sa[i]. So:
    // suffix(sa[i]) = s[sa[i]], s[sa[i]+1], ..., s[n-1]
    // suffix(sa[i+1]) = s[sa[i+1]], s[sa[i+1]+1], ..., s[n-1]
    // 
    // For suffix(sa[i]) < suffix(sa[i+1]):
    // Let j = sa[i], k = sa[i+1].
    // Compare s[j] vs s[k]. If s[j] < s[k], done. If s[j] > s[k], impossible (SA invalid).
    // If s[j] == s[k], compare suffixes starting at j+1 and k+1.
    //   suffix starting at j+1 < suffix starting at k+1 iff rank[j+1] < rank[k+1].
    //   (Where rank[x] is the position of position x in the SA.)
    //   Special case: if j+1 >= n, suffix at j+1 is empty, which is the smallest possible suffix.
    //   So if j+1 >= n and k+1 < n: empty < non-empty, so s[j] == s[k] works.
    //   If j+1 >= n and k+1 >= n: both empty, so s[j] == s[k] works.
    //   If j+1 < n and k+1 >= n: non-empty > empty, so s[j] < s[k] required (can't equal).
    
    // But wait, I also need to check: can s[j] > s[k]? If so, the SA is invalid.
    // Actually, the problem says "If no such string exists, print -1." So we need to check validity too.
    // But actually, any permutation can be a suffix array of some string over a large enough alphabet.
    // The question is about the minimum alphabet size. So the SA is always valid (we can always find a string).
    // Actually, that's true only if the SA is a valid SA. But the problem guarantees it's a valid SA.
    
    // Hmm, actually not every permutation is a valid suffix array. But the problem says we're given a valid one.
    // So we just need to find the minimum alphabet.
    
    // Let me re-examine. We assign characters to positions 0..n-1. The assignment must make
    // the suffix array exactly sa[]. The minimum number of distinct characters is what we want.
    
    vector<int> rank_arr(n);
    for (int i = 0; i < n; i++) rank_arr[sa[i]] = i;
    
    int max_char = 0;
    vector<int> ch(n, 0);
    ch[sa[0]] = 0;
    
    for (int i = 1; i < n; i++) {
        int j = sa[i-1], k = sa[i];
        bool can_equal = false;
        if (j + 1 >= n) can_equal = true;
        else if (k + 1 >= n) can_equal = false; // suffix at j+1 is longer than empty suffix at k+1, so s[j] must be < s[k]
        else if (rank_arr[j+1] < rank_arr[k+1]) can_equal = true;
        
        if (can_equal) {
            ch[k] = ch[j];
        } else {
            ch[k] = ch[j] + 1;
        }
        max_char = max(max_char, ch[k]);
    }
    
    printf("%d\n", max_char + 1);
    return 0;
}
