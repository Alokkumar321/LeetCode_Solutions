class Solution {
public:
    int maxDepth(string s) {
        stack<char> myStack;
        int count = 0;
        int max_count = 0;
        char char_to_check = '(';
        char char_to_check2 = ')';
        
        for(int i = 0; i < s.size(); ++i) {
            myStack.push(s[i]);
            if(s[i] == char_to_check) {
                count++;
                if(count > max_count) {
                    max_count = count;
                }
            }
            else if(s[i] == char_to_check2 && count > 0) {
                count--;
            }
        }
        return max_count;
    }
};
