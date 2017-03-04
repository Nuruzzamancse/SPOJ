#include<bits/stdc++.h>

using namespace std;

int getweight(char ch)
{
    switch(ch)
    {

    case '-':
        return 1;

     case '+':
        return 2;
     case '*':
        return 3;
     case '/':
        return 4;
     case '^':
        return 5;

     default:
        return 0;


    }
}
void postfix(char str[],int siz)
{
    stack<char> operatr;
    vector<char>operand;

    char ch;

    operatr.push('(');

    for(int i=0;i<siz+1;i++)
    {
        ch = str[i];

        if(getweight(ch)==0&&(ch!='('||ch!=')')){
                operand.push_back(ch);


        }
        if(ch=='('){
           operatr.push(ch);
        }
        if(getweight(ch))
        {
             while(getweight(ch)<=getweight(operatr.top()))
                {
                    if(operatr.top()!='('||operatr.top()!=')')
                     operand.push_back(operatr.top());

                    operatr.pop();
                }
                operatr.push(ch);
        }
        if(ch==')')
        {
            while(operatr.top()!='(')
            {
                operand.push_back(operatr.top());

                operatr.pop();
            }
            operatr.pop();
        }

    }

    int i=operand.size();

    for(int j=0;j<i;j++){
            if(operand[j]=='('||operand[j]==')')
            continue;
        cout<<operand[j];
    }
    cout<<endl;

}

int main()
{


    int test;

    scanf("%d",&test);

    getchar();

    char str[500];
    while(test--){

    gets(str);

    int siz = strlen(str);

    str[siz] = ')';

    str[siz+1] = '\0';

    postfix(str,siz);

    }

    return 0;
}