//������10��

#include <stdio.h>
#include <conio.h>
   int main()
{
  int i,j;
  printf("\1\1\n"); /*�������Ц��*/
  for(i=1;i<11;i++)
  {
    for(j=1;j<=i;j++)
      printf("%c%c",2,2);
    printf("\n");
  }
  return 0; 
}

