class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> temp;
        vector<int> answer(heights.size(), 0); 
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            int current = heights[i];
            
            while (!temp.empty() && temp.top() < current) {
                temp.pop();
                answer[i]++; 
            }
            
            if (!temp.empty()) {
                answer[i]++;
            }
            
            temp.push(current);
        }
        
        return answer;
    }
};
