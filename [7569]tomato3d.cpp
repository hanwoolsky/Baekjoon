#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

#define MAX_VERTEX 100

int map[MAX_VERTEX][MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX][MAX_VERTEX][MAX_VERTEX];
int N, M, H, i, j, k, next_x, next_y, next_z;
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<std::pair<std::pair<int, int>, int>> q;

void BFS(int x, int y, int z){  
  while(!q.empty()){
    x = q.front().first.first;
    y = q.front().first.second;
    z = q.front().second;
    q.pop();
    for(i = 0; i < 6; i++){
      next_x = x + dx[i];
      next_y = y + dy[i];
      next_z = z + dz[i];

      if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && next_z >= 0 && next_z < H){
        if(map[next_z][next_x][next_y] == 0 && visit[next_z][next_x][next_y] == 0) {
          map[next_z][next_x][next_y] = 1;
          visit[next_z][next_x][next_y] = visit[z][x][y] + 1;
          q.push(make_pair(std::make_pair(next_x, next_y), next_z));
        }
      }
    }
  }
  for(k = 0; k < H; k++){
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++){
        if(map[k][i][j] == 0){
          cout << "-1";
          return;
        }
      }
    }
  }
  cout << visit[z][x][y];
}

int main() {
  cin >> M >> N >> H;

  
  for(k = 0; k < H; k++){
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++){
        cin >> map[k][i][j];
        visit[k][i][j] = 0;
      }
    }
  }

  for(k = 0; k < H; k++){
    for(i = 0; i < N; i++){
      for(j = 0; j < M; j++){
        if(map[k][i][j] == 1) {
          q.push(make_pair(std::make_pair(i, j), k));
        }
      }
    }
  }
  BFS(q.front().first.first, q.front().first.second, q.front().second);

  return 0;
}