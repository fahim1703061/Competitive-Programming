#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool isprime[100000002];
//long long primelist[100000002];
vector<int> primelist;
void printprime(ll p);

void siv(int n);

int main()
{

    int n=100003;
//    int n;
//    cin>>n;
    siv(n);
    primelist.push_back(2);
    //printf("hei");
    for(int i = 3;i <=n; i+=2){
        if(isprime[i] == 0){
            primelist.push_back(i);
        }
    }
    for (ll i = 2; i < 100000 + 1; i++)
    {
        //cout << i << ":";
        printf(" %lld:",i);

        printprime(i);
        //cout << endl;
        printf("\n");
    }
    
    
    
    //cout << primelist[5000000-4];

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

void printprime(ll p)
{
    //bool space = true;
    if(isprime[p] == 0 && p % 2 == 1){
        //cout << " " << p;
        printf(" %lld",p);
        return;
    }
    ll t = p;
    for (ll i = 0; primelist[i] * primelist[i] <= p; i++)
    {
        if((t) % (primelist[i]) == 0){
            //cout << " " << primelist[i];
            printf(" %d",primelist[i]);
            while (t % primelist[i] == 0)
            {
                t = t / primelist[i];

            }
            
        }
        if(t == 1){
            break;
        }
    }
    if(t > 1){
        //cout << " " << t;
        printf(" %lld",t);
    }
    
}
