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
int main() {
    printf("welcome to our code \n");
    return 0;}

