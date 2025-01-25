#include <iostream>
using namespace std;

import Math;

// 어떻게 빌드 속도를 단축시키는가
// 전처리 -> 컴파일 -> 링크
// 기존에 사용하던 방법의 문제점
// 1) 빌드 속도
// 너무 느리다.
// 2) 매크로 (#define)
// 3) 심볼 중복 정의 (여러 번 정의된 기호가 있습니다.)

int main()
{
	// Module
	// - 모듈은 딱 한번만 import 된다.
	// - import 순서에 상관 없음
	// - 심볼 중복 정의 문제 X
	// - 모듈의 이름도 지정 가능
	// - 인터페이스/구현부 분리 관리할 필요 없음.

	cout << Add(1, 2) << endl;
	TestExport1();
	Test::TestExport2();

	MathTimeFunc();
}