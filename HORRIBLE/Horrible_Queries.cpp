#include<bits/stdc++.h>

using namespace std;

#define mx 100005

typedef long long  lli;



lli arr[mx];
lli t[3*mx];
lli lazy[3*mx];

void build_tree(lli node, lli b, lli e)
{

    if(b==e)
    {

        t[node]=arr[b];
        return;

    }

    build_tree(node*2,b,(b+e)/2);
    build_tree(node*2+1,(b+e)/2+1,e);

    t[node] = t[node*2]+t[node*2+1];


}
lli query(lli node, lli b, lli e, lli i, lli j)
{


    if(b>j||e<i)
        return 0;

    if(lazy[node]!=0)
    {

        t[node] +=lazy[node]*(e-b+1);

        if(b!=e)
        {

            lazy[node*2]+=lazy[node];
            lazy[node*2+1] +=lazy[node];

        }

        lazy[node]=0;

    }

    if(b>=i&&e<=j)
        return t[node];


    lli s1=query(node*2,b,(b+e)/2,i,j);
    lli s2=query(node*2+1,(b+e)/2+1,e,i,j);

    return s1+s2;



}
void update(lli node, lli b, lli e, lli i, lli j, lli inc)
{



    if(lazy[node]!=0)
    {
        t[node] +=lazy[node]*(e-b+1);

        if(e!=b)
        {

            lazy[node*2]+=lazy[node];
            lazy[node*2+1] +=lazy[node];

        }

        lazy[node]=0;

    }


    if(e<i||b>j)
        return;


    if(b>=i&&e<=j)
    {



        t[node] +=(e-b+1)*inc;

        if(b!=e)
        {

            lazy[node*2]+=inc;
            lazy[node*2+1]+=inc;

        }



        return;

    }

    //cout<<"Hello"<<endl;
    update(node*2,b,(b+e)/2,i,j,inc);
    update(node*2+1,(b+e)/2+1,e,i,j,inc);

    t[node] = t[node*2]+t[node*2+1];

}


int main()
{

    lli T,n,qu,q,p,a;
    cin>>T;

    while(T--)
    {
        cin>>n>>qu;
        build_tree(1,0,n-1);
        for (lli i = 0; i < mx*3; ++i) lazy[i]=0;
        while(qu--)
        {
            cin>>a;
            if (a==0)
            {
                lli  inc;
                cin>>p>>q>>inc;
                update(1,0,n-1,p-1,q-1,inc);
            }
            else
            {
                cin>>p>>q;
                cout<<query(1,0,n-1,p-1,q-1)<<endl;
            }
        }

    }
    return 0;



}
