/*
* version: 5.1
* 2023 11 17 16:41
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    int time = 1200;
    char a[100];
    char answer[100] = "123456";
    int try_time = 0;
    do
    {
        system("shutdown -s -t 1200");
        printf("Your computer will shutdown in %d seconds\n", time);
        for (int i = 0; i < (2000 - time); i++)
        {
            putchar('*');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        printf("Please enter the password:");
        gets_s(a, 100);
        try_time++;
        switch (try_time)
        {
        case 1:
            system("shutdown -a");
            system("shutdown -s -t 1100");
            time -= 100;
            break;
        case 2:
            system("shutdown -a");
            system("shutdown -s -t 1000");
            time -= 100;
            break;
        case 3:
            system("shutdown -a");
            system("shutdown -s -t 900");
            time -= 100;
        case 4:
            system("shutdown -a");
            system("shutdown -s -t 600");
            time -= 300;
            break;
        case 5:
            system("shutdown -a");
            system("shutdown -s -t 300");
            time -= 300;
            break;
        case 6:
            system("shutdown -a");
            system("shutdown -s -t 60");
            time -= 240;
            break;
        case 7:
            system("shutdown -a");
            system("shutdown -s -t 10");
            time -= 50;
        default:
            system("shutdown -a");
            system("shutdown -s -t 0");
            break;
        }
        if (strcmp(a, answer) != 0)
        {
            printf("Wrong!");
        }
        else
        {
            break;
        }
        system("CLS");
        printf("Do you want to continue guessing?\nIf no, please enter 'N' or 'n'. If yes, press other key.");
        char choice = getch();
        getchar();
        if (choice == 'N' || choice == 'n')
        {
            printf("Don't give up! Really quit? enter 'Y' or 'y' to quit.");
            choice = getch();
            getchar();
            if (choice == 'Y' || choice == 'y')
            {
                printf("Really?\n");
                for (int i = 10; i >= 0; i--)
                {
                    printf("%d\n", i);
                    Sleep(1000);
                }
                system("shutdown -s -t 0");
                goto Last;
            }
        }

    } while (strcmp(a, answer) != 0);
    printf("Right!");
    system("shutdown -a");
Last:
    return 0;
}