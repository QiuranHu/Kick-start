#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int V[20001];
long long sum[20001];
double dp[50001];
int upperHelper(int arr[], int target, int length, int start, int end) {
	if (start == end) {
		if (arr[start] > target)
			return start;
		else
			return start + 1;
	}
	int half = (start + end) / 2;
	if (arr[half] <= target) {
		return upperHelper(arr, target, length, half + 1, end);
	}
	else {
		return upperHelper(arr, target, length, start, half);
	}
}
int upper(int arr[], int target, int length) {
	return upperHelper(arr, target, length, 0, length - 1);
}

int main() {
	int T; // There is totally T cases.
	scanf("%d", &T);
	int caseNum = 1;
	while (caseNum <= T) {
		int K;// Totally we can choose K + 1 times
		int N;// The length of the array is N
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &V[i]);
		}
		sort(V, V + N);// Sort the array V
		// Calculate the prefix summation
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				sum[0] = V[0];
			}
			else {
				sum[i] = sum[i - 1] + V[i];
			}
		}
		// Calculate dp
		for (int i = 0; i <= K; i++) {
			if (i == 0) {
				dp[0] = (double)sum[N - 1] / N;
			}
			else {
			    // Get the index of the first element
			    // that is greater than dp[i - 1]
				int x = upper(V, dp[i - 1], N);
				long long summation = 0;
				if (x == 0)
					summation = sum[N - 1];
				else
					summation = sum[N - 1] - sum[x - 1];
				dp[i] = (double)(x * dp[i - 1] + summation) / N;
			}
		}
		printf("Case #%d: %f\n", caseNum, dp[K]);
		caseNum += 1;
	}
	return 0;
}