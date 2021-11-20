//link: https://codeforces.com/contest/534/problem/C 

#include <bits/stdc++.h>
#define int long long int 
using namespace std;

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


void solve(){

    int i,n,A, d_sum=0;
    cin>>n>>A;
    
    vector<int>d(n);

    vector<int>invalid(n,0);

    for(i=0;i<n;i++){
        cin>>d[i];

        d_sum += d[i];
    }

    for(i=0;i<n;i++){

        int rem_max_possible = d_sum - d[i];  //max possible sum by remaining dices (d1+d2..+dn) - (di)
        int rem_min_possible = n-1;           // min possible sum by remaining dices ie 1+1+1

        //obv: range can be achieved by sum of values of remaining dices is [rem_min_possible, rem_max_possible]

        // now to achieve A - suitable/allowed range for ith dice would be [A-rem_max_possible, A-rem_min_possible]
        //                                      but range of ith  dice is  [1,di]
        // so we need to find uncommon values in two ranges [1,di] and [A-rem_max_possible, A-rem_min_possible]

        //upper bound for ith dice  is <=  min( di, A-rem_min_possible )
        // lower bound for ith dice  is >= max(1, A-rem_max_possible)
        
        invalid[i] += d[i] - min( d[i], A-rem_min_possible );
        invalid[i] += max((int)1, A-rem_max_possible) - 1;
    }

  
   for(i=0;i<n;i++){
       cout<<invalid[i]<<" ";
   }

   cout<<endl;


}



int32_t main()
{
    int tc = 1;
    // cin >> tc;

 
    while (tc--)
    {
        solve();
    }

    return 0;
}
