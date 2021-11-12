//  constructive algorithms + implementation based - So the proof is also awesome and alien when tried first time to think
// link: https://codeforces.com/contest/1602/problem/B
// resource: https://www.youtube.com/watch?v=TkfIa1sFTBU (awesome explanation of proof)

#include <bits/stdc++.h>

#define all(c) c.begin(), c.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define int long long

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


int expo(int a, int b){

    // a^b  = a ^ (101...) = a^(binary format of b) = O(log(b))

    int res = 1;

    while(b){

        if(b&1)
            res = res * a;

        a = a*a;
        b = b>>1;
    }

    return res;

}



void solve(){

   
    int i,j,n,q;

    cin>>n;

    int mx = (int)log2(n);


    vector<vector<int>>a(mx+2,vector<int>(n,0));

    for(i=0;i<n;i++)
        cin>>a[0][i];

    

    for(i=1;i<=mx+1;i++){

        int cnt[2001]={0};

        for(j=0;j<n;j++){
            cnt[a[i-1][j]] += 1;
        }

        for(j=0;j<n;j++){
            a[i][j] = cnt[a[i-1][j]];
        }

    }

    // cout<<a<<endl;
    
    cin>>q;
  
    for(i=0;i<q;i++){
        int k,ind;
        cin>>ind>>k;

        ind--;
        k = min(k,mx+1);

        cout<<a[k][ind]<<endl;
    }


    return;
}





int32_t main()
{

    int tc = 1;
    cin >> tc;

 
    while (tc--)
    {
        solve();
    }


    return 0;
}

