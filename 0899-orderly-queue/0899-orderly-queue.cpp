class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string minString = s;
            for (int i = 1; i < s.size(); ++i) {
                string rotatedString = s.substr(i) + s.substr(0, i);
                if (rotatedString < minString) {
                    minString = rotatedString;
                }
            }
            return minString;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};