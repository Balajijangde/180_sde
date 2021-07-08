#include<iostream>
#include<string>
using namespace std;

int stepsForPalindrome(string &str){
	int low = 0;
	int high = str.size()-1;
	while(low < high){
		if(str[low] == str[high]){
			int first = low;
			int last = high;
			while(str[first] == str[last]){
				first++;
				last--;
			}
			if(first >= last){
				return str.size()-(high+1); 
			}else{
				high--;
			}
		}else{
			high--;
		}
	}
	return str.size()-1;
}

int main(){
	string s;
	getline(cin, s);
	cout<<stepsForPalindrome(s);
}