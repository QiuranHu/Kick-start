#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;
long long exponential(long long x, int times) {
	long long result = 1;
	for (int i = 0; i < times; i++) {
		result *= x;
	}
	return result;
}

long long f(long long x) {
	vector<int> nums;
	long long copy = x;
	while (copy != 0) {
		nums.push_back(copy % 10);
		copy /= 10;
	}
	if (x == 0) {
		nums.push_back(0);
	}
	reverse(nums.begin(), nums.end());
	int length = nums.size();
	long long ans = 0;
	for (int i = 0; i <= length - 2; i++) {
		ans += nums[i] * exponential(9, length - 2 - i) * 8;
	}

	long long start = x - nums[length - 1];
	while (start != x + 1) {
		if (start % 9 != 0) {
			ans += 1;
		}
		start += 1;
	}
	return ans;
}

void solve(int caseNum) {
	long long F;
	cin >> F;
	long long L;
	cin >> L;
	long long ans = f(L) - f(F) + 1;
	cout.setf(ios::fixed, ios::floatfield);
	cout << "Case #" << caseNum << ": " << ans << endl;
}

int main() {
	int T; // T test cases follow
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		solve(caseNum);
	}
	return 0;
}