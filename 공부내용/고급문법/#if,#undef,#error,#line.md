# #if
**#if**: 매크로의 값을 평가하거나 여러 가지 조건을 결합하여 컴파일 여부를 결정하는 전처리문    
&nbsp;&nbsp;&nbsp;**형태**: #if 조건 코드들 #elif 조건 코드들 #else #코드들 #endif  
> #ifdef과 #ifndef은 매크로의 존재 여부만으로 컴파일 조건을 판단하며 매크로가 어떤 값으로 정의 되어 있는지는 평가하지 않는다.  
> #elif와 #else는 생략 가능하며 #elif는 얼마든지 올 수 있다.   
> #if는 뒤의 조건을 평가해 보고 이 조건이 참이면 바로 아래의 블록을 컴파일러에게 넘기고 그렇지 않으면 삭제하여 없는 것으로 취급.  
> #if와 #elif다음에 오는 조건문은 전처리 과정에서 진위 여부를 판단할 수 있는 것이어야 한다.  
> #if는 조건문이 참일 때 1, 거짓일 때 0으로 평가하는데 결과가 0이 아니면 인어지는 코드 블록을 컴파일한다.

**<#if 전처리문 작성 규칙>**
1. 매크로값을 비교할 때는 상등, 비교 연산자를 사용한다. [#if (LEVEL == 3)]
2. 비교 대상은 정수 상수여야 하며 실수나 문자열은 매크로와 비교할 수 없다. [#if (LEVEL == BASIC)]
3. 수식 내에서 간단한 사칙 연산을 할 수 있다. [#if (LEVEL*2 == 6)]
4. 논리 연산자로 두 개 이상의 조건문을 동시에 평가할 수 있다. [#if (LEVEL == 8 && VER != 3)]
5. defined 연산자로 매크로의 존재 여부를 평가할 수 있다. [#if (LEVEL == 8 || defined(PROFESSIONAL))]
6. #if 다음의 조건부 컴파일 블록에는 어떤 문장이든 옹 수 있다.

<br><br><br><br><br>

# #undef
**#undef**: 정의되어 있는 매크로를 삭제하는 전처리문
&nbsp;&nbsp;&nbsp;**형태**: #undef 매크로이름

<pre>#include < stdio.h >

void main()
{
#define SIZE 10
    printf("SIZE=%d\n", SIZE);

#undef SIZE
#define SIZE 20
    printf("SIZE=%d\n", SIZE);
}</pre><br><br><br><br><br>

# #error
**#error**: 지정한 에러 메시지를 출력하고 전처리 과정에서 컴파일을 중자히도록 하는 전처리문

**#line**: __LINE__, __FILE__ 매크로를 재정의하는 전처리문  
> 줄 수는 정수로 주고 파일명은 문자열 형태로 지정하되 파일명을 생략할 경우 기존의 파일명이 그대로 유지된다

<pre>#ifndef UNICODE

#error This program require unicode environment

#endif</pre>
