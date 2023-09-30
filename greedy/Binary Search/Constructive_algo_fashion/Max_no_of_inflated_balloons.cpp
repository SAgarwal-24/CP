//link- https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
// helpful repo: https://github.com/ksaveljev/codeforces-edu/blob/main/binary-search/step2/D.cpp

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int  long long
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define INF 1e18
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


struct assistant{

    int t;
    int z;
    int y;
};

void solve(){

    int m,n,i;
    cin>>m>>n;

    vector<assistant>a(n);

    for(i=0;i<n;i++){
        cin>>a[i].t;
        cin>>a[i].z;
        cin>>a[i].y;
    }

    int lo=0, hi=m*1000, ans=0;

    while(lo<=hi){
        int mid = lo+(hi-lo)/2;

        int inflate_balloons=0;

        for(i=0;i<n;i++){

            int t=a[i].t,  z=a[i].z,  y=a[i].y;
            int b1=0, b2=0, rem_time=0;

            b1 = z*(mid/(t*z+y));          //balloons inflated along with rest 
            rem_time = mid % (t*z+y);  //time left , in this time if assistant still inflates then he if finished with his job 
            
            if(rem_time>=t*z)       //if condition-> Thinking mathematically -> when y is very big then b2 = (rem_time)/t can give more than z balloons which is not possible
                b2 = z;
            else
                b2 = (rem_time)/t;

            inflate_balloons += b1+b2;
        }


        if(inflate_balloons>=m){
            ans=mid;
            hi = mid-1;
            
        }
        else{
            lo = mid+1;
        }
    }

    // watch(ans);

    cout<<ans<<endl;

    for(i=0;i<n;i++){
     
        int t=a[i].t,  z=a[i].z,  y=a[i].y;
        int b1=0, b2=0, rem_time=0;

        b1 = z*(ans/(t*z+y)); 
        rem_time = ans % (t*z+y);

        if(rem_time>=t*z)
            b2=z;
        else
            b2 = (rem_time)/t;

        int contri = min(m,b1+b2);
        
        m-=contri;
        cout<<contri<<" ";
    }

  
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
