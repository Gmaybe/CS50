#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int height;
   do
   {
       height = get_int("Enter a Height between 1 and 8: ");
   }
   while (height < 1 || height > 8);

   for(int i = 0; i < height; i++)
   {
      for(int j = 1; j <= height; j++)
      {
         if (j >= height - i)
         {
            printf("#");
         }
         else
         {
            printf(" ");
         }
      }
      printf("\n");

   }
}