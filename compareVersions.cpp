class Solution {
public:
    int compareVersion(string version1, string version2) {
        // int onecr = 0;
        // int twocr = 0;
        // while(true){
        //     int oneptr = 0;
        //     int twoptr = 0;
        //     //getting revision from first
        //     while(version1[oneptr] != '.' && oneptr<version1.size() ){
        //         int digit = version1[oneptr] - '0';
        //         onecr = onecr*10+digit;
        //     }
        //     //getting revision from second
        //     while(version2[twoptr] != '.' && twoptr<version2.size()){
        //         int digit = version2[twoptr] - '0';
        //         twocr = twocr*10+digit;
        //     }
        //     //got revision from both not compare them
        //     if(oneptr < version1.size() && twoptr<version2.size()){
        //         if(onecr > twocr)
        //             return 1;
        //         else if(onecr < twocr)
        //             return -1;
        //         else{
        //             onecr = 0;
        //             twocr = 0;
        //             oneptr++;
        //             twoptr++;
        //         }
        //     }
        // }
        vector<int> ver1rec;
        vector<int> ver2rec;
        //create record for version1
        int digit1 = 0;
        for(int i=0; i<version1.size(); i++){
            if(version1[i] != '.'){
                 digit1 = digit1*10+(version1[i]-'0');
            }else{
                ver1rec.push_back(digit1);
                digit1 = 0;
            }
        }
        ver1rec.push_back(digit1);
        //creating record for version2
        int digit2 = 0;
        for(int i=0; i<version2.size(); i++){
            if(version2[i] != '.'){
                digit2 = digit2*10+(version2[i]-'0');
            }else{
                ver2rec.push_back(digit2);
                digit2 = 0;
            }
        }
        ver2rec.push_back(digit2);
        //compare both of them
        for(int i=0; i<min(ver1rec.size(), ver2rec.size()); i++){
            if(ver1rec[i] > ver2rec[i])
                return 1;
            else if(ver1rec[i] < ver2rec[i])
                return -1;
        }
        
        if(ver1rec.size() > ver2rec.size()){
            for(int i=ver2rec.size(); i<ver1rec.size(); i++){
                if(ver1rec[i] > 0)
                    return 1;
            }
        }else if(ver1rec.size() < ver2rec.size()){
            for(int i=ver1rec.size(); i<ver2rec.size(); i++){
                if(ver2rec[i] > 0)
                    return -1;
            }
        }
        return 0;
    }
};