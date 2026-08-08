class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for(int j = 0; j < graph.size(); j++) {
            if(graph[node][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(j, graph, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for(int city = 0; city < n; city++) {
            if(!visited[city]) {
                provinces++;
                dfs(city, isConnected, visited);
            }
        }
        return provinces;
    }
};