class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0; 
        
        if (nums.size() == 0) {
            return 0;
        }
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                ++pos;
                nums[pos] = nums[i];
            }
        }
        
        return pos+1;
    }
};