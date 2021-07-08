#include<bits/stdc++.h>
using namespace std;
vector<int> zAlgorithm(string &text, string &pattern) {
	string demoText = pattern +"$"+text;
	vector<int> answer;
	int i = 0;
	int j = 0;
	vector<int> record;
	while (j < demoText.size()) {
		if (j == 0) {
			record.push_back(0);
			j++;
			continue;
		}
		if (demoText[i] == demoText[j]) {
			int first = i;
			int second = j;
			while (demoText[first] == demoText[second]) {
				first++;
				second++;
			}
			i = 0;
			record.push_back(first);
			j++;
		}else {
			record.push_back(0);
			j++;
		}
	}
	for (int i = 0; i < record.size(); i++) {
		if (record[i] == pattern.size()) {
			answer.push_back(i-(pattern.size()+1));
		}
	}
	return answer;
}
int main() {
	string text = "acabababca";
	string pattern = "aba";
	zAlgorithm(text, pattern);
}