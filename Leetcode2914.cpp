class Solution {
public:
    int minChanges(string s) {
        int currentChar = s[0];
        int subLength = 1;
        int changes = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == currentChar) {
                subLength++;
                continue;
            }
            if (subLength % 2 == 0) {
                currentChar = s[i];
                subLength = 1;
            } else {
                changes++;
                subLength++;
            }
        }
        return changes;
    }
};
