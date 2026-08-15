class Solution {
public:
    int minInsertions(string s) {

        int n=s.size();

        int ans=0;
        int req=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(req%2!=0){
                    req--;
                    ans++;
                }
                req+=2;
            } 
            else{ 
                req--;
                if(req<0){
                    ans++;         
                    req+=2; 
                }
            }
        }
        
        return ans+req;
    }
};