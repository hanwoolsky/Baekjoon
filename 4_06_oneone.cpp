#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  while(cin >> n){
    int one = 1;
    int count = 1;
    while(1){
      if(one%n == 0){
        cout << count << "\n";
        break;
      }
      else {
        one = (one * 10) % n + 1;
        count += 1;
      }
    }
  }
}