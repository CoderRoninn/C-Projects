#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define SUITS 4

typedef struct card{
    char* face;
    char* suit;
}Card;

void fillDeck(Card* wDeck, char* const face[], char* const suit[]);
void showDeck(Card* wDeck);
void shuffle(Card* wDeck);
void design();

int main(){

    char* face[]={"Ace" ,"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    char* suit[]={"Hearts", "Clubs", "Diamonds", "Spades"};
    Card deck[52];
    design();
    
    fillDeck(deck, face, suit);
    printf("\nBEFORE SHUFFLE\n");
    showDeck(deck);
    printf("\n-----------------");

    srand(time(NULL));
    shuffle(deck);
    printf("\nAFTER SHUFFLE\n");
    showDeck(deck);


return 0;}

void fillDeck(Card* wDeck, char* const face[], char* const suit[]){

    int i, j, count = 0;

    for(i=0; i<SUITS; i++)
       {
        for(j=0; j<FACES; j++)
           {
            wDeck[count].suit = suit[i];
            wDeck[count].face = face[j];
            count++;
           }
       }
       
}

void showDeck(Card* wDeck){

    int i;

    for(i=0; i<CARDS; i++)
       {
        printf("%d. %s of %s\n", i+1, wDeck[i].face, wDeck[i].suit);
       }

}

void shuffle(Card* wDeck){
    
    Card temp;
    int i, j;

    for(i=0; i<CARDS; i++)
       {
        temp = wDeck[i];
        j = rand() % CARDS;
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
       }

}

void design() {

    printf("\n\n\t\t\t\t***WELCOME TO 21'S CASINO***\n");
    printf("\t\t\t      ___________________________\n");
    printf("\t\t\t     /                           \\\n");
    printf("\t\t\t     |   _____           _____    |\n");
    printf("\t\t\t     |  |     |         |     |   |\n");
    printf("\t\t\t     |  |  A  |         |  Q  |   |\n");
    printf("\t\t\t     |  |     |         |     |   |\n");
    printf("\t\t\t     |  |_____|         |_____|   |\n");
    printf("\t\t\t     |                            |\n");
    printf("\t\t\t     |   _____   _____   _____    |\n");
    printf("\t\t\t     |  |     | |     | |     |   |\n");
    printf("\t\t\t     |  |  7  | |  3  | |  8  |   |\n");
    printf("\t\t\t     |  |     | |     | |     |   |\n");
    printf("\t\t\t     |  |_____| |_____| |_____|   |\n");
    printf("\t\t\t     |                            |\n");
    printf("\t\t\t     |   _____   _____   _____    |\n");
    printf("\t\t\t     |  |     | |     | |     |   |\n");
    printf("\t\t\t     |  |  2  | |  4  | |  6  |   |\n");
    printf("\t\t\t     |  |     | |     | |     |   |\n");
    printf("\t\t\t     |  |_____| |_____| |_____|   |\n");
    printf("\t\t\t      \\___________________________/ \n");
    
}