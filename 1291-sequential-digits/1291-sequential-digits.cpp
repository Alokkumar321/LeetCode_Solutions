class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector <int> ans;
        string digits = "123456789";
        for(int i=0; i<digits.size(); i++){
            string count = "";
            for(int j=i; j<digits.size(); j++){
                count += digits[j];
                int num = stoi(count);
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};