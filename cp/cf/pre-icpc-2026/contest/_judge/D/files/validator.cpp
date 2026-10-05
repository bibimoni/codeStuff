#include "testlib.h"

// Hàm bỏ qua mọi khoảng trắng, tab hoặc xuống dòng thừa
void skipWhitespace() {
    while (!inf.eof() && (inf.curChar() == ' ' || inf.curChar() == '\t' || 
                          inf.curChar() == '\r' || inf.curChar() == '\n')) {
        inf.readChar();
    }
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    skipWhitespace();
    int T = inf.readInt(1, 10000, "T");

    for (int i = 0; i < T; i++) {
        skipWhitespace();
        int n = inf.readInt(1, 1000000000, "n");
    }

    skipWhitespace();
    inf.readEof();

    return 0;
}