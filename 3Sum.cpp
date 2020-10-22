class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int start = i+1;
            int stop = n-1;
            while(start<stop){
                if(nums[start]+nums[stop] == -nums[i]){
                    ans.push_back({nums[start++],nums[stop--],nums[i]});
                    while(start<stop && nums[start]==nums[start-1]) start++;
                    while(start<stop && nums[stop]==nums[stop+1]) stop--;
                }
                else if( nums[start]+nums[stop] < -nums[i])
                    start++;
                else
                    stop--;
            }
        }
        return ans;
    }
};