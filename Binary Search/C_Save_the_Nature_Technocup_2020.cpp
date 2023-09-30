// https://codeforces.com/contest/1223/problem/C
// C. Save the Nature
// Technocup 2020 - Elimination Round 1

#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define int long long


// minimum number of tickets you need to sell to make 
// the total ecological contribution of at least k
int32_t main(){
int tc=1;
cin>>tc;
while(tc--){
    int n,i; cin>>n;

    int p[n+1]={0};
    for(i=1;i<=n;i++)cin>>p[i],p[i]=p[i]/100;  //ticket prices

    int x,a; cin>>x>>a; //x% price of a,2a,3a,...nath ticket
    int y,b; cin>>y>>b; //y% price of b,2b,3b,...nbth ticket
    int k; cin>>k;      // reqd total contribution

    if(x<y)swap(x,y), swap(a,b);

    sort(p+1,p+n+1); //O(nlog(n))
    int ab=(a*b)/(__gcd(a,b));

    int ans=-1;  //we sold all ticket but still raised_funds_for_nature<k

    int lo=1,hi=n; // lo=1 ie one ticket is sold is least no of tickets we can sell
                  // hi=n max. we can sell all tickets

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;  //check if mid no of tikets can raise_funds>=k

        int cab=mid/ab;      // max first mid ticket we can sell  at (x+y)%
        int ca=(mid/a)-cab;  // max first mid ticket we can sell  at (x)%
        int cb=(mid/b)-cab;  // max first mid ticket we can sell  at (y)%

        i=n;
        int funds=0;                        // greedy logic
        while(cab--)funds+=(x+y)*p[i--];  //sell ticket with highest rate with max contri ie (x+y)%
        while(ca--)funds+=(x)*p[i--];    // since we keep x>y therefore greedily send remaining highest price ticket at x%
        while(cb--)funds+=(y)*p[i--];   // remaining highest at y%

        // cout<<lo<<" "<<mid<<" "<<hi<<endl;
        // cout<<funds<<" "<<k<<endl;

        if(funds>=k){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }

    }

    cout<<ans<<endl;
    
}
return 0;
}
