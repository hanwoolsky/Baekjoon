#include <iostream>

using namespace std;

#define MAX_VERTEX 1001

int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];
int queue[MAX_VERTEX];
int rear, front, count;

void BFS(int start, int N){
  visit[start] = 1;
  int i;
  queue[rear++] = start;
  while(front < rear){
    start = queue[front++];
    for(i = 0; i <= N; i++){
      if(map[start][i] == 1 && visit[i] != 1){
        visit[i] = 1;
        count++;
        queue[rear++] = i;
      }
    }
  }
  
}

int main() {
  int N, M, V, v1, v2;
  cin >> N >> M;

  int con = M;
  for(int i = 0; i < MAX_VERTEX; i++){
    for(int j = 0; j < MAX_VERTEX; j++){
      map[i][j] = 0;
    }
    visit[i] = 0;
    queue[i] = 0;
  }
  front = 0;
  rear = 0;
  count = 0;

  while(con--){
    cin >> v1 >> v2;
    map[v1][v2] = 1;
    map[v2][v1] = 1;
  }

  BFS(1, N);
  cout << count;

  return 0;
  
}