/**
 * File              : digitqueries.cpp
 * Author            : distiled
 * Date              : 31.05.2023
 * Last Modified Date: 31.05.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxN (long long) 1e6 + 5
#define mod 1000000007
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//int g[] = {9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889}

void findNum(int k, int num, int base) {
    int index = k % base;
    //cout << num << endl;
    vector<int> extracted_numbers;
    while(num > 0) {
        extracted_numbers.push_back(num % 10);
        num /= 10;
    }
    reverse(extracted_numbers.begin(), extracted_numbers.end());
    if(index != 0) cout << extracted_numbers[index - 1] << endl;
    else cout << extracted_numbers[extracted_numbers.size() - 1] << endl;
}

void solve(int k) {
    if(k <= 9) {cout << k; return;};
    int num_of_digits = 0;
    int n = 1;
    int base_of_ten = 1; //luu so chu so o g(n) 9
    int temp = 0; // luu so chu so o g(n-1)
    while(num_of_digits <= k) {
        temp = num_of_digits;
        num_of_digits += n * 9 * base_of_ten;
        n++; base_of_ten *= 10;
        //cout << num_of_digits << endl;
    }
    n--;
    int range = num_of_digits - temp;
    k -= temp;
    int i_th_number_of_n = ceil(k / (double) n);
    int numbner_of_n = (pow(10, n - 1) + i_th_number_of_n - 1);
    findNum(k, numbner_of_n, n);
}
signed main() {
    fast
    //freopen("NUMBER.INP", "r", stdin);
    //freopen("NUMBER.OUT", "w", stdout);
    //std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    //start = std::chrono::high_resolution_clock::now();
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        solve(n);
    }
    //end = std::chrono::high_resolution_clock::now();
    //int elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    //cout << "\nElapsed Time: " << elapsed_time << "ms\n";
}
/*
   1 2 3 4 5 6 7 8 9 so co 1 chu so 1->9 | 9 (1 * 9) chu so   k = 5 -> n = 1 -> g(n) = 9 -> so thu 5/1 = 5
10111213141516171819  so co 2 chu so 1->10 20 so   => k = 17 -> g(2) = 189 -> k = 17 - 9 = 8 -> 8/2 = 4 so thu 4 trong day 2 chu so la 13 vi 8 mod 2 = 0 => do la so 3
2                 29                 1->10 20 so
...
8                 89                 1->10 20 so
9                 99                 1->10 20 so
    -> 10 ... 99 -> 180 (2 * 90) chu so
    
100...999 -> 2700 so (3 * 900)

co g(n) = n*9*10^(n-1);

tim so g(n-1) < k <= g(n) voi (n thuoc 1,2,3,...)

gia su so thu k la 190 
+ g(n-1) -> g(n) <=> 189 -> 2889
-> so k-th phai thuoc khoang 1->2700 trong cac so co 3 chu so vi` g(n) voi n = 3
ta co so k la 1 trong khoang tu 1-2700 (k - g(n - 1) <=> 190 - 189)
lay k / n = so thu i-th trong day 3 chu so ceil(1/3) = 1
so 1st cua day 3 chu so la 100
ma k mod 3 = 1 (so thu 1 trong 100)
nen k = 1
*/
