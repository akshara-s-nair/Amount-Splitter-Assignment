#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// person struct and count scoped globally
struct person
{
    char name[50];
    int id;
    int expenses[6];
    int ind_total_exp;
    int spl;
} p[5];

int p_count = 0;

void person()
{
    printf("\033[0;31m");
    // add new person
    if (p_count < 6)
    {
        p[p_count].id = p_count;
        printf("Enter the name of the person\t");
        fgets(p[p_count].name, sizeof(p[p_count].name), stdin);
        printf("Added Successfully\n");
        p_count++;
    }
    else
    {
        printf("Limit exceeded");
    }
    printf("\033[0m");
}

void expenses()
{
    char name[50];
    int count=0, status = 0;
    char *act[] = {"activity 1", "activity 2", "activity 3", "activity 4", "activity 5"};
    // assigns individual expenses to each person

    // checking if the person exists or not
    if (p_count != 0)
    {
        printf("Name of the person\t");
        fgets(name, sizeof(name), stdin);
        while (count <= p_count)
        {
            if (strcmp(p[count].name, name) == 0)
            {
                status = 1;
                break;
            }
            else
            {
                count++;
                status = 0;
            }
        }
        if (!status)
            printf("Person not found !!!!\n");
        else
        {
            int len = sizeof(act);
            printf("%s%s%s", "Enter expenses of  ", p[count].name,"\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%s%s%s", "Enter expense of ", act[i], ":\t");
                scanf("%d", &p[count].expenses[i]);
            }
        }
    }
    else
    {
        printf("Add a person to continue");
    }
}

void calculate()
{
    // calculates and split up expenses between each person
    int total_day_expenses = 0;
    int split_up = 0;
    int len = sizeof(p)/sizeof(int);

    // total expenses
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            total_day_expenses = total_day_expenses + p[i].expenses[j];
        }
        p[i].ind_total_exp = total_day_expenses;
    }

    split_up = total_day_expenses / len;

    // individual total
    for (int i = 0; i <= len; i++)
    {
        p[i].spl = split_up - p[i].ind_total_exp;
    }

    // print expense table
    printf("Name\tAmount\n");
    for (int i = 0; i <= len; i++)
        printf("%s%s%d", p[i].name, "\t", p[i].spl);
}

int main()
{
    int option;
    do
    {
        printf("======================================================================");

        printf("\n 1. Add Person\n 2. Add Expenses \n 3. View Split Up\n 4. Exit\n\n Select one to continue:\t");
        scanf("%d", &option);
        getchar();
        if (option == 1)
            person();
        else if (option == 2)
            expenses();
        else if (option == 3)
            calculate();
        else if (option == 4)
            exit(0);
        else
            printf("Invalid Option");
        printf("What next ?\n");
    } while (option != 4);

    return 0;
}