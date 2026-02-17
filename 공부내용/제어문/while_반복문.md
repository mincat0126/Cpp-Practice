# while 반복문
**while 반복문**: 조건이 만족하는동안 명령을 계속 실행.  
&nbsp;&nbsp;&nbsp;**선언**: while(조건){명령들}
> 명령 블록 내에서 루프를 끝내야한다.

<pre>
#include < stdio.h >

void main()
{
     int i,sum;
     sum=0;
     i=1;

     while (i<=100) 
     {
          sum=sum+i;
          i=i+1;
     }
     printf("1~100까지의 합 = %d\n",sum);
}</pre>

**do while 반복문**: 조건이 충족되지 않았더라도 명령을 한번은 실행  
> while 없이 do만 있으면 오류 발생
<pre>
#include < stdio.h >

int main()
{
	int i = 1;
	do
	{
		printf("%d", i);
		i--;
	} while (i > 2);
}</pre>
