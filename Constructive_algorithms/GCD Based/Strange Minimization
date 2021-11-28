//link: https://www.codechef.com/LTIME102B/problems/STRGMNZ


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ll long long
#define pi (3.141592653589)
#define mod 998244353 
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfo(i, a, b) for (int i = (int)a; i >= (int)b; i--)
#define fo(i, a, b) for (int i = (int)a; i <= (int)b; i++)
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

ll mod_pow(ll a, ll b)
{
    if (b < 0)
        return 0;
    a %= mod;
    if (b == 0)
        return 1;
    if (b == 1)
        return a % mod;
    if (b == 2)
        return ((a % mod) * (a % mod)) % mod;
    return (mod_pow(mod_pow(a, b / 2), 2) * mod_pow(a, b % 2)) % mod;
}




int pow(int n, int i){
    int a=n,ans=1;
    while(i>0){
        if(i&1){
            ans=(ans*1LL*a)%mod;
        }
        a=(a*1LL*a)%mod;
        i=i>>1;
    }
    return ans;
}

int inv(int n){
    return pow(n, mod-2);
}

long long calculate(long long p,
                    long long q)
{
    long long mod1 = 998244353, expo;
    expo = mod1 - 2;
 
    // Loop to find the value
    // until the expo is not zero
    while (expo) {
 
        // Multiply p with q
        // if expo is odd
        if (expo & 1) {
            p = (p * q) % mod1;
        }
        q = (q * q) % mod1;
 
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

//--------SieveOfEratosthenes---------

bool prime[1000000 + 1];
void SieveOfEratosthenes()
{
    int n = 1000000;
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}


void primeFactors(int n, set<int>&pfs)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        // cout << 2 << " ";
        pfs.insert(2);
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n) ; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            // cout << i << " ";
            pfs.insert(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
        //pfs.insert(n);  // cout << n << " ";
    }
       
}

bool isPrime(int n){

    if(n%2==0)
        return false;

    
    for(int i=3; i*i<=n; i=i+2){

        if(n%i==0)
            return false;
    }

    return true;
}

int smallest_odd_prime(int n){

    for(int i=3;i*i<=n; i=i+2)
    {
        if(n%i==0)
          return i;
    }
}


void solve(){
	
    int i,n;
    cin>>n;

   
    if(isPrime(n)){
        cout<<n+1<<endl;
        return;
    }

    //for min_value of |gcd(n,x)-lcm(n,x)| just increase the smallest_div by 1 of n inorder to make x rest will be same
     
    if(n%2==0){

        /*    n =   2   * y 
        //    x = (2+1) * y  = 3*y = 3*(n/2)
        // |g-l| =  y - 3*2*y = y(1-3*2) = y*5 = minimum value  */

        cout<<3*(n/2)<<endl;
    }
    else{
        /*
            n =   smallest * y
            x = (smallest+1)*y  

            x = (smallest+1)*(n/smallest)
        */
        int smallest_div = smallest_odd_prime(n);

        cout<< (smallest_div + 1)*(n/smallest_div)<<endl;
    }

    

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
