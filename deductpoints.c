#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"prototypes.h"

void deductpoints()
{
    FILE *fstudentpoints, *foffpoints;
    int adm, offence, points, line=1, offence_weight, new_points;
    char buffer[100], *first, *last, *char_offence, *name_concat_in_file, name[50], buffer2[10], *char_points;

    printf("Enter name of student\n");
    scanf("%[^\n]", name);
    adm = check_student(name);
    if (adm == 0)
    {
        printf("Student not found!\n");
        return;
    }
    printf("Enter offence number ");
    scanf("%d", &offence);
    char_offence = check_offence(offence);

    foffpoints = fopen("./files/offencepoints.txt", "r");
    check_file(foffpoints);

    while(fgets(buffer2, 10, foffpoints) != NULL)
    {
        line++;
        if (line == offence)
        {
            offence_weight = atoi(buffer2);
            break;
        }
    }

    fstudentpoints = fopen("./files/studentspoints.txt", "a+");
    check_file(fstudentpoints);

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
            printf("He committed '%s' which is %d points\n", char_offence, offence_weight);
            new_points = points - offence_weight;
            fseek(fstudentpoints, points, SEEK_CUR); // sizeof(*points)
            sprintf(char_points, "%d", new_points);
            fputs(char_points, fstudentpoints); //
            if(new_points <= 60)
            {
                printf("Points = %d\n", new_points);
                printf("%s will go for suspension\n", name);
            }
            else if(new_points <= 80)
            {
                printf("Points = %d\n", new_points);
                printf("Call %s's parents\n", name);
            }
            break;
        }
    }
    free(char_offence);
    fclose(fstudentpoints);
    fclose(foffpoints);
}