module; // Global Module Fragment

// 각종 외부 헤더 추가
#include <vector>

// 모듈 시작
export module Math;

// 다른 모듈 import
// Submodule
export import Math.time;


// 1) 함수 앞에다가 export
export int Add(int a, int b)
{
	return a + b;
}

// 2) export 하고 싶은 애들을 따로 묶어줌
export
{
	void TestExport1()
	{

	}
}

void Internal()
{

}

// 3) namespace를 지정
export namespace Test
{
	void TestExport2()
	{

	}
}