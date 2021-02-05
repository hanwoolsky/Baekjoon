#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n, o;
  int arr[1000];
  int count = 0;

  cin >> n >> o;
  for(int i = 0; i < n-1; i++){
    arr[i] = i+2;
  }
  for(int k = 2; k <= n; k++){
    for(int i = 0; i < n; i++){
      if(arr[i] != 0 && arr[i] % k == 0){
        count++;
        if(count == o) cout << arr[i];
        arr[i] = 0;
      }
    }
  }
}