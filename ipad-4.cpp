#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void solve(int caseNum) {
	int N;
	cin >> N;
	vector<vector<int>> graph;
	for (int i = 0; i < N; i++) {
		graph.push_back(vector<int>());
	}
	vector<int> degrees;
	for (int i = 0; i < N; i++) {
		degrees.push_back(0);
	}

	for (int i = 0; i < N; i++) {
		int xi;
		int yi;
		cin >> xi;
		cin >> yi;
		xi -= 1;
		yi -= 1;
		degrees[xi]++;
		degrees[yi]++;
		graph[xi].push_back(yi);
		graph[yi].push_back(xi);
	}
	vector<int> degreeOne;
	for (int i = 0; i < N; i++) {
		if (degrees[i] == 1) {
			degreeOne.push_back(i);
		}
	}
	while ((int)(degreeOne.size()) != 0) {
		int sizeOfDegreeOne = degreeOne.size();
		for (int i = 0; i < sizeOfDegreeOne; i++) {
			int sizeOfNodes = graph[degreeOne[i]].size();
			degrees[degreeOne[i]] = 0;
			for (int j = 0; j < sizeOfNodes; j++) {
				int node = graph[degreeOne[i]][j];
				degrees[node] --;
			}
		}
		degreeOne.clear();
		for (int i = 0; i < N; i++) {
			if (degrees[i] == 1) {
				degreeOne.push_back(i);
			}
		}
	}
	vector<int> results;
	for (int i = 0; i < N; i++) {
		results.push_back(-1);
	}
	unordered_set<int> s;
	vector<int> nodesForBFS;
	for (int i = 0; i < N; i++) {
		if (degrees[i] == 2) {
			results[i] = 0;
			nodesForBFS.push_back(i);
			s.insert(i);
		}
	}
	int cur = 1;
	while (true) {
		if (int(s.size()) == N) {
			break;
		}
		vector<int> newNodes;
		for (int i = 0; i < int(nodesForBFS.size()); i++) {
			int node = nodesForBFS[i];
			for (int j = 0; j < int(graph[node].size()); j++) {
				int nodeToCalculate = graph[node][j];
				if (s.find(nodeToCalculate) != s.end()) {
					continue;
				}
				else {
					s.insert(nodeToCalculate);
					results[nodeToCalculate] = cur;
					newNodes.push_back(nodeToCalculate);
				}
			}
		}
		cur += 1;
		nodesForBFS = newNodes;
	}
	cout << "Case #" << caseNum << ":";
	for (int i = 0; i < N; i++) {
		cout << " " << results[i];
	}
	cout << endl;

}

int main() {
	int T; // T test cases follow
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++) {
		solve(caseNum);
	}
	return 0;
}