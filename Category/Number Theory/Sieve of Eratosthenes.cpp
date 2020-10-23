#include <bits/stdc++.h>

using namespace std;

int isprime[100000002];

void siv(int n);

int main()
{

    int n=100000000;
//    int n;
//    cin>>n;
    siv(n);
    for(int i = 1;i <=n; i++){
        if(isprime[i] == 0){
            cout<<i<<" ";
        }
    }

}

void siv(int n)
{
    isprime[1]=1;
    int rt = sqrt(n);
    for(int i = 4;i <=n; i+=2){
        isprime[i]=1;
    }
    for(int i = 3; i<=rt; i+=2){
        if(isprime[i] == 0){
            for(int j = i*i; j<=n; j+=i){
                isprime[j]=1;
            }
        }
    }
}
