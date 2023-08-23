/**
 * File              : D1.cpp
 * Author            : distiled
 * Date              : 27.07.2023
 * Last Modified Date: 27.07.2023
 * Last Modified By  : distiled
 */
#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==0)ans++;
        else if(a[i]==2&&a[i-1]==1)ans++,a[i]=1;
    }
    for(int i=n;i>=1;i--){
        if(a[i]==0)ans++;
        else if(a[i]==2&&a[i+1]==1)ans++,a[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1&&a[i-1]!=0&&a[i+1]!=0)ans++;
    }
    printf("%d\n",ans);
    return 0;
}

