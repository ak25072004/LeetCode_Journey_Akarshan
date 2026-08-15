class Solution {
public:
    string toHex(unsigned int num) {
        std::string ans;
        if (num != 0) {
            while (num != 0) {
                int group = num & 0b1111;
                ans += (group > 9) ? (group + 87) : (group + '0');
                num = num >> 4;
            }
        } else {
            return "0";
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};