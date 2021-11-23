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


# To calculate C(n,r) without modulo
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

