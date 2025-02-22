#include <stdio.h>
#include <stdlib.h>                  // it is  required for malloc()
#include <math.h>                    // it is required mathematical operations
#define n 30                         // Maximum number of operations
#define PI 3.14159265358979323846    // Definition of PI

void design();
double factorial();
double angle_value();
double number_value();
double power_value();
double decision(double* elements, int index);
void calculator_menu(int* choice);

int main(){
    
    double* elements = (double*) malloc(n * sizeof(double)); // Dynamically allocate memory to store up to n elements
    if(elements == NULL)  // If memory allocation fails, display error and exit
      {
       printf("The Calculator is out of order. \n");
       return 1; // Exit program if memory allocation fails
      }

    int choice , index=0;  // Initialize choice and index for menu operations

    double result =0.0;   // Initialize the result variable to store the ongoing result

    design();           // Display the calculator's design and menu

    result = decision( elements , index );  // Initial operation based on the user's choice
    index++;   // Increment the index after the first operation

    while(1)
    {
     if(index >= 30) // Check if the maximum number of operations has been exceeded
       {
        printf("You have exceeded the specified operation limit. \n");
        break;  // Exit loop if the limit is exceeded
        }
          
     calculator_menu(&choice);  // Display the calculator menu and get user's choice
          
     switch(choice)
     {
      case 1:
      result +=decision( elements , index );  
      index++;   // Increment index after the operation
      break;

      case 2:
      result -= decision( elements , index );
      index++;
      break;

      case 3:
      result *= decision( elements , index );
      index++;
      break;

      case 4:{   // Handle division case
      double divisor;
      while(1)
      {
       divisor = decision(elements, index);
       if(divisor == 0) // Prevent division by zero
         {
         printf("Division by zero is not allowed. Please enter a valid number. \n");
         continue;  // Ask for a valid number if zero is entered
         }
       result /=divisor;  
       break;  // Exit the loop once valid input is received
      }
      index++;
      break;}

      case 5:
      printf("The result is:%lf. \n" , result);
      break;

      case 6:
      printf("Checking Out. \n");
      free(elements);     //Free allocated memory before exiting
      exit(0);            //Exit the program    We don't need a break statement because exit()
                 
      default:
      printf("Invalid choice. Please enter a valid option. \n");
      break;
     }
    }

    free(elements);   // Free the allocated memory when the program exits 

return 0;}   // End of main function

void design(){
    
    printf("\n");
    printf("\t\t\t\t\t\t\t   *** DOGUKAN'S CALCULATOR ***\n\n");
    printf("\t\t\t\t\t\t\t----------------------------------\n");
    printf("\t\t\t\t\t\t\t|                                |\n");
    printf("\t\t\t\t\t\t\t|        TRIGONOMETRIC           |\n");
    printf("\t\t\t\t\t\t\t|                                |\n");
    printf("\t\t\t\t\t\t\t|    * Cosine (cos)              |\n");
    printf("\t\t\t\t\t\t\t|    * Sine (sin)                |\n");
    printf("\t\t\t\t\t\t\t|    * Tangent (tan)             |\n");
    printf("\t\t\t\t\t\t\t|    * Cotangent (cot)           |\n");
    printf("\t\t\t\t\t\t\t|    * Secant (sec)              |\n");
    printf("\t\t\t\t\t\t\t|    * Cosecant (csc)            |\n");
    printf("\t\t\t\t\t\t\t----------------------------------\n");
    printf("\t\t\t\t\t\t\t|                                |\n");
    printf("\t\t\t\t\t\t\t|          MISCELLANEOUS         |\n");
    printf("\t\t\t\t\t\t\t|                                |\n");
    printf("\t\t\t\t\t\t\t|    * Power (a^b)               |\n");
    printf("\t\t\t\t\t\t\t|    * Square Root (sqrt)        |\n");
    printf("\t\t\t\t\t\t\t|    * Factorial (fact)          |\n");
    printf("\t\t\t\t\t\t\t|    * Logarithm (log)           |\n");
    printf("\t\t\t\t\t\t\t----------------------------------\n");
    printf("\t\t\t\t\t\t\t|                                |\n");
    printf("\t\t\t\t\t\t\t|     * Addition (+)             |\n");
    printf("\t\t\t\t\t\t\t|     * Subtraction (-)          |\n");
    printf("\t\t\t\t\t\t\t|     * Multiplication (*)       |\n");
    printf("\t\t\t\t\t\t\t|     * Division (/)             |\n");
    printf("\t\t\t\t\t\t\t|     * Display Result           |\n");
    printf("\t\t\t\t\t\t\t|     * Exit                     |\n");
    printf("\t\t\t\t\t\t\t----------------------------------\n");

}

