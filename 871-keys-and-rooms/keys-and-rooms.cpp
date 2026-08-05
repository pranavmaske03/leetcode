class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neighbours : rooms[node]) {
                if(!visited[neighbours]) {
                    visited[neighbours] = true;
                    q.push(neighbours);
                }
            }
        }
        for(bool isVisited : visited) {
            if(!isVisited) 
                return false;
        }
        return true;
    }
};