# switch문
**다중선택**:  하나의 변수값을 평가하여 각 값에 대해 개별적인 처리를 지정할 수 있는 문장  
&nbsp;&nbsp;&nbsp;**선언**: switch(변수){case 값 : 명령; break; case 값 : 명령; break; ... default : 명령 break;}  
> 변수 부분에는 평가할 변수를 넣는다.  
> case는 원하는만큼 넣을 수 있다.  
> dafult는 else처럼 앞쪽 case값 이외의 값일 때 실행하는 명령이다.  
> 실수나 사용자 정의형 등은 다중 선택에 사용할 수 없다.  
> case 다음에는 반드시 정수 상수 하나가 와야 한다.

<pre>
#include < stdio.h >

void main()
{
    int i;
    printf("값을 입력해 주세요 : ");
    scanf("%d", &i);

    switch (i)
    {
    case 0:
        printf("입력한 값은 0입니다.\n");
        break;
    case 1:
        printf("1을 입력했습니다.\n");
        break;
    case 2:
        printf("2입니다.\n");
        break;
    default:
        printf("0,1,2가 아닌 다른 수입니다.\n");
        break;
    }
}
</pre>
<img width="476" height="251" alt="image" src="https://github.com/user-attachments/assets/b42c6a7a-345e-4c20-8b04-82dbcbf89b60" />
<br><br><br>

> 순서에 대한 제약은 없다.

<pre>
#include < stdio.h >

void main()
{
    int i;
    printf("값을 입력해 주세요 : ");
    scanf("%d", &i);

    switch (i)
    {
    case 0:
        printf("입력한 값은 0입니다.\n");
        break;
    case 9:
        printf("9를 입력했습니다.\n");
        break;
    case 4:
        printf("4입니다.\n");
        break;
    default:
        printf("0,4,9가 아닌 다른 수입니다.\n");
        break;
    }
}
</pre><br><br><br>

> default에 대한 처리가 필요치 않으면 생략할 수 있다. 만약 해당하는 case가 없고 default도 없으면 switch문 전체가 무시된다.

<pre>
#include < stdio.h >

void main()
{
    int i;
    printf("값을 입력해 주세요 : ");
    scanf("%d", &i);

    switch (i)
    {
    case 0:
        printf("입력한 값은 0입니다.\n");
        break;
    case 1:
        printf("1을 입력했습니다.\n");
        break;
    }
}
</pre>

> break가 없으면 다음 case의 명령까지도 계속 실행한다.

<pre>
#include < stdio.h >

void main()
{
    int i=0;

    switch (i)
    {
    case 0:                                        //<실행결과>
        printf("입력한 값은 0입니다.\n");           //입력한 값은 0입니다
    case 1:                                       //1을 입력했습니다.
        printf("1을 입력했습니다.\n");             //"0,1이 아닌 다른 수입니다.
    default:
        printf("0,1이 아닌 다른 수입니다.\n");
    }
}
</pre>
