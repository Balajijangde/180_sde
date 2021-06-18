#include<bits/stdc++.h>
using namespace std;
class Queue{
public:
	int data[10] = {0};
	int count = 0;
	int front = -1;
	int back = 0;
	void push(int x){
		if(count == 0){
			data[back++] = x;
			front++;
			count++;
		}else{
			data[back++] = x;
			count++;
		}
	}
	int pop(){
		if(count>0){
			count--;
			int res = data[front];
			data[front++] = 0; 
			return res;
		}
	}
};

int main(){
	Queue trial;
	trial.push(1);
	trial.push(2);
	trial.push(3);
	trial.push(4);
	trial.push(5);
	trial.pop();
	trial.pop();
	trial.pop();
	trial.pop();
	trial.pop();
	trial.pop();
	trial.push(10);
	for(int x: trial.data){
		cout<<x<<" ";
	}
	cout<<endl<<trial.count;
	return 1;
}