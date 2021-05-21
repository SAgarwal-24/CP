// link - https://codeforces.com/contest/492/problem/B

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);



int32_t main(){
fast
int tc=1;
//cin>>tc;
while(tc--){
   int n,m,i,l;
   cin>>n>>l;

   int a[n+2];
   a[0]=0;
   for(i=1;i<=n;i++)cin>>a[i];
   a[n+1]=l;

    sort(a,a+n+2);


   float ans=0.0;


   // Well this problem can be done with out binary search also 
   // which is better 
   int lo=0,hi=l;

   while(lo<=hi){
       int mid=lo+(hi-lo)/2;

       i=0;
       while(i<n+1){
           if(a[i+1]-a[i]<=mid)i++;
           else break;
       }


       if(i==n+1){
           float f1=a[1]-a[0], f2=a[n+1]-a[n];

           ans=(float)mid/2;
           ans=max(ans,max(f1,f2));
           //cout<<"a "<<ans<<endl;
           hi=mid-1;
       }
       else{
           lo=mid+1;
       }

   }

   cout<<fixed<<setprecision(10)<<ans;
}
return 0;
}
