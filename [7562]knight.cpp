#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

#define MAX_board 301

int visit[MAX_board][MAX_board];
int T, B, i, j, x, y, next_x, next_y;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
queue<std::pair<int, int>> q;

void BFS(int ex, int ey){
  while(!q.empty()){
    x = q.front().first;
    y = q.front().second;
    q.pop();

    if(x == ex && y == ey) {
      cout << visit[x][y] - 1 << "\n";
      while(!q.empty()) q.pop();
      return;
    }

    for(i = 0; i < 8; i++){
      next_x = x + dx[i];
      next_y = y + dy[i];
      
      if(next_x >= 0 && next_x < B && next_y >= 0 && next_y < B){
        if(visit[next_x][next_y] == 0){
          visit[next_x][next_y] = visit[x][y] + 1;
          q.push(std::make_pair(next_x, next_y));
        }
      }
    }
  }
  cout << -1;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int sx, sy, ex, ey;

  cin >> T;
  while(T--){
    cin >> B >> sx >> sy >> ex >> ey;
    visit[sx][sy] = 1;
    q.push(std::make_pair(sx, sy));
    BFS(ex, ey);
    for(i = 0; i < B; i++){
      for(j = 0; j < B; j++){
        visit[i][j] = 0;
      }
    }
  }
  return 0;
}