#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stdio.h>
using namespace std;

long long getHash(char startCharacter, char endCharacter, int nums[]) {
	long long seed = 13331;
	long long hashValue = (startCharacter - 'a') + (endCharacter - 'a') * seed;
	for (int i = 0; i < 26; i++) {
		hashValue *= 13331;
		hashValue += nums[i];
	}
	return hashValue;
}

void solve(int caseNum) {
	int L; // There are totally L words in the dictionary.
	cin >> L;
	unordered_map<long long, int> mapBetweenHashValueAndTimes;	
	unordered_set<int> lengths;
	for (int i = 0; i < L; i++) {
		string word;
		cin >> word;
		int num[26];
		int size = word.size();
		lengths.insert(size);
		memset(num, 0, sizeof(num));
		for (int j = 1; j <= size - 2; j++) {
			num[word[j] - 'a'] ++;
		}
		long long hashValue = getHash(word[0], word[size - 1], num);
		if (mapBetweenHashValueAndTimes.count(hashValue) == 0) {
			mapBetweenHashValueAndTimes[hashValue] = 1;
		}
		else {
			mapBetweenHashValueAndTimes[hashValue] ++;
		}
	}
	string S1;
	cin >> S1;
	string S2;
	cin >> S2;
	int N;
	cin >> N;
	int A;
	cin >> A;
	int B;
	cin >> B;
	int C;
	cin >> C;
	int D;
	cin >> D;
	vector<int> X;
	X.push_back(int(S1[0]));
	X.push_back(int(S2[0]));
	string resultingString = S1 + S2;
	for (int i = 2; i <= N - 1; i++) {
		int Xi = ((long long)A * X[i - 1] + (long long)B * X[i - 2] + C) % D;
		X.push_back(Xi);
		char Si = char(97 + Xi % 26);
		resultingString += Si;
	}
	long long ans = 0;
	for (auto iterator = lengths.begin(); iterator != lengths.end(); iterator++) {
		int length = *iterator;
		if (length > resultingString.size()) {
			continue;
		}
		int nums[26];
		memset(nums, 0, sizeof(nums));
		for (int i = 1; i <= length - 2; i++) {
			nums[resultingString[i] - 'a'] ++;
		}
		long long hashValue = getHash(resultingString[0], resultingString[length - 1], nums);
		if (mapBetweenHashValueAndTimes.count(hashValue) != 0) {
			ans += mapBetweenHashValueAndTimes[hashValue];
			mapBetweenHashValueAndTimes.erase(hashValue);
		}
		for (int start = 1; start + length <= resultingString.length(); start++) {
			nums[resultingString[start] - 'a']--;
			nums[resultingString[start + length - 2] - 'a']++;
			long long hashValue = getHash(resultingString[start], resultingString[start + length - 1], nums);
			if (mapBetweenHashValueAndTimes.count(hashValue) != 0) {
				ans += mapBetweenHashValueAndTimes[hashValue];
				mapBetweenHashValueAndTimes.erase(hashValue);
			}
		}
	}
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