class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int duplicate;
        int missing;
        for(int i=1;i<=nums.size();i++){
            if(mpp[i]==2){
                duplicate=i;
            }
            else if(mpp[i]==0){
                missing=i;
            }
        }
        ans.push_back(duplicate);
        ans.push_back(missing);   
        return ans;
        }
    
    
    
};