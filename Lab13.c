#include <stdio.h>
#include <ctype.h> // для функций со строками
#include <stdint.h> // для форматов инта
#include <stdbool.h> // для булевого типа данных

int onecounter(uint64_t sett) 
{	
	int cnt = 0; // cnt-считает единицы, digit-то, на сколько сдвинуть(для умножения, так мы получаем степени двойки)
	uint64_t dynamic = 1; // число для степеней двойки
	
	while (dynamic <= sett) {
	//printf("%ld %ld %d\n", sett, dynamic, cnt);
		if ((sett & dynamic) == dynamic) { // проевряем наличие единиицы в разряде
			cnt += 1;
			//printf("333333333333\n");
			//printf("%ld\n", dynamic);		
		} 
		dynamic = dynamic << 1; // умножаем число на 2
		
	}
	//printf("3143\n");
	if (cnt > 1) { // если в множестве больше одной согласной буквы - 0, иначе - 1
		return false;
	} else {
		return true;
	}
}

int main() 
{	
	//bool value = false; // есть или нету нужное слово в вх. данных
	char c, c1;
	uint64_t set = 0;
	uint64_t mv;
	
	while ((c = getchar()) != EOF) { // пока читаются вх. данные
	
		c = tolower(c);	// эеономим память и не учитываем загл. буквы	
		
		if (isalpha(c)) { // если буква, записываем ее в множество под ее номером в алфавите
		
			if ((c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u') && (c != 'y')) {
				mv = (c -'a');
				set |= 1u << mv;
				
			}
			
		} else if (isspace(c)) { // если пробел, подводим итог и обнуляем для чтения нового слова
			printf("%d\n", onecounter(set));
			set = 0;	
			
		} 
		
	}
		//c1 = c; // remember, when word ends on numbers. you should do CHECK
	//printf("%d\n", tobin(400));
	
}
