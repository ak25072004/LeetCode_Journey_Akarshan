class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n=A.size();

        sort(A.begin(),A.end());

        vector<pair<int,int>> b;
        for(int i=0;i<n;i++)
            b.push_back({B[i], i});

        sort(b.begin(), b.end());

        vector<int> ans(n);

        int l = 0;
        int r = n - 1;

        for(int a : A){
            if(a > b[l].first){
                ans[b[l].second] = a;
                l++;
            } else {
                ans[b[r].second] = a;
                r--;
            }
        }

        return ans;
    }
};