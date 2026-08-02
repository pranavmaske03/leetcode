class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int& dest) {

        path.push_back(node);
        if(node == dest)    {
            res.push_back(path);
            path.pop_back();
            return;
        }

        visited[node] = true;
        for(auto& neibour : graph[node]) {
            if(!visited[neibour]) {
                dfs(neibour, graph, path, visited, dest);
            }
        }
        path.pop_back();
        visited[node] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<bool> visited(n, false);
        int source = 0, dest = n - 1;

        dfs(source, graph, path, visited, dest);
        return res;
    }
};