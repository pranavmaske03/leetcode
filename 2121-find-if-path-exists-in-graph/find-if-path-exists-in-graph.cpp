class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == destination) {
                return true;
            }
            for(int& vertex : graph[node]) {
                if(!visited[vertex]) {
                    q.push(vertex);
                    visited[vertex] = true;
                }
            }
        }
        return false;
    }
};