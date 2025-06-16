# for 반복문
**for 반복문**: 비슷한 명령들을 여러 번 실행하는 제어 구조.  
&nbsp;&nbsp;&nbsp;**선언**: for(초기식; 조건식; 증감식){명령들}  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**초기식**: 초기식은 제어 변수의 초기값을 지정하여 루프가 수행될때 한 번만 수행된다.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**조건식**: 반복문이 언제까지 실행될지 결정한다.루프가 실행될 때마다 계속 평가한다.  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**증감식**: 한 번 루프를 돌 때 제어 변수를 얼마나 증감시킬 결정한다.  
> 초기식 안에서 임시 변수를 선언하여 사용 가능하다.(이미 선언된 변수도 가능)  
> 명령이 한 줄인 경우 중괄호{}는 생략이 가능하다.  
> 조건을 **만족시키지 않았을 때 루프를 탈출한다.** 
<pre>#include < stdio.h >
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
	}
}</pre>

**무한루프**: 반복 횟수가 미리 정해져 있지 않고 무한히 반복되는 루프.  
&nbsp;&nbsp;&nbsp;**선언**: for(;;){명령들}  
&nbsp;&nbsp;&nbsp;**break;**: 조건식을 무시하고 강제로 루프를 종료하는 명령어.  
> 무한루프란 정말 무한으로 실행되는 것이 아닌 루프 내부에서 끝낼 시점을 결정하는 루프다.  
> 루프를 끝내는 조건이 없이 진짜 무한으로 실행되면 시스템 다운 상태가 된다.
<pre> #include < stdio.h >
void main()
{
     int i,Num1,Num2;
     printf("첫 번째 숫자를 입력하세요 : ");
     scanf("%d",&Num1);
     printf("두 번째 숫자를 입력하세요 : ");
     scanf("%d",&Num2);

     i=1;
     for (;;) 
     {
          if (i % Num1 == 0  && i % Num2 == 0)
              break;
          i+=1;
     }
     printf("최소 공배수 = %d\n",i);
}</pre>

**다중루프**: 두 개 이상의 루프가 겹쳐있는 제어구조.  
> 단순 루프가 여러개인 구조가 아닌, 루프 안에 루프가 있는 구조  
<pre>#include < stdio.h >

void main()
{
     int i,j;

     for (i=1;i<=9;i++) 
     {
          for (j=1;j<=9;j++)
	  {
              printf("%d*%d=%d\n",i,j,i*j);
          }
          printf("\n");
     }
}</pre>