double factorial(){
   
    int number, i;
    double result=1.0;

    while(1)
    {
     printf("Enter a positive integer: \n");
     scanf("%d", &number);

     if(number < 0) // Factorial is not defined for negative numbers
       {
        printf("Factorial of a negative number is not defined. Please enter a positive integer. \n");
        continue; // Prompt user to enter a valid positive integer
       }

     for(i=1; i<=number; i++)
     {
      result *= i;
     }

     break;   // Break loop once valid factorial is calculated
    }

return result;}

double angle_value(){

    double angle;
    printf("Enter the angle in degrees: \n");
    scanf("%lf", &angle);

    while(angle < 0)  // Ensure the angle is non-negative
    {
     angle +=360;     // Adjust angle to be positive by adding 360 if negative
    }

    angle = fmod( angle , 360 ); // Normalize angle to be within 0 to 360 degrees thanks to fmod

return angle;}

double number_value(){

    double number;
    printf("Enter an  integer or decimal number: \n");
    scanf("%lf", &number);

return number;}

double power_value(){

    double base, power, result;
    
    while(1)
         {
          printf("Enter base and power: \n");
          scanf("%lf%lf", &base, &power);

          if((base == 0) && (power <= 0))  // Handle invalid base and power combinations
            {
             printf("Exponentiation is undefined for base 0 and negative power. Please enter valid values. \n");
             continue;   // Prompt user to enter valid values
            }

          result = pow(base, power);
          break;  // Exit loop once valid result is calculated
         }

return result;}

double decision(double* elements, int index){   // Function to decide what operation to perform based on user input
    
    int choice;   
    
    while(1)  // Loop until a valid choice is made
    {
     printf("Enter type of element \n");
     printf("1.Integer or decimal number \n");
     printf("2.Cosine  \n");
     printf("3.Sine  \n");
     printf("4.Tangent  \n");
     printf("5.Cotangent  \n");
     printf("6.Cosecant  \n");
     printf("7.Secant  \n");
     printf("8.Exponents \n");
     printf("9.Square root \n");
     printf("10.Factorial \n");
     printf("11.Logarithm \n");

     scanf("%d", &choice);

     switch(choice)
     {
      case 1:
      elements[index] = number_value();
      break;

     case 2:{
     double angle = angle_value();
     elements[index] = cos(angle * PI / 180.0);
     break;} 
                
     case 3:{
     double angle = angle_value();
     elements[index] = sin(angle * PI / 180.0);
     break;}
                      
     case 4:{
     while(1)
     {
     double angle = angle_value();

     if((angle == 90) || (angle == 270))   // Avoid invalid angles for tangent
       {
        printf("Invalid angle. Please enter a valid angle. \n");
        continue;
       }
     elements[index] = tan(angle * PI / 180.0);
     break;  
     }
     break;}

     case 5:{
     while(1)  // Loop until valid input is provided
     {
      double angle = angle_value();

      if((angle == 0) || (angle == 180))  // Avoid invalid angles for cotangent
        {
         printf("Invalid angle. Please enter a valid angle. \n");
         continue;
         }
      elements[index] = 1.0/ tan(angle * PI / 180.0);
      break;  
      }
     break;}

     case 6:{
     while(1)
     {
      double angle = angle_value();

      if((angle == 0) || (angle == 180))  // Avoid invalid angles for cosecant
        {
         printf("Invalid angle. Please enter a valid angle. \n");
         continue;
        }
      elements[index] = 1.0 / sin(angle * PI / 180.0);
      break; 
     }
     break;}

     case 7:{
     while(1)
     {
      double angle = angle_value();

      if((angle == 90) || (angle == 270)) // Avoid invalid angles for secant
        {
         printf("Invalid angle. Please enter a valid angle. \n");
         continue;
        }
      elements[index] = 1.0 / cos(angle * PI / 180.0);
      break;  
     }
     break;}

     case 8:
     elements[index] = power_value();
     break;

     case 9:{
     while(1)
     {
      double number = number_value();

      if(number < 0)
        {
         printf("Square root of a negative number is not defined. Please enter a valid value. \n");
         continue;
        }
      elements[index] = sqrt(number);
      break;  
     }
     break;}

     case 10:
     elements[index] = factorial();
     break;

     case 11:
     while(1){
     {
      double number = number_value();

      if(number <= 0)
        {
         printf("Logarithm of a non-positive number is not defined. Please entter a positive number. \n");
         continue;
        }
      elements[index] = log(number);
      break; 
     } 
     break;}

     default:
     printf("Invalid choice. Please enter valid choice. \n");
     continue;          
     }
     break;    
    }

return elements[index];}

void calculator_menu(int* choice){ // Function to display the calculator menu
 
    while(1)
    {
     printf("CALCULATOR MENU \n");
     printf("1.Addition \n");
     printf("2.Substraction \n");
     printf("3.Multiplication \n");
     printf("4.Division \n");
     printf("5.The result \n");
     printf("6.Exit \n");

     scanf("%d", choice);

     if((*choice >= 1) && (*choice <= 6))
       {
        break;
       }

     else
     {
      printf("Invalid choice please enter a valid option.");
      continue; 
     }        

    } 

}