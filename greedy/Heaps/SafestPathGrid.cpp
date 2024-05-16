/*

Complexity
Time complexity: O(n^2 * log(n))

Space complexity: O(n^2)

--------------

1. Finally we have to do bfs on a distance-matrix  ( based on manhatten formula)
2. but key point is - we have to generate that distance matrix for which again have to use BFS
3. and precisely speaking - it will be - multi-source BFS
4. as while generating matrix there will be multiple ones 
5. note - using comparator is must for these kind of problems

https://www.naukri.com/code360/library/multi-source-shortest-path-in-unweighted-graph


*/

struct point {
        int x;
        int y;
    };


class Compare {
public:
    bool operator()(pair<int,point> below, pair<int,point> above)
    {
        if (below.first < above.first) {
            return true;
        }
         
        return false;
    }
};


class Solution {
public:
    
    
    
    void print(vector<vector<int>>& grid){
        
        cout<<"\n---------\n";
        
        int r = grid.size(), c = grid[0].size(), x = 0, y = 0;
        
        for(x=0; x<r; x++){
            for(y=0; y<c; y++){
                cout<<grid[x][y]<<" ";
            }
            cout<<endl;
        }
        
        cout<<"\n---------\n";
        
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size(), x = 0, y = 0;
        
        vector<vector<int>>dis(r, vector<int>(c, -1));
        
        point p = {x=1,y=5};
        
        // filter out - cell marked 1 
        queue<point>ones;
        for(x=0; x<r; x++){
            for(y=0; y<c; y++){
                
                if(grid[x][y] == 1){
                    ones.push({x,y});
                    dis[x][y] = 0;
                }
            }
        }
        
        // construct safeness matrix - bfs on all pushed 1's - we call this multi-source
        int dx[4] = {-1,0,0,1};
        int dy[4] = {0,-1,1,0};
        while(!ones.empty()){
            
            point p = ones.front();
            
            for(int j=0; j<4; j++){
                
              point n = { x =  p.x + dx[j],
                          y =  p.y + dy[j] };
                
               if(n.x >=0 and n.x<r and n.y>=0 and n.y<c and dis[n.x][n.y] < 0){
                
                   dis[n.x][n.y] = dis[p.x][p.y] + 1;
                   ones.push(n);
               }
                
            }
            

            
            ones.pop();
        }
        
       // print(dis);
    
        
        // iterate on generate safeness matrix from (0,0 to n-1,n-1)
        int maxSafenessFactor = dis[0][0];
        vector<vector<int>>vis(r, vector<int>(c, -1)); // visited array 
        
        priority_queue< pair<int,point>,  vector<pair<int,point>>, Compare >maxSafenessHeap;
        vis[0][0] = 1;
        maxSafenessHeap.push( {dis[0][0], {0,0} }); // push cell (0,0)
        
    
        while(!maxSafenessHeap.empty()){
            
            pair<int,point> cell = maxSafenessHeap.top();
            maxSafenessHeap.pop();
            
            maxSafenessFactor = min(maxSafenessFactor, cell.first);
                     
            point p = cell.second;
            
            if(p.x == r-1 && p.y == c-1){
                break;
            }
            
            for(int j=0; j<4; j++){
                
              point n = { x =  p.x + dx[j],
                          y =  p.y + dy[j] };
                
               if(n.x >=0 and n.x<r and n.y>=0 and n.y<c and vis[n.x][n.y] < 0){
                
                   vis[n.x][n.y] = 1;
                   maxSafenessHeap.push({dis[n.x][n.y] , n});
               }
                
            }
            
         }
        
        return maxSafenessFactor;
    }
};

/*

1 0 0
0 0 0
0 0 1



0 0 0
0 0 0
0 0 0

0 1 0
1 0 1
0 1 0

0 1 2
1 2 1
2 1 0




*/
