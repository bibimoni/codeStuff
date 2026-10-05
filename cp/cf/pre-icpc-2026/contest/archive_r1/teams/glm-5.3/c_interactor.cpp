// Local interactor for C: run solution as subprocess, simulate complete binary tree.
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
typedef long long ll;

int main(int argc, char** argv){
    // usage: interactor <N>
    // talks on pipes with child process "./c"
    ll N = atoll(argv[1]);
    // spawn
    int inpipe[2], outpipe[2];
    if(pipe(inpipe) || pipe(outpipe)){ perror("pipe"); return 1; }
    pid_t pid = fork();
    if(pid == 0){
        dup2(inpipe[0], 0); dup2(outpipe[1], 1);
        close(inpipe[1]); close(outpipe[0]); close(inpipe[0]); close(outpipe[1]);
        execl("./c", "./c", (char*)NULL);
        _exit(127);
    }
    close(inpipe[0]); close(outpipe[1]);
    FILE* toChild = fdopen(inpipe[1], "w");
    FILE* fromChild = fdopen(outpipe[0], "r");
    setvbuf(toChild, NULL, _IONBF, 0);
    // Tell child T=1
    fputs("1\n", toChild);
    ll cur = 1;
    long long queries = 0;
    char line[256];
    while(fgets(line, sizeof line, fromChild)){
        if(line[0] == '?'){
            queries++;
            if(queries > 8000){ printf("N=%lld QUERY LIMIT EXCEEDED\n", N); return 1; }
            char d = line[2];
            int ok = 0;
            if(d == 'L'){ if(cur*2 <= N){ ok = 1; cur = cur*2; } }
            else if(d == 'R'){ if(cur*2+1 <= N){ ok = 1; cur = cur*2+1; } }
            else if(d == 'B'){ if(cur > 1){ ok = 1; cur /= 2; } }
            fprintf(toChild, "%d\n", ok);
        } else if(line[0] == '!'){
            ll ans = atoll(line+2);
            bool verdict = (ans == N);
            printf("N=%lld ans=%lld %s queries=%lld\n", N, ans, verdict?"OK":"WRONG", queries);
            fclose(toChild); fclose(fromChild);
            waitpid(pid, NULL, 0);
            return verdict ? 0 : 1;
        }
    }
    printf("N=%lld CHILD DIED, queries=%lld\n", N, queries);
    return 1;
}
