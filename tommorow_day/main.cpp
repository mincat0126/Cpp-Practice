#include <stdio.h>

void PrintTomorrow(int y,int m, int d)
{
    static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))//윤년 구분
    {
        days[2] = 29; 
    }

    if (d > days[m] || m < 1 || m > 12 || y < 0)
    {
        printf("입력한 날짜가 틀렸습니다.\n");
    }
    else
    {
        d++;
        if (d > days[m])//월, 일 구분
        {
            d = 1;
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
        printf("내일은 %d년 %d월 %d일입니다.\n", y, m, d);
    }
}

void main()
{
    int year,mon, day;

    printf("오늘 날짜(년 월 일)을 공백으로 구분하여 입력해 주세요 : ");
    scanf_s("%d%d%d", &year, &mon, &day);

    PrintTomorrow(year,mon, day);
}