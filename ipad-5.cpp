#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void solve(int caseNum) {
	int N;
	cin >> N;
	int O;
	cin >> O;
	long long D;
	cin >> D;
	long long X1;
	cin >> X1;
	long long X2;
	cin >> X2;
	long long A;
	cin >> A;
	long long B;
	cin >> B;
	long long C;
	cin >> C;
	long long M;
	cin >> M;
	long long L;
	cin >> L;
	vector<long long> X;
	X.push_back(X1);
	X.push_back(X2);
	vector<long long> S;
	for (int i = 2; i <= N - 1; i++) {
		long long Xi = (A * X[i - 1] + B * X[i - 2] + C) % M;
		X.push_back(Xi);
	}
	for (int i = 0; i <= N - 1; i++) {
		S.push_back(X[i] + L);
	}
	vector<long long> sum; // sum[i] means the sum of numbers with a index between 0 and i (inclusive).
	long long curSum = 0; 
	for (int i = 0; i <= N - 1; i++) {
		curSum += S[i];
		sum.push_back(curSum);
	}
	long long ans = -(1e17);
	int right = 0;// The number in index right is excluded.
	int numberOfOddNumbers = 0;
	multiset<long long> s;
	for (int left = 0; left < N; left++) {
		while (right <= N - 1) {
			if (S[right] % 2 != 0 && numberOfOddNumbers + 1 > O) {
				break;
			}
			if (S[right] % 2 != 0) {
				numberOfOddNumbers += 1;
			}
			right += 1;
			s.insert(sum[right - 1]); // The number in index right is excluded.
		}
		if (right == left) {
			right = left + 1;
		}
		else {
			// sum[right] - sum[left] + S[left] <= D
			multiset<long long>::iterator it = s.lower_bound(D + sum[left] - S[left] + 1);
			if (it != s.begin()) {
				it--;
				long long curAns = *(it) - sum[left] + S[left];
				ans = max(ans, curAns);
			}
			s.erase(s.find(sum[left]));
			if (S[left] % 2 != 0) {
				numberOfOddNumbers--;
			}
		}
	}
	cout << "Case #" << caseNum << ": ";
	if (ans == (long long)(-1e17)) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << ans << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		solve(caseNum);
	}
	return 0;
}