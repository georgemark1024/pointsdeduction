#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototypes.h"

int check_student(char *name)
{
    int found, adm;
    FILE *fstudents;
    char name_in_file[100], buffer[100];

    fstudents = fopen("./files/students.txt", "r");

    check_file(fstudents);

    while(fgets(buffer, 100, fstudents) != NULL)
    {
        char *first, *surname;
        first = strtok(buffer, " ");
        surname = strtok(buffer, " ");
        sprintf(name_in_file, "%s %s", first, surname);
        int found = 0;
        if(name_in_file == name)
        {
            found = 1;
            adm = atoi(strtok(buffer, " "));
        }
    }

    if(fgets(buffer, 100, fstudents) == NULL)
    {
        printf("Student not found! Please check again");
        return(0);
    }

    fclose(fstudents);
    return(adm);
}

char* check_offence(int offence)
{
    FILE *foffence;
    char *buffer, *char_offence;
    foffence = fopen("./files/offence.txt", "r");

    check_file(foffence);

    buffer = (char *)malloc(100);
    while(fgets(buffer, 100, foffence) != NULL)
    {
        char_offence = strtok(buffer, ".");
        if (offence == atoi(char_offence))
        {
            printf("%s", buffer);
            fclose(foffence);
            return(buffer);
        }
    }
}

void check_file(FILE *file)
{
    if(file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}