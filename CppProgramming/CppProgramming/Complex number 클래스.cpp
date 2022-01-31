#include <iostream>

class Complex {
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }

	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;

	Complex& operator=(const Complex& c);
	Complex& operator+= (const Complex & c);
	Complex& operator-= (const Complex & c);
	Complex& operator*= (const Complex & c);
	Complex& operator/= (const Complex & c);
	void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const
{
	Complex temp(real + c.real, img + c.img);
	return temp;
}

Complex Complex::operator-(const Complex& c) const
{
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) const
{
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}

Complex Complex::operator/(const Complex& c) const
{
	Complex temp((real * c.real + img * c.img) / (c.real * c.real + c.img * c.img), 
				(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex& Complex::operator+=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}

int main()
{
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex c(0.0, 0.0);

	c = a * b + a / b + a + b;

	c.println();
}