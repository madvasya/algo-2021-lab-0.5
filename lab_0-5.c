/*Вариант 13                                                                     Задание 0.5а
Из входного потока вводится произвольное число строк. 
Каждая строка представляет собой последовательность 
многоразрядных десятичных чисел,  
разделенных одним или несколькими пробелами 
и/или знаками табуляции. 
Длина каждой строки произвольна. Конец ввода 
определяется концом файла.

Для каждой строки сформировать новую строку, 
поместив в нее числа исходной строки, цифры в которых 
записаны в обратном порядке. В полученной строке 
числа разделять только одним пробелом. 
Лидирующие нули в перевернутых числах должны быть 
подавлены. Полученную строку вывести на экран.*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *getstr();
char *process(char*);
char *skipSpace(char*);
char *skipWord(char*);
char *copyWord(char *from, char *to);

int main(){
	char *s = NULL, *p = NULL;
	printf("Source string: \"%s\"\n", getstr());

	
	/*while(puts("enter..."), s = getstr()){
		printf("Source string: \"%s\"\n", s);
		free(s);
	}*/
	return 0;
}

char *getstr(){
	char *ptr=(char*)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do{
		n = scanf("%80[^\n]", buf);
		printf("n: %d\n", n);

		if(n < 0){
			free(ptr);
			ptr = NULL;
			continue;
		}
		if(n == 0){
			scanf("%*c");
		}
		else{
			len+=strlen(buf);
			printf("strlen: %d\n", strlen(buf));
			ptr = (char*)realloc(ptr, len+1);
			strcat(ptr, buf);
		}
	}while(n > 0);
	return ptr;
}
