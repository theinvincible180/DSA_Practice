class Solution {
public:
    int traversal(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;
        for(int i = 0 ; i < adj[node].size() ; i++){
            int nbr = adj[node][i];

            if(nbr == parent) continue;

            int temp = traversal(nbr, node, adj, hasApple);

            if(temp > 0 || hasApple[nbr]) time += temp + 2;
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];

            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        return traversal(0, -1, adj, hasApple);
    }
};