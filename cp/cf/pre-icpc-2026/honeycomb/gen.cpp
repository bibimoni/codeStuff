#include "testlib.h"
using namespace std;
int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    if (mode == "sample") {
        println("3\n1\n2\n3");
    } else if (mode == "edge1") {       // t min, n min
        println("1\n1");
    } else if (mode == "edgemax") {     // n max -> answer 2999999997000000001 (int64 trap)
        println("1\n1000000000");
    } else if (mode == "trail") {       // stress 64-bit: near-max values
        println("5\n1000000000\n999999999\n500000000\n999999937\n123456790");
    } else if (mode == "full") {        // t max of tiny n (I/O volume)
        println(10000);
        int seed = opt<int>(2, 1); rnd.setSeed(seed);
        for (int i = 0; i < 10000; i++) println(rnd.next(1, 10));
    } else if (mode == "rand") {
        int t = opt<int>(2);
        long long lo = opt<long long>(3), hi = opt<long long>(4); int seed = opt<int>(5);
        rnd.setSeed(seed);
        println(t);
        for (int i = 0; i < t; i++) println(rnd.next(lo, min(hi, 1000000000LL)));
    }
    return 0;
}
