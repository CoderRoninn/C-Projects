#include <stdio.h>
#include <string.h>

//Maximum number of books allowed in the library
#define MAX_BOOK 100

// Structure for Book
struct Book{
    int id;
    char title[50];
    char author[50];
    int is_borrowed;
    int student_id;
};
// Structure for Library
struct Library{
    struct Book books[MAX_BOOK];
    int book_count;
};

// Function prototypes
void add_book(struct Library* library, int id, const char* title, const char* author);
void list_books(struct Library* library );
void search(struct Library* library, int id);
void borrow_book(struct Library* library, int id, int student_id);
void return_book(struct Library* library, int id);

int main(){

    struct Library library;
    library.book_count = 0;// Initially, no books in the library
    
    int student_id, id;
    int choice;
    char title[50], author[50];
    do{
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. List All Book\n");
        printf("3. Search Book by ID\n");
        printf("4. Rent Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: // Add a new book to the library
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Title: ");
            getchar(); // To clear the newline left by scanf
            fgets(title, sizeof(title), stdin); // Read book title
            title[strcspn(title, "\n")] = 0;// Remove the newline character

            printf("Enter Author: ");
            fgets(author, sizeof(author), stdin); // Read author name
            author[strcspn(author, "\n")] = 0;// Remove the newline character

            add_book(&library, id, title, author); // Add book to the library
            break;

            case 2: // List all the books in the library
            list_books(&library);
            break;

            case 3: // Search for a book by ID
            printf("Enter book ID to search:\n");
            scanf("%d", &id);
            search(&library, id);
            break;

            case 4: // Borrow a book from the library
            printf("Enter book ID to borrow:\n");
            scanf("%d" ,&id);
            printf("Enter student ID:");
            scanf("%d", &student_id);
            borrow_book(&library, id, student_id);
            break;

            case 5:  // Return a borrowed book
            printf("Enter book ID to return:\n");
            scanf("%d", &id);
            return_book(&library, id);
            break;

            case 6:  // Exit the program
            printf("Checking Out...\n");
            break;

            default:  // Invalid choice made by user
            printf("Invalid choice. Please try again.\n");
        }

    }while(choice != 6);

return 0;}

// Function to add a new book to the library
void add_book(struct Library* library, int id, const char* title, const char* author){

    if(library->book_count < MAX_BOOK){ // Check if there is space for more books

        if(strlen(title) == 0 || strlen(author) == 0){ 
            printf("Invalid input. Please enter a valid title and author. \n");
            return;
        }

        struct Book new_book; // Create a new book instance
        new_book.id = id;
        strcpy(new_book.title, title);  // Copy title to book structure
        strcpy(new_book.author, author);
        new_book.is_borrowed = 0; // Initially, the book is not borrowed
        new_book.student_id = -1; // No student has borrowed the book yet

        library->books[library->book_count++] = new_book; // Add the book to the library's books array
        printf("Book added.\n");
    }else{
        printf("Library is full, can not add book.\n");
    }
}

// Function to list all the books in the library
void list_books(struct Library* library){

    if(library->book_count == 0){  // If no books are available in the library
        printf("Library is empty. \n");
        return;
    }

    printf("All Books:\n");
    printf("%-5s %-20s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------------\n");

    int i;
    for(i=0; i<library->book_count; i++){
        printf("%-5d %-20s %-20s %-10s\n", library->books[i].id, library->books[i].title, library->books[i].author,
            library->books[i].is_borrowed ? "Borrowed" : "Available"); // Check borrowing status and print accordingly
    }
}

// Function to search for a book by its ID
void search(struct Library* library, int id){
    
    int i;
    for(i=0; i<library->book_count; i++){
        if(library->books[i].id == id){
            printf("Book found!\n");
            printf("ID: %d\n", library->books[i].id);
            printf("Title: %s\n", library->books[i].title);
            printf("Author: %s\n", library->books[i].author);
            printf("Status: %s\n", library->books[i].is_borrowed ? "Borrowed" : "Available");
            printf("Student ID: %d\n", library->books[i].student_id);
            return;
        }
    }
    printf("Book not found. \n");
}

// Function to borrow a book from the library
void borrow_book(struct Library* library, int id, int student_id){

    int i;
    for(i=0; i<library->book_count; i++){
        if(library->books[i].id == id){
            if(library->books[i].is_borrowed){
                printf("This book is already borrowed.\n");
            }else{
                library->books[i].is_borrowed = 1; // Mark the book as borrowed
                library->books[i].student_id = student_id;
                printf("Book borrowed.\n");
            }
            return;
        }
    }
    printf("Book id not found.\n");
}

// Function to return a borrowed book to the library
void return_book(struct Library* library, int id){

    int i;
    for(i=0; i<library->book_count; i++){
        if(library->books[i].id == id){
            if(library->books[i].is_borrowed){
                library->books[i].is_borrowed = 0; // Mark the book as returned
                library->books[i].student_id = -1;  // Reset student ID
                printf("Book returned. \n");
            }else{
                printf("This book is already in the library. \n");
            }
            return;
        }
    }
    printf("Book id not found. \n");
}