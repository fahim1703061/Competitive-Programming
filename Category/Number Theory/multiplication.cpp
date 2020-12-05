#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll multiply(ll a, ll b, ll mod)
{
    a %= mod;
    ll result = 0;
    while(b){
        if(b & 1){
            result += a;
            result %= mod;
        }
        a <<= 1;
        a %= mod;
        b >>= 1;
    }
    return result % mod;
}

int main()
{
    cout << multiply(1,30,8);
}