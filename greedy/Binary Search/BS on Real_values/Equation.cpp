//link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int  long long
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define INF 1e18
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

void solve(){

    long double c;
    cin>>c;

    cout<<setprecision(20);

    long double x=0,lo=0, hi = 1e10; //10000000000.0;

    
    // watch(hi);

    for(int iterations=0; iterations<100; iterations++){

        long double mid = lo + (hi-lo)/2;

        if(mid*mid + sqrt(mid) < c){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }

    // watch(lo);

    cout<<lo<<endl;

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
