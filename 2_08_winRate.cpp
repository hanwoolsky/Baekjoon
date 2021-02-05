#include <iostream>

using namespace std;
int main() {
  long long x, y, z;
  int more, mid;
  int left = 0;
  int right = 1000000000;

  cin >> x >> y;
  z = y * 100 / x;

  if(z >= 99) cout << -1;
  else{
    while(left <= right){
      mid = (left + right) / 2;
      more = (y+mid)*100/(x+mid);
      if(more > z){
        right = mid - 1;
      }
      else{
        left = mid + 1;
      }
    }
    cout << left;
  }
}