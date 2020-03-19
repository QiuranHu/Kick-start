#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<unordered_map>
using namespace std;

char str[1000010];
int X[1000010];

const int SEED = 13331;
unsigned long long getHash(char start, char end, int num[]) {
	unsigned long long ret = start * SEED + end;
	for (int i = 0; i < 26; i++) {
		ret = ret * SEED + num[i];
	}
	return ret;
}

char dict[100010];
unsigned long long dictHash[20010];
int num[26];
int Len[20010];

int main() {
	int T;
	int iCase = 0;
	cin >> T;
	while (T--) {
		iCase++;
		int L;
		cin >> L;
		int totLen = 0;
		for (int i = 0; i < L; i++) {
			cin >> dict; // dict is one word in the dictionary
			int len = strlen(dict); // len is the length of that one word dict
			memset(num, 0, sizeof(num)); // Initialize the array num to be an array of 26 0
			for (int j = 1; j < len - 1; j++) {
				num[dict[j] - 'a'] ++; // To calculate how many times every character appears except for first letter and last letter
			}
			dictHash[i] = getHash(dict[0], dict[len - 1], num); // Get the hash value from the first letter, last letter and num
			Len[totLen++] = len; // totLen == i. Len[i] means the the length of i-th word in the dictionary.
		}
		int N, A, B, C, D;
		cin >> str[0];
		cin >> str[1];
		cin >> N;
		cin >> A;
		cin >> B;
		cin >> C;
		cin >> D;
		// str is the resulting string. The index between 0(inclusive) and N(exclusive) is valid. 
		// N is the length of the resulting string.
		X[0] = str[0];
		X[1] = str[1];
		for (int i = 2; i < N; i++) {
			X[i] = ((long long) A * X[i - 1] + (long long)B * X[i - 2] + C) % D;
			str[i] = (char)(97 + X[i] % 26);
		}
		str[N] = 0;
		// Len[i] means the the length of i-th word in the dictionary.
		// totLen is the length of the array Len
		sort(Len, Len + totLen);
		totLen = unique(Len, Len + totLen) - Len;
		// After this, totLen is the number of unique elements in array Len.

		unordered_map<unsigned long long, int> mp;
		// This is a map between hash value of a word in the dictionary and the number of times it appears in the dictionary.
		// Words of same hash value could appears in the dictionary.
		for (int i = 0; i < L; i++) {
			// L is the number of words in the dictionary
			// dictHash[i] is the hash value of i-th word
			mp[dictHash[i]] ++;
		}
		int ans = 0;
		// ans is the answer: how many words in the dictionary appears in the string
		for (int j = 0; j < totLen; j++) {
			int len = Len[j];
			// Get a length of a word in the dictionary
			if (len > N) {
				// The length of that word is greater than the string, continue
				continue;
			}
			// Get us a array of 26 0s
			memset(num, 0, sizeof(num));
			// Start from word at [0, len]
			for (int i = 1; i < len - 1; i++) {
				num[str[i] - 'a']++;
			}
			// Get the hash value of the starting word
			unsigned long long tmp1 = getHash(str[0], str[len - 1], num);
			// If the hash value appears in map, add the number of time it appears to the answer.
			if (mp.count(tmp1)) {
				ans += mp[tmp1];
				mp.erase(tmp1);
				// We have to delete this hash value in the map, because we have already count this hash value
			}
			for (int i = len; i < N; i++) {
				// Change the start and end of the index of the word
				num[str[i - 1] - 'a'] ++;
				num[str[i - len + 1] - 'a']--;
				// Calculate the hash value and see if it appears in the string
				unsigned long long tmp = getHash(str[i - len + 1], str[i], num);
				if (mp.count(tmp)) {
					ans += mp[tmp];
					mp.erase(tmp);
				}
			}
		}
		cout << "Case #" << iCase <<": "<< ans <<endl;
	}
	return 0;
}