#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>

/*
 Name:نبيل ياسر نبيل
 Sec:4
 BN:34
 Name:يوسف اسماعيل محمد
 Sec:4
 BN:51
 Name:محمود محمد السيد
 Sec:4
 BN:3
 */
struct students { char Name[20];
    int ID ;
    int year; int month; int day;
    int Score;};
struct node {
    struct students student;          // Data
    struct node *next; // Address
};



// Display entire list
void printList(struct node** head)
{
    struct node *temp;

    // Return if list is empty
    if(*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = *head;
    while(temp != NULL)
    {

        printf("Student Name= %s\n", temp->student.Name); // Print data of current node
        printf("Student ID= %d\n", temp->student.ID);
        printf("Student Birth (DD/MM/YYYY)= %d/%d/%d\n", temp->student.day,temp->student.month,temp->student.year);
        printf("Student Score= %d\n", temp->student.Score);
        printf("\n");
        temp = temp->next;                 // Move to next node
    }
}
struct node* newnode(){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter the data of the first student:\n");
    printf("Student name:");
    scanf("%s", &(newNode->student.Name));
    printf("Student Id:");
    scanf("%d", &(newNode->student.ID));
    printf("Student birth day month year:");
    scanf("%d", &(newNode->student.day));
    scanf("%d", &(newNode->student.month));
    scanf("%d", &(newNode->student.year));
    printf("Student score:");
    scanf("%d", &(newNode->student.Score));
    printf("\n");
    newNode->next = NULL;
    return newNode;



}

void InsertLinkedList(int*LinkedListNum, struct node** head, struct node** tail){

    int selection ,spec_position;
    int choose=1;
while (choose) {
    printf("________________LINKED LIST________________\n");
    printf("Type the num of your choose:\n");
    printf("1:Insert a new student in the beginning \n");
    printf("2:Insert a new student in the middle\n");
    printf("3:Insert a new student at the end\n");
    printf("4:Insert a new student at a specific position\n");
    printf("5:print the content of the linked list\n");
    printf("6:Clear the linked list\n");
    printf("7:Exit to the main menu\n");

    scanf_s("%d", &selection);
    if (selection == 4) {

        printf("choose a position between 0 and %d:", *LinkedListNum);
        scanf_s("%d", &spec_position);
    }

    struct node *newNode, *temp;
    temp = *head;
    newNode = (struct node *) malloc(sizeof(struct node));
if (selection<5){
    newNode=newnode();
}
    switch (selection) {
        case 1: {
            newNode->next = temp;
            *head = newNode;
            if (*LinkedListNum == 0)
                *tail = *head;
            *LinkedListNum = *LinkedListNum + 1;
            break;
        }
        case 2: {
            for (int i = 0; i < ((*LinkedListNum / 2) - 1); ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            *LinkedListNum = *LinkedListNum + 1;
            break;
        }
        case 3: {
            (*tail)->next = newNode;
            *tail = newNode;
            if (*LinkedListNum == 0)
                *head = *tail;
            *LinkedListNum = *LinkedListNum + 1;
            break;

        }
        case 4: {
            if (spec_position == 0) {
                newNode->next = temp;
                *head = newNode;
                if (*LinkedListNum == 0)
                    *tail = *head;
                *LinkedListNum = *LinkedListNum + 1;
                break;
            }
            for (int i = 0; i < spec_position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            *LinkedListNum = *LinkedListNum + 1;
            break;
        }
        case 5: {
            printList(head);
            break;
        }
        case 6:{
            free(*head);
            free(*tail);
            *head=NULL;
            *tail=NULL;
            *LinkedListNum=0;
            break;
        }
        case 7: {
           choose=0;
            break;

        }
        default:{
            printf("Wrong Selection please write a num between 1->7\n");
            break;
        }

    }

}
}
/Dynamic Array/
struct strudents* CreatArray(){
    struct students* NewElement;
    NewElement = (struct students*) calloc(1 , sizeof(struct students));

    // if memory cannot be allocated
    if(NewElement == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter the data of the student:\n");
    printf("Student name:");
    scanf("%s", &((NewElement)->Name));
    printf("Student Id:");
    scanf("%d", &((NewElement)->ID));
    printf("Student birth day month year:");
    scanf("%d", &((NewElement)->day));
    scanf("%d", &((NewElement)->month));
    scanf("%d", &((NewElement)->year));
    printf("Student score:");
    scanf("%d", &((NewElement)->Score));
    printf("\n");
    return NewElement;
}
void PrintArray(int* DynamArrayNum,struct students** Init){

    if (*Init==NULL){
        printf("The Array is Empty\n");
        return;
    }
    for (int i = 0; i <*DynamArrayNum ; i++) {
        printf("Student Name= %s\n", (*(*Init+i)).Name); // Print data of current node
        printf("Student ID= %d\n",  (*(*Init+i)).ID);
        printf("Student Birth (DD/MM/YYYY)= %d/%d/%d\n", ((*Init+i)).day,((Init+i)).month,((*Init+i)).year);
        printf("Student Score= %d\n", (*(*Init+i)).Score);
        printf("\n");
    }

  void Array(int* DynamArrayNum, struct students** Init){

    int selection ,spec_position;
    int choose=1;
    while (choose) {
        printf("_____DYNAMIC ARRAY______\n");
        printf("Type the num of your choose:\n");
        printf("1:Insert a new student in the beginning \n");
        printf("2:Insert a new student in the middle\n");
        printf("3:Insert a new student at the end\n");
        printf("4:Insert a new student at a specific position\n");
        printf("5:print the content of the Array\n");
        printf("6:Clear the array\n");
        printf("7:Exit to the main menu\n");

        scanf_s("%d", &selection);
        if (selection == 4) {

            printf("choose a position between 0 and %d:", *DynamArrayNum);
            scanf_s("%d", &spec_position);
        }

        switch (selection) {
            case 1: {

                 (*DynamArrayNum)++;
                struct students* NewElement;
                Init = (struct strudents)realloc(*Init, *DynamArrayNum * sizeof(struct students));
                for(int i=(*DynamArrayNum-1);i>0;i--){
                    strcpy(((*Init+i)).Name,((*Init+(i-1))).Name);
                    ((*Init+i)).ID=((*Init+(i-1))).ID;
                    ((*Init+i)).day=((*Init+(i-1))).day;
                    ((*Init+i)).month=((*Init+(i-1))).month;
                    ((*Init+i)).year=((*Init+(i-1))).year;
                    ((*Init+i)).Score=((*Init+(i-1))).Score;
                }
                NewElement=CreatArray();
                strcpy((*(*Init)).Name,(*NewElement).Name);
                (*(*Init)).ID=(*NewElement).ID;
                (*(*Init)).day=(*NewElement).day;
                (*(*Init)).month=(*NewElement).month;
                (*(*Init)).year=(*NewElement).year;
                (*(*Init)).Score=(*NewElement).Score;
                free(NewElement);

                break;
            }
            case 2: {
                (*DynamArrayNum)++;
                struct students* NewElement;
                Init = (struct strudents)realloc(*Init, *DynamArrayNum * sizeof(struct students));
                for(int i=(*DynamArrayNum-1);i>((*DynamArrayNum-1)/2)-1;i--){
                    strcpy(((*Init+i)).Name,((*Init+(i-1))).Name);
                    ((*Init+i)).ID=((*Init+(i-1))).ID;
                    ((*Init+i)).day=((*Init+(i-1))).day;
                    ((*Init+i)).month=((*Init+(i-1))).month;
                    ((*Init+i)).year=((*Init+(i-1))).year;
                    ((*Init+i)).Score=((*Init+(i-1))).Score;
                }
                NewElement=CreatArray();
                strcpy((*(*Init+((*DynamArrayNum-1)/2))).Name,(*NewElement).Name);
                (*(*Init+((*DynamArrayNum-1)/2))).ID=(*NewElement).ID;
                (*(*Init+((*DynamArrayNum-1)/2))).day=(*NewElement).day;
                (*(*Init+((*DynamArrayNum-1)/2))).month=(*NewElement).month;
                (*(*Init+((*DynamArrayNum-1)/2))).year=(*NewElement).year;
                (*(*Init+((*DynamArrayNum-1)/2))).Score=(*NewElement).Score;
                free(NewElement);
                break;

            }
            case 3: {
                (*DynamArrayNum)++;
                struct students* NewElement;
                Init = (struct strudents)realloc(*Init, *DynamArrayNum * sizeof(struct students));
                NewElement=CreatArray();
                strcpy((*(*Init+(*DynamArrayNum-1))).Name,(*NewElement).Name);
                (*(*Init+(*DynamArrayNum-1))).ID=(*NewElement).ID;
                (*(*Init+(*DynamArrayNum-1))).day=(*NewElement).day;
                (*(*Init+(*DynamArrayNum-1))).month=(*NewElement).month;
                (*(*Init+(*DynamArrayNum-1))).year=(*NewElement).year;
                (*(*Init+(*DynamArrayNum-1))).Score=(*NewElement).Score;
                free(NewElement);
                break;

            }
            case 4: {
                (*DynamArrayNum)++;
                struct students* NewElement;
                Init = (struct strudents)realloc(*Init, *DynamArrayNum * sizeof(struct students));
                for(int i=(*DynamArrayNum-1);i>(spec_position-1);i--){
                    strcpy(((*Init+i)).Name,((*Init+(i-1))).Name);
                    ((*Init+i)).ID=((*Init+(i-1))).ID;
                    ((*Init+i)).day=((*Init+(i-1))).day;
                    ((*Init+i)).month=((*Init+(i-1))).month;
                    ((*Init+i)).year=((*Init+(i-1))).year;
                    ((*Init+i)).Score=((*Init+(i-1))).Score;
                }
                NewElement=CreatArray();
                strcpy((*(*Init+spec_position)).Name,(*NewElement).Name);
                (*(*Init+spec_position)).ID=(*NewElement).ID;
                (*(*Init+spec_position)).day=(*NewElement).day;
                (*(*Init+spec_position)).month=(*NewElement).month;
                (*(*Init+spec_position)).year=(*NewElement).year;
                (*(*Init+spec_position)).Score=(*NewElement).Score;
                free(NewElement);
                break;

            }
            case 5: {
                PrintArray(DynamArrayNum,Init);
                break;
            }
            case 6:{
                free(*Init);
                *Init=NULL;
                *DynamArrayNum=0;
                break;
            }
            case 7: {
                choose=0;
                break;

            }
            default:{
                printf("Wrong Selection please write a num between 1->7\n");
                break;
            }

        }

    }
int main() {
    int selection=0;
    int LinkedListNum=0;
    int DynamArrayNum=0;
    struct node *head=NULL;
    struct node *tail=NULL;
    struct students *Init=NULL;
    printf("welcome to our code \n");
    while (selection!=5) {
        printf("________________MAIN MENU_______________\n");
        printf("Choose 1 or 2 or 3:\n");
        printf("1:Insert a new student in an array \n");
        printf("2:Insert a new student in a linked list\n");
        printf( "3:print the content of tha array \n");
        printf("4:print the content of tha linked list\n");
        printf("5:Clear both of the array and the linked list\n");
        printf("6:Exit the program\n");
        printf("\n");
        scanf_s("%d", &selection);

        switch (selection) {
            case 1:{
                Array(&DynamArrayNum, &Init);
                break;

            }
            case 2: {

                InsertLinkedList(&LinkedListNum, &head, &tail);

                break;
            }
            case 3:{
                PrintArray(&DynamArrayNum,&Init);
            }
            case 4: {
                printList(&head);
                break;
            }
            case 5:{
                free(Init);
                free(head);
                free(tail);
                DynamArrayNum=0;
                LinkedListNum=0;
                break;
            }
            case 6:{

                return 0;

            }
            default:{
                printf("Wrong Selection please write a num between 1->6\n");
                break;
            }
        }
    }

}
    return 0;}

