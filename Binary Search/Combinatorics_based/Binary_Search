// link: https://codeforces.com/contest/1436/problem/C
// sol : https://codeforces.com/contest/1436/submission/136557747

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ll long long
#define pi (3.141592653589)
// #define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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

/*

To calculate C(n,r) modulo 10^9+7
->      C(n,r) %  M
->      [n!/((n-r)! . (r!))] % M

we want something like below , but it mathematically wrong
->       (n! % M) / ([(n-r)! % M]. [(r!) % M] %M )

so we will do 
->    C(n,r) %  M =  [ numerator * inv(denominator) ] % M                    
->    C(n,r) %  M =  [ (numerator % M) * (inv(denominator) % M) ] % M 

//Using fermat little theo
->  inv(n) = power(n, mod-2); 
-> Find using bin expo

*/

int fact[1001];

int mod = 1e9 + 7;


int inv(int n){

    // inv(n) = power(n, mod-2); fermat little theo

    int res = 1;
    int b = mod-2;

    n = n % mod;

    while(b){

        if(b&1)
          res = (res * n) % mod;

        b = b>>1;
        n = (n*n) % mod;
    }

    return res;
}

int npr(int n, int r){

    int ans=1;
    
    //numerator = n!, denominator =  (n-r)! 

    int nr = fact[n];                
    int inv_dr = inv(fact[n-r]);    

    ans = (nr * inv_dr) % mod;

    return ans;
}

void solve(){

	int n,x,pos,ans=0;
     cin>>n>>x>>pos;


    int lo = 0, hi = n;
    int sm=0, big=0; //smaller and bigger no.s required


    while(lo<hi){
         int mi = (lo + hi)/2;
         if(mi<=pos){  //and here we need smaller
            lo = mi + 1;

            if(mi!=pos)
            sm++;
        }
        else{           //we want bigger no here
            hi = mi;
            big++;
        }

    }


    int tot_bigger = n-x;
    int tot_sm = x-1;
    int rem = n - 1 - (big+sm);


    int cnt_big = npr(tot_bigger, big);
    int cnt_less = npr(tot_sm, sm);

    ans = (cnt_big * cnt_less) % mod;

    ans = (ans * fact[rem]) % mod;

    cout<< ans <<endl;
}



// Fuck rating 
// enjoy process and improvement(by red coders like colin)

int32_t main()
{   
    fact[0]=1;

    for(int i=1;i<=1e3;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }

    fast int tc = 1;
    // cin >> tc;

 
    while (tc--)
    {
        solve();
    }


    return 0;
}


 
