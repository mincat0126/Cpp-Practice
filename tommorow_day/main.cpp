#include <stdio.h>

void PrintTomorrow(int y,int m, int d)
{
    static int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))//���� ����
    {
        days[2] = 29; 
    }

    if (d > days[m] || m < 1 || m > 12 || y < 0)
    {
        printf("�Է��� ��¥�� Ʋ�Ƚ��ϴ�.\n");
    }
    else
    {
        d++;
        if (d > days[m])//��, �� ����
        {
            d = 1;
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
        printf("������ %d�� %d�� %d���Դϴ�.\n", y, m, d);
    }
}

void main()
{
    int year,mon, day;

    printf("���� ��¥(�� �� ��)�� �������� �����Ͽ� �Է��� �ּ��� : ");
    scanf_s("%d%d%d", &year, &mon, &day);

    PrintTomorrow(year,mon, day);
}