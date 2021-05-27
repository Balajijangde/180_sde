class Solution
{
    public:
    struct meeting{
        int start;
        int end;
        int index;
    };
    static bool comparator(struct meeting a, meeting b){
        if(a.end != b.end)
            return a.end<b.end;
        else
            return a.index<b.index;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    { 
        if(n<2)
            return n;
        //adding meetings into meeting array
        struct meeting meets[n];
        for(int i=0; i<n; i++){
            meets[i].start = start[i];
            meets[i].end = end[i];
            meets[i].index = i+1;
        }
        //sorting meeting
        sort(meets, meets+n, comparator);
        int numbers = 0;
        int lastEndTime = 0;
        for(int i=0; i<n; i++){
            if(i == 0){
                numbers++;
                lastEndTime = meets[i].end;
            }
                
            //if meeting starting point is greater then ending time of previous meeting
            if(meets[i].start > lastEndTime){
                numbers++;
                lastEndTime = meets[i].end;
            }
                
        }
        return numbers;
    }
};