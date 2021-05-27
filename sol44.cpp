if(n < 2)
            return n;
            
        sort(arr, arr + n);
        sort(dep, dep + n);
        int max = 1;
        
        int j = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] > dep[j]){
                j++;
            }else if(arr[i] < dep[j]){
                max++;
                j++;
            }
        }
        return max;