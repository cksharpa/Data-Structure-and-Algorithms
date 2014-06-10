#include<stdio.h>

int stringcmp(char *s1, char *s2)
{
    int i;
    for(i=0;s1[i]&&s2[i];++i)
    {
        if(s1[i] == s2[i] ||(s1[i]^32) == s2[i])
            continue;
        else
            break;
    }
    if(s1[i] == s2[i])
        return 1;
    return 0;
}

int main()
{
    printf(" return value: %d", stringcmp("geeks","geeks"));
    return 0;
}
