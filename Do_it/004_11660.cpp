#include <iostream>
#include <cstring>

#define MAX_SIZE 1024
using namespace std;

int arr[MAX_SIZE + 2][MAX_SIZE + 2];
int sumArr[MAX_SIZE + 2][MAX_SIZE + 2];
// main 안에 선언하면 함수가 실행될 때 메모리에 할당되므로 배열의 크기가 크거나 초기화하는데 많은 시간이 걸리면 프로그램 실행 중 지연이 발생하여 제대로 동작하지 않는다.
// 배열을 전역변수로 선언하면 해당 배열이 프로그램 실행 초기에 메모리에 할당되어 초기화된다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    memset(sumArr, 0, sizeof(sumArr));

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sumArr[i][j] = sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1] + arr[i][j];
        }
    }

    int x1, y1, x2, y2;
    while (m--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sumArr[x2][y2] - sumArr[x2][y1 - 1] - sumArr[x1 - 1][y2] + sumArr[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}