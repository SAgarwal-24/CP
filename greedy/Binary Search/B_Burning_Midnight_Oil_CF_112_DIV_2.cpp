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
   int n,m,i,k;
   cin>>n>>k;

   int ans=0;

   int lo=0,hi=n;

   while(lo<=hi){
       int mid=lo+(hi-lo)/2;

       int dn=1,v=mid,sum=0;
       
       while((v/dn)>0){
           sum+=(v/dn);
           dn=dn*k;
       }
      
      //cout<<lo<<" "<<hi<<" "<<sum<<endl;
       if(sum>=n){
           ans=mid;
           hi=mid-1;
       }
       else{
           lo=mid+1;
       }

   }

    cout<<ans;
  
}
return 0;
}
