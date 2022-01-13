#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//using namespace std;

int main()
{
    char ch ;      //= 'a';
    char str[100];   //="language";  
    char stn[100];   //="welcome to c!!";
    
    scanf("%c",&ch);
    printf("%c\n",ch);   //cout<<ch<<endl;
    scanf("\n");

    gets(str);
    puts(&str[0]);            //cout<<" language "<<str<<endl;

    gets(stn);
    puts(&stn[0]);               //cout<<" welcome to c!!"<<stn;
    

    return 0;
}