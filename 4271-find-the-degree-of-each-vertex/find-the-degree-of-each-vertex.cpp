class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int V = matrix.size();
        vector<int> degree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1) {
                    degree[j]++;
                }
            }
        }
        return degree;
    }
};