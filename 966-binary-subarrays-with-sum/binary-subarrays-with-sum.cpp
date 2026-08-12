class Solution {
public:
    int func(vector<int>& nums, int goal){
        if (goal < 0) return 0;
        
        int n = nums.size();
        int r = 0, l = 0;
        int ans = 0;
        vector<int> v(2, 0);

        while (r < n) {
            v[nums[r]]++;

            while(v[1] > goal) {
                v[nums[l]]--;
                l++;
            }

            ans += r - l + 1;
            r++;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal - 1);
    }
};