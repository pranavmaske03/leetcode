class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if(state[node] == 1)
            return false;
        if(state[node] == 2)
            return true;
        if(state[node] == 3)
            return false;

        state[node] = 1;
        for(int neighbour : graph[node]) {
            if(!dfs(neighbour, graph, state)) {
                state[node] = 3;
                return false;
            }
        }
        
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, state))
                res.push_back(i);
        }
        return res;
    }
};