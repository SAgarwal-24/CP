//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
// helpful repo:https://github.com/forestLoop/Learning-ITMO-Academy-Pilot-Course/blob/main/binary-search/2-B.cpp 

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int unsigned long long

#define watch(x) cout << (#x) << " is " << (x) << endl
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);





void solve(){
    
  int n,k,i;
  cin>>n>>k;
  long double s=0;

  vector<int>ropes(n);

  for(i=0;i<n;i++){
     cin>>ropes[i];
     s+=ropes[i];   
  }
    
    long double ans=0.0, l=0, r=10000000;

 

    // while(r-l>1e-4){

    for(int iterations=0;iterations<100; iterations++){

        long double mid = l+(r-l)/2;
        int cnt=0;

        for(i=0;i<n;i++){
            cnt += floor(ropes[i]/mid);
        }

        if(cnt>=k){
            ans = mid;
            l = mid;
        }
        else{
            r = mid ;
        }

        
    }

    // watch(c);

   cout<<setprecision(20)<<ans<<endl; //setting precision to 20 was important

}


// Fuck rating 
// enjoy process and improvement(by red coders like colin)

int32_t main()
{
    fast int tc = 1;
    // cin >> tc;

 
    while (tc--)
    {
        solve();
    }


    return 0;
}
