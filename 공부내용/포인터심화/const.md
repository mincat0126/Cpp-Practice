# const
**const**: 값을 변경할 수 없는 상수를 정의  
&nbsp;&nbsp;&nbsp;**선언**: const 타입 변수명 = 초기값;  
> const를 붙일 경우 초기값을 반드시 지정해야 한다.  
> const 선언 후 타입을 생략할 경우 int로 간주한다.  
> const는 타입 뒤에 붙여도 상관없다.

<pre>
#include < stdio.h >

const int Hour = 24;
const int Min = 60;
const int Sec = 60;

void main()
{                                                      //<실행결과>
    printf("하루는 %d초입니다.\n", Hour * Min * Sec);   //하루는 86000초입니다.  
}
</pre>

<br><br><br>
## const 포인터
**상수 지시 포인터**: 상수를 가리키는 포인터  
&nbsp;&nbsp;&nbsp;**선언**: const 타입 *변수명;  
> 상수 지시 포인터가 가리키는 곳의 내용은 상수로 취급된다.  
> int const *는 const int *와 같은 표현이다.    

**상수 포인터**: 포인터 변수가 상수인 변수   
&nbsp;&nbsp;&nbsp;**선언**: 타입 * const 변수명;  

<pre>
void main()
{
     int ar[5]={1,2,3,4,5};

     int *pi1=&ar[0];
     pi1++;                  // 포인터가 다른 대상체를 가리킬 수 있다.
     *pi1=0;                 // 대상체를 변경할 수 있다.

     const int *pi2=&ar[0];
     pi2++;                  // 포인터가 다른 대상체를 가리킬 수 있다.
     *pi2=0;                 // 에러 : 대상체가 상수이므로 변경할 수 없다.

     int * const pi3=&ar[0];
     pi3++;                  // 에러 : 포인터가 다른 대상체를 가리킬 수 없다.
     *pi3=0;                 // 대상체는 변경할 수 있다.

     const int * const pi4=&ar[0];
     pi4++;                  // 에러 : 포인터가 다른 대상체를 가리킬 수 없다.
     *pi4=0;                 // 에러 : 대상체가 상수이므로 변경할 수 없다.
}</pre><br><br><br>

# volatile
**volatile**: 변수에 대해 최적화 처리를 금지시키는 키워드  
> const와 volatile을 cv 지정라고 부른다.
