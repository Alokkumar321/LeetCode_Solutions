class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0]){
            return 0;
        }
        for(int i=0; i<nums.size(); i++){
            if(target<=nums[i]){
                return i;
            }
        }
        return nums.size();
    }
};