#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;
  int m;
  int j;
  int count;
  float narr[100000];

  cin >> n;
  for(int i = 0; i < n; i ++){
    cin >> narr[i];
  }

  cin >> m;

  for (int i = 0; i < m; i++){
    cin >> count;
    for(j = 0; j < n; j++){
      if (count == narr[j]) {
        cout << 1;
        j = n + 1;
      }
    }
    if(j==n){
      cout << 0;
    }
    cout << "\n";
  }
}