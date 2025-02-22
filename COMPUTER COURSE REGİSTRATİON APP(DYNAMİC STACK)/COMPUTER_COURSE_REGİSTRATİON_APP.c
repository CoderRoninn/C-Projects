#include <stdio.h>
#include <stdlib.h>

// Structure definition for Stack (Node)
typedef struct Stack{
    char phone_number[12];
    char name[50];
    char surname[50];
    float grade;
    struct Stack* next;
}Node;

// Function declarations
Node* add_trainee(Node* top);    // Adds a trainee to the stack
Node* delete_trainee(Node* top); // Deletes a trainee from the stack
void show_trainee(Node* top);    // Displays all trainees
void discount(Node* top);        // Applies discount (displays trainees with grade >= 67.5)

int main(){

    Node* top = NULL;  // Initialize top as NULL (empty stack)
    int choice;
    
    printf("\t\t\t\t****WELCOME****\n");
    while(1)          // Infinite loop for menu options
    {
     printf("1.Add trainee\n");
     printf("2.Delete trainee\n");
     printf("3.Show trainees\n");
     printf("4.Apply discount\n");
     printf("5.Exit\n");
     scanf("%d", &choice);
     
     // Switch case for handling different options
     switch(choice)
     {
      case 1:
      top = add_trainee(top);
      break;

      case 2:
      top = delete_trainee(top);
      break;

      case 3:
      show_trainee(top);
      break;

      case 4:
      discount(top);
      break;

      case 5:
      printf("Checking Out. \n");
      exit(0);  // Exit the program
      break;

      default:
      printf("Invalid choice. Enter a valid choice. \n");
      break;
     }

    }

return 0;}

Node* add_trainee(Node* top){
    
    Node* new_trainee = (Node*) malloc(sizeof(Node));  // Allocate memory for new trainee

    if(new_trainee == NULL)   // Check if memory allocation failed
    {
        printf("Adding trainee failed. \n");  
        return top;    // Return current stack if allocation fails
    }
    // Ask user to input trainee information
    printf("Enter trainee's name: \n");
    scanf("%s", new_trainee->name);
    printf("Enter trainee's surname: \n");
    scanf("%s", new_trainee->surname);
    printf("Enter trainee's phone number: \n");
    scanf("%11s", new_trainee->phone_number);  // %11 to prevent overflow
    printf("Enter trainee's computer exam grade: \n");
    scanf("%f", &new_trainee->grade);
    
    if(top == NULL)
    {
        new_trainee->next = NULL;
        top = new_trainee;
    }
    else
    {
        new_trainee->next = top;  // Link the new trainee to the previous one
        top = new_trainee;         // Update top to the new trainee
    }   

    return top;
}

Node* delete_trainee(Node* top){
    
    if(top == NULL)
    {
       printf("There are no trainees to delete. \n");
       
    }
    else
    {
     Node* temp = top->next;  // Temporary node to store the next trainee
     printf("%s %s successfully deleted. \n", top->name, top->surname);
     free(top);    // Free memory allocated for the top trainee
     top = temp;   // Update top to the next trainee
    }  

return top;}  // Return the updated stack

void show_trainee(Node* top){
    
    if(top == NULL)
    {
       printf("There are no trainees to show. \n");
       return;
    }

    Node* temp = top;  // Temporary node to traverse the stack
    int count = 1;

     // Loop through the stack and display trainee information
    while(temp != NULL)
    {
     printf("%d.Name:%s  Surname:%s  Phone number:%s  Grade:%.2f \n", count, temp->name, temp->surname,
     temp->phone_number, temp->grade);
     count++;
     temp = temp->next;  // Move to the next trainee
    }  
}

void discount(Node* top){
    
    if(top == NULL)  // If no trainees in the stack
    {
       printf("There are no trainees to apply discount. \n");
    }
    else{
     Node* temp = top;
     float discount_grade = 67.5;   // Discount threshold
     int count = 1;
     
     printf("Discount winners for new year: \n");

     while(temp != NULL)  // Traverse the stack and apply discount to trainees with grades >= 67.5
     {
      if(discount_grade <= temp->grade)
        {
         printf("%d.Name:%s  Surname:%s \n", count, temp->name, temp->surname);
         count++;
        }
      temp = temp->next;  
     }}
    
}
