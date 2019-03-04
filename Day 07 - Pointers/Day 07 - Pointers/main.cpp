#include <iostream>

int main()
{
	// Question 1.
//	char c = 'T', d = 'S';									
//	char *p1 = &c;																		//*p3 = S
//	char *p2 = &d;																		//*p3 = T, p3 = T GARBAGE_MEMORY
//	char *p3;																			//*p1 = S, p1 = S GARBAGE_MEMORY
//
//	p3 = &d;
//
//	std::cout << "*p3 = " << *p3 << std::endl; // (1)
//
//	p3 = p1;
//
//	std::cout << "*p3 = " << *p3; // (2)
//	std::cout << ", p3 = " << p3 << std::endl; // (3)
//
//	*p1 = *p2;
//
//	std::cout << "*p1 = " << *p1; // (4)
//	std::cout << ", pl = " << p1 << std::endl; // (5)

	// Question 2.
//	int *p;
//	int i;
//	int k;
//
//	i = 42;
//	k = i;
//	p = &i;
//
//	*p = 75;
//
//	std::cout << i << '\t' << k << '\t' << p << '\n';

	// Question 4.
//	char c = 'A';
//	double *p = &c;

	// Question 5.
	char blocks[3] = { 'A', 'B', 'C' };
	char *ptr = &blocks[0];
	char temp;

	temp = blocks[0];
	temp = *(blocks + 2);
	temp = *(ptr + 1);
	temp = *ptr;

	ptr = blocks + 1;
	temp = *ptr;
	temp = *(ptr + 1);

	ptr = blocks;
	temp = *++ptr;
	temp = ++*ptr;
	temp = *ptr++;
	temp = *ptr;

	system("pause");

	return 0;
}