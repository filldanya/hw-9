#include <iostream>
class Fraction
{
private:
	int x_ = 0;
	int y_ = 0;

public:
	Fraction(int x, int y)
	{
		x_ = x;
		y_ = y;
	}
	Fraction operator + (const Fraction& sum) const
	{
		return Fraction{ x_ * sum.y_ + y_ * sum.x_ , y_ * sum.y_ };
	}
	Fraction operator - (const Fraction& sum) const
	{
		return Fraction{ x_ * sum.y_ - y_ * sum.x_ , y_ * sum.y_ };
	}
	Fraction operator * (const Fraction& sum) const
	{
		return Fraction{ x_ * sum.x_ , y_ * sum.y_ };
	}
	Fraction operator / (const Fraction& sum) const
	{
		return Fraction{ x_ * sum.y_ , y_ * sum.x_ };
	}
	Fraction& operator++ ()
	{
		x_ += y_;
		return *this;
	}
	Fraction& operator-- ()
	{
		x_ -= y_;
		return *this;
	}
	Fraction operator++ (int)
	{
		Fraction copy{ *this };
		++(*this);
		return copy;
	}
	Fraction operator-- (int)
	{
		Fraction copy{ *this };
		--(*this);
		return copy;
	}
	int get_x()
	{
		return x_;
	}
	int get_y()
	{
		return y_;
	}
	Fraction reduction(Fraction& x2)
	{
		for (int i = 1; i <= x_ && i <= y_; i++)
		{

			if (!(x_ % i) && !(y_ % i))
			{
				x2.x_ = x_ / i;
				x2.y_ = y_ / i;
			}
		}
		return Fraction{ x2.x_, x2.y_ };
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> c;
	std::cout << "Ведите знаменатель дроби 2: ";
	std::cin >> d;
	Fraction f1(a, b);
	Fraction f2(c, d);
	Fraction f3 = f1 + f2;
	Fraction f4 = f3;
	Fraction f5 = f1;
	f3 = f3.reduction(f4);
	std::cout << f1.get_x() << "/" << f1.get_y() << " + " << f2.get_x() << "/" << f2.get_y() << " = " << f3.get_x() << "/" << f3.get_y() << std::endl;
	f3 = f1 - f2;
	f4 = f3;
	f3 = f3.reduction(f4);
	std::cout << f1.get_x() << "/" << f1.get_y() << " - " << f2.get_x() << "/" << f2.get_y() << " = " << f3.get_x() << "/" << f3.get_y() << std::endl;
	f3 = f1 * f2;
	f4 = f3;
	f3 = f3.reduction(f4);
	std::cout << f1.get_x() << "/" << f1.get_y() << " * " << f2.get_x() << "/" << f2.get_y() << " = " << f3.get_x() << "/" << f3.get_y() << std::endl;
	f3 = f1 / f2;
	f4 = f3;
	f3 = f3.reduction(f4);
	std::cout << f1.get_x() << "/" << f1.get_y() << " / " << f2.get_x() << "/" << f2.get_y() << " = " << f3.get_x() << "/" << f3.get_y() << std::endl;
	f3 = ++f1 * f2;
	f4 = f3;
	f3 = f3.reduction(f4);
	std::cout << "++" << f5.get_x() << "/" << f5.get_y() << " * " << f2.get_x() << "/" << f2.get_y() << " = " << f3.get_x() << "/" << f3.get_y() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.get_x() << '/' << f1.get_y() << std::endl;
	f5 = f1;
	f3 = f1-- * f2;
	f4 = f3;
	f3 = f3.reduction(f4);
	std::cout << f5.get_x() << "/" << f5.get_y() << "--" << " * " << f2.get_x() << "/" << f2.get_y() << " = " << f3.get_x() << "/" << f3.get_y() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.get_x() << '/' << f1.get_y() << std::endl;
	return 0;
}
