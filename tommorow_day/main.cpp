#include <stdio.h>

void PrintTomorrow(int y,int m, int d)
{
    static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (d > days[m] || m < 1 || m > 12)
    {
        printf("�Է��� ��¥�� Ʋ�Ƚ��ϴ�.\n");
    }
    else
    {
        d++;
        if()
        printf("������ %d�� %d�� %d���Դϴ�.\n", y,m, d);
    }
}

void main()
{
    int year,mon, day;

    printf("���� ��¥(�� �� ��)�� �������� �����Ͽ� �Է��� �ּ��� : ");
    scanf_s("%d%d%d", &year, &mon, &day);

    PrintTomorrow(mon, day,year);
}