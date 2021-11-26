link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G



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

    int i,k,n,s=0, ans=0;
    cin>>k>>n;

    vi fre(n); //fre[group] = frequency of student of a group

    for(i=0;i<n;i++)
     cin>>fre[i], s+=fre[i];

    int lo=0, hi = s/k; 

    while(lo<=hi){

        int mid = lo + (hi-lo)/2; //no of councils = mid
        int need = mid*k;        //think it as 2d matrix (mid X k) 

        
        for(i=0;i<n;i++){
            need -= min(fre[i],mid);  //  min(fre[i],mid) columns are filled by students of ith group-> ie 1 student in each column(or council)
        }

        if(need<=0){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    cout<<ans<<endl;
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
