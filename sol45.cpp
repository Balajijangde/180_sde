/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool compare(Job a, Job b){
        // if(a.profit >= b.profit)
        //     return a.profit>b.profit;
        // else
        //     return b.profit>a.profit;
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        if(n == 1){
            vector<int> result = {1, arr[0].profit};
            return result;
        }
        //sorting array of jobs a/c to profit decending order
        sort(arr, arr+n, compare);
        int maxDeadline = 0;
        
        //getting largest deadline among all
        for(int i=0; i<n; i++){
            if(arr[i].dead > maxDeadline)
                maxDeadline = arr[i].dead;
        }
        
        //create array with max deadline value
        int jobs[maxDeadline] = {0};
        int maxJobs, profit;
        maxJobs = profit = 0;
        
        //loop through every element in jobs array
        for(int i=0; i<n; i++){
            int deadline = arr[i].dead;
            if(jobs[deadline-1] == 0){
                jobs[deadline-1] = arr[i].id;
                maxJobs++;
                profit += arr[i].profit;
            }else{
                int point = deadline-2;
                while(point >= 0){
                    if(jobs[point] == 0){
                        jobs[point] = arr[i].id;
                        maxJobs++;
                        profit+=arr[i].profit;
                        break;
                    }else{
                        point--;
                    }
                }
            }
        }
        
        
        vector<int> result = {maxJobs, profit};
        return result;
    } 
};





