#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int random_number, quess_number, score = 100;

    srand(time(NULL));
    random_number = rand() % 100 + 1;
    printf("Welcome to the number guessing game. \n");

    while(1)
    {
     printf("Enter a number between 1 and 100: \n");
     scanf("%d", &quess_number);

     if(quess_number == -1)
       {
        printf("Invalid number. Checking Out... \n");
        break;
       }

     if(quess_number < 1 || quess_number > 100)
       {
        printf("Invalid number. Enter a valid number. \n");
        continue;
       }
       
     if(quess_number == random_number)
       {
        printf("You guessed the number correctly. \n");
        break;
       } 
     else
     {
      if(quess_number > random_number)
        {
         printf("Enter a smaller number. \n");
        }
      else
      {
       printf("Enter a larger number. \n");
      } 
      score -= 10; 
     } 
  
    }
    
    printf("Your score is %d \n", (score < 0) ? 0 : score);

return 0;}