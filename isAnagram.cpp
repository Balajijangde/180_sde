class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26, 0);

	if (s.size() != t.size())
		return false;

	for (int i = 0; i < s.size(); i++) {
		record[s[i] - 'a'] += 1;
	}
	for (int i = 0; i < t.size(); i++) {
		record[t[i] - 'a'] -= 1;
	}
	for (int i = 0; i < record.size(); i++) {
		if (record[i] != 0)
			return false;
	}
	return true;
    }
};