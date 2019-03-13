#include <iostream>
#include <fstream>

struct book_information
{
	char title[40];
	char author[40];
	char publisher[30];
	int year_published;
	double price;
};

void write_file(book_information *a_book);
void read_file(int book_number);

int main()
{
	book_information new_book = 
	{
		"";
	}

	return 0;
}