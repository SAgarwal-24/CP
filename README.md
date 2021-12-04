# DSU MY TEMPLATE

```
class tree {

    int num_components;
    int nodes;
    int *par, *rank; //rank -> is size of component

 public:
    tree(int n){
        this->nodes = n;
        num_components = n;

        par = new int[n+1];
        rank = new int[n+1];

        for(int i=1; i<=n; i++)
         par[i] = -1,  rank[i] = 1;
    }

    

    int findset(int u){

        if(par[u]<0)
            return u;

        return par[u] = findset(par[u]); //path compression
    }

    void union_set(int u, int v){

        u = findset(u);
        v = findset(v);

        if(u==v)return;

        if(rank[u]>rank[v]){ //merge smaller into bigger
            par[v] = u; 
            rank[u]+=rank[v];
            rank[v]=0;
        }
        else{
            par[u] = v;
            rank[v] += rank[u];
            rank[u] = 0;
        }
    }

    int getSize(int u){  //to find size of a component 

        return rank[findset(u)];
    }

     void print(){

        for(int i=1; i<=nodes; i++){
            cout<<par[i]<<" - "<<i<<endl;
        }

        cout<<"----\n";
    }

    void print_rank(){

        for(int i=1; i<=nodes; i++){
            cout<<rank[i]<<" ";
        }

        cout<<"\n----\n";
    }
};

```





# (Concept of Modulo Multiplicative Inverse and Fermat little Theorem) 
# To calculate C(n,r) modulo 10^9+7 

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

```
int pow(int n, int i){
    int a=n,ans=1;
    while(i>0){
        if(i&1){
            ans=(ans*1LL*a)%MOD;
        }
        a=(a*1LL*a)%MOD;
        i=i>>1;
    }
    return ans;
}

int inv(int n){
    return pow(n, MOD-2);
}
int nCr(int n, int r){
    if(r>n)return 0;
    else{
        int res = f[n];
        res = (res*1LL*inv(f[r]))%MOD;
        res = (res*1LL*inv(f[n-r]))%MOD;
        return res;
    }
}

```


# To calculate C(n,r) efficiently without modulo

```
int ncr(int n, int r){

    if(n<r)
        return 0;

    if(r>n-r)
        r = n-r;

    /*  if(r==0)                (can also sepreately handle  this case )
            return 1;           (notice if r==0 then we get ans=1 )
    */

    int nr=1, den=1; 

    while(r){

        nr *= n;
        den *= r;

        int g = gcd(nr,den);

        nr /= g;
        den /= g;

        n--;
        r--;
    }

  
    return nr/den;       // or simply->  return nr; 
}
```

# General template for Binary Search on real values 

```
      long double ans=0.0, l=0, r=10000000;
    
    //change no of iterations acc. to requirements
    for(int iterations=0;iterations<100; iterations++){  //Alter for-loop can be while-loop->  while(r-l>1e-4) 

        long double mid = l+(r-l)/2;
      
        if(check_logic(mid)){
            ans = mid;
            l = mid;
        }else{
            r = mid ;
        }  
    }
 
  cout<<setprecision(20)<<ans<<endl;
  ```



