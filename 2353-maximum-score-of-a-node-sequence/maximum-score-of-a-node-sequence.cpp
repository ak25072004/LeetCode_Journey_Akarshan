class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int N = scores.size();
        vector<vector<int>> G(N);
        vector<array<int, 3>> best(N, array<int, 3>{-1, -1, -1});
        for (const auto& e : edges) {
            G[e[0]].emplace_back(e[1]);
            G[e[1]].emplace_back(e[0]);
        }
        for (int i = 0; i < N; ++i) {
            for (const int neigh : G[i]) {
                auto& heap = best[i];
                if (heap[0] == -1 || scores[neigh] >= scores[heap[0]]) {
                    heap[2] = heap[1];
                    heap[1] = heap[0];
                    heap[0] = neigh;
                }
                else if (heap[1] == -1 || scores[neigh] >= scores[heap[1]]) {
                    heap[2] = heap[1];
                    heap[1] = neigh;
                }
                else if (heap[2] == -1 || scores[neigh] > scores[heap[2]]) {
                    heap[2] = neigh;
                }
            }
        }
        int ret = -1;
        for (int i = 0; i < N; ++i) {
            for (const int neigh : G[i]) {
                for (const int cur_best : best[i]) {
                    if (cur_best == -1) { break; }
                    for (const int neigh_best : best[neigh]) {
                        if (neigh_best == -1) { break; }
                        if (cur_best != neigh && cur_best != neigh_best && neigh_best != i) {
                            ret = max(ret, scores[i] + scores[neigh] + scores[cur_best] + scores[neigh_best]);
                        }
                    }
                }
            }
        }
        return ret;
    }
};