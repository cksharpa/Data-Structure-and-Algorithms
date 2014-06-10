#include <time.h>
#include<stdio.h>
int main()
{

     time_t currtime;
     struct tm * timeinfo;
     char buffer [80];
 
     time ( &currtime );
     timeinfo = localtime ( &currtime );
 
     strftime (buffer,80,"%H%M%S.txt",timeinfo);
     puts (buffer);
    
   FILE *fil1;
   fil1=fopen(buffer,"w");

return 0;
}
