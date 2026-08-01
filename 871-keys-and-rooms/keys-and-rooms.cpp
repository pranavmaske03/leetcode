class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for(auto& neighbours : graph[node]) {
            if(!visited[neighbours]) {
                dfs(neighbours, graph, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);
        for(auto val : visited) {
            if(!val) 
                return false;
        }
        return true;
    }
};