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

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int ja = b == d? a + c : a*d + b*c;
  int mo = b == d? b : b*d;

  if (ja == mo) cout << "1 1";
  else{
    int kun = ja > mo ? ja : mo;
    int jak = ja > mo ? mo : ja;
    int gong = namoji(kun, jak);
    cout << ja / gong << " " << mo / gong;
  }
}