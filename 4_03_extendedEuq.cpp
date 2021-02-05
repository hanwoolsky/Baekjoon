#include <iostream>

using namespace std;

int namoji(int x, int y){
  int mod = x%y;
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

int eeq(long long a, long long b){
  long long q, r, t;
  int mod = a;
  int t1 = 0;
  int t2 = 1;
  while(b){
    q = a / b;
    r = a % b;
    t = t1 - q * t2;
    a = b;
    b = r;
    t1 = t2;
    t2 = t;
  }
  while(t1 < 0) t1 += mod;
  return t1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  long long c, k;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> k >> c;
    if(namoji(k, c) != 1) cout << "IMPOSSIBLE" << "\n";
    else if (c==1){
      if (k < 1000000000) cout << k + 1 << "\n";
      else cout << "IMPOSSIBLE" << "\n";
    }
    else if(k == 1) cout << "IMPOSSIBLE" << "\n";
    else{
      if (k < 1000000001) cout << eeq(k, c) << "\n";
      else cout << "IMPOSSIBLE" << "\n";
    }
  }
}