#include <iostream>

using namespace std;

int factorial(int a){
  for (int i = a - 1; i > 0; i--){
    a *= i;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n, k;
  cout << "nCk를 입력하세요. n: ";
  cin >> n >> k;

  if(k!=0 && n != k) cout << factorial(n) / (factorial(k) * factorial(n-k));
  else cout << 1;
}