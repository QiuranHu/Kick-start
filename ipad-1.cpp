#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long getBig(long long N) {
	vector<int> digits;
	while (N != 0) {
		digits.push_back(N % 10);
		N = N / 10;
	}
	reverse(digits.begin(), digits.end());
	digits.insert(digits.begin(), 0);
	for (int index = 0; index < digits.size(); index++) {
		if (digits[index] % 2 != 0) {
			if (digits[index] == 9) {
				for (int i = index - 1; i >= 0; i--) {
					if (digits[i] != 8) {
						digits[i] = digits[i] + 2;
						for (int j = i + 1; j < digits.size(); j++) {
							digits[j] = 0;
						}
						break;
					}
				}
			}
			else {
				digits[index] = digits[index] + 1;
				for (int j = index + 1; j < digits.size(); j++) {
					digits[j] = 0;
				}
			}
			break;
		}
	}
	long long result = 0;
	for (int index = 0; index < digits.size(); index++) {
		result *= 10;
		result += digits[index];
	}
	return result;
}

long long getSmall(long long N){
    vector<int> digits;
    while(N != 0){
        digits.push_back(N % 10);
        N /= 10;
    }
    reverse(digits.begin(), digits.end());
    for(int index = 0; index < digits.size(); index++){
        if(digits[index] % 2 != 0){
            digits[index] -= 1;
            for(int i = index + 1; i < digits.size(); i ++){
                digits[i] = 8;
            }
            break;
        }
    }
    long long result = 0;
    for(int index = 0; index < digits.size(); index ++){
        result *= 10;
        result += digits[index];
    }
    return result;
}

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		long long N;
		cin >> N;
		long long big = getBig(N);
        long long small = getSmall(N);
        long long result = min(big - N, N - small);
        cout << "Case #" << caseNum << ": " << result << endl;
	}
	return 0;
}