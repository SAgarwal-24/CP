//This can be solved by 2-pointer approach too which is more optimised also

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
   int n,m,i,k,d;
   cin>>n>>d;
   int a[n];
   for(i=0;i<n;i++)cin>>a[i];

   sort(a,a+n);

   int ans=0;

   for(i=0;i<n-2;i++){
       int len=upper_bound(a+i,a+n,a[i]+d)-(a+i+1);
       ans+=(len*(len-1))/2;
   }


    cout<<ans;
  
}
return 0;
}
