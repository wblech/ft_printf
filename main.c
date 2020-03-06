#include <stdio.h>

int	main(void)
{
	printf("%%.5d: %.5d\n", -15);
	printf("%%0: %0d\n", 15);
	printf("%%05: %05d\n", 15);
	printf("%%5: %5d\n", 15);
	printf("%%-5: %-5d\n", 15);
	printf("%%0-5: %0-5d\n", 15);
	printf("%%5-: %5-d\n", 15);
	printf("%%10-5: %10-5d\n", 15);
	printf("%%.5: %.5d\n", 15);
	printf("%%0.5: %0.5d\n", 15);
	printf("%%10.5: %10.5d\n", 15);
	printf("%%-10.5: %-10.5d\n", 15);
	printf("%%-.5: %-.5d\n", 15);
	printf("%%*(10).5: %*.5d\n", 10,15);
	printf("%%*(-10).5: %*.5d\n", -10,15);
	printf("%%.*(5): %.*d\n", 5, 15);
	printf("%%.*(-5): %.*d\n", -5, 15);
}
