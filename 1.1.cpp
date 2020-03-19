#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int V[20001];
long long sum[20001];
double dp[50001];

int main() {
	int T; // There is totally T cases.
	scanf("%d", &T);
	int caseNum = 1;
	while (caseNum <= T) {
		int K;
		int N;
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &V[i]);
		}
		sort(V, V + N);
		for (int i = 0; i < N; i++) {
			if (i == 0) {
				sum[0] = V[0];
			}
			else {
				sum[i] = sum[i - 1] + V[i];
			}
		}

		for (int i = 0; i <= K; i++) {
			if (i == 0) {
				dp[0] = (double)sum[N - 1] / N;
			}
			else {
				int x = upper_bound(V, V + N, dp[i - 1]) - V;
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