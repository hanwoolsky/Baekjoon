#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

#define MAX_VERTEX 1000

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX][MAX_VERTEX];
int N, M, i, j, next_x, next_y;
int count = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<std::pair <int, int>> q;

void BFS(int x, int y){  
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    q.pop();
    count++;
    for(i = 0; i < 4; i++){
      next_x = x + dx[i];
      next_y = y + dy[i];

      if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
        if(map[next_x][next_y] == 0 && visit[next_x][next_y] == 0) {
          map[next_x][next_y] = 1;
          visit[next_x][next_y] = visit[x][y] + 1;
          q.push(std::pair<int, int>(next_x, next_y));
        }
      }
    }
  }
  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      if(map[i][j] == 0){
        cout << "-1";
        return;
      }
    }
  }
  cout << visit[x][y];
}

int main() {
  cin >> M >> N;

  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      cin >> map[i][j];
      visit[i][j] = 0;
    }
  }

  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      if(map[i][j] == 1) {
        q.push(std::pair<int, int>(i, j));
      }
    }
  }
  BFS(q.front().first, q.front().second);

  return 0;
}