#include <bits/stdc++.h>

using namespace std;

#define ll long long int

//---Miller-Robin primality test-- starts here--

//multiply to avoid overflow
ll multiply(ll a, ll b, ll mod)        //a*b % mod
{
    a %= mod;
    ll result = 0;
    while(b){
        if(b & 1){
            result += a;
            result %= mod;
        }
        a += a;
        a %= mod;
        b >>= 1;
    }
    return result % mod;
}
// bigmod b^p % m
ll bigmod(ll b_int, ll p_int, ll m_int)
{
    ll result = 1;
    b_int %= m_int;
    while(p_int){
        if(p_int & 1){
            result = multiply(result, b_int, m_int);
        }
        b_int = multiply(b_int, b_int, m_int);
        p_int >>= 1;
    }
    return result % m_int;
}

bool testingComposite(ll a, ll d, ll n, ll r)     //returns true if the n is composite
{
    ll val = bigmod(a, d, n);                   // a^d % n
    if(val == 1 || val == n-1){
        return false;
    }
    for (ll i = 1; i < r; i++)
    {
        val = ((val % n) * (val % n)) % n;
        if(val == n-1){
            return false;
        }
    }
    return true;
    
}
// Miller-Robin primality test
bool millerRobinTest(ll p)                 // returns true if p is prime
{
    ll r = 0;
    ll n = p;
    ll d = 0;
    if (p == 2)
    {
        return true;
    }
    if(!(p & 1))
    {
        return false;
    }
    n = n - 1;
    
    while ((n & 1) == 0)
    {
        n = n >> 1;
        r++;
        //cout << "false"<<n;
    }
    d = n;
    ll smallbase[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (ll i = 0; i < 9; i++)
    {
        if(smallbase[i] == p){
            return true;
        }
        if(testingComposite(smallbase[i], d, p, r)){
            cout << "falsecomp"<<smallbase[i];
            return false;
        }
    }
    return true;
    
    
}

int main()
{
    ll t = 3;
    cout << millerRobinTest(t) << endl;
    for (ll i = 3; i < t; i+=2)
    {
        if(t % i == 0){
            cout << "prime " << i <<endl;
        }
    }
    cout<<"not prime" <<endl;
    
}