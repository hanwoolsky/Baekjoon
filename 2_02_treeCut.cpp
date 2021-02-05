#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a, i;
  long long int b;
  int arr[1000000];
  cin >> a >> b;

  for(i = 0; i < a; i++){
    cin >> arr[i]; 
  }
  sort(arr, arr+a);
  int left = 0;
  int right = arr[a-1];
  int mid;
  long long int sum = 0;

  while(left <= right){
    mid = (left + right)/2;
    for(i = 0; i < a; i++){
      if(arr[i]-mid > 0) {
        sum += arr[i]-mid;
      }
    }
    if (sum == b){
      cout << mid;
      return 0;
    }
    else if (sum < b){
      sum = 0;
      right = mid - 1;
    }
    else if (sum > b) {
      sum = 0;
      left = mid + 1;
    }
  }
  cout << right;
}