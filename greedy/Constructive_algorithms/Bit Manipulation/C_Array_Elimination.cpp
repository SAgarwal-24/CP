//link: https://codeforces.com/contest/1602/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ll long long
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()

#define watch(x) cout << (#x) << " is " << (x) << endl

#define INF 1e18
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

template <typename C,
          typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
          typename std::enable_if<!std::is_same<C, std::string>::value>::type * = nullptr>
std::ostream &operator<<(std::ostream &os, const C &container)
{
    bool first = true;
    std::stringstream ss;
    ss << '[';
    for (const auto &x : container)
    {
        if (!first)
        {
            ss << ", ";
        }
        first = false;
        ss << x;
    }
    ss << ']';
    return os << ss.str();
}
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << '{' << p.first << ", " << p.second << '}';
    return os;
}

/*
8 12
12 8
8 4
4 0
*/
int gcd(int a, int b){

    if(b!=0)
        return gcd(b, a%b);

    return a;
}

/* 
eg: a[] = {2,3,3,3}
-> represent this array a[] in form of binary 2D matrix 
-> for each column 

Initially: 
c1 c2 - columns
1 0  - 2   
1 1  - 3
1 1  - 3
1 1  - 3
----
4 3 - set bits
----

Goal to be achieved : all a[i] = 0 
- ie binary 2D matrix now containing 0 everywhere 
- ie turn off all set bits for each column
0 0
0 0
0 0
0 0
----
0 0 - set bits
----

Q. what k to choose ? how to turn off bits ? 
- acc. to algo mentioned in question - we need to find 'k' which fetches us a 'x' which we subtract from each 
 a[i] from 'k' chosen elements or specifically saying from 'k' elements having bits 'set/on' for a particular position 'pos'

 - in the given example: a[] = {2,3,3,3}
 - in binary matrix form(4X2) we represented with two columns c1 and c2 
 
 intitally c1         ->        finally c1
   0                                0
   1                                0
   1                                0
   1                                0

   so for c1 we expect k = 3 so that we achieve all zeros 

   similarly for c2 

 intitally c2         ->        finally c2
   1                                0
   1                                0
   1                                0
   1                                0

   so for c2 we expect k = 4 so that we achieve all zeros 

but we can't satisfy both c1 and c2 
- or in other words we can't make both c1 and c2 happy simultaneously
- ie if k==4 then c1 is unhappy
    else if k==3 then c2 is unhappy
    else if k==gcd(k1,k2) then both c1 and c2 are happy..hurrah

- so to make to make both c1 and c2 happy ...
we will go with "intersection of their expectations" ie gcd of k1 and k2

- and if their and 30 columns ie c0,c1,c2,...c29 as a[i]<2^30
- then: there are "30 different expectations " or "30 different k" ie k0,k1,k2....k29
- and to make all 30 people happy - we need intersection of there expectations ie "gcd of all 30 k values"
- ie gcd(k0,k1,k2....k29)


Q. Why gcd is intersection????
- bcd gcd makes sure that best (or highest common factor) 
- ie intuitively highest common intrest of all 30 candidates or 30 columns
- formally highest common number which qualifies to be 'k' and responsible enough to eliminate all set bits and after finite operations can make all a[i]=0

*/
void solve(){
	 
     int n,j,i,mx=-1;
     cin>>n;

    vector<int>a(n);

    for(i=0;i<n;i++){
        cin>>a[i];
        mx = max(mx, a[i]);
    }

    
    int msb = (int)log2(mx);
    int k=0; 

    

    for(i=0;i<=msb;i++){

        int on=0;

        for(j=0;j<n;j++){

            if(a[j] & (1<<i)){
                on++;
            }
        }

        k = gcd(k, on);
        
    }

    //k - is gcd of: cnt of all set bits for each of the position (0th pos to msb pos) for all array elements 
    //k - now k is the highest common factor or intrest which can  eliminate all set bits and after finite operations can make all a[i]=0

    for(i=1;i<=n;i++){
        if(k%i==0){
            cout<<i<<" ";
        }
    }

    cout<<endl;
}


int32_t main()
{
    fast int tc = 1;
    cin >> tc;

 
    while (tc--)
    {
        solve();
    }


    return 0;
}
