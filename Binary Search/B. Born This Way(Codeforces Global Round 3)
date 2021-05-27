// https://codeforces.com/problemset/problem/1148/B
// B. Born This Way
// Codeforces Global Round 3
// deserves a revision

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define watch(x) cout << (#x) << " is " << (x) << endl
#define hh cout << endl
#define bor cout<<"\n---\n";


int32_t main(){
int tc=1;
//cin>>tc;
while(tc--){
    
    int n,m,ta,tb,k,i,j; 
    cin>>n>>m>>ta>>tb>>k;

    int a[n+1]={0}, b[m+1]={0};
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=m;i++)cin>>b[i];

    if(k>=n){  // Cancel all flights from A to B
        cout<<-1; return 0;
    }

    int ans=-1;

    for(int x=0;x<=k;x++){ // Check for all x ie no of flights we can cancel is from 0 to k
    // ie min is we can cancel no flight from A->B and max is cancel all first k flight from A->B
    
    
        int b_ariv=a[x+1]+ta; //time to arrive B

        //flights available at B
        int b_avail=lower_bound(b,b+m+1,b_ariv)-(b);

        //now we can cancel first k-x flights from b to c (greedy)
        b_avail+=(k-x);

        if(b_avail>m){
            cout<<-1; return 0;
        }

        ans=max(b[b_avail]+tb,ans);

    
    }

    cout<<ans;

}
return 0;
}



//Main Code logic without stl
/*
  if(k>=n){  // Cancel all flights from A to B
        cout<<-1; return 0;
    }

    int ans=-1;

    for(int x=0;x<=k;x++){ // Check for all x ie no of flights we can cancel is from 0 to k
    // ie min is we can cancel no flight from A->B and max is cancel all first k flight from A->B

    
        int b_ariv=a[x+1]+ta; //time to arrive B

        //flights available at B
        int b_avail=m+1;  //assume flights not available initially

        int lo=1, hi=m;
        while(lo<=hi){  // Find time>=b_ariv  in b ie lower_bound(b,b+m+1,b_ariv)-(b);
            int mid=lo+(hi-lo)/2; 

            if(b[mid]>=b_ariv){
                b_avail=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        //now we can cancel first k-x flights from b to c (greedy)
        b_avail+=(k-x);

        if(b_avail>m){
            cout<<-1; return 0;
        }

        ans=max(b[b_avail]+tb,ans);

    
    }

    cout<<ans;
  
*/
