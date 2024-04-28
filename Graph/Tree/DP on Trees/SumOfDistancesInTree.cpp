class Solution {
public:
    #define vvi vector<vector<int>>
    #define vi vector<int>
    #define pb push_back

    void dfs(int src, int par, vi &dist, vi &cntSubtree, map<int, vi> &adj){

        for(auto nbr: adj[src]){

            if(nbr == par)
                continue;

            dfs(nbr, src, dist, cntSubtree, adj);
            cntSubtree[src] +=  cntSubtree[nbr];
            dist[src] += dist[nbr] + cntSubtree[nbr];

        }
    }

    void dfsAdjust(int nodes,int src, int par, vi &dist, vi &cntSubtree, map<int, vi> &adj){

        for(auto nbr: adj[src]){

            if(nbr == par)
                continue;

            // dist[nbr] = distance[src] - removeExtraDistance(w.r.t nbr)  + (increament of 1 from of all nodes which doesn't belong to subtree of nbr)
            dist[nbr] = ( dist[src] - cntSubtree[nbr]) + (nodes - cntSubtree[nbr]);
            dfsAdjust(nodes, nbr, src, dist, cntSubtree, adj);
            

        }
    }

    vi sumOfDistancesInTree(int n, vvi& edges) {
        
        map<int, vi> adj;

        for(auto ed: edges){
            int u = ed[0], v = ed[1];

            adj[u].pb(v);
            adj[v].pb(u);
        }

        vi dist(n, 0),  cntSubtree(n, 1);

        dfs(0, -1, dist, cntSubtree, adj);
        dfsAdjust(n,0, -1, dist, cntSubtree, adj);
      
        return dist;
    }
};
