/**
 * 
 * version: 5.5.2 (6.1 dev) (带注释)
 * 2023 11 18 23:40
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Notify(int second);
void tryLuck(int num);
void level2(void);

int main(void)
{
    int time = 1200;
    char a[100];
    char answer[100] = "I love you"; /*密码*/
    int try_time = 0;
    system("shutdown -sg -t 1200"); /*关机1200秒*/
    do
    {
        printf("Your computer will shutdown in %d seconds\n", time);
        for (int i = 0; i < (2000 - time); i++) /*输入2000-time个星号*/
        {
            putchar('*');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        for (int i = 0; i < 50; i++)
        {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        printf("Please enter the password:");
        gets_s(a, 100); /*输入密码*/
        for (int i = 0; i < 50; i++)
        {
            putchar('-');
            Sleep((0.01 * (2000 - time) + i / 100));
        }
        putchar('\n');
        try_time++;
        /*密码错误1次: 时间变成1100s
        密码错误2次: 时间变成1000s
        密码错误3次: 时间变成900s
        密码错误4次: 时间变成800s
        密码错误5次: 时间变成300s
        密码错误6次: 时间变成60s
        密码错误7次: 时间变成30s
        8次及以上: 每次10s
        */
        switch (try_time)
        {
        case 1:
            system("shutdown -a");
            system("shutdown -sg -t 1100");
            time -= 100;
            break;
        case 2:
            system("shutdown -a");
            system("shutdown -sg -t 1000");
            time -= 100;
            break;
        case 3:
            system("shutdown -a");
            system("shutdown -sg -t 900");
            time -= 100;
        case 4:
            system("shutdown -a");
            system("shutdown -sg -t 800");
            time -= 300;
            break;
        case 5:
            system("shutdown -a");
            system("shutdown -sg -t 300");
            time -= 300;
            break;
        case 6:
            system("shutdown -a");
            system("shutdown -sg -t 60");
            time -= 240;
            break;
        case 7:
            system("shutdown -a");
            system("shutdown -sg -t 30");
            time -= 30;
        default:
            system("shutdown -a");
            system("shutdown -s -t 10");
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
        system("CLS"); /*清除屏幕*/
        printf("Do you want to continue guessing?\nIf no, please enter 'N' or 'n'. If yes, press other key.\n");
        char choice = getch(); /*输入选项*/
        if (choice == 'N' || choice == 'n')
        {
            printf("Don't give up! Really quit? enter 'Y' or 'y' to quit.\n");
            choice = getch();
            if (choice == 'Y' || choice == 'y')
            {
                printf("Really?\n");
                system("shutdown -s -t 10");  /*5.3版本修改: 解决shutdown -a不能解决取消的问题*/
                for (int i = 10; i >= 0; i--) /*倒计时 10s*/
                {
                    printf("%d\n", i);
                    Sleep(1000);
                }
                goto Last;
            }
        }
    } while (strcmp(a, answer) != 0);
    printf("Right!\n"); /*第1关结束*/
    system("shutdown -a");
    /*5.4新版本：增加lv2*/
    Sleep(2000); /*休息2s*/
    printf("Do you think it is easy?");
    Sleep(2000); /*休息2s*/
    system("CLS");
    for (int i = 20; i > 0; i--)
    {
        printf("Level 2 starts\n");
        /*5.5新修改: lv2界面改变*/
        printf("Wait a few seconds.\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        Sleep(1000);
        system("CLS");
    }
    level2();
    system("shutdown -a");

    printf("You win!");
    Sleep(10000);

Last:
    return 0;
}

void level2(void)
{
    srand((unsigned int)(time(0)));
    int num = rand() % 10000 + 1;
    printf("When number is in (1000,10000), your computer will shutdown, (1-1000) will sleep\n");
    printf("Your number: %d\n", num);
    Sleep(2000);
    printf("Wait a few seconds.");
    printf("......................\n");
    tryLuck(num);
    printf("Now it's your turn.");
    printf("Please enter the password!\n");

    int luck = rand() % 100 + 1;
    char discard[100];
    char newPassword[100] = "I love you";
    char inputPassword[100];
    int plus = 1 /*概率增加*/;
    int probablity = rand() % 100 + plus;

    while (strcmp(inputPassword, newPassword) != 0)
    {
        /*5.4.0新修改吃掉密码，5.4.1吃掉密码为100%概率bug修改，5.5增加随机数*/
        printf("Little worm come! The probablity of it comes is %d%%\n", (100 - probablity));
        if (luck > probablity) // 有概率密码被吃掉,这个概率是随机数
        {
            gets_s(discard, 100);
            printf("Your password was eaten by a little worm!\n"); /*密码被吃掉*/
            Sleep(2000);
            system("CLS"); /*清屏*/
        }
        else
        {
            gets_s(inputPassword, 100);
            if (strcmp(inputPassword, newPassword) == 0)
            {
                return;
            }
            else
            {
                printf("Please retry!"); /*密码错误，密码被吃掉概率增加1%*/
                plus++;
            }
            system("CLS");
        }
        printf("Please enter the password!\n");
        luck = rand() % 100 + 1;
        probablity = rand() % 100 + plus;
    }
}

void tryLuck(int num)
{
    /*有90%的概率关机, 9.99%概率直接进入睡眠模式，0.01%直接退出*/
    if (num == 10000)
    {
        printf("Good good!"); /*直接退出*/
        return;
    }
    
    else
    {
        // 关机
        printf("You have to wait and stay here without doing anything\n");
        if (num > 9000)
        {
            system("shutdown -s -t 900");
            Notify(90);
        }
        else if (num > 8000)
        {
            system("shutdown -s -t 800");
            Notify(80);
        }
        else if (num > 7000)
        {
            system("shutdown -s -t 700");
            Notify(70);
        }
        else if (num > 6000)
        {
            system("shutdown -s -t 600");
            Notify(60);
        }
        else if (num > 5000)
        {
            system("shutdown -s -t 500");
            Notify(50);
        }
        else if (num > 4000)
        {
            system("shutdown -s -t 400");
            Notify(40);
        }
        else if (num > 3000)
        {
            system("shutdown -s -t 300");
            Notify(30);
        }
        else if (num > 2000)
        {
            system("shutdown -s -t 200");
            Notify(20);
        }
        else if (num > 1000)
        {
            system("shutdown -s -t 100");
            Notify(10);
        }
        else // 睡眠
        {
            printf("Good luck!\n");
            Sleep(5000);
            system("shutdown -h");
        }
    }
}

void Notify(int second)
{
    for (int i = second; i >= 0; i--)
    {
        printf("Wait a few seconds.\n");
        printf("..............................................\n");
        printf("......................%2d......................\n", i);
        printf("..............................................\n");
        Sleep(1000);
        system("CLS");
    }
}