class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {// TC : O(N) & SC : O(1)

        int maxSeen = 0;
        int cnt = 0;

        for(int i=0;i<arr.size();i++){

            maxSeen = max(maxSeen,arr[i]);

            if(maxSeen == i){
                cnt++;
            }
        }

        return cnt;
    }
};