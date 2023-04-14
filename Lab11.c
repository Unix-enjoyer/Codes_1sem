/* Чёрный 104-Б 
выделить предпоследнее десятичное число и вычислить сумму его цифр - вар 26 */
#include <stdio.h>
#include <ctype.h>

long long sm(long long numb) { // функция для подсчета суммы цифр в числе
	
	long long res = 0;
	
	while (numb > 0) {
		res += numb % 10;
		numb /= 10;
	}
	return res;
}

int main() 
{	
	char c, c1;
	long long sum1 = 0, sum = 0, sum2 = 0; //bad_word - пометка испорч. слова(в составе числа есть цифры)
	int bad_word = 0;
	
	while ((c = getchar()) != EOF) { // читать символы, пока файл не закончится
		c1 = c;
		
		if (bad_word == 1) { // * по установленной пометке пропускает текущее слово
			if (isspace(c)) { // слово кончилось, убираем пометку
				bad_word = 0; 
			}
			continue;
		} 
		
		if (isdigit(c)) { // цифра, собираем число
			sum = sum * 10 + (c - '0');
		} else if (isalpha(c) || ispunct(c)) { /* встречена буква или знак пунктуации, либо в числе, либо в обычном слове - делаем пометку */
			sum = 0; // сбрасываем sum, слово не подходит!
			bad_word = 1;
			continue;
		} else if (isspace(c)) { // после каждого слова собирает итог

			if (sum != 0) { // пишет новое число, если пишется
				sum2 = sum1; // на случай если прочитано последнее число=
				sum1 = sum; // сохраняет, осуществляется сдвиг
				sum = 0; // готов к чтению нового числа
			}
			continue;
		}
	}
	
	if (c == EOF && !isspace(c1)) {
		sum2 = sum1; 
		sum1 = sum; 
		sum = 0; 
	}
	
	if (sum2 != 0) {	
		printf("%lld\n", sum2); 
		printf("%lld\n", sm(sum2));
	}

}


