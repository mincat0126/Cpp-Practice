# switch문
**다중선택**:  하나의 변수값을 평가하여 각 값에 대해 개별적인 처리를 지정할 수 있는 문장  
&nbsp;&nbsp;&nbsp;**선언**: switch(변수){case 값 : 명령; break;, case 값 : 명령; break; ... default : 명령 break;}  
> 변수 부분에는 평가할 변수를 넣는다.  
> break로 탈출하지 않을시 위에서 아래로 전부 실행된다.    
> dafault의 명령은 else처럼 위에 case 조건들이 모두 만족을 안 했을 시 실행시킨다.    
> case 다음에 오는 값은 switch()에 넣은 변수랑 같은지 판단하는 값이다.  
> switch() 부분에서 평가하는 변수에 연산을 해도 된다.  
> switch() 부분에서 평가하는 변수에는 대부분 정수형만 가능하다.(실수x 사용자 정의형x)  
> case 다음에 오는 값에는 정수 상수 1개가 와야한다.(변수x, 범위 지정 x)  
> case 다음에 오는 값에는 딱히 순서가 없다.(dafault도 꼭 맨 밑에 배치할 필요는 없다.)  
> default는 생략이 가능하다.(해당하는 case가 없고 dafault가 없을 시 switch문 전체가 생략된다.)  
> 조건에 맞는 case를 만나면 case 아래에 있는 명령들을 순차적으로 실행한다. 따라서 중괄호{}는 필요없다.(다만 break 필요)  
<pre>#include < stdio.h >

int main()
{
    int i;

    printf("값을 입력해 주세요 : ");
    scanf_s("%d", &i);

    switch (i)
    {
    case 1:
        printf("입력한 값은 1입니다.\n");
        break;
    case 2:
        printf("입력한 값은 2입니다.\n");
        break;
    default:
        printf("1,2가 아닌 다른 수입니다.\n");
        break;
    }
}</pre>
<pre>#include < stdio.h >

int main()                                      //break가 없을 시
{
    int i=2;

    switch (i)                                  //<실행결과>
    {                                           //입력한 값은 2입니다.
    case 1:                                     //1,2가 아닌 다른 수입니다.
        printf("입력한 값은 1입니다.\n");
    case 2:
        printf("입력한 값은 2입니다.\n");
    default:
        printf("1,2가 아닌 다른 수입니다.\n");
    }
}</pre>
<pre>#include < stdio.h >

int main()                                        //잘못된 예
{
    float i = 2;
    int num = 1;
  
    switch (i%2)                                  //실수형이 들어감
    {                                             
    case num:                                     //case 다음에 정수 상수가 아닌 변수가 들어감
        printf("입력한 값은 1입니다.\n");
        break;
    case 2:
        printf("입력한 값은 2입니다.\n");
        break;
    default:
        printf("1,2가 아닌 다른 수입니다.\n");
        break;
    }
}</pre>
