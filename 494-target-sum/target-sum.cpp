class Solution {
    unordered_map<string,int> mem;
    long long ways(vector<int>& nums,int n,int sum,int S,int pos)
    {
        if(n==pos)
            return sum==S?1:0;
        string key = to_string(pos) + "*" + to_string(sum);
        if(mem.find(key)!=mem.end())
            return mem[key];
        
        return mem[key] = ways(nums,n,sum+nums[pos],S,pos+1) + ways(nums,n,sum-nums[pos],S,pos+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if(n==0)
            return 0;
        
        return ways(nums,n,nums[0],S,1) + ways(nums,n,-nums[0],S,1);
    }
};