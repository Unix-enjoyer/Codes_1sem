/*Чёрный 104Б вариант 16*/
#include <stdio.h> 
#include <stdbool.h>
void scan_num(long long nm) // для анализа числа (есть ли в числе отсутствующие цифры, если да - какие?)
{	
	bool is_right = false; // пер-ая для р-та - да или нет
	int numb; // текущая считанная цифра
	int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0; // считают цифры, которые есть
	
	if (nm < 0) { // если отр. - модуль
		nm *= -1;
	}
	
	if (nm == 0) { //если 0 - не зайдем в основной цикл, прописываем ноль отдельно
		cnt0 += 1;
		is_right = true;
	} else {
		while (nm != 0) { // осн. цикл, считывает по одной цифре, присваеивает нужному счетчику плюс 1
			numb = nm % 10;
			nm /= 10;
			
			switch (numb) {
			case 1:
				cnt1 += 1;
			  	break;
			case 2:
				cnt2 += 1;
			  	break;
			case 3:
				cnt3 += 1;
			  	break;
			case 4:
				cnt4 += 1;
			  	break;
			case 5:
				cnt5 += 1;
			  	break;
			case 6:
				cnt6 += 1;
			  	break;
			case 7:
				cnt7 += 1;
			  	break;
			case 8:
				cnt8 += 1;
			  	break;
			case 9:
				cnt9 += 1;
			  	break;
			 
			default:
				cnt0 += 1;
				break;
			}
					
		}
	}
	
	if (cnt1 == 0) { // каскад if'ов - выводит недостающие цифры, если таких нет - пустая строка
		printf("%d", 1);
	}
	if (cnt2 == 0) {
		printf("%d", 2);
	}
	if (cnt3 == 0) {
		printf("%d", 3);
	}
	if (cnt4 == 0) {
		printf("%d", 4);
	}
	if (cnt5 == 0) {
		printf("%d", 5);
	}
	if (cnt6 == 0) {
		printf("%d", 6);
	}
	if (cnt7 == 0) {
		printf("%d", 7);
	}
	if (cnt8 == 0) {
		printf("%d", 8);
	}
	if (cnt9 == 0) {
		printf("%d", 9);
	}
	if (cnt0 == 0) {
		printf("%d", 0);
	}
	
	if (cnt0 > 0 && cnt1 > 0 && cnt2 > 0 && cnt3 > 0 && cnt4 > 0 && cnt5 > 0 && cnt6 > 0 && cnt7 > 0 && cnt8 > 0 && cnt9 > 0) {
		is_right = false; // условие верно, значит все цифры на месте
	} else {
		is_right = true; // неверно - отсутствует хотя бы одна
	}

	printf("\n%s\n", is_right? "Yes" : "No"); // вывод результата

}

int main() 
{
	long long num = 0; // входное число

	while (scanf("%lld", &num) == 1) { // пока цифры не кончатся - читаем их и обрабатываем
		scan_num(num);
	}

}
