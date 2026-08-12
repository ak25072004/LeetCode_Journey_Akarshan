class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n%3!=0) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            vector<int> temp;
            if(nums[i+2] - nums[i] <=k)
            {
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                ans.push_back(temp);
                i = i+2;
            }
            else
            {
                vector<vector<int>>arr;
                return arr;
            }
        }
        return ans;
    }
};