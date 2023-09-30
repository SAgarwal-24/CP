/*
B. Nice Matrix
https://codeforces.com/problemset/problem/1422/B
------
-Trick to be realized is that median rules over mean when data is skewed
- suppose a=[1,1,1,1,20] so it is better to replace each value with median(=1) rather than mean(=4) to decrease no of operations
   bcz clearly the data is left skewed that is density of like-population is located on left side so median is better choice as it is located on left
   
- in symmetric data both mean and median gives same answer
------------

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define all(c) c.begin(), c.end()
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main(){
    fast
    int tc=1;
    cin>>tc;

    while(tc--){
    int n,m,i,j;
    cin>>n>>m;

    int a[n+1][m+1];
    memset(a,0,sizeof(a));

    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cin>>a[i][j];

    int ans=0,sum=0;

    for(i=1;i<=n/2;i++){
        for(j=1;j<=m/2;j++){
            int x=a[i][j], y=a[n-i+1][j];
            int z=a[i][m-j+1], w=a[n-i+1][m-j+1];

            vector<int>v(4);
            v[0]=x, v[1]=y, v[2]=z, v[3]=w;
            sort(all(v));

            int med=v[2]; //median of all 4 nos
            ans+=abs(med-x)+abs(med-y)+abs(med-z)+abs(med-w);
        }
    }

    // mid odd row
    if(n&1){
        int mid=(n+1)/2;
        for(j=1;j<=(m+1)/2;j++){
            int med=a[mid][j]; //one of the 2 nos is median
            ans+=abs(a[mid][m-j+1]-med);
        }
    }


    //mid odd col
    if(m&1){
        int mid=(m+1)/2;
        for(j=1;j<=(n+1)/2;j++){
            int med=a[j][mid];
            ans+=abs(a[n-j+1][mid]-med);
        }
    }

    cout<<ans<<endl;

    }
return 0;
}
