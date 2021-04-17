#include <iostream>
using std::cout;
using std::cin;

#define MAX_VERTEX 50

int map[MAX_VERTEX][MAX_VERTEX];

void BFS(int i, int j, int M, int N){
  if(map[i][j] == 1) {
    map[i][j] = 0;
  }
  if(j > 0 && map[i][j-1] == 1) BFS(i, j-1, M, N);
  if(i > 0 && map[i-1][j] == 1) BFS(i-1, j, M, N);
  if(j < N - 1 && map[i][j+1] == 1) BFS(i, j+1, M, N);
  if(i < M - 1 && map[i+1][j] == 1) BFS(i+1, j, M, N);
}

int main() {
  std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int one;
  int T, M, N, K, m, n;
  cin >> T;

  while(T--){
    cin >> M >> N >> K;
    one = 0;
    for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
        map[i][j] = 0; 
      }
    }
    while(K--){
      cin >> m >> n;
      map[m][n] = 1; 
    }

    for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
        if(map[i][j] == 1){
          BFS(i, j, M, N);
          one++;
        }
      }
    }

    cout << one << "\n";
  }

  return 0;
}