class Solution {
public:
    bool isValid(string s) {
        stack<char> rec;
        char a = '(';
        char b = '{';
        char c = '[';
        char x = ')';
        char y = '}';
        char z = ']';
        for(int i=0; i<s.size(); i++){
            
            char t = s[i];
            if(t == a || t == b || t == c){
                rec.push(s[i]);
            }else{
                if(rec.empty())
                    return false;
                if(t == x){
                  if(rec.top() == a){
                            rec.pop();
                        }else{
                            return false;
                        }  
                }else if(t == y){
                    if(rec.top() == b){
                            rec.pop();
                        }else{
                            return false;
                        }
                }else if(t == z){
                    if(rec.top() == c){
                            rec.pop();
                        }else{
                            return false;
                        }
                }
                
                
            }
        }
        if(rec.empty()){
            return true;
        }
        return false;
    }
};