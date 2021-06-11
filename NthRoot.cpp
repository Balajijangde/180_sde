class Solution{
	public:
	int NthRoot(int n, int m)
	{
	   if (n == 1)
		return m;
	vector<int>  record(m + 1);
	for (int i = 0; i <= m; i++) {
		record.push_back(i);
	}
	int low = 0;
	int high = record.size() - 1;
	int mid = 0;
	while (low <= high) {
		mid = low + (high-low) / 2;
		
		//if mid is greater
		if (pow(record[mid], n) > m) {
			high = mid-1;
		}
		//if mid is smaller
		else if (pow(record[mid], n) < m) {
			low = mid+1;
		}
		//if mid is value we want
		else if (pow(record[mid], n) == m) {
			return record[mid];
		}
		//if mid is equal to low or mid
		
	}
	return -1;
	}  
};