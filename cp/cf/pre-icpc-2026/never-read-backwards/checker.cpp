#include "testlib.h"
using namespace std;
int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);
    int line = 0;
    while (!ans.seekEof()) {
        line++;
        string a = ans.readLine();
        string o = ouf.readLine();
        if (a != o) quitf(_wa, "line %d: expected <%s>, found <%s>", line, a.c_str(), o.c_str());
    }
    if (!ouf.seekEof()) quitf(_wa, "extra output after %d lines", line);
    quitf(_ok, "%d reversed lines", line);
}
