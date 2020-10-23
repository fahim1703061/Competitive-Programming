#include <bits/stdc++.h>

using namespace std;

int isprime[1000];

void siv(int n);
bool check(int n,int pos);
int  setflag(int n,int pos);

int main()
{

    int n=21000;
//    int n;
//    cin>>n;
    siv(n);
    for(int i = 1;i <=n; i++){
        if(check(isprime[i/32],i%32) == 0){
            cout<<i<<" ";
        }
    }

}

void siv(int n)
{
    isprime[1]=1;
    int rt = sqrt(n);
    for(int i = 4;i <=n; i+=2){
        isprime[i/32]=setflag(isprime[i/32],i%32);
    }
    for(int i = 3; i<=rt; i+=2){
        if(check(isprime[i/32],i%32) == 0){
            for(int j = i*i; j<=n; j+=2*i){
                isprime[j/32]=setflag(isprime[j/32],j%32);
            }
        }
    }
}

bool check(int n,int pos)
{
    return n & (1<<pos);
}

int setflag(int n, int pos)
{
    return n = n | (1<<pos);
}
