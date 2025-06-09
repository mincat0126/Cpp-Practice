# void형 포인터
**void형 포인터**: 선언할 때 대상체의 타입을 명시하지 않는 포인터.  
&nbsp;&nbsp;&nbsp;**선언**: void *변수명;  
> 일반 변수에는 void형을 쓸 수 없다.  
> 임의의 포인터에 보이드형 포인터를 대입할 때는 반드시 캐스팅을 해야 한다.  
> void형 포인터는 임의의 대상체에 대한 번지값만 알고 그 내용을 모른다.  
> void형 포인터에 *연산자를 쓰고 싶으면 대입받은 내용의 타입으로 캐스팅을 해야 한다.  
> void형 포인터 증감을 하고 싶은 경우는 먼저 캐스팅 한 뒤에 더하면 된다.  

**<void형 포인터 특징>**
1. 임의의 대상체를 가리킬 수 있다.(어떠한 대상체라도 가리킬 수 있다)
2. *연산자를 쓸 수 없다.
3. 증감연산자를 쓸 수 없다.

<pre>#include < stdio.h >

int main()
{
	int i[] = {1,2,3,4};
	float j = 1.23;
	void* vp;

	vp = &j;
	vp = &i;

  vp = (int*)vp+1;
	printf("%d\n", *(int*)vp);
}</pre><br><br><br>

# void형 포인터 활용
**memset함수**: s번지에서 n바이트만큼 c값으로 가득 채우는 함수  
&nbsp;&nbsp;&nbsp;**선언**: void *memset(void *s, int c, size_t n);  
<pre>#include < windows.h >
#include < stdio.h >

int main()
{
	int ari[10];
	char arc[10];
	double ard[10];

	memset(ari, 0, sizeof(ari));
	memset(arc, 0, sizeof(arc));
	memset(ard, 0, sizeof(ard));

	for (int i = 0; i < 10; i++)
	{
		printf("%d", ari[i]);
	}
}</pre><br><br><br>

# NULL 포인터
**NULL 포인터**: 0으로 정의되어 있는 포인터 상수값.  
> 어떤 포인터 변수가 NULL값을 가지고 있으면 이 포인터는 0번지를 가리키는 것이다.  
> 포인터를 리턴하는 대부분 함수가 에러가 났을 때 NULL값을 리턴한다.  
> 0번지를 읽거나 리턴하면 시스템이 다운된다.  
