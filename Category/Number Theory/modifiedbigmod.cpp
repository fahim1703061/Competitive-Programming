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