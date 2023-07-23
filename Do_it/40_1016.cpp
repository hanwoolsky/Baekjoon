#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long minNum, maxNum;
	cin >> minNum >> maxNum;

	vector<bool> square(maxNum - minNum + 1);

	for (long i = 2; i * i <= maxNum; i++) {
		long power = i * i;
		long startIndex = minNum / power;

		if (minNum % power) startIndex++;
		for (long j = startIndex; power * j <= maxNum; j++) {
			square[j * power - minNum] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < maxNum - minNum + 1; i++) {
		if (!square[i]) count++;
	}
	cout << count;
}