class Solution {
public:
    string reverseString(string s, int lo, int hi) {
        string result;
        while (lo <= hi) {
            result += s[hi--];
        }
        return result;
    }
    string reverseWords(string s) {
        string result;
        bool started = false;
        int start = -1;
        int end = -1;
        for (int i = 0; i < s.size(); i++) {
            if (!started) {
                //got starting point
                if ((i == 0 && s[i] != ' ') || (i != 0 && s[i] != ' ' && s[i - 1] == ' ')) {
                    start = i;
                    started = true;
                }
            }
            if(started) {
                if (i == s.size() - 1 && s[i] != ' ') {
                    end = i;
                    started = false;

                }
                else if (s[i] == ' ' && s[i - 1] != ' ') {
                    end = i - 1;
                    started = false;
                }

            }
            if (start != -1 && end != -1) {
                result += reverseString(s, start, end);
                result += ' ';
                start = -1; end = -1;
            }
        }
        return reverseString(result, 0, result.size() - 2);
    }
};