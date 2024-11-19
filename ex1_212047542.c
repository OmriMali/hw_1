#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int oct_to_dec(int num) {
	int i = 1, num_dec=0;
	while (num != 0) {
		num_dec += (num % 10)*i;
		num /= 10;
		i *= 8;
	}	
	return(num_dec);	
}
int hex_to_dec(int num) {
	int i = 1, num_dec = 0;
	while (num > 0) {
		num_dec += (num % 10) *i;
		num /= 10;
		i*=16;
	}
	return(num_dec);
}
int sum_of_digits(int num) {
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int number_of_digits(int num) {
	int i = 0;
	while (num > 0) {
		num /= 10;
		i++;
	}
	return i;
}
int repr_base_prefix(int num, int base) {
	switch (base) {
	case(8):
		printf("Od%d = O%o", num, num);
		break;
	case(16):
		printf("Od%d = Ox%x", num, num);
		break;
	default:
		printf("Base 10 representation was already computed above.\n");
	}
	return 0;
}
int main() {
	int num=0, base=0,num_abs, num_abs_dec=0, flag=1;
	char sign;
	printf("Please enter an integer and a base\n");
	scanf("%d", &num);
	if (num > 0) {
		num_abs = num;
		sign = '+';
	}
	else if (num < 0) {
		num_abs = -num;
		sign = '-';
	}
	else{
		num_abs = 0;
		sign = '0';
	}
	do {
		scanf("%d",&base);
		switch (base)
		{
		case(8):
			num_abs_dec = oct_to_dec(num_abs);
			flag = 0;
			break;
		case(16):
			num_abs_dec = hex_to_dec(num_abs);
			flag = 0;
			break;
		case(10):
			num_abs_dec = num_abs;
			flag = 0;
			break;
		default:
			printf("Invalid base %d\nPlease enter a valid base [8,10,16]:\n",base);

		} 
	} while (flag);

	printf("Here is some information about the given number: %d\n", num);
	printf("It's sign is: %c\n", sign);
	printf("Decimal representatiom of absolute value: %d\n", num_abs_dec);
	printf("The sum of digits is: %d\n", sum_of_digits(num_abs_dec));
	printf("The number of digits is: %d\n", number_of_digits(num_abs_dec));
	repr_base_prefix(num_abs, base);
}