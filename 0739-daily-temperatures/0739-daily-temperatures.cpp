class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        stack<int> helperStack;
        int n = temperatures.size();
        vector<int> result(n, 0);
        
        for(int index = n-1; index >= 0; index--) {
            while(!helperStack.empty() && temperatures[index] >= temperatures[helperStack.top()]) {
                helperStack.pop();
            }
            if(!helperStack.empty()) {
                result[index] = helperStack.top() - index;
            }
            helperStack.push(index);
        }
        return result;
    }
};
