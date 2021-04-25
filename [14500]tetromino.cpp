#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500
int paper[MAX][MAX];
int visit[MAX][MAX];
int N, M, i, j;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(int x, int y, int cnt){
  if(cnt == 4) return paper[x][y];
  int sum = 0;

  for(int i = 0; i < 4; i++){ // 1)
    int next_x = x + dx[i]; // 2)
    int next_y = y + dy[i]; // 3)     왜 1), 2), 3) 에서 int 를 안하고 global var 로 쓰면 값이 다르게 나올까?

    if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && visit[next_x][next_y] == 0){
      visit[next_x][next_y] = 1;
      sum = max(sum, paper[x][y] + DFS(next_x, next_y, cnt+1));
      visit[next_x][next_y] = 0;
    }
  }
  return sum;
} 

int yok(int i, int j){
  int result = 0;
  if(i >= 1 && j >= 1 && j < M - 1){ // ㅗ
    result = max(result, paper[i][j] + paper[i][j-1] + paper[i][j+1] + paper[i-1][j]);
  }
  if(i < N - 1 && j >= 1 && j < M - 1){ // ㅜ
    result = max(result, paper[i][j] + paper[i][j-1] + paper[i][j+1] + paper[i+1][j]);
  }
  if(i >= 1 && i < N - 1 && j >= 1){ // ㅓ
    result = max(result, paper[i][j] + paper[i-1][j] + paper[i+1][j] + paper[i][j-1]);
  }
  if(i >= 1 && i < N - 1 && j < M - 1){ // ㅏ
    result = max(result, paper[i][j] + paper[i-1][j] + paper[i+1][j] + paper[i][j+1]);
  }
  return result;
}

int main(){
  cin >> N >> M;
  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      cin >> paper[i][j];
      visit[i][j] = 0;
    }
  }
  int result = 0;
  for(i = 0; i < N; i++){
    for(j = 0; j < M; j++){
      visit[i][j] = 1;
      result = max(result, DFS(i, j, 1));
      result = max(result, yok(i, j));
      visit[i][j] = 0;
    }
  }
  cout << result;
}


// 출처: https://jaimemin.tistory.com/623