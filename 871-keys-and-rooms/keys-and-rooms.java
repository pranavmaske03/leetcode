class Solution {
    public void DFS(List<List<Integer>> grid, boolean[] visited, int node) {
        visited[node] = true;

        for (int neighbour : grid.get(node)) {
            if(visited[neighbour] == false) {
                DFS(grid, visited, neighbour);
            }
        }
    }

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] visited = new boolean[n];

        DFS(rooms, visited, 0);
        for(boolean node : visited) {
            if(node == false)
                return false;
        }
        return true;
    }
}