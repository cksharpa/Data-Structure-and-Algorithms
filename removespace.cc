#include<stdio.h>
#include<string.h>

int main()

{
    char s[] = "a,a,b,,,c,d,e..-";
    char *t;
    printf("splitting string \"%s\" into tokens:\n",s);
    //t=strtok(s,".-,");
    while(t!=NULL)
    {
        printf("%s",t);
        t=strtok(NULL,".-,");
    }
    return 0;

}
