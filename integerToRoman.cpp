class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> ref = {{"M", 1000},{"CM", 900}, {"D",500}, {"CD",400}, {"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        string answer;
        for(int i=0; i<13;i++){
            if(num>=ref[i].second){
                int quotient = num/ref[i].second;
                for(int j=0; j<quotient; j++){
                    answer += ref[i].first;
                }
                num %= ref[i].second;
            }
        }
        return answer;
    }
};