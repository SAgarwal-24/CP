//https://www.codechef.com/problems/RECHEND
// if all elements of opp daignols are filled then its not possible to reach end

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


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



void solve(){
	int n; 
    cin>>n;

    map<int,int>sum;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;

        sum[x+y] +=1;
    }

    bool ok = true;

    for(auto it:sum){

        int num = it.first;
        int fre = it.second;

        if(num> n+1)
            num = num - 2*(num% (n+1) );
        
        if(num-1 == fre){
            ok = false;
            break;
        }
    }

    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";

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
