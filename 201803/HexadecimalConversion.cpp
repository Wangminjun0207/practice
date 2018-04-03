#include <stdio.h>
#include <stdlib.h>
void showmenu1()
{
    printf("\n请选择需要被转换的进制:\n");
    printf("1、二进制\n");
    printf("2、八进制\n");
    printf("3、十进制\n");
    printf("4、十六进制\n");
    printf("0、退出\n");
    printf("请输入菜单：");
}
void showmenu2()
{
    printf("请选择需要输出的进制:\n");
    printf("1、二进制\n");
    printf("2、八进制\n");
    printf("3、十进制\n");
    printf("4、十六进制\n");
    printf("请输入菜单：");
}
int inputNum(int min, int max)
{
    int num;
    while(1)
    {
        int s = scanf("%d", &num);
        if(1!=s)
        {
            printf("输入错误， 请重新输入：");
            continue;
        }
        if(num<min || num>max)
        {
            printf("输入范围有误，请重新输入：");
            continue;
        }
        break;
    }
    return num;
}
/*十进制转二进制输出 */
void fun1(int n)
{
    if(n/2)
        fun1(n/2);
    putchar('0'+n%2);
}
/*十进制转八进制输出 */
void fun2(int n)
{
    if(n/8)
        fun2(n/8);
    putchar('0'+n%8);
}
/*十进制转十六进制输出 */
void fun3(int n)
{
    if(n/16)
        fun3(n/16);
    int i = n%16;
    if(i<10)
        putchar('0'+i);
    else
        putchar('a'+i-10);
}
/*二进制转十进制 */
int fun4(char *str)
{
    int num = 0;
    while(*str != '\0')
    {
        int i = *str-'0';
        if(i>=0 && i<=1)// 跳过其它字符 
            num = num*2+i;
        str++;
    }
    return num;
}
/*八进制转十进制 */
int fun5(char *str)
{
    int num = 0;
    while(*str != '\0')
    {
        int i = *str-'0';
        if(i>=0 && i<8)
            num = num*8+i;
        str++;
    }
    return num;
}
/*十六进制转十进制 */ 
int fun6(char *str)
{
    int num = 0;
    while(*str != '\0')
    {
        char ch = *str;
        if(ch>='0' && ch<='9')
            num = num*16+ch-'0';
        if(ch>='a' && ch<='f')
            num = num*16+10+ch-'a';
        str++;
    }
    return num;
} 

int main(void)
{
    char str[1024];
    int menu, output;
    while(1){
        showmenu1();
        menu = inputNum(0, 4);
        if(menu == 0)
            break;
        fflush(stdin);
        printf("请输入数据：");
        switch(menu)
        {
            case 1:
                gets(str);
                output = fun4(str);
                break;
            case 2:
                gets(str);
                output = fun5(str);
                break;
            case 3:
                output = inputNum(0, INT_MAX);
                break;
            case 4:
                gets(str);
                output = fun6(str);
                break;
        }

        showmenu2();
        menu = inputNum(0, 4);
        switch(menu)
        {
            case 1:
                fun1(output);
                putchar('B');
                break;
            case 2:
                fun2(output);
                putchar('Q');
                break;
            case 3:
                printf("%d", output);
                putchar('D');
                break;
            case 4:
                fun3(output);
                putchar('H');
                break;
        }
        putchar('\n');
        system("pause");
    }
    return 0;
}
