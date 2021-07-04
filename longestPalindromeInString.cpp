class Solution {
public:
bool checkPalindrome(vector<vector<bool>> &dp, string &s, int start, int end) {
    if (end - 1 == start) {
        if (s[start] == s[end]) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (s[start] == s[end] && dp[start + 1][end - 1] == true) {
            return true;
        }
        else {
            return false;
        }
    }
}
string longestPalindrome(string s) {
    string result;
    int start = 0;
    int end = 0;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < dp.size(); i++) {
        dp[i][i] = true;
    }
    //filling the dp table
    for (int sub = 1; sub < dp.size(); sub++) {
        for (int i = 0; i < dp.size() - sub; i++) {
            dp[i][i + sub] = checkPalindrome(dp, s, i, i + sub);
        }
    }
    //searching for palindromic part
    for (int sub = dp.size() - 1; sub >= 0; sub--) {
        for (int i = 0; i < dp.size(); i++) {
            if (i + sub >= dp.size())
                break;
            if (dp[i][i + sub] == true) {
                start = i;
                end = i + sub;
                goto evaluate;
            }
        }
        
    }
    evaluate:
    for (int i = start; i <= end; i++) {
        result += s[i];
    }
    return result;
}
};