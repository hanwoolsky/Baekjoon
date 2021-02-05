#include <iostream>

using namespace std;

int main(){
  int a, b, i;
  cin >> a >> b;

  for(i = 2; i <= b; i++){
    if (a % i == 0){
      cout << "BAD" << " " << i;
      i = b + 2;
    }
  }
  if (i == b + 1) cout << "GOOD";
}