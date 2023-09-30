//link: https://codeforces.com/contest/1462/problem/E1

/*
Main kickstart for thinking is -> order of input_array[] doesn't matter 

-> ie we are allowed to change the order of input_array[] 
-> ie sorting is allowed

Why order of input_array doesn't matter??

since we want , 
=> max(a[i],a[j],a[z])−min(a[i],a[j],a[z]) ≤ 2.  such that (i<j<z) 

=> but thinking carefully we get condition can also be (i!=j!=z) that's it -> we don't need to maintain any range or some kind of order
=> and simply pick up 3 numbers 
=> we just need to know cnt[a[i]] or cnt[a[j]] or cnt[a[z]] 

=> so 6 favourable cases (from editorial) 
Let's iterate over x – the minimum number in the triples. Then there are the following options:

[x, x+1, x+2]
[x, x+1, x+1]
[x, x+2, x+2]
[x, x, x+1]
[x, x, x+2]
[x, x, x]

*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(c) c.begin(), c.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define see(x) cout << (x) << endl
#define hh cout << endl
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


int gcd(int a,int b){

    if(b==0)
        return a;

    return gcd(b,a%b);
}

/*

To calculate C(n,r) modulo 10^9+7
->      C(n,r) %  M
->      [n!/((n-r)! . (r!))] % M

we want something like below , but it mathematically wrong
->       (n! % M) / ([(n-r)! % M]. [(r!) % M] %M )

so we will do 
->    C(n,r) %  M =  [ numerator * inv(denominator) ] % M                    
->    C(n,r) %  M =  [ (numerator % M) * (inv(denominator) % M) ] % M 

*/


//[1, 1, 2, 2, 3, 4, 5, 6, 8, 9]


int ncr(int n, int r){

    // cout<<"n,r : "<<n<<","<<r<<endl;

    if(n<r)
        return 0;

    if(r>n-r)
        r = n-r;

    int nr=1, den=1;

    while(r){

        nr *= n;
        den *= r;

        int g = gcd(nr,den);

        nr /= g;
        den /= g;

        n--;
        r--;
    }

    // cout<<"nr,den : "<<nr<<","<<den<<endl;

    return nr/den;
}

void solve(){

    int i,n;
    cin>>n;

    vi a(n);

    for(i=0;i<n;i++)
        cin>>a[i];
    

    sort(all(a));

    // watch(a);

    int ans=0;

    for(i=2;i<n;i++){

        int lo = 0,  hi=i-1, start=i;

        while(lo<=hi){

            int mid = (lo + hi)/2;

            /*  
                mx = a[i],   mi=a[mid]
                mx - mi <=2 

            */
            if(a[mid]+2 >= a[i]){
                start = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        // cout<<"st, i: "<<start<<", "<<i<<endl;

        //tuple -> [start , i]  and tuple_len = i-start+1;
        // we need to choose 3 elements from tuple
        // keeping a[i] is fixed we left with only 2 elements to choose from remaining elements
        // ie 2 elements out of tuple_len-1
        // ie no of ways to choose 2 elements = ncr(tuple_len-1, 2)

        int tuple_len = i-start+1;  
    
        ans += ncr(tuple_len-1, 2); // otherwise simply -> ans += (tuple_len-1)*(tuple_len-2)/2;

        // watch(ans);
    }


    cout<<ans<<endl;
}



// Fuck rating 
// enjoy process and improvement(by red coders like colin)

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





 
