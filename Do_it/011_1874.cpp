#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<char> answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp, curNum;
    cin >> n;

    curNum = 1;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        while (tmp >= curNum) {
            st.push(curNum++);
            answer.push_back('+');
        }
        if (st.top() > tmp) {
            cout << "NO";
            return 0;
        }
        st.pop();
        answer.push_back('-');
    }
    for (char pp : answer) cout << pp << "\n";
}