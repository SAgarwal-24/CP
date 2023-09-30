//link: https://codeforces.com/contest/1551/problem/B2

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
 why monotonicity is possible ? why bs is valid ?

  n = total elements 

  if I can successfully paint 'x' elements ie n-x are unpainted  (x is multiple of k)
  
  then I can also successfully paint 'y' elements ie n-y are unpainted 
   where -> 1<= y < n (y is multiple of k)

   since y<x -> n-y>n-x  ie. we simply left more elements unpainted 

   eg n=20 , k=3
   say x=12 is possible 
   ie  x=12 (painted) and n-x=8 (unpainted)
   
   now we can also make any of 3 painted elements unpainted (1 from each color)
   ie 
   x-k = 12-3 = 9    , n-x+k = 8+3 = 11
   20 = 9 (painted) + 11(unpainted)

*/

void solve(){
	int n,k,x,i,j; 
    cin>>n>>k;

    
    vi out(n,0);

    //stores occurrences of element
    map<int,vi>mp; //mp[element] = ind1, ind2 

    for(i=0;i<n;i++){
        cin>>x;

    //Condition-2 satisfied-> remove extra elements so that same elements don't have same color
        if(mp[x].size()<k) 
        mp[x].push_back(i);
    }

    int lo=0, hi=n - n%k;
    int  mx_ele_paint=0 ; //total cnt of maximum elements which we can paint 

    while(lo<=hi){

        //lets paint 'mid' no of elements 
        int mid = lo + (hi-lo)/2;
        mid = mid - (mid%k); //mid should be multiple of k 

        int cnt = mid;

        for(auto it:mp){
            cnt -= it.second.size();
        }

        if(cnt<=0){    //we have enough elements to paint 'mid' no. of elements 
            mx_ele_paint = mid;
            lo = mid+k;  //so explore for more 
        }
        else{
            hi = mid-k;  
        }
    }

    //So now we have -> mx_ele_paint = total cnt of max. no of elements which we can paint 
    // now we greedily just assign the positions 
    int paint = 1;

    for(auto it:mp){

        int num = it.first;

        for(auto ind: mp[num]){

            out[ind] = paint;

            paint = (paint % k) + 1;

            mx_ele_paint--;

            if(mx_ele_paint==0)
              goto output;
        }
    }


    output:
      for(i=0;i<n;i++)
      cout<<out[i]<<" ";

      cout<<endl;

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

/*
---- testcase ----
1
15 3
1 1 1 1 1 1 2 2 3 3 3 3 3 3 3 

1 2 3 0 0 0 1 2 3 1 2 0 0 00 


1 1 2 3 3 3


*/
