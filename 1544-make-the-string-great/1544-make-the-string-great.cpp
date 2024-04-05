class Solution {
public:
    string makeGood(string s) {
        stack<char> my_stack;
        for (char c : s) {
            if (!my_stack.empty() && tolower(my_stack.top()) == tolower(c) && my_stack.top() != c) {
                my_stack.pop();
            } else {
                my_stack.push(c);
            }
        }
        string result = "";
        while (!my_stack.empty()) {
            result = my_stack.top() + result;
            my_stack.pop();
        }

        return result;
    }
};