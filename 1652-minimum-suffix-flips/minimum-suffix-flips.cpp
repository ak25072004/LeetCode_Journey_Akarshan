class Solution {
public:
    int minFlips(string target) {
        int minCount = 0;
        int flag = 0;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            if (target[i] != (flag % 2 + '0')) {
                minCount++;
                flag++;
            }
        }

        return minCount;
    }
};