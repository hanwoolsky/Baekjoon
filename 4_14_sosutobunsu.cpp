#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

long long namoji(long long x, long long y){
  long long mod = x%y;
  if (mod == 0) return y;
  if (y % mod == 1){
    mod = 1;
  }
  else if(y % mod != 0){
    mod = namoji(y, mod);
  }
  else return mod;
  return mod;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int num[6];
  int arr[15];
  vector <string> sv;
  string command;
  int n;
  cin >> n;

  while(n--){
    cin >> command;
    sv.push_back(command);
    
    int strsize = sv[0].size();
    int i = 2;
    int j = 0;
    int ja = 0;
    int mo = 0;

    while(sv[0].substr(i, 1) != "(") {
      num[i] = atoi(sv[0].substr(i, 1).c_str());
      i++;
      mo++;
      if(mo==strsize-2) break;
    }

    for(i = 2; i < strsize; i++){
      if(sv[0].substr(i, 1) != "(" && sv[0].substr(i, 1) != ")"){
        arr[j] = atoi(sv[0].substr(i, 1).c_str());
        j++;
        ja++;
      }
    }

    long long bunja = 0;
    long long bunja2 = 0;
    long long bunmo = pow(10, ja) - pow(10, mo);

    for(i = 0; i < ja - 1; i++){
      bunja = (bunja + arr[i]) * 10;
    }
    bunja += arr[ja-1];

    for(i = 2; i < mo+1; i++){
      bunja2 = (bunja2 + num[i]) * 10;
    }
    bunja2 += num[mo+1];
    bunja -= bunja2;
 
    if(bunja == 0 && bunja == 0){
      bunja = bunja2;
      bunmo = pow(10, ja);
      long long gong = namoji(bunja, bunmo);
      cout << bunja / gong << "/" << bunmo / gong << "\n";
    }
    else if (bunja == bunmo) cout << "1/1";
    else{
      long long gong = namoji(bunja, bunmo);
      cout << bunja / gong << "/" << bunmo / gong << "\n";
    }
    sv.clear();
  }
}