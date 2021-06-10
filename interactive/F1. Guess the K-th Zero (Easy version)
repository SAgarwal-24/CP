/*Binary search on prefix count of zeros
trick was if we get prefix count of zeros as 

ind    ->    1 2 3 4 5 5 7 8
prefix ->    1 1 1 2 2 2 2 3

and say we want k=2 ie 2nd zero then we need ind=4 as answer
so when writing code BS  we need to equality in hi=mid-1 and whenever we hit this inequality will be our probable answer

if(z>=k)hi=mid-1, ans=mid

*/

#include <bits/stdc++.h>
using namespace std;
//#define endl "\n"
#define int long long
#define watch(x) cout << (#x) << " is " << (x) << endl
#define hh cout << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



int32_t main(){
fast

    int n,i,t,k,sum=0,z=0; cin>>n>>t>>k;

    int lo=1, hi=n, ans=-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            cout<<"? 1 "<<mid<<endl;
            cin>>sum;
            z=(mid)-sum;

   
            if(z>=k)
                hi=mid-1,ans=mid; // we need left most k in prefix
            else
                lo=mid+1;
        
        }

        cout<<"! "<<ans<<endl;
return 0;
}
