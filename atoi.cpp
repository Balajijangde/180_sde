class Solution {
public:
    int myAtoi(string s) {
        int answer = 0;
        bool isNegative = false;
        bool started = false;
        bool limitReached = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ')
                if(!started)
                    continue;
                else
                    break;
            else if(s[i] == '-' && !started){
                isNegative = true;
                started = true;
            }
            else if(s[i] == '+' && !started){
                isNegative = false;
                started = true;
            }
            else{
                started = true;
                long current = s[i]-'0';
                if(current>=0 && current<=9){
                    if(((long)answer*10)+current > INT_MAX){
                        limitReached = true;
                        break;
                    }
                    answer = (answer*10)+current;
                }else{
                    break;
                }
                
            }
        }
        if(limitReached){
            if(isNegative)
                return INT_MIN;
            else
                return INT_MAX;
        }
        if(isNegative)
            answer *= -1;
        return answer;
    }
};