#include <iostream>
#include <deque>
using namespace std;

struct DATA {
    int index;
    int value;
};
deque<DATA> deq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;

        while (deq.size() && deq.back().value > now) deq.pop_back();
        deq.push_back({ i, now });

        if (deq.front().index <= i - l) deq.pop_front();
        cout << deq.front().value << " ";
    }
}
// Q) i - L + 1 ~ i까진데 왜 i = 0부터 덱에 넣을까? => i <= 0인 Ai는 무시하고 D를 구하라는 조건 때문에