#include<iostream>
#include<string.h>
using namespace std;

int checkBKAC(string str){
  if (str.find("B") == string::npos || str.find("A") == string::npos || str.find("K") == string::npos || str.find("C") == string::npos){
      return -1;
  } 
  return max({str.find("B"),str.find("K"),str.find("A"),str.find("C")});
}

int checkGDSC(string str){
  if (str.find("G") == string::npos || str.find("D") == string::npos || str.find("S") == string::npos || str.find("C") == string::npos){
      return -1;
  } 
  return max({str.find("G"),str.find("D"),str.find("S"),str.find("C")});
}


int main(){
  int t;
  cin>>t;
  for (int i = 1 ; i<=t ;i++){
    int n;
    cin>>n;
    string str;
    cin>>str;
    if (checkBKAC(str) == -1){
      cout << "GDSC\n";
    } else if (checkGDSC(str) == -1){
      cout << "BKAC\n";
    } else{
      cout << (checkBKAC(str)<checkGDSC(str) ? "BKAC\n" : (checkBKAC(str)>checkGDSC(str) ? "GDSC\n" : "DRAW\n"));
    }
  }
}
