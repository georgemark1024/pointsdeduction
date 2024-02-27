#include<stdio.h>
#include"prototypes.h"

int menu()
{
    int choice;

    printf("Welcome to Light Academy points management system\n");
    printf("Choose 1 for deducting points\n");
    printf("Choose 2 for viewing students points\n");
    printf("Choose 3 to exit from program\n");

    scanf("%d", &choice);

    return(choice);
}