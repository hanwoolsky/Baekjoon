// idea : 구간 합 배열 S에 대해 S[i] % M =  S[j] % M이면 (S[i] - S[j]) % M = 0이다.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long> sumArr(n, 0);
    vector<long> remainArr(m, 0); // count sort처럼 m으로 나누므로 크기는 m

    cin >> sumArr[0];
    int tmp = 0;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        sumArr[i] = sumArr[i - 1] + tmp;
    }

    int rm;
    long answer = 0;
    for (int i = 0; i < n; i++) {
        rm = sumArr[i] % m;
        if (rm == 0) answer++;
        remainArr[rm]++;
    }
    for (int i = 0; i < m; i++) {
        if (remainArr[i]) answer += remainArr[i] * (remainArr[i] - 1) / 2;
    }
    cout << answer;
}

// Step 1. sumArr에 구간합을 구한다.
// Step 2. % m이 0이면 1부터 해당 번호까지의 합이 m으로 나누어떨어진다는 의미이므로 answer에 포함한다.
// Step 3. count sort하듯이 나머지를 인덱스로하여 나머지가 같은 칸 개수를 센다.
// Step 4. 나머지가 같다는 것은 S[i] % M = S[j] % M, 즉 (S[i] - S[j]) % M = 0이므로 j에서 i까지의 합이 M으로 나누어 떨어진다는 의미이다.
// Step 5. 따라서 나머지가 같은 칸들 중 2개를 뽑으면 그 두 구간 사이의 합은 M으로 나누어 떨어진다는 의미이므로 nCr 공식을 사용하여 answer에 포함한다.