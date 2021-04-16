#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using std::cout;
using std::cin;
using std::vector;

#define MAX_VERTEX 25

vector <int> v;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX][MAX_VERTEX];
int count = 0;

void BFS(int i, int j, int N){
  if(map[i][j] == 1) {
    count++;
    map[i][j] = 0;
  }
  if(j > 0 && map[i][j-1] == 1) BFS(i, j-1, N);
  if(i > 0 && map[i-1][j] == 1) BFS(i-1, j, N);
  if(j < N - 1 && map[i][j+1] == 1) BFS(i, j+1, N);
  if(i < N - 1 && map[i+1][j] == 1) BFS(i+1, j, N);
}

int main() {
  int N, num;
  int one = 0;
  cin >> N;
  char str[MAX_VERTEX];

  for(int i = 0; i < N; i++){
    cin >> str;
    for(int j = 0; j < N; j++)
      map[i][j] = str[j] - '0';
  }

  for(int i = 0; i < MAX_VERTEX; i++){
    for(int j = 0; j < MAX_VERTEX; j++){
      if(map[i][j] == 1){
        BFS(i, j, N);
        one++;
        v.push_back(count);
        count = 0;
      }
    }
  }

  cout << one << "\n";
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++){
    cout << v[i] << "\n";
  }
  return 0;
  
}

/*
input
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

answer
3
7
8
9
*/