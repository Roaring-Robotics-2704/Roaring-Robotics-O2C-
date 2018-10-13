#include "../include/easy.h"

int addthree(int a, int b, int c) {
	return a+b+c;
}


float average(int a, int b, int c) {
	return addthree(a,b,c)/3;
}

int main() {
	print("Hello World!");
	print("The average of 1,2,3 is:");
	print(average(1,2,3));
}
