
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, Max, p;
    ifstream f("date.in");
    int v[10], l[10], poz[10];
    f>>n;
    for ( i=1; i<=n; i++)
       f>>v[i];
    l[n]=1;
    poz[n]=0;
    for(i=n-1; i>=1; i--)
    {

        Max=0;
        p=0;
        for(int j=i+1; j<=n; j++)
            if(l[j]>Max && v[i]<v[j])
            {
                Max=l[j];
                p=j;
            }
        l[i]= 1+ Max;
        poz[i]=p;
    }
    Max=0;
    p=0;
    for(i=1; i<=n; i++)
        if(Max<l[i])
        {
            Max=l[i];
            p=i;
        }
    while(p)
    {
        cout<<v[p]<<" ";
        p=poz[p];
    }
    return 0;
}
