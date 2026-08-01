class Solution {
public:
    void bfs(int city, vector<vector<int>>& graph, vector<bool>& visited) {
        int n = graph.size();
        queue<int> q;

        q.push(city);
        visited[city] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int i = 0; i < n; i++) {
                if(graph[node][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
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
                bfs(city, isConnected, visited);
            }
        }
        return provinces;
    }
};