class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }
        
        if (pos == -1) return; 
        
        for (int i = pos + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];
                nums[i] = 0;
                for (int j = pos + 1; j < nums.size(); j++) {
                    if (nums[j] == 0) {
                        pos = j;
                        break;
                    } 
                }
            }
                            
        }
    }
};