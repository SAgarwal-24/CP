//https://www.codechef.com/problems/INTCONCA
//sol link: https://www.codechef.com/viewsolution/54265921

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int  long long
#define vi vector<int>
#define all(x) x.begin(),x.end()
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


int length(int num){

    int c=0;

    while(num>0){
        c++;
        num /=10;
    }

    return c;

}


int pow10(int p){  //10^p = 10^3 

    int ans=1, wt=10;   //10^0

    while(p>0){

        if(p&1)
        ans = ans * wt;

        p = p>>1;
        wt = wt * wt;
    }

    return ans;
}

/*

a1  a2  a3....an

for each element say i=1 then we do n concatenation

  conc(a1,a1)  =    a1*(10^len(a1)) + a1
  conc(a1,a2)   =   a2*(10^len(a1)) + a1
  --
  --
  conc(a1,an)   =   an*(10^(len(a1))) + a1

These concatenations should lie in range [L,R]
say
  L <= conc(a1,an) <= R
  L <= an*(10^(len(a1))) + a1 <= R

  (L-a1)/10^(len(a1))  <= an <= (R-a1)/10^(len(a1)) 


*/

void solve(){
	
    int i,n,l,r;
    cin>>n>>l>>r;

    vi a(n);

    for(i=0;i<n;i++)
    cin>>a[i];

    sort(all(a));

    int ans=0;
  

    for(i=0;i<n;i++){

        int len = length(a[i]);
        int den = (pow10(len));

        int  L = (l-a[i]+den-1)/den;
        int  R = (r-a[i])/den;

        if(L>R)
            continue;

        //for each a[i] find [start,end] 
        //l <= conc(a[i],a[start])  ,  conc(a[i],a[end]) <= r
        // L <= a[start] , a[start+1], ... a[end] <= R

        int lo=0, hi=n-1, start=n+10, end=-1e2, g=10;
        
        //find start
        while(lo<=hi){

            int mid = lo + (hi-lo)/2 ;

            if(L<= a[mid]){
                start = mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
           
        }

        
        //find end
        lo = 0, hi=n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;

            if(a[mid]<=R){
                end = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        ans += max(end-start+1, (int)0);
        
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
