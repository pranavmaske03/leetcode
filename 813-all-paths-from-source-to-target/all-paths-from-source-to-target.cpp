class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, int& dest) {
        path.push_back(node);

        if(node == dest)    {
            res.push_back(path);
        } else {
            for(auto& neibour : graph[node]) {
                dfs(neibour, graph, path, dest);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        int source = 0, dest = n - 1;

        dfs(source, graph, path, dest);
        return res;
    }
};