/*Чёрный Дмитриё 104 вар 20 */ /* считать множество, исключить гласные и вывести его */
#include <stdio.h>
#include <ctype.h> // для функций со строками
#include <stdint.h> // для форматов инта
#include <stdbool.h> // для булевого типа данных

void print_result(bool result) 
{
	if (result) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}		
}
// поэлементно вычитать гласные из целого множества букв
int main() 
{
	bool result = true, need_skip = false; // есть или нету нужное слово в вх. данных
	char c;
	uint64_t set = 0;
	
	while ((c = getchar())) { // пока читаются вх. данные
		
		if (need_skip && (!(isspace(c)))) {
			continue;
		}
		
		if (isalpha(c)) { // если буква, записываем ее в множество под ее номером в алфавите
		
			c = tolower(c);	// экономим память и не учитываем загл. буквы	
		
			int new_elem = 1u << (c - 'a');
		
			if ((c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u') && (c != 'y')) {
				
				if ( set == 0 || ((set | new_elem) == set) ) {
					result = true;
					set |= new_elem;
				} else {
					result = false;
					need_skip = true;
				}
			}
			
		} else if (isspace(c) || c == EOF) { // если пробел, подводим итог и обнуляем для чтения нового слова
			
			if (c == EOF) {
				break;
			}
			print_result(result);
			set = 0;
			need_skip = false;
			
		}
		
	}
	
}

