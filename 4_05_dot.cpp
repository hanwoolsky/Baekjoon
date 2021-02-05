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
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n, m;
  int arr[1001];
  cin >> n;
  arr[0] = 3;
  int count = 0;

  for(int i = 1; i<=1000; i++){
    for(int j = 1; j < i; j++){
      if(namoji(i, j) == 1) count++;
    }
    arr[i] = arr[i-1] + 2* count;
    count = 0;
  }
  while(n--){
    cin >> m;
    cout << arr[m] << "\n";
  }
}