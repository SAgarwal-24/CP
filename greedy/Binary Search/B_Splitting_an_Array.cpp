//Awesome question deserves revision from ITMO PILOT COURSE
// B. Splitting an Array 
// kind of min(max(sum)) problem
// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/B

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

   int i,a[n],sum=0;
   for(i=0;i<n;i++)cin>>a[i],sum+=a[i];
//    sort(a,a+n);  Don't fall for this....sorting is not reqd

//     for(i=0;i<n;i++)cout<<a[i]<<" ";
//     cout<<endl;


   // divide array-> into k segments
   // minimize possible maximum sum on the segment.

   
   int lo=*max_element(a,a+n), hi=sum;
   int ans=sum; //maximum sum of a segment possible ...no more than this

   while(lo<=hi){
       int mid=lo+(hi-lo)/2;   //check this sum(ie mid) qualifies for minimum max sum of segment
                              // this sum(mid) will qualify if we get segments<=k into which we  divide whole array  

        int segments=1,s=0,i=0;
        while(i<n){
            if(s+a[i]<=mid){
                s+=a[i];
            }else{
                segments++;
                s=a[i];
            }
            i++;
        }

        // cout<<lo<<" "<<mid<<" "<<hi<<endl;
        // cout<<segments<<" "<<k<<endl;

        if(segments<=k){ //this sum(ie mid) qualifies successfully
            ans=mid;     // even if segements<k no worries 
                        // bcz we can divide a segment so that segments 
                        // increase to become equal to k acc to our wish 
                         // like mid=24 qualifies [1,2,2,3,3,4] and [4,5,8,10]
                         // make them as say as [1,2,2], [3,3,4] , [4,5] , [8,10]  or anything
            
            hi=mid-1;   // now check for lower mid
        }
        else{
            lo=mid+1;
        }
        
   }

   // observation: if we increase no of segments ie k 
   // then better lower ans(ie minimum max possible sum) we can achieve

   cout<<ans;

   
}
return 0;
}
