#include "testlib.h"
using namespace std;

string rndline(random_t& rnd, int len) {
    string s;
    for (int i = 0; i < len; i++) s += 'a' + rnd.next(0, 25);
    for (int i = 1; i + 1 < len; i += rnd.next(4, 12)) s[i] = ' '; // single spaces only (wfval)
    return s;
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    string mode = opt<string>(1);
    if (mode == "pledge") {
        println("1\n5");
        println("retupmoc eno gnirahs stnatsetnoc eerht yltcaxe sah maet hcae");
        println("tsetnoc eht gnirud dewolla era sloot ia ro ssecca tenretni pleh lanretxe on");
        println("lanif era segduj eht fo snoisiced eht dna sruoh evif stsal tsetnoc eht");
        println("emit ytlanep latot yb neht smelborp devlos yb deknar era smaet");
        println("ytivitaerc dna krowmaet ronoh htiw etepmoc dna stnenoppo ruoy tcepser");
    } else if (mode == "edge1") {
        println("1\n1\na");
    } else if (mode == "pal") {
        int t = opt<int>(2, 5), m = opt<int>(3, 3), len = opt<int>(4, 100), seed = opt<int>(5, 1);
        rnd.setSeed(seed);
        println(t);
        for (int i = 0; i < t; i++) {
            println(m);
            for (int j = 0; j < m; j++) {
                int L = rnd.next(1, len);
                string s(L, 0);
                for (int k = 0; k < (L + 1) / 2; k++) s[k] = s[L - 1 - k] = (char)('a' + rnd.next(0, 25));
                for (int k = 1; 4 * k <= L - 4; k += rnd.next(4, 12)) // mirrored, never adjacent
                    { s[k] = ' '; s[L - 1 - k] = ' '; }
                println(s);
            }
        }
    } else if (mode == "rand") {
        int t = opt<int>(2), m = opt<int>(3), len = opt<int>(4), seed = opt<int>(5);
        rnd.setSeed(seed);
        println(t);
        for (int i = 0; i < t; i++) {
            println(m);
            for (int j = 0; j < m; j++) println(rndline(rnd, rnd.next(1, len)));
        }
    } else if (mode == "manysmall") {
        int seed = opt<int>(2);
        rnd.setSeed(seed);
        println(100);
        for (int i = 0; i < 100; i++) {
            println(100);
            for (int j = 0; j < 100; j++) println(rndline(rnd, rnd.next(1, 20)));
        }
    } else if (mode == "max") {
        int seed = opt<int>(2, 1);
        rnd.setSeed(seed);
        println("1\n50");
        for (int i = 0; i < 50; i++) println(rndline(rnd, 20000));
    }
    return 0;
}
