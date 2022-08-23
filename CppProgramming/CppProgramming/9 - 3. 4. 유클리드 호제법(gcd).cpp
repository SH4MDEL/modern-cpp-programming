#include <iostream>

template <int X, int Y>
struct GCD {
	static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

// p/q 꼴로 쓸 수 있는 수(유리수)를 오차 없이 표현해 주는 클래스 Ratio
template <int N, int D = 1>
struct Ratio {
private:
	const static int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type;
	static const int num = N / _gcd;	// 분자
	static const int den = D / _gcd;	// 분모
};

template <class R1, class R2>
struct _Ratio_add {
	using type =  Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
	using type = Ratio<R1::num* R2::den - R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
	using type = Ratio<R1::num * R2::num, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
	using type = Ratio<R1::num * R2::den, R1::den* R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

int main()
{
	typedef Ratio<2, 3> rat;
	typedef Ratio<3, 2> rat2;

	//typedef _Ratio_add<rat, rat2>::type rat3;
	//typedef Ratio_add<rat, rat2> rat3;
	using rat3 = Ratio_add<rat, rat2>;

	std::cout << rat3::num << " / " << rat3::den << std::endl;

	using rat4 = Ratio_multiply<rat, rat3>;

	std::cout << rat4::num << " / " << rat4::den << std::endl;
}