class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        st.erase(startGene);
        while(!q.empty()) {
            string gene = q.front().first;
            int mutations = q.front().second;
            q.pop();
            if(gene == endGene) return mutations;
            for(int i = 0; i < gene.size(); i++) {
                char orig = gene[i];
                for(char ch : {'A', 'C', 'G', 'T'}) {
                    gene[i] = ch;
                    if(st.find(gene) != st.end()) {
                        q.push({gene, mutations + 1});
                        st.erase(gene);
                    }
                }
                gene[i] = orig;
            }
        }
        return -1;
    }
};