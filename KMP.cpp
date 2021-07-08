#include<bits/stdc++.h>
using namespace std;
int kmp(string &t, string &p){
	vector<pair<char, int>> les;
	unordered_map<char, int> record;

	les.push_back({'0', 0});
	for(int i=0; i<p.size(); i++){
		if(record.find(p[i]) != record.end()){
			les.push_back({p[i], record[p[i]]});
			record[p[i]] = i+1;
		}else{
			//char not found
			les.push_back({p[i], 0});
			record.insert({p[i], i+1});
		}
	}
	int i = 0;
	int j = 0;
	while(i<t.size()){
		if(t[i] == les[j+1].first){
			i++;
			j++;
		}else{
			if(j == 0){
				i++;
			}
			j = les[j].second;
		}
		if(j == les.size()-1 && les[j].first == t[i-1]){
				return i-p.size();
			}
	}
	return -1;

}
int main(){

	string text = "ababcabcabababd";
	string patt = "ababd";
	cout<<kmp(text, patt);
}