#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

#define MAX_VERTEX 100

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX][MAX_VERTEX];
int N, M, i, j, next_x, next_y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<std::pair <int, int>> q;

void BFS(int x, int y){
  q.push(std::pair<int, int>(x, y));
  
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    q.pop();
    for(i = 0; i < 4; i++){
      next_x = x + dx[i];
      next_y = y + dy[i];

      if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
        if(map[next_x][next_y] == 1) {
          visit[next_x][next_y] = visit[x][y] + 1;
          map[next_x][next_y] = 0;
          q.push(std::pair<int, int>(next_x, next_y));
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  char str[MAX_VERTEX];

  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      map[i][j] = 0;
      visit[i][j] = 0;
    }
  }
  visit[0][0] = 1;
  map[0][0] = 0;

  for(i = 0; i < N; i++){
    cin >> str;
    for(j = 0; j < M; j++)
      map[i][j] = str[j] - '0';
  }
  BFS(0, 0);

  cout << visit[N-1][M-1];

  return 0;
}