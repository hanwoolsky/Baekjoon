#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::queue;

#define MAX_VERTEX 100001

int visit[MAX_VERTEX] = {0};
int N, K, i, x, next_x;
int dx[3] = {-1, 1, 2};
queue<int> q;

void BFS(){  
  while(!q.empty()){
    x = q.front();
    q.pop();
    for(i = 0; i < 3; i++){
      if(dx[i] == 2) next_x = x * dx[i];
      else next_x = x + dx[i];

      if(next_x >= 0 && next_x < MAX_VERTEX && visit[next_x] == 0){
        visit[next_x] = visit[x] + 1;
        q.push(next_x);
        if(next_x == K) {
          cout << visit[next_x] - 1 << "\n";
          return;
        }
      }
    }
  }
}

int main() {
  cin >> N >> K;

  visit[N] = 1;
  q.push(N);

  if(N < K) BFS();
  else if (N == K) cout << 0;
  else cout << N - K;

  return 0;
}