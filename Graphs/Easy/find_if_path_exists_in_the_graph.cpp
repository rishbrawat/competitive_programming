class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // premature check
        if(source == destination) return true;

        // first we need to build an adjacency list for the given edges
        vector<vector<int>> adj(n);
        for(const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        visited[source] = true;
        q.push(source);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int x: adj[curr]) {
                if(x == destination) return true;

                if(!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }

        return false;
    }
};