#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n, m, k;
  int pascal[202][202];
  char ans[201];
  cin >> n >> m >> k;

  for(int i = 1; i <= n+m; i++){
    pascal[i][0] = 1;
    pascal[i][i] = 1;
    for(int j = 1; j <= i; j++){
      pascal[i+1][j] = pascal[i][j-1] + pascal[i][j];
    }
  }

  int L = m + n;
  int L2 = m + n;
  int loc = 0;
  if(pascal[L][m] < k) cout << -1;
  else{
    while(--L >= 0){
      if(pascal[L][m] > k - 1 && n > 0){
        ans[loc++] = 'a';
        n--;
      }
      else if (m > 0){
        ans[loc++] = 'z';
        m --;
        k -= pascal[L][m];
      }
      else if(loc < L2) ans[loc++] = 'a';
    }
    ans[loc] = '\0';
    cout << ans;
  }
}