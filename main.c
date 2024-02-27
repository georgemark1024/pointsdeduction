#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototypes.h"


int main()
{
    int choice, adm, int_offence;
    char *str_offence;

    choice = menu();
    while(1)
    {
        if(choice == 1)
        {
            deductpoints();
        }
        else if(choice == 2)
        {
            view_points();
        }
        else if(choice == 3)
        {
            exit(0);
        }
        else
        {
            printf("Wrong choice!");
            printf("Try again!");
            continue;
        }
    
    }
    return (0);
}