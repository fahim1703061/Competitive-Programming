#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool isprime[100000002];
//long long primelist[100000002];
vector<int> primelist;

void siv(int n);

int main()
{

    int n=90000000;
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
    int k;
    int q;
    cin >> q;
    while (q>0) {
        q--;
        cin >>k;
        cout << primelist[k-1] <<endl;
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
