#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int pascal[1002][1002];
  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= n; i++){
    pascal[i][0] = 1;
    pascal[i][i] = 1;
    for(int j = 1; j <= i; j++){
      pascal[i+1][j] = (pascal[i][j-1] + pascal[i][j]) % 10007;
    }
  }

  cout << pascal[n][k];  
}