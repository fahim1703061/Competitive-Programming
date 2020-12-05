#include <bits/stdc++.h>


using namespace std;
#define ll long long

bool isprime[10000002];
//long long primelist[100000002];
vector<ll> primelist;
void totaldiv(ll p);

void siv(int n);



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
    ll val = bigmod(a, d, n);                 // a^d % n
    //cout << " "<< r << endl;
    if(val == 1 || val == n-1){
        return false;
    }
    for (ll i = 1; i < r; i++)
    {
        val = multiply(val, val, n);
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
    if (p < 2)
    {
        return false;
    }
    if(!(p & 1))
    {
        return false;
    }
    n = n - 1;
    
    while (!(n & 1))
    {
        n = n >> 1;
        r++;
    }
    d = n;
    ll smallbase[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ll i = 0; i < 12; i++)
    {

        if(smallbase[i] == p){
            return true;
        }

        if(testingComposite(smallbase[i], d, p, r)){
            //cout << "false";
            return false;
        }
    }
    return true;
    
    
}



int main()
{

    ll n=10000003;
//    int n;
//    cin>>n;
    siv(n);
    primelist.push_back(2);
    //printf("hei");
    for(ll i = 3;i <=10000000; i+=2){
        if(isprime[i] == 0){
            primelist.push_back(i);
        }
    }

    ll t;
    ll num_t;
    vector <ll> num;
    cin >> t;
    
    while (t > 0)
    {
        t--;
        scanf("%lld", &num_t);
        //num.push_back(num_t);
        totaldiv(num_t);
    }
  

}

void siv(int n)
{
    isprime[1]=1;
    int rt = sqrt(n);
//    for(int i = 4;i <=n; i+=2){
//        isprime[i]=1;
//    }
    for(int i = 3; i<=rt; i+=2){
        if(isprime[i] == 0){
            for(int j = i*i; j<=n; j+=2*i){
                isprime[j]=1;
            }
        }
    }
}

void totaldiv(ll p)
{
    //bool space = true;
    ll total = 1;
    ll sum = 0;
    
    ll t = p;
    for (ll i = 0; i<primelist.size() && primelist[i] * primelist[i] * primelist[i] <= t; i++)
    {
        if((t) % (primelist[i]) == 0){
            //cout << " " << primelist[i];
            //printf(" %d",primelist[i]);
            sum = 0;
            while (t % primelist[i] == 0)
            {
                t = t / primelist[i];
                sum+=1;

            }
            total = total * (sum + 1);
            
        }
        if(t == 1){
            break;
        }
    }
    if(t > 1){
        //cout << " " << t;
        //printf(" %lld",t);
        //total = total * 2;
        ll rt = sqrt(t);
        if(rt * rt == t){
            total*= 3;
        }
        //else if(t <=1000000 && (t & 1) && isprime[t] == 0){
        //    total = total * 2;
        //}

        else if(millerRobinTest(t)){
            total = total * 2;
        }
        
        else
        {
            total *= 4;
        }
        
    }
    //printf("%lld",total);
    printf("%lld\n",total);
    
    
}
