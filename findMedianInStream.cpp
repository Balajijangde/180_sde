class Solution
{
    public:
    //Function to insert heap.
    vector<int> minHeap;
    vector<int> maxHeap;
    void insertHeap(int &x)
    {
        if(minHeap.size() == 0 && maxHeap.size() == 0){
            maxHeap.push_back(x);
        }else if(maxHeap.size() == 1 && minHeap.size() == 0){
            int temp = maxHeap[0];
            maxHeap.pop_back();
            minHeap.push_back(max(temp, x));
            maxHeap.push_back(min(temp, x));
        }else if(minHeap.size() > maxHeap.size() && (double) x > getMedian()){
            int minHeapRoot = minHeap[0];
            maxHeap.push_back(minHeapRoot);
            balanceMaxHeap();
            minHeap[0] = (int) x;
            balanceDeletionMinHeap(0);
        }else if(maxHeap.size() > minHeap.size() && (double) x < getMedian()){
            int maxHeapRoot = maxHeap[0];
            minHeap.push_back(maxHeapRoot);
            balanceMinHeap();
            maxHeap[0] = (int) x;
            balanceDeletionMaxHeap(0);
        }else{
            double median = getMedian();
            if((double) x > median){
                minHeap.push_back((int) x);
                balanceMinHeap();
            }else{
                maxHeap.push_back((int) x);
                balanceMaxHeap();
            }
        }
    }
    void balanceDeletionMinHeap(int x){
        int element = x;
        int left = 2*element+1;
        int right = 2*element+2;
        if(left < minHeap.size() && minHeap[left] < minHeap[element]){
            element = left;
        }
        if(right < minHeap.size() && minHeap[right] < minHeap[element]){
            element = right;
        }
        if(element != x){
            swap(minHeap[x], minHeap[element]);
            balanceDeletionMinHeap(element);
        }
    }
    void balanceDeletionMaxHeap(int x){
        int element = x;
        int left = element*2+1;
        int right = element*2+2;
        if(left < maxHeap.size() && maxHeap[left] > maxHeap[element]){
            element = left;
        }
        if(right < maxHeap.size() && maxHeap[right] > maxHeap[element]){
            element = right;
        }
        if(element != x){
            swap(maxHeap[element], maxHeap[x]);
            balanceDeletionMaxHeap(element);
        }
    }
    void balanceMinHeap(){
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
    void balanceMaxHeap(){
        int element = maxHeap.size() - 1;
        int parent = (element-1)/2;
        while(parent >= 0){
            if(maxHeap[element] >maxHeap[parent]){
                swap(maxHeap[parent], maxHeap[element]);
                element = parent;
                parent = (element-1)/2;
            }else break;
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(minHeap.size() > maxHeap.size()) return (double) minHeap[0];
        else if(maxHeap.size() > minHeap.size()) return (double) maxHeap[0];
        else return (double) (minHeap[0] + maxHeap[0])/(double) 2;
    }
};