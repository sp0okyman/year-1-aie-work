#include <iostream>
#include <fstream>


// making struct to hold information of book_information
struct book_information
{
	char title[60];
	char author[40];
	char publisher[30];
	int year_published;
	double price;
};

// declaring functions
void write_file(book_information *a_book);
void read_file(int book_number);

int main()
{
	// make a new_book with DMC memes
	book_information new_book =
	{
		"Smokin' Sick Style - A DMC Guide To Being SSStylish",
		"Dante",
		"Devil May Cry",
		2001,
		15.99,
	};
	// another one, but with vergil memes
	book_information new_book2 = 
	{
		"Where Is Your Motivation? - A Guide To Gaining More Power",
		"Vergil",
		"Devils Never Cry",
		2003,
		17.50,
	};
	// yet another one, but nero this time
	book_information new_book3 = 
	{
		"Why Arms Are God's Gift To Earth - Also, Fuck You Dad",
		"Nero",
		"Devil May Seethe",
		2019,
		21.99,
	};

	// call the functions to actually do stuff
	write_file(&new_book);
	write_file(&new_book2);
	write_file(&new_book3);

	read_file(0);
	read_file(1);
	read_file(2);

	system("Pause");

	return 0;
}

void write_file(book_information *a_book)
{
	// set permissions and allocate file name
	std::ofstream file("data.dat", std::ios::in | std::ios::out | std::ios::binary);

	// if file opens well enough...
	if (file.good())
	{
		// ... print this shit to console
		std::cout << "Opened File data.dat successfully\n";
	}
	else 
	{
		// create a data.dat file if there isn't one
		std::ofstream file("data.dat", std::ios::out | std::ios::binary);
		std::cout << "creating data.dat\n";
		file.close();
		// call the function again
		write_file(a_book);
		return;
	}
	//seek the beginning of the file and write to it
	file.seekp(0, std::ios::end);
	file.write((char*)a_book, sizeof(book_information));

	file.close();
}

void read_file(int a_book_number)
{
	// make a variable of book_information called read_book
	book_information read_book;
	//open file of data.dat
	std::ifstream file("data.dat", std::ios::in | std::ios::out | std::ios::binary);
	//if there's no problems opening it...
	if (file.good())
	{
		// seek for start of desired book number and read it
		file.seekg(a_book_number * sizeof(book_information), std::ios::beg);
		file.read((char*)&read_book, sizeof(book_information));
		// details of book number
		std::cout << read_book.title << '\n';
		std::cout << read_book.author << '\n';
		std::cout << read_book.publisher << '\n';
		std::cout << read_book.year_published << '\n';
		std::cout << read_book.price << '\n';
	}
	else 
	{
		// shit's fucked
		std::cout << "Error opening file\n";
	}
}