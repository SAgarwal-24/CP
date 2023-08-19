
/*
https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
- awesome problem involves 
- force addition and exclusion (of edges) operation in MST algo like kruskals

helpful resource - https://www.youtube.com/watch?v=zl-rLRPpl_s

Time :  O(E^2)           E->no of edges
      - kruskals take O(E) to find MST 

Space : O(nodes) - for parent and rank array while using union and find 

*/

#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl

template <typename C,
          typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
          typename std::enable_if<!std::is_same<C, std::string>::value>::type * = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container)
{
    bool first = true;
    std::stringstream ss;
    ss << '[';
    for (const auto &x : container)
    {
        if (!first)
        {
            ss << ", ";
        }
        first = false;
        ss << x;
    }
    ss << ']';
    return os << ss.str();
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << '{' << p.first << ", " << p.second << '}';
    return os;
}


class Tree {
    
   

    public:
    int size = 0;
    vi parent;
    vi rank;
  
    Tree(int numNodes) {
        parent.resize(numNodes, -1);
        rank.resize(numNodes, -1);
        size = numNodes;
    }
    
    int findParent(int x){  // O(1)  - bcz of path compression  
        return parent[x] < 0 ? x : parent[x] = findParent(parent[x]);
    }
  
    bool unionComponents(int x, int y){ // O(1)
        
        int p1 = findParent(x);
        int p2 = findParent(y);
        
        if(p1 == p2)
            return false;
        
        // union by rank
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
    
    bool compEdges(vi ed1, vi ed2){
        
        int n1 = ed1.size(),  n2 = ed2.size();
        return (n1 >= 2 && n2>=2 && ed1[0] == ed2[0] && ed1[1] == ed2[1]);
    }
    
    int MST(int n, vvi &edges, vi includeEdge, vi excludeEdge){ // O(E)
        
        int mstCost = 0;
        
        if( includeEdge.size()>=3 && unionComponents(includeEdge[0], includeEdge[1]) ){
            mstCost += includeEdge[2];
        }
        
        for(auto ed: edges){ // O(E)
            
            int x = ed[0], y = ed[1], wt = ed[2];
            
            if( !compEdges(ed , excludeEdge) && unionComponents(x, y)){                     
                mstCost += wt;
            }
        }
        
        return size == 1 ? mstCost : INT_MAX;
    }
};

class Solution {
public:
    
    bool static cmp(vi a, vi b){
        return a[2] < b[2];
    }
    
 

    vvi findCriticalAndPseudoCriticalEdges(int n, vvi& edges) {
        
        Tree t (n);
        vi criticalEdges, pseudoCriticalEdges;
        
        map<vi, int>edgeIndexMap;
        for(int i=0; i<edges.size(); i++){ // O(E)
            edgeIndexMap[edges[i]] = i;
        }
        
        sort(all(edges), cmp);// O(Elog(E))
        
        
        int minCost = t.MST(n, edges, {}, {}); // O(E)
        
        
        for(auto ed: edges){ // O(E^2)
    
            Tree incl(n), excl(n);
        
            int excludeCost = incl.MST(n, edges, {}, ed); // O(E)
           
            
            if(excludeCost > minCost){  // then -> this is a : critical edge
                criticalEdges.pb(edgeIndexMap[ed]); 
            }
            else{
          
                int includeCost = excl.MST(n, edges, ed, {});  // O(E)
               
                if(includeCost == minCost){ // then -> this is a : pseudo critical edge
                    pseudoCriticalEdges.pb(edgeIndexMap[ed]);
                }
            }
            
            
        }
        
        
        return  {criticalEdges, pseudoCriticalEdges};
    }
};

/*
5
[[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
4
[[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
2
[[0,1,1]]
3
[[0,1,1],[0,2,1],[1,2,2]]
3
[[0,1,1],[0,2,1],[1,2,1]]
6
[[0,1,1],[1,2,1],[0,2,1],[2,3,4],[3,4,2],[3,5,2],[4,5,2]]

*/
