#include<bits/stdc++.h>

using namespace std;


int main()
{
    char str[105];

    stack<int>st;

    gets(str);

    for(int i=0; str[i]; i++)
    {

        if(isdigit(str[i]))
        {
            int m = str[i] - '0';
            int  k = st.top();
            st.pop();
            int temp = m*k;
            st.push(temp);
        }
        else if(str[i]==')')
        {
            int t =0;
            while(!st.empty()&&st.top()!=-10)
            {
                t = t + st.top();
                st.pop();
            }
            st.pop();
            st.push(t);
        }
        else if(str[i]=='H')
            st.push(1);
        else if(str[i]=='O')
            st.push(16);
        else if(str[i]=='C')
            st.push(12);
        else if(str[i]=='(')
            st.push(-10);

    }

    int sum=0;
    while(!st.empty())
    {
        sum+=st.top();
        st.pop();
    }
    cout<<sum<<endl;

    return 0;
}