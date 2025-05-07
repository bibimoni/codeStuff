/**
 * Author: distiled
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include "../testlib.h"
using namespace std;

#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

const int N = (int) 2e5 + 5;
const long long MOD = (long long) 1e9 + 7;

// rolling hash with one-based indexing
//
// usage Hash(s, BASE)
//
// query
//   hash.fwd(l, r) //get forward hash
//   hash.bwd(l, r) //get backward hash

struct Hash {
  vector<long long> hash, hashR, pow;
  Hash(string &s, int BASE) {
    int n = s.size() - 1;
    hash = vector<long long>(N);
    hashR = vector<long long>(N);
    pow = vector<long long>(N);
    hash[0] = 0;
    hashR[0] = 0;
    pow[0] = 1;
    for(int i = 1; i <= n; i++) {
      pow[i] = (pow[i - 1] * BASE) % MOD;
    }
    for(int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
    }
    for(int i = n; i >= 1; i--) {
      hashR[i] = (hashR[i + 1] * BASE + s[i] - 'a' + 1) % MOD;
    } 
  }
  long long fwd(int i, int j) {
    return (hash[j] - hash[i - 1] * pow[j - i + 1] + MOD * MOD) % MOD;
  }
  long long bwd(int i, int j) {
    return (hashR[i] - hashR[j + 1] * pow[j - i + 1] + MOD * MOD) % MOD;
  }
};

int main(int argc, char* argv[]) {
  setName("Check the final size of string and the number k used");
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerTestlibCmd(argc, argv);
  int tc = inf.readInt();
  vector<pair<int, string>> inputs;
  for(int i = 0; i < tc; i++) {
    int n = inf.readInt(1, (int) 2e5, "n");
    string s = inf.readToken();
    inputs.push_back({n, s});
  }
  auto readStream = [&] (InStream &in) -> vector<pair<int, int>> {
    vector<pair<int, int>> ret;
    for(int i = 0; i < tc; i++) {
      int n = inputs[i].first;
      int sz = in.readInt(1, n, "size");
      int len = in.readInt(1, n / 2, "k");
      ret.push_back({sz, len});
    }    
  };
  // auto ja = readStream(ans);
  // auto pa = readStream(ouf);
  auto getAns = [&] (int len, string &s) -> int {
    int n = s.size();
    s = "#" + s;
    Hash hs1(s, 331), hs2(s, 31);
    int curr = n;
    for(int i = 1; i + len - 1 <= n; i++) {
      if(hs1.fwd(i, i + len - 1) == hs1.fwd(i + len, i + 2 * len - 1) && hs2.bwd(i, i + len - 1) == hs2.bwd(i + len, i + 2 * len - 1)) {
        curr -= len;
        i += len - 1;
      }
    }
    return curr;
  };
  for(int testcase = 0; testcase < tc; testcase++) {
    int n = inputs[testcase].first;
    string s = inputs[testcase].second;
    // int szAns = ja[testcase].first, lenAns = ja[testcase].second;
    // int szP = pa[testcase].first, lenP = pa[testcase].second;
    int szAns = ans.readInt(1, n, "size"), lenAns = ans.readInt(1, max(1, n / 2), "k");
    int szP = ouf.readInt(1, n, "size"), lenP = ouf.readInt(1, max(1, n / 2), "k");
    if(szAns < szP) {
      quitf(_fail, "[testcase: %d]. Participant' answer is better = %d vs Bao's = %d", testcase + 1, szP, szAns);
    }
    if(szAns > szP) {
      quitf(_wa, "[testcase: %d]. Bao has a better answer = %d vs your answer = %d", testcase + 1, szAns, szP);
    }
    int sz = getAns(lenP, s);
    if(sz != szAns) {
      quitf(_wa, "[testcase: %d]. Your number k is invalid. Your's string length is %d, Bao's string length is %d. Your's number k is %d, Bao's number k is %d", testcase + 1, sz, szAns, lenP, lenAns);
    }
  }
  quitf(_ok, ":) Correct [%d testcases]", tc);
}

