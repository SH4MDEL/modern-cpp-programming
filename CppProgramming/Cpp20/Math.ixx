module; // Global Module Fragment

// ���� �ܺ� ��� �߰�
#include <vector>

// ��� ����
export module Math;

// �ٸ� ��� import
// Submodule
export import Math.time;


// 1) �Լ� �տ��ٰ� export
export int Add(int a, int b)
{
	return a + b;
}

// 2) export �ϰ� ���� �ֵ��� ���� ������
export
{
	void TestExport1()
	{

	}
}

void Internal()
{

}

// 3) namespace�� ����
export namespace Test
{
	void TestExport2()
	{

	}
}