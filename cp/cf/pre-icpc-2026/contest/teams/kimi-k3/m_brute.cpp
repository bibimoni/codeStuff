#include <bits/stdc++.h>
using namespace std;
int main(int argc,char**argv){
    srand(atoi(argv[1]));
    int N=7, TRIALS=300;
    for(int tc=0;tc<TRIALS;tc++){
        int n=1+rand()%N;
        int maxm=n*(n-1)/2;
        int m=rand()%(maxm+1);
        long long k=1+rand()%20;
        // brute
        vector<int> perm(n); iota(perm.begin(),perm.end(),1);
        vector<vector<int>> all;
        do{
            int inv=0;
            for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(perm[i]>perm[j]) inv++;
            if(inv==m) all.push_back(perm);
        }while(next_permutation(perm.begin(),perm.end()));
        // expected
        string expect;
        if((long long)all.size()<k) expect="-1";
        else { sort(all.begin(),all.end()); for(int i=0;i<n;i++){ expect+=to_string(all[k-1][i]); expect+=' '; } }
        // call solution via pipe
        string input="1\n"+to_string(n)+" "+to_string(m)+" "+to_string(k)+"\n";
        FILE* fp=fopen("/tmp/m_in.txt","w"); fputs(input.c_str(),fp); fclose(fp);
        system("./m < /tmp/m_in.txt > /tmp/m_out.txt");
        ifstream in("/tmp/m_out.txt"); string got; getline(in,got);
        // normalize spaces
        string norm; { istringstream ss(got); string w; while(ss>>w){ norm+=w; norm+=' '; } }
        string enorm; { istringstream ss(expect); string w; while(ss>>w){ enorm+=w; enorm+=' '; } }
        if(norm!=enorm){ printf("MISMATCH n=%d m=%d k=%lld expected=[%s] got=[%s]\n",n,m,k,enorm.c_str(),norm.c_str()); return 1; }
    }
    printf("all ok\n");
    return 0;
}
