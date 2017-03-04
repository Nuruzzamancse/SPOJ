#include<bits/stdc++.h>

using namespace std;

int main()
{

    int input;

    cin>>input;

    int arra[input+5],sum[input+5]= {0};

    for(int i=0; i<input; i++)
    {
        cin>>arra[i];

        if(i>0)
            sum[i] = arra[i] + sum[i-1];
        else
            sum[i] = arra[i];


    }

    /*for(int i=0;i<input;i++)
        cout<<sum[i]<<' ';*/

    int query,left, right;

    cin>>query;

    while(query--)
    {

        cin>>left>>right;

        if(left!=right&&left>0)
            cout<<sum[right]-sum[left-1]<<endl;
        else if(left!=right&&left==0)
            cout<<sum[right]<<endl;
        else if(left==right&&left>0)
            cout<<sum[right]-sum[left-1]<<endl;

        }

}