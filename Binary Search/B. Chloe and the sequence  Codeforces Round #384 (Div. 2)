//B. Chloe and the sequence
// Codeforces Round #384 (Div. 2)

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back

#define all(c) c.begin(), c.end()

#define watch(x) cout << (#x) << " is " << (x) << endl
#define see(x) cout << (x) << endl
#define hh cout << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);




int32_t main(){

fast
int tc=1;
//cin>>tc;

while(tc--){
   int n,m,k;
   cin>>n>>k;

   //value of the element with index k 
   // in the obtained sequence, i. e. after (n - 1) steps.

   // 1                  => l=1  or  2^1-1
   // 121                => l=3      2^2-1
   // 1213121            => l=7      2^3-1
   // 121312141213121    => l=15     2^4-1

   // 1  2  3  4  5  6  7  8  9   10  11  12  13  14 15
   // 1  2  1  3  1  2  1  4  1   2    1   3   1   2  1

   // This problem is not exact binary search ie no monotonicity
   // its just following the notion of searching it
   // from some indexes which can be segregated at each step like bs
   
//    int sz=1; initially size of vector 
//    for(int i=2;i<=n;i++)sz=sz*2+1; size becomes double +1 at each step

 
   int lo=1;
   int hi=((1LL<<n)-1); // or  hi=sz; ie maximum  hi=2^50-1
   

   while(lo<=hi){
       int mid=lo+(hi-lo)/2;
       
       if(mid==k){  // at mid we have highest no of that particular level
           cout<<n; return 0;
       }
       else if(mid>k){  // since we missed mid pos so we can't find current 'n'
           hi=mid-1;    // afterwards as now all nos. will be less than n
           n--;         // so decrease 'n' by 1 each time we miss mid position
       }
       else{
           lo=mid+1;
           n--;
       }
   }


   
}
return 0;
}
