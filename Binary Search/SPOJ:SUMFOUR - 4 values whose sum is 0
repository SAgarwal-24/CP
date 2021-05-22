//equal_range : STL C++ based on binary search , can use both lower_bound and upper_bound

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
    int ans=0,i,j,n;
    cin>>n;

    int a[n][4];

    for(i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    }

    vector<int>v1,v2;
  

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){

            v1.push_back(a[i][0]+a[j][1]);
            v2.push_back(a[i][2]+a[j][3]);
           
        }
    }

    sort(v2.begin(),v2.end());

    for(auto x:v1){

        auto p=equal_range(v2.begin(),v2.end(),-1*x);
        ans+=p.second-p.first;
    }

 

    cout<<ans;
  
}
return 0;
}
