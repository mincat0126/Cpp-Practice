#include <stdio.h>

void PrintTomorrow(int y,int m, int d)
{
    static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (d > days[m] || m < 1 || m > 12)
    {
        printf("입력한 날짜가 틀렸습니다.\n");
    }
    else
    {
        d++;
        if()
        printf("내일은 %d년 %d월 %d일입니다.\n", y,m, d);
    }
}

void main()
{
    int year,mon, day;

    printf("오늘 날짜(년 월 일)을 공백으로 구분하여 입력해 주세요 : ");
    scanf_s("%d%d%d", &year, &mon, &day);

    PrintTomorrow(mon, day,year);
}