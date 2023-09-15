/*

- link : https://leetcode.com/problems/min-cost-to-connect-all-points/

- Kruskals to calculatae min cost of the MST , implemented using DSU 

*/

#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) x.begin(),x.end()

struct edge {
    
    int len;
    int p1;
    int p2;
};

class DSU {
   
 public: 
    vi parent;
    vi rank;
    int size = 0;
    
    DSU(int n){
        parent.resize(n, -1);
        rank.resize(n, -1);
        size = n;
    }
    
    int findParent(int u){ // O(1)
        
        return  (parent[u] < 0) ? u : parent[u] = findParent( parent[u]  );
    }
    
    bool unite(int u, int v){  // O(1)
        
        int p1 = findParent(u);
        int p2 = findParent(v);
        
        if(p1 == p2)
            return false;
        
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
            rank[p2] = 0;
        }
        else{
            parent[p1] = p2;
            rank[p2] += rank[p1];
            rank[p1] = 0;
        }
        
        size --;
        
        return true;
    }
    
    // calculate mst cost
    int MST(vector<edge>&allEdges){ // O(E)
        
        int minCost = 0, si = allEdges.size();
        for(int i=0; i<si; i++){
            
            int e1 = allEdges[i].p1;
            int e2 = allEdges[i].p2;
                
            if(unite (e1, e2)){
                minCost += allEdges[i].len;
            }
        }
        
        return minCost;
        
    }
    
};



class Solution {
public:
    

    
    int dis(vi p1, vi p2){
        
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        
    }
    
    bool static cmp(edge e1,  edge e2){
        
        return e1.len < e2.len;
    }
    
    int minCostConnectPoints(vvi& points) {
        
        int i, n = points.size(), minCost = 0;
        
        vector<edge>allEdges;
        
        // store all possible edges
        for(i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int d = dis(points[i], points[j]);
                
                edge ed;
                ed.len = d, ed.p1 = i,  ed.p2 = j;
                
                allEdges.pb(ed);
                
            }
        }
        
        sort(all(allEdges), cmp);
        
        DSU d(n);

        return d.MST(allEdges);
    }
};
