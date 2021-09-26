class KthLargest {
public:
    int size = 0;
    vector<int> minHeap;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i=0; i<nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(minHeap.size() < size){
            minHeap.push_back(val);
            balanceInsertion();
        }else{
            if(val > minHeap[0]){
                minHeap[0] = val;
                balanceDeletion(0);
            }
        }
        return minHeap[0];
        
    }
    void balanceInsertion(){
        int element = minHeap.size() - 1;
        int parent = (element-1)/2;
        
        while(parent >= 0){
            if(minHeap[parent] > minHeap[element]){
                swap(minHeap[parent], minHeap[element]);
                element = parent;
                parent = (element-1)/2;
            }else break;
        }
    }
    void balanceDeletion(int x){
        int element = x;
        int left = element*2 + 1;
        int right = element*2 + 2;
        if(left < minHeap.size() && minHeap[left] < minHeap[element]) element = left;
        if(right < minHeap.size() && minHeap[right] < minHeap[element]) element = right;
        if(element != x){
            swap(minHeap[element], minHeap[x]);
            balanceDeletion(element);
        }
    }
};