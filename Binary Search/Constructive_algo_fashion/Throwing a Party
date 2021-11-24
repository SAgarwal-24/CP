//one of the gem questions

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

struct people{

    int at_most_richer=0;
    int at_most_poorer=0;
    
};

//while solving this kind of constructive / adhoc flavour problem
//1. we can remove confusion by thinking like
// in this question it seems like "we have to play with different subsequences of people"
//ie the subsequence of people which can be invited safely
//but the trick is we need to output only count of people not the exact subsequence

//2. and there are 2 unknowns - 
// how many poorer person wrt to each one? = poors (say)
// how many richer person wrt to each one? = richers (say)
// ie we don't know how many people = total = poors + richers ?? (3 unknowns) -> unknown = unknown + unknown
// so many unkowns ie we have to fix something for a moment and make someone 'known'
// so lets fix total no of people 
// ie now -> known = unknown + unknown 

//and use relation poor = total-rich ->    unknown = known - unknown (see actual code to understand now onwards)

/*
-> Main greedy logic for finding a subsequence of size 'mid' (while implementing BS in code) is
-> say we start from i=0 and go till i<n
-> and since all person are in sorted order acc to wealth

-> ie  [poorest , 2nd poorest, 3rd......, 2nd richest, richest]
-> observation:
   1. whatever 1st person we choose will be the poorest of the choosen subsequence 
   and should be in happy with having atleast mid-1 richer person 

   2. vice versa for richest guy ie last person of subsequence

   3. for ith person -> he should be happy with i-1 poorer and  (mid-1 - (i-1)) richer

*/

void solve(){
	
    int i,n;
    cin>>n;
    
    vector<people>a(n);

    for(i=0;i<n;i++){
        cin>>a[i].at_most_richer;
        cin>>a[i].at_most_poorer;
    }

    int invites = n;

    //if x invites are possible then x-1 are definitely possible 
    //bcz once we find 'x' invites are possible 
    //(ie invite_1,invite_2,...invite_x)
    //then simply drop anyone of them say invite_1 or invite_2 or...invite_x
    //we will left with x-1 people

    //dry run of sample tc it's easy to understand

    int lo=0,  hi=n;
    while(lo<=hi){

        int mid = lo + (hi-lo)/2;

        int now=0; //till now invites possible (when we are exploring whether we can call 'mid' no of invites or not)
        for(i=0;i<n;i++){

            if( (a[i].at_most_poorer >= now) && (a[i].at_most_richer >= mid-1-now)){
                now++;
            }
        }

        if(now>=mid){
            invites = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }

    }

    cout<<invites<<endl;
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
