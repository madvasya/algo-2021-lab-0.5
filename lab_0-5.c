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
#define _CRT_SECURE_NO_WARNINGS


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
	
	while(puts("Enter new string"), s = getstr()){
		printf("Source string: \"%s\"\n", s);
		p = process(s);
		printf("New string: \"%s\"\n", p);
		free(s);
	}
	return 0;
}

char *getstr(){
	char *ptr=(char*)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do{
		n = scanf("%80[^\n]", buf);

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
			ptr = (char*)realloc(ptr, len+1);
			strcat(ptr, buf);
		}
	}while(n > 0);
	return ptr;
}

char* process(char* s) {//переворачивает каждое слово в строке и возвращает указатель на изменённую строчку
	char* p = (char*)malloc(strlen(s) + 1);
	int fl = 0;
	char* tmp = p;
	*tmp = '\0';
	while (*(s = skipSpace(s))) {
		s = reverseWord(s);
	}

	return p;
}



char* copyWord(char* from, char* to) {
	int k = strcspn(from, " \t");
	strncat(to, from, k);
	to += k;
	*to++ = ' ';
	*to = '\0';

	return to;
}

char* skipSpace(char* s) {
	int k = strspn(s, " \t");
	return s + k;
}

//пропускает слово
char* skipWord(char *s) {

	int k = strcspn(s, " \t"); //длина слова
	
	return s + k;
}

char* reverseWord(char* s) {
	int k = strcspn(s, " \t"); //длина слова
}
