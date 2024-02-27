#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototypes.h"


void view_points()
{
    FILE *fstudentpoints;
    char name[50], buffer[100], *first, *last, *name_concat_in_file;
    int adm, points;

    fgets(name, 50, stdin) ;
    adm = check_student(name);

    if (adm == 0)
    {
        printf("Student not found!\n");
        return;
    }

    fstudentpoints = fopen("files/studentspoints.txt", "r");
    while(fgets(buffer, 100, fstudentpoints) != NULL)
    {
        first = strtok(buffer, " ");
        last = strtok(buffer, " ");
        points = atoi(strtok(buffer, " "));
        // strcat(first, last);
        sprintf(name_concat_in_file, "%s %s", first, last);
        if(name == name_concat_in_file)
        {
            printf("%s has %d points\n", name_concat_in_file, points);
            return;
        }
    }
    // free(adm);
    fclose(fstudentpoints);
}