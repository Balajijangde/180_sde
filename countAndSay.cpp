class Solution {
public:
    string cns(string s){
        s+="$";
        int counter = 1;
        string answer;
        for(int i=1; i<s.size(); i++){
            if(s[i] == s[i-1])
                counter++;
            else{
                answer += to_string(counter);
                answer += s[i-1];
                counter = 1;
            }
        }
        return answer;
    }
    string countAndSay(int n) {
        if(n == 1){
            string first = "1";
            return first;
        }else{
            int iter = 0;
            string term = "1";
            for(iter = 2; iter<=n; iter++){
                term = cns(term);
            }
            return term;
        }
        
            
    }
};