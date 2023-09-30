
/*

link: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

I just realized
For the first problem - rectangle packing is a recognized topic in real world where we have to pack rectangles in to different polygon wasting minimum space 

Fast Optimizing Rectangle Packing Algorithm for Building CSS Sprites-https://www.codeproject.com/Articles/210979/Fast-optimizing-rectangle-packing-algorithm-for-bu

 https://en.wikipedia.org/wiki/Rectangle_packing

*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int unsigned long long
#define watch(x) cout << (#x) << " is " << (x) << endl
#define INF 1e18
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


void solve(){
	int h,w,n; 
    cin>>h>>w>>n;

    int rec_area = h*w;

    int side = 1e18;

    int lo=1, hi=1e18;

    while(lo<=hi){

        int mid = lo + (hi-lo)/2;

        int rec_x = (mid)/h;
        int rec_y = (mid)/w;


        if(rec_x * rec_y >= n){
         
            side = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    cout<<side<<endl;

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
