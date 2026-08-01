class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, int dest) {
        if(node == dest){
            return true;
        }
        visited[node] = true;

        for(int& vertex : graph[node]) {
            if(!visited[vertex]) {
                if(dfs(graph, visited, vertex, dest))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        return dfs(graph, visited, source, destination);
    }
};