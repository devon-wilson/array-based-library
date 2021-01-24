#include <iomanip>
#include <iostream>
#include <cstring>
#ifndef BOOK_H
#define BOOK_H
using namespace std;
const int MAX_STR = 200;
class Book
{
	public:
		Book();
		void print();
		void getTitle(char tempTitle[]);
		void getAuthor(char tempAuthor[]);
		void getPublisher(char tempPublisher[]);
		double getPrice();
		int getInStock();		
		int getISBN();
		void setTitle(char tempTitle[]);
		void setAuthor(char tempAuthor[]);
		void setPublisher(char tempPublisher[]);
		void setInStock(int tempInStock);
		void setISBN(int tempISBN);
		void setPrice(double tempPrice);
	private:
		double price;
		int isbn;
		int inStock;
		char publisher[MAX_STR];	
		char author[MAX_STR];
		char title[MAX_STR];
		
};
#endif
