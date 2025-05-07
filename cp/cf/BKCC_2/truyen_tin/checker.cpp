#include <iostream>
#include "testlib.h"

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int tt = inf.readInt(1, 100, "tc"); // n0 testcases 
    for (int tc = 1; tc <= tt; tc++) {
        setTestCase(tc);
        int n = inf.readInt();
        ans.readToken("?");
        ouf.readToken("?");

        int c = ouf.readInt();
        int c2 = ans.readInt();
        
        for (int i = 0; i < c; i++) {
          ouf.readToken();
          ouf.readInt();
          int k = ouf.readInt();
          ouf.readInts(k);
        }
        
        for (int i = 0; i < c2; i++) {
          ans.readToken();
          ans.readInt();
          int k = ans.readInt();
          ans.readInts(k);
        }
        
        ouf.readToken("!");
        ans.readToken("!");
        int mistake = ans.readInt();
        int guess = ouf.readInt();
        if (mistake != guess) {
            quitf(_wa, "wrong guess, you guess: %d but the mistake is: %d", guess, mistake);
        }
    }
    quitf(_ok, "correct!");
}