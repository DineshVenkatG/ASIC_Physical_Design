#include<stdio.h>
#include<math.h>

int main()
{
	unsigned long long int a;
	long long int max,min;
	a=(unsigned long long int)(pow(2,64)-1);
	max=(long long int)(pow(2,63)-1);
	min=(long long int)(pow(2,63)*(-1));
	printf("Max value of 64 bit unsigned number is %llu\nMax value of 64 bit signed number is %lld\nMin value of 64 bit signed number is %lld\n",a,max,min);
	
	return 0;
	
}
