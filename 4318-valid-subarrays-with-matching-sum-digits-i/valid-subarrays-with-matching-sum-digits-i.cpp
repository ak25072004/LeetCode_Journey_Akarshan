class Solution {
public:
    int countValidSubarrays(vector<int>& a, int x) {

        int ans=0;
        int n=a.size();

        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];

                int last = sum%10;
                long long t=sum;
                while(t >= 10) t/=10;
                int first = t;
                if(first==x and last ==x) ans++;
            }
        }
        return ans;
    }
};