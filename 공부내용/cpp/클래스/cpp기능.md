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

<pre>#include <iostream>
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
#include <iostream>
using namespace std;

void main()
{
     int i;
     cout << "정수를 입력하십시오 : ";
     cin >> i;
     cout << "입력한 값은 " << i << "입니다." << endl;
}
</pre>
