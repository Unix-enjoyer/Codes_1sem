#include <stdio.h>
#include <stdio.h>
#include <math.h>

double f3(double x) // функция для варианта 3
{
	return 1 - x + sin(x) - log(1 + x);
}

double f3_1derivative(double x) // ее первая производная
{
	return -1 + cos(x) - 1 / (1 + x);
}

double f3_2derivative(double x) // ее вторая производная
{
	return -sin(x) + 1 / pow((1 + x), 2);
}

double f3_x(double x) // функция 3 с выраженным х
{
	return 1 + sin(x) - log(1 + x);
}

double f3_x_derivative(double x) // ее производная
{
	return cos(x) - 1 / (1 + x);
}


double f4(double x) // функция для варианта 4
{
	return 3 * x - 14 + exp(x) - exp(-x);
}

double f4_1derivative(double x) // ее первая производная
{
	return 3 + exp(x) + exp(-x);
}

double f4_2derivative(double x) // ее вторая производная
{
	return exp(x) - exp(-x);
}

double f4_x(double x) // функция 4 с выраженным х
{
	return (14 - exp(x) + exp(-x)) / 3.0;
}

double f4_x_derivative(double x) // ее производная
{
	return (-2 * exp(x)) / 3.0;
}

int main()
{	
	double EPS = 1.0; // машинное эпсилон
	while (1.0 + EPS / 2.0 > 1.0) { // вычисляем машинное эпсилон
		EPS /= 2.0;
	}
	// численные методы
	
	double dih(double f(double), double a, double b) // дихотомия
	{	
		int cnt1 = 0;
		if (f(a) * f(b) < 0) {
		
			while (fabs(a - b) >= EPS) {
			
				if ( f(b) * f((a + b) / 2.0) > 0.0) {
					b = (a + b) / 2.0; 
				} else if ( f(a) * f((a + b) / 2.0) > 0.0) {
					a = (a + b) / 2.0;
				} 
				
				cnt1 += 1;
				if (cnt1 > 200) break;
			}
			return (a + b) / 2.0;
			
		} 
	}
	
	
	double iter(double f(double), double a, double b) // итераций
	{	
		int cnt2 = 0;
		double x = 0, x0 = (a + b) / 2.0;
			
		while (fabs(x - x0) >= EPS) {
			x = f(x0);
			x0 = x;
			
			cnt2 += 1;
			if (cnt2 > 200) break;
		}
		
		if (x != 0) {
			return x;
		} else {
			return -999;
		}
	}
	
	
	double newt(double f(double), double f_2d(double), double f_1d(double), double a, double b) // Ньютона
	{	
		double x = 0, x0 = (a + b) / 2.0;
		if ( fabs(f4(x) * f4_2derivative(x)) < pow(f4_1derivative(x), 2) ) {
		
			while (fabs(x - x0) >= EPS) {
			
				x = x0 - f(x0) / f_1d(x0);
				x0 = x;

			}
			
		}
		if (x != 0) {
			return x;
		} else {
			return -999;
		}
		
	}
	

	double ans11, ans12, ans13, ans21, ans22, ans23;
	ans11 = dih(f3, 1.0, 1.5);
	ans21 = dih(f4, 1.0, 3.0);
		
	if (f3_x_derivative(1.0) < 1 && f3_x_derivative(1.5) < 1) {
		ans12 = iter(f3_x, 1.0, 1.5);
	} else {
		return -999;
	}
	
	if (f4_x_derivative(1.0) < 1 && f4_x_derivative(3.0) < 1) {
		ans22 = iter(f4_x, 1.0, 3.0);
	} else {
		return -999;
	}
	
	ans13 = newt(f3, f3_2derivative, f3_1derivative, 1.0, 1.5);
	ans23 = newt(f4, f4_2derivative, f4_1derivative, 1.0, 3.0);
	
	printf(" _____________________________________________________________________\n");
	printf("|#########|    дихотомии    |     итераций      |       Ньютона       |\n");
	printf("|#########|_________________|___________________|_____________________|\n");
	printf("|         |                 |                   |                     |\n");
	printf("|функция 3|%1.9f      |%1.9f        |%1.9f          |\n", ans11, ans12, ans13);
	printf("|_________|_________________|___________________|_____________________|\n");
	printf("|         |                 |                   |                     |\n");
	printf("|функция 4|%1.9f      |%1.9f        |%1.9f          |\n", ans21, ans22, ans23);
	printf("|_________|_________________|___________________|_____________________|\n");
	
}
