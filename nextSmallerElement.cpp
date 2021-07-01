#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> result(arr.size(), 0);
    stack<int> mystack;
    for(int i=arr.size()-1; i>= 0; i--){
        if(!mystack.empty()){
            while(!mystack.empty() && mystack.top()>=arr[i]){
                mystack.pop();
            }
            if(mystack.empty()){
                mystack.push(arr[i]);
                result[i]  = -1;
            }else{
                result[i] = mystack.top();
                mystack.push(arr[i]);
            }
            
        }else{
            mystack.push(arr[i]);
            result[i] = -1;
        }
    }
    return result;
}