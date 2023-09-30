//Coloring(Seating arrangement kind of or assigning colors and parallely satisfying some conditions)
//and observation based
//link: https://codeforces.com/contest/1551/problem/B2

//alter binary search solution: https://codeforces.com/contest/1551/submission/137076295

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

    //total elements we should consider for coloring
    int total=0; 

    for(auto it:mp){
        total += it.second.size();
    }

    //total elements which we are considering should be multiple of k
    //so that we can assign k colors equally 
    //Now we can say Condition-3 is satisfied 
    total = total - (total % k); 


    //Learning - How to think?? How to satisfy conditions separately one by one ??

    //Notice to make condition-1 and condition-2 satisfied
    //we removed extra elements for both of them 
    //ie elements with freq>k -> if(mp[element].size()<k){mp.pb(element_index)}
    //and total_elements must multiple of k -> total -= total%k

    int paint = 1;

    for(auto it:mp){

        int ele = it.first;

        for(auto ind: mp[ele]){

            out[ind] = paint;

            paint = (paint % k) + 1;

            total --;

            //total elements which we want to consider if reduced to zero
            //then simply stop and ignore remaining elements as they are not 
            //enough to consume all k colors
            if(total==0)goto _output;
        }
    }


_output:
    for(i=0;i<n;i++){
        cout<< out[i] <<" ";
    }

    // watch(a);
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
