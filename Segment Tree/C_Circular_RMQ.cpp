//problem link: https://codeforces.com/contest/52/problem/C
//sol link: https://codeforces.com/contest/52/submission/136043668

/* -- some other links ----

  https://codeforces.com/contest/52/submission/136019819
  https://github.com/Waqar-107/Codeforces/blob/master/C-set/52C.Circular%20RMQ.cpp (definitely see this awesome oops based code too) 
  https://www.diffchecker.com/poybMGLa (changes in my initial wrong codes)
  
  http://gautamsegtree.blogspot.com/2015/10/circular-rmqrmq-in-circular-que.html (blogs written in 2015) 
  
*/

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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define vi vector<int>
#define vvi vector<vector<int>>
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

/* --- Guy who helped me to correct my mistake ....xd -----

    That guy:   https://codeforces.com/profile/Noble_Mushtak 

You are calculating the change wrong when you do updates.
 You calculate change by doing (ss-se+1)*new_val,
  but this is the change of the entire interval sum.
   We do not care about the entire interval sum, we only care about the minimum value. 
   And if we add all elements by new_val, the minimum value increases only by new_val. 
   So the change should just be new_val not (ss-se+1)*new_val.

I changed your solution to be correct here,
 if you want to see the correct version: https://codeforces.com/contest/52/submission/136019819
*/



/*
n=5

 1 2 3 4 

 query-1 : 3 0 -> min(4,1) -> 1
 query-2 : 3 0 -1 -> 4,1 -> 4-1,1-1 -> 3,0

 updated array : 0 2 3 3

 query-3 : 0 1 -> min(0,2) -> 0

 query-4 : 2 1 -> min(3,3,0,2) -> 0
 


*/



void build(vi &tree,int index,vi &a,int as,int ae){

     if(as==ae){
         tree[index] = a[as];
         return;
     }

     int mid = as + (ae-as)/2;

     build(tree,2*index,a,as,mid);
     build(tree,2*index+1,a,mid+1,ae);
    
    tree[index] = min(tree[2*index], tree[2*index+1]);
}

/* 
eg a[] = {1,2}

say information for range [ss to se] is stored at tree[index] 
ie

#correct (what we want)
 - tree[index] = min element in range [ss to se]  
 - ie each node is storing min element in range [ss to se] not the sum of elements in range
 
 #how to handle updates?
 - so when we need to update all elements by  '+x or -x' in range[ss to se]
 - we need to update each relevant node of segment tree 
 - tree[index] += change //change = increment or decrement

 #intitution for updates explained
 -  tree[index] = old_min
 -  tree[index] += change is equivalent to old_min = old_min + change
 - so  now we achieved new_min in range [ss to se]
 -  old_min = new_min  (as new_min = old_min + change)

 - 

#wrong (what I confused with initially)
 (- alert: don't confuse  with standard range sum 
  tree[index] = sum of elements in range [ss to se])

#Wrong, MyInitial mistake while updating segment tree node
- lazy[index] = change
- tree[index] += lazy[index]*(se-ss+1) 

*/

int query(vi &tree,vi &lazy,int index,int ss, int se,int qs,int qe){

    //handle lazy/pending updates
    if(lazy[index]!=0){

        int change = lazy[index];
        tree[index] += change;

        if(ss!=se)  //if not a leaf node then pass updates to left & right subtree(or ranges)
        lazy[2*index] +=lazy[index], lazy[2*index+1] += lazy[index];

        lazy[index]=0;
    }

    //full overlap
    if(qs<=ss  and  se<=qe)
        return tree[index];

    //no overlap
    if(se<qs || qe<ss)
        return 1e18;

    //partial overlap
    int mid = ss + (se-ss)/2;

    int left = query(tree,lazy,2*index,ss,mid,qs,qe);
    int ri  = query(tree,lazy,2*index+1,mid+1,se,qs,qe);

    return min(left, ri);

}   

void update(vi &tree,vi &lazy,int index,int ss, int se,int qs,int qe,int new_val){

    //handle lazy/pending updates
    if(lazy[index]!=0){

        int change = lazy[index];
        tree[index] += change;

        if(ss!=se)  //if not a leaf node then pass updates to left & right subtree(or ranges)
        lazy[2*index] +=lazy[index], lazy[2*index+1] += lazy[index];

        lazy[index]=0;
    }


    //full overlap
    if(qs<=ss and se<=qe){

        //since we want whole range [ss,se] (stored at tree[index])
        // therefore before using this stored info at tree[index]
        //  we need to update this range or information tree[index]

        tree[index] +=  new_val; //information or range [ss,se] updated

        if(ss!=se) // updates passed to subtree or subranges
        {
            lazy[2*index]   +=  new_val;
            lazy[2*index+1] +=  new_val;
        }

        return;
    }


    //no overlap
    if(se<qs || qe<ss)
        return;


    //partial overlap
    int mid = ss + (se-ss)/2;
    update(tree,lazy,2*index,ss,mid,qs,qe,new_val);
    update(tree,lazy,2*index+1,mid+1,se,qs,qe,new_val);

    tree[index] = min(tree[2*index], tree[2*index+1]);
}

void solve(){

    int i,n;
    cin>>n;

    vector<int>a(n);

    for(i=0;i<n;i++)
        cin>>a[i];

    
    vector<int>tree(4*n,0);
    vector<int>lazy(4*n, 0);

    build(tree,1,a,0,n-1);


    int q;
    cin>>q;

     string garbage;
     getline(cin,garbage);

    for(i=0;i<q;i++){
        string qry,intermediate;
        int l,r;
        vector<int>tokens;

        getline(cin,qry);
        stringstream s(qry);

        while (getline(s,intermediate,' '))
        {
            tokens.push_back(stoll(intermediate));
        }

        

        l = tokens[0];
        r = tokens[1];

        // cout<<l<<","<<r<<endl;
        // watch(tree);

        if(tokens.size()==3){

            int change = tokens[2];
            // watch(change);
            //update query

            if(l<=r){
                update(tree,lazy,1,0,n-1,l,r,change);
            }
            else{
                // ...r l... (r<l)
                update(tree,lazy,1,0,n-1,0,r,change);
                update(tree,lazy,1,0,n-1,l,n-1,change);
            }
        }   
        else{
            int ans=0;

            if(l<=r){
                ans = query(tree,lazy,1,0,n-1,l,r);
            }
            else{
                int p1 = query(tree,lazy,1,0,n-1,0,r);
                int p2 = query(tree,lazy,1,0,n-1,l,n-1);
                ans = min(p1,p2);
            }

            cout<<ans<<endl;

        }

        // watch(tree);
        // cout<<"-----\n";
    }
  
}

// Fuck rating 
// enjoy process and improvement(by red coders like colin)

int32_t main()
{
    fast int tc = 1;
    // cin >> tc;

 
    while (tc--)
    {
        solve();
    }

 

    return 0;
}
