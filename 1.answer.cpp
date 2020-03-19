#include<iostream>
#include<algorithm>
using namespace std;
int a[20001];
long long sum[20001];
double dp[50001];
int main(){
    int N, K;
    int T;
    int iCase = 0;
    scanf("%d", &T);
    while(T--){
        iCase ++;
        scanf("%d%d", &N, &K);
        for(int i=0;i<N;i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+N);
        sum[N] = 0;
        for(int i=N - 1;i >= 0; i--){
            sum[i] = sum[i + 1] + a[i];
        }
        dp[0] = (double) sum[0] / N;
        for(int i = 1; i<=K;i ++){
            int cnt = upper_bound(a, a + N, dp[i - 1]) - a;
            dp[i] = (cnt * dp[i - 1] + sum[cnt]) / N;
        }
        printf("Case #%d: %f\n",iCase, dp[K]);
    }
    return 0;
}