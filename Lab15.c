#include <stdio.h>

int main() {

	int size; // размер массива
	scanf("%d", &size); // считали 
	int array[size][size]; // создадим массив сайз на сайз
	
	for (int i = 0; i < size; ++i) { // заполним массив
		for (int j = 0; j < size; ++j) {
			scanf("%d", &array[i][j]);
		}
	}
	
	
	int swap; // переменная-буфер
	
	for (int i = 0, j = size - 1; i < size; ++i, --j) { // цикл замены местами элементов на диагоналях
		swap = array[i][i];
		array[i][i] = array[i][j];
		array[i][j] = swap;
		
	}
	
	
	
	
	

	for (int i = 0; i < size; ++i) { // вывод матрицы по строкам
		for (int j = 0; j < size; ++j) {
			int k = j;
			printf("%d\t", array[i][j]);
			
			if ((k + 1) % size == 0) { // для того, чтобы матрица выводилась в виде таблицы
				printf("\n");
			}
			
		}
	}
}

/*
	int arr[size]; // создадим буферный массив для элементов гл. диаг.
	
	for (int i = 0; i < size; ++i) { // заполняем его
		arr[i] = array[i][i];
	}
	
	for (int i = 0, j = size - 1; i < size; ++i, --j) { // на гл. диаг. ставим побочную
		array[i][i] = array[i][j];
		
	}

	//
	for (int i = 0, j = size - 1; i < size; ++i, --j) { // на побоч. диаг. ставим значения из буфера
		array[i][j] = arr[i];
	}
	
	*/
	
	
	
	
	
