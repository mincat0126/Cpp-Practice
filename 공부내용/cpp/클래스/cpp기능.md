# C++
**C++**: C언어에 여러 가지 기능을 추가하거나 개선하여 만들어진 C의 상위 버전.  
> 하위 호환성이 있으므로 대부분의 C코드는 C++ 컴파일러에서도 별다른 수정없이 그대로 컴파일된다.  
> C++언어의 초기 이름이 C with class였는데 이 이름은 C에 클래스 기능을 추가하여 C++을 만들었다는 것을 상징적으로 나타낸다.  
> C는 구조적 프로그래밍 방식을 사용하고 C++은 객체 지향적인 방식을 사용한다.

<br><br><br><br><br>
# IOStream
**cout**: 문자열을 화면으로 출력하는 객체  
&nbsp;&nbsp;&nbsp;**선언**: cout << 데이터 << 데이터 ...;  
> iostream은 cpp에서의 stdio.h쯤에 해당하는 기본 헤더 파일이다.  
> cout출력 객체는 iostream 헤더파일에 내장되어 있다.  
> namespace는 명령을 저장하는 기억 영역으로서 c++에 새로 추가된 기능이다.  
> c++ 표준 라이브러리는 std라는 이름의 네임 스페이스에 모두 저장되어 있어서 std 사용 선언을 해야 한다.  

**<< 연산자(삽입 연산자)**: 다음에 출력할 데이터를 적는다.  
> 데이터의 타입은 객체가 알아서 판단한다.  
> 여러 개의 데이터를 이어서 출력할 때는 << 연산자를 계속해서 사용한다.  
> endl은 개행 코드를 의미하며 확장열 '\n'과 기능적으로 동일하다.  

<pre>#include < iostream >
using namespace std;

void main()
{
     cout << "Welcome C++" << endl;
}</pre>

<pre>
#include <iostream>
using namespace std;

void main()
{
     int i=123;
     char ch='A';
     double d=3.14;
     char str[]="문자열";
                                             //<실행결과>
     cout << i << ch << d << str << endl;    //123A3.14문자열 
}
</pre><br><br><br>

**cin**: 사용자로부터 정보를 입력 받아 변수에 저장하는 객체   
&nbsp;&nbsp;&nbsp;**선언**: cin >> 변수;    

**>> 연산자(추출 연산자)**: 데이터를 입력받아 변수에 저장  
> 데이터의 타입은 객체가 알아서 판단한다.   

<pre>
#include < iostream >
using namespace std;

void main()
{
     int i;
     cout << "정수를 입력하십시오 : ";
     cin >> i;
     cout << "입력한 값은 " << i << "입니다." << endl;
}
</pre><br><br><br><br><br>

# new
**new**: C++의 메모리 할당 연산자  
&nbsp;&nbsp;&nbsp;**선언**: 포인터 = new 타입[(초기값)];    
> new 다음에 할당 대상 타입을 밝히면 sizeof(타입)만큼의 메모리가 할당되고 할당된 포인터가 리턴된다.  
> new가 리턴하는 번지는 같은 타입의 포인터 변수로 대입받는다.  
> 할당과 동시에 메모리를 초기화하고 싶으면 타입 다음의 괄호에 원하는 초기값을 적되 초기화를 할 필요가 없으면 생략할 수 있다.  
> 초기화하지 않은 메모리는 쓰레기값을 가진다.  
> 메모리 부족 등의 이유로 할당에 실패하면 NULL을 리턴한다.    
> 만약 할당만 하고 해제를 하지 않으면 메모리 일부를 사용할 수 없게 되는 메모리 누수가 발생하므로 동적 할당한 메모리는 반드시 delete해야 한다.  

**delete**: 메모리 해제 연산자  
&nbsp;&nbsp;&nbsp;**선언**: delete 포인터;  
> 한 포인터에 대해 delete를 두 번 하는 것은 안되지만 NULL 포인터를 삭제하는 것은 가능하다.  
> 동적으로 할당한 배열을 삭제할 때는 delete 대신 반드시 delete [ ] 문을 사용해야 한다.  

<pre>
#include < iostream >

void main()
{
     int *pi=new int;
     *pi=123;
     printf("*pi=%d\n",*pi);
     delete pi;
}
</pre>
<pre>
#include < iostream >

struct tag_Friend
{
    char Name[10];
    int Age;
    double Height;
};

void main()
{
    tag_Friend* pF = new tag_Friend;
    strcpy(pF->Name, "아무개");
    pF->Age = 22;
    pF->Height = 177.7;

    printf("이름=%s, 나이=%d, 키=%.1f\n", pF->Name, pF->Age, pF->Height);

    delete pF;
}
</pre>
<pre>
#include < iostream >

void main()
{
     int *ar=new int[5];
     int i;
     for (i=0;i<5;i++) {
          ar[i]=i;
     }

     for (i=0;i<5;i++) {
          printf("%d번째 = %d\n",i,ar[i]);
     }
     delete [] ar;
}
</pre>
