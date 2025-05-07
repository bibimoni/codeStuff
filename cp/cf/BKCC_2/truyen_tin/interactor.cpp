/**
 * Author: distiled
 */
#include<iostream>
using namespace std;

#include "testlib.h"
#ifdef DEBUG
#include </Users/distiled/codeStuff/templates/debug.h>
#else
#define dbg(x...)
#endif

int main(int argc, char * argv[]) {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  registerInteraction(argc, argv);

  int tt = inf.readInt(1, 100, "tc"); // n0 testcases 
  const int C = 50;
  const int N = 5000;

  cout << tt << '\n';
  cout.flush();
  for (int tc = 1; tc <= tt; tc++) {
    setTestCase(tc);
    int n = inf.readInt(1, N, "n");
    cout << n << '\n';
    cout.flush();

    vector<int> message = inf.readInts(n, 0, 1, "message");
    dbg(message);
    ouf.readToken("?");
    int c = ouf.readInt(0, C, "c");
    tout << "? " << c << "\n\n";
    // cout.flush();
    vector<vector<int>> info(c);
    vector<int> pos(c);
    for (int i = 0; i < c; i++) {
      ouf.readToken("?");
      pos[i] = ouf.readInt(1, n + c, "pos");
      int k = ouf.readInt(0, n, "k");
      info[i] = ouf.readInts(k, 1, n + c, "info");
      set<int> st(info[i].begin(), info[i].end());
      if (st.size() != info[i].size()) {
        quitf(_wa, "the infomation for each xor_bit must be unique");
      }
      tout << "? " << pos[i] << " " << k << ' ';
      for (auto inn : info[i]) {
        tout << inn << ' ';
      }
      tout << "\n\n";
      // println(info[i]);
      // cout.flush();
    }
    set<int> pos_st(pos.begin(), pos.end());
    if (pos_st.size() != pos.size()) {
      quitf(_wa, "the position of the xor_bit must be unique");
    }
    for (auto p : info) {
      for (int inn : p) {
        if (pos_st.find(inn) != pos_st.end())  {
          quitf(_wa, "the infomation must not equal to one of the xor_bit's position");
        }
      }
    }
    vector<int> new_message(n + c, 0);
    for (auto p : pos) {
      new_message[p - 1] = -1;
    }
    for (int i = 0, j = 0; i < n + c; i++) {
      if (new_message[i] == -1) {
        continue;
      }
      new_message[i] = message[j];
      j += 1;
    }
    for (int i = 0; i < c; i++) {
      int xor_bit = 0;
      for (int inn : info[i]) {
        xor_bit ^= new_message[inn - 1];
      }
      new_message[pos[i] - 1] = xor_bit;
    }

    int mistake = rnd.next(1, n + c);
    new_message[mistake - 1] ^= 1;
    println(new_message);
    cout.flush();
    ouf.readToken("!");
    int guess = ouf.readInt(1, n + c, "guess");
    // if (mistake != guess) {
    //   quitf(_wa, "wrong guess, you guess: %d but the mistake is: %d", guess, mistake);
    // }
    tout << "! " << guess << "\n\n";
    // tout.flush();

  }
  quitf(_ok, "correct!");
}
