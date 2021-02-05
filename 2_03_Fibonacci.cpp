#include <iostream>

using namespace std;

long long fibarr[90];

int main() {
  int n;
  cin >> n;
  fibarr[0] = 0;
  fibarr[1] = 1;
  for(int i = 2; i <= n; i++){
    fibarr[i] = fibarr[i-2] + fibarr[i-1];
  }
  cout << fibarr[n];
}