#include<stdlib.h>
#include<stdio.h>
//#define NO_OF_CHARS 256
 
/* Returns an array of size 256 containg count
   of characters in the passed char array */
int *countingChar(char *str)
{
   int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
   int i;
   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;
   return count;
}
 
/* The function returns index of first non-repeating
   character in a string. If all characters are repeating
   then returns -1 */
int getUniqueCharacter(char *stream)
{
  int *count = countingChar(stream);
  int index = -1, i;
 
  for (i = 0; *(stream+i);  i++)
  {
    if (count[*(stream+i)] == 1)
    {
      index = i;
      break;
    }  
  } 
   
 // free(count);
  return index;
}

int main()
{
  char stream[] = "aAbBABac";
  int index =  getUniqueCharacter(stream);
  if (index == -1) 
    printf("Not Found");
  else
   printf("First non-repeating character is %c", stream[index]);
   return 0;
}

