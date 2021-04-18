#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

#define MAX_VERTEX 1000

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX][MAX_VERTEX][2] = {0};
int N, M, i, j, next_x, next_y;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<std::pair<std::pair<int, int>, int>> q;

void BFS(int x, int y, int drill){
    visit[0][0][1] = 1; 
    while(!q.empty()){
      x = q.front().first.first;
      y = q.front().first.second;
      drill = q.front().second;
      q.pop();

      if(x == N - 1 && y == M - 1) {
        cout << visit[x][y][drill];
        return ;
      }

      for(i = 0; i < 4; i++){
        next_x = x + dx[i];
        next_y = y + dy[i];
        
        if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
          if(map[next_x][next_y] == 1 && drill == 1){
            visit[next_x][next_y][drill - 1]= visit[x][y][drill] + 1;
            q.push(make_pair(std::make_pair(next_x, next_y), drill - 1));
          }
          else if(map[next_x][next_y] == 0 && visit[next_x][next_y][drill] == 0){
            visit[next_x][next_y][drill] = visit[x][y][drill] + 1;
            q.push(make_pair(std::make_pair(next_x, next_y), drill));
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

  cin >> N >> M;
  char str[MAX_VERTEX];

  for(int i = 0; i < N; i++){
    cin >> str;
    for(int j = 0; j < M; j++)
      map[i][j] = str[j] - '0';
  }
  
  q.push(make_pair(std::make_pair(0, 0), 1));

  BFS(q.front().first.first, q.front().first.second, q.front().second);

  return 0;
}