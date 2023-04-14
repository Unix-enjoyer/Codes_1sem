#include <stdio.h>
#include <math.h>

long long factorial(int number) 
{
	long long result = 1;	
	if (number == 0) {
		return result;
	} else {
	
		for (int i = 1; i <= number; ++i) {
			result *= i;
		}
		return result;
	}

}

int main() 
{	
	long double EPS = 1.0, a = 0.0, b = 1.0, s, x, f, elem;
	int count, m, n = -1, k;
	
	while (1.0 + EPS/2.0 > 1.0) { // вычисляем машинное эпсилон
		EPS /= 2.0;
	}
	printf("Введите количество отрезков и коэффицент k\n");
	scanf("%d%d", &m, &k); // число отрезков и коэф. k
	printf("Эпсилон = %1.21Lf\n", EPS);
	printf("______________________________________________________\n");
	printf("|  x  |    summ of row     |   function value   |iter|\n");
	printf("|_____|____________________|____________________|____|\n");	
	
	for (x = a; x <= b + EPS; x += (b - a) / m) { // цикл для каждого х с интервалом 
	
		count = 0;
		f = (1 + 2 * x*x) * exp(x*x); // вычислили значение функции
		s = 0;
		
		while (count < 100) { // считаем ряд Тейлора, нужно уложиться в 100 итераций
			
			elem = (2 * count + 1) * powl(x, 2 * count) / factorial(count); // слагаемое ряда вычислили
			s += elem;
			if (elem < EPS * k) break;
			
			count += 1;		
		}
		
		printf("| %1.1Lf | %16.16Lf | %16.16Lf | %1.2d |\n", x, s, f, count);
		
	}
	
	printf("|_____|____________________|____________________|____|\n");
	
	return 0;

}


