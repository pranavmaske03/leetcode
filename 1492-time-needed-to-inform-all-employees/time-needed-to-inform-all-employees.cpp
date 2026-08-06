class Solution {
public:
    int dfs(int node, vector<vector<int>>& graph, vector<int>& informTime) {

        int time = 0;
        for(auto& neibour : graph[node]) {
            time = max(time, dfs(neibour, graph, informTime));
        }

        return informTime[node] + time;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);

        for(int i = 0; i < manager.size(); i++) {
            if(manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        return dfs(headID, graph, informTime);
    }
};