#include <bits/stdc++.h>

using namespace std;

int main ()
{

    int test;

    scanf("%d",&test);

    while(test--)
    {
    int number;

    scanf("%d",&number);

    getchar();

    int pnumber = number;
    char str[1000006];

    char ch;
    int k=0;
    while(number)
    {
        scanf("%c",&ch);

        if(ch==' ')
            continue;
        if(ch=='\n')
            break;
        str[k++] = ch;
        number--;

    }

    str[k] = '\0';

    if(next_permutation(str,str+pnumber))
        printf("%s\n",str);
    else
        printf("-1\n");
    }

    return 0;
}