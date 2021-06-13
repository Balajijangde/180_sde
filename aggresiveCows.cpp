#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<int> &nums, int cows, int distance){
	int last = 0;
	for(int i=0; i<nums.size(); i++){
		if(nums[i]-last >= distance){
			cows--;
			if(cows == 0)
				return true;
			last = nums[i];
		}
	}
	return cows == 0;
}
int aggrcow(vector<int> &nums, int cows, int N){
	if(cows > N) return -1;
	sort(nums.begin(), nums.end());
	int low = 0;
	int high = 1e9;
	
	int mid = 0;
	while(low <= high){
		mid = (low+high)/2;
		if(isPossible(nums, cows, mid)) low = mid +1;
		else high = mid -1;	
	}
	return low;
}
int main(){
	int test;
	cin >> test;
	while(test--){
		int N, C;
		cin >>N>>C;
		vector<int> n;
		for(int i=0; i<N; i++){
			int entry;
			cin>>entry;
			n.push_back(entry);
		}
		cout<<aggrcow(n, C, N)<<endl;
	}
}