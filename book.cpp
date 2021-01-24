#include "book.h"

Book::Book()
{
	isbn = 0;
	title[0] = '\0';
	author[0] = '\0';
	publisher[0] = '\0';
	inStock = 0;
	price = 0;
}

void Book::print()
{	
        cout << "ISBN: " << isbn << endl;
        cout << "======Book======" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "In stock total: " << inStock << endl;
}

void Book::getTitle(char tempTitle[])
{
        strcpy(tempTitle, title);
}

void Book::getAuthor(char tempAuthor[])
{
        strcpy(tempAuthor, author);
}

void Book::getPublisher(char tempPublisher[])
{
        strcpy(tempPublisher, publisher);
}

double Book::getPrice()
{
        return price;
}

int Book::getInStock()
{
       return inStock;
}
int Book::getISBN()
{
        return isbn;
}
void Book::setTitle(char tempTitle[])
{
        strcpy(title, tempTitle);
}

void Book::setAuthor(char tempAuthor[])
{

        strcpy(author, tempAuthor);
}

void Book::setPublisher(char tempPublisher[])
{
        strcpy(publisher, tempPublisher);
}

void Book::setInStock(int tempInStock)
{
	if(tempInStock >= 0)
	{
		inStock = tempInStock;
	}
}
void Book::setISBN(int tempISBN)
{
	if(tempISBN >= 0)
	{
        	isbn = tempISBN;
	}
}
void Book::setPrice(double tempPrice)
{
                if(tempPrice >= 0)
                {
                      price = tempPrice;

                }
}
