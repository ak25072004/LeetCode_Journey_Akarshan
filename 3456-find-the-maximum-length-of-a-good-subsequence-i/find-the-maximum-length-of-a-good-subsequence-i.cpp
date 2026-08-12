int dp[5000][51];
class Solution {
public:
int maximumLength(vector<int>& nums, int k) {
    int res = 0, max_k[51] = {};
    map<int, int> next_ind;
    for (int i = nums.size() - 1; i >= 0; --i) {
        auto it = next_ind.find(nums[i]);
        int p = it != end(next_ind) ? it->second : i;
        for (int j = k; j >= 0; --j) {
            dp[i][j] = max(
                1 + (i != p ? dp[p][j] : 0),
                1 + (j ? max_k[j - 1] : 0));
            max_k[j] = max(max_k[j], dp[i][j]);  
        }     
        next_ind[nums[i]] = i;
        res = max(res, dp[i][k]);
    } 
    return res;
}
};