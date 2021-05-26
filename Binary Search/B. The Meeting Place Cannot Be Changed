// https://codeforces.com/contest/780/problem/B
// B. The Meeting Place Cannot Be Changed

// Awesome binary search question ... based on meeting of all n members ..time-distance concept
// deserves a revision

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ld long double 
//becoming best coder of myself 
int32_t main(){

fast
int tc=1;
//cin>>tc;
while(tc--){

    int i,n; cin>>n;
    int x[n],v[n];

    for(i=0;i<n;i++)cin>>x[i];
    for(i=0;i<n;i++)cin>>v[i];

    ld lo=0.0, hi=1e9;
    ld ans=hi;
    while(hi-lo>=(0.0000000001)){
        ld mid=lo+(hi-lo)/2;

        ld left=1.0, right=1e9;
        for(i=0;i<n;i++){
            ld L=x[i]-(v[i]*mid);
            ld R=x[i]+(v[i]*mid);

            left=max(left,L);
            right=min(right,R);
        }
// 1 <---.---->
// 2      <-----.---->
// 3      <------.-----> (all 3 of them can meet)

// out of 3 elements some will move right others will move left
// ie those who move right we are intrested only the one who is in left most ie 1st element
// similarly who move left we are intrested only the one who is rightmost  ie   3 element

// now we need right of 1st element
// now we need left of 3rd element 
// as 1 and 3 are farthest 
// so left(3rd)<=right(1st) if this condition holds then we can say
// for this given time(ie mid) all of them can meet 
    
    
        if(left<=right){ // all of them can meet just observe farthest guys can meet 
            ans=mid; // minimum time to make all them to meet 
            hi=mid- 0.0000000001;
        }
        else{
            lo=mid+ 0.0000000001;
        }
    }

    cout<<fixed<<setprecision(7)<<ans;

  
}
return 0;
}
