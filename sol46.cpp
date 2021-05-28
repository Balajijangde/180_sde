class Solution
{
    public:
    static bool compare(Item a, Item b){
        return (double)a.value/(double)a.weight>(double)b.value/(double)b.weight;
        
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        int curWeight = 0;
        double maxValue = 0.0;
        for(int i=0; i<n; i++){
            if(curWeight+arr[i].weight <= W){
                // W -= arr[i].weight;
                // maxValue += arr[i].value;
                curWeight += arr[i].weight;
                maxValue += arr[i].value;
            }else{
                int remain = W-curWeight;
                maxValue += (arr[i].value/(double)arr[i].weight)*(double)remain;
                break;
            }
        }
        return maxValue;
    }
        
};