#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int coin[n];
    bool in[n]={false};

    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
        if(coin[i]==1 || coin[i]==2  || coin[i]==5  || coin[i]==10  || coin[i]==20 ||  coin[i]==50 || coin[i]==100  || coin[i]==200  || coin[i]==500 || coin[i]==1000)
        {
            in[i]=true;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!in[i])
        {
            printf("invalid note found\n");
            return 0;
        }
    }
    int total=-1,ans=0;
    cin>>total;
    sort(coin,coin+n,greater<int>());
    for(int i=0;i<n;i++)
    {
        if(total>=coin[i])
        {
            ans+=total/coin[i];
            total=total%coin[i];
        }
    }
    if(total==0)
        cout<<ans<<endl;
    if(total>0)
        cout<<"Not possible\n";
    if(total==-1)
        cout<<"invalid input\n";

    return 0;
}