#include <fstream>
#ifndef INVENTORY_H
#define INVENTORY_H
using namespace std;
#include "book.h"
class Inventory
{
        public:
		Inventory();
		void printAll();
		void readIn();
		void printMenu();
		void menu();
		void search();
		void find();
		void addBook();
		int checkIsbn(int newIsbn);
		int checkInStock(int newInStock);
		double checkPrice(double newPrice);
		void addReader(int newIsbn, char newTitle[], char newAuthor[], char newPublisher[], double newPrice, int newInStock);
		void reader(int i, int tempISBN, char tempTitle[],char tempAuthor[], char tempPublisher[], double tempPrice, int tempInStock);
		void modify();
		void printModMenu();
		void changeISBN();
		void changeTitle();
		void changeAuthor();
		void changePublisher();
		void changeInStockTotal();
		void changePrice();
		void writeOut();
        private:
		Book book[MAX_STR]; 
		int count;
};

#endif

