class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        // for(i=0;i<nums.size();i++){
        //     if(nums[i]==1){

        //     }
        // }
        int i = 0, count = 0;
        while (i < nums.size()) {
            if (nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }
            ans = max(ans, count);
            i++;
        }
        return ans;
    }
};