#include<bits/stdc++.h>
using namespace std;
int givenXor(vector<int> &numbers, int k){
    int preXor = 0;
    int count = 0;
    unordered_map<int, int> ele;
    for(int i=0; i<numbers.size(); i++){
        preXor = preXor ^ numbers[i];
        if(ele.find(preXor) == ele.end()){
            ele[preXor] = 1;
        }else{
            ele[preXor] = ele[preXor]+1;
        }
        if(preXor == k){
            count++;
        }else{
            int wanted = k^preXor;
            if(ele.find(wanted) != ele.end()){
                count += ele[wanted];
            }
        }
    }
    
    cout<<count;
}
int main(){
    vector<int> numbers{4, 2, 2, 6, 4};
    int k = 6;
    givenXor(numbers, k);
    return 0;
}