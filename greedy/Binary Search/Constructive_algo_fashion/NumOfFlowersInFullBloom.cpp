#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vl vector<long>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define watch(x) cout << (#x) << " -> "  << (x) << endl

class Solution {
public:
    
    int lower_bound( vl &nums ,  int x){
        
        int lo = 0,  hi = nums.size() - 1;
        
        int lower_index = -1;
        
        while(lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] <= x){
                lower_index = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }   
        }
        
        return lower_index + 1;
    }
    
    void print(vi &a){
        
        for(auto x: a){
            cout<<x<<" ";
        }
        
        cout<<endl;
    }
    
    vi fullBloomFlowers(vvi& flowers, vi& people) {
        
        int i, n = people.size(), fs = flowers.size();
        
        vi ans(n, 0);
        vl start(fs, 0), end(fs, 0);
        
        for(i=0; i< fs ; i++){
            
            start[i] = flowers[i][0];
            end[i] =   flowers[i][1] + 1;
        }
        
        sort(all(start));
        sort(all(end));
        
        // print(start);
        // print(end);
        
        
        for(i=0; i<n; i++){
            
            ans[i] = lower_bound(start, people[i])
                    - lower_bound(end, people[i]);
        }
        
        
        return ans;
    }
};

/*



1 2 3  4  5 6  7  8  9  10  11  12   13

1             -1

    1             -1 
                     1               -1
       1                                 -1        

1 1 2  3  3 3  2  1   2  2   2   2   1 

------------
 0 1 2 3 4  5  6  7
 1 3 5 8 11 15 19 23
 
 
 

 0 1 2 3 4 5 6 7 8 9
 
 l                 h

           l       h
           l h
           l,h
           h,l


*/
