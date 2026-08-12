class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        
        unordered_set<string> st = {""};
        
        string longest = "";
        
        for (int i = 0; i < words.size(); i++) {
            string prefix = words[i].substr(0, words[i].size() - 1);
            
            if (st.find(prefix) != st.end()) {
                st.insert(words[i]);
                
                if (words[i].size() > longest.size()) {
                    longest = words[i];
                }
            }
        }
        
        return longest; 
    }
};