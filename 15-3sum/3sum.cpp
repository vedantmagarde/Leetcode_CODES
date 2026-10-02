class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && nums[i - 1] == nums[i])
                continue;

            int l=i+1;
            int r=n-1;

            while(l<r){
                int sum=nums[l]+nums[i]+nums[r];
                if(sum>0)r--;
                else if(sum<0)l++;
                else{
                    ans.push_back({nums[l],nums[i],nums[r]});

                    while(l<r&&nums[l]==nums[l+1])l++;
                    while(l<r&&nums[r-1]==nums[r])r--;

                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};