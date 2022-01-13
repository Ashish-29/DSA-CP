#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";

    int i1;
    double d1;
    char s1[100];

    scanf("%d",&i1);
    scanf("%lf\n",&d1);
    gets(s1);
    strcat(s,s1);

    // printf("%c\n",s1[0]);

    printf("%d\n",(i+i1));
    printf("%0.1lf\n",(d+d1));
    puts(s);
    puts(s1);
    
    return 0;
}