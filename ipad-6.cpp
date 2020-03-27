#include<iostream>
#include<vector>
using namespace std;

void solve(int caseNum) {
	int N;
	int K;
	cin >> N;
	cin >> K;
	vector<long long > M;
	for (int i = 0; i < N; i++) {
		long long Mi;
		cin >> Mi;
		M.push_back(Mi);
	}
	long long small = 1;
	long long big = M[(int)(M.size()) - 1] - M[0];
	while (small < big) {
		long long middle = (small + big) / 2;
		long long cur = 0;
		for (int i = 1; i <= (int)(M.size() - 1); i++) {
			int add = 0;
			// ceil((M[i] - M[i - 1]) / middle)
			if ((M[i] - M[i - 1]) % middle == 0) {
				add = (M[i] - M[i - 1]) / middle - 1;
			}
			else {
				add = (M[i] - M[i - 1]) / middle;
			}
			cur += add;
		}

		if (cur <= (long long)K) {
			big = middle;
		}
		else {
			small = middle + 1;
		}
	}
	cout << "Case #" << caseNum << ": " << small << endl;
	return;
}

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		solve(caseNum);
	}
	return 0;
}