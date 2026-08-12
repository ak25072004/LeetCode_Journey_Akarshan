const int FAIL_LO=-1, FAIL_HI=1e5+1;
int dp[2][20001];
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=arr.size(), ans=1;
        map<int, int> sts;
        map<int, int>::iterator it;
        sts[arr[n-1]]=n-1;
        dp[0][n-1]=dp[1][n-1]=true;
        sts[FAIL_LO]=sts[FAIL_HI]=n;
        dp[0][n]=dp[1][n]=false;        
        for(int i=n-2; i>=0; --i) {
            it=sts.lower_bound(arr[i]);
            ans+=dp[1][i]=dp[0][it->second];
            dp[0][i]= it->first==arr[i] ? dp[1][it->second] : dp[1][(--it)->second];
            sts[arr[i]]=i;
        }
        return ans;
    }
};