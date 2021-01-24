#include "inventory.h"

Inventory::Inventory()
{
	count = 0;
}

void Inventory::printAll()
{
	for(int i = 0; i < count; i++)
	{
		book[i].print();
	}
}

void Inventory::readIn()
{
	char tempTitle[MAX_STR] = {'\0'};
	char tempAuthor[MAX_STR] = {'\0'};
	char tempPublisher[MAX_STR] = {'\0'};
	int tempISBN = 0;
	int tempInStock = 0;
	double tempPrice = 0;
	ifstream infile;
        infile.open("inventory.txt");
        if(!infile)
        {
			cout << " " << endl;
                        cout << "Failed to open file " << endl;
			return;
        }
        char c = infile.peek();
	infile >> count;
	infile.ignore();
	int i = 0;
	while(!infile.eof() && count <= MAX_STR && c != '\n')
        {
                infile >> tempISBN;
		infile.ignore(MAX_STR, '\n');
                infile.getline(tempTitle, MAX_STR);
                infile.getline(tempAuthor, MAX_STR);
                infile.getline(tempPublisher, MAX_STR);
                infile >> tempPrice;
		infile.ignore(MAX_STR, '\n');
                infile >> tempInStock;
		infile.ignore(MAX_STR, '\n');
                c = infile.peek();
		reader(i, tempISBN, tempTitle, tempAuthor, tempPublisher, tempPrice, tempInStock);
		i++;
        }
        infile.close();
}

void Inventory::reader(int i, int tempISBN, char tempTitle[], char tempAuthor[], char tempPublisher[], double tempPrice, int tempInStock)
{
	book[i].setISBN(tempISBN);
	book[i].setTitle(tempTitle);
	book[i].setAuthor(tempAuthor);
	book[i].setPublisher(tempPublisher);
	book[i].setPrice(tempPrice);
	book[i].setInStock(tempInStock);
}

void Inventory::find()
{
	int newIsbn, tempISBN;
	cout << " " << endl;
	cout << "Enter isbn of book: " << endl;
	cin >> newIsbn;
	cin.ignore();
	for(int i = 0; i < count; i++)
	{
		tempISBN = book[i].getISBN();
		if(tempISBN == newIsbn)
		{
			book[i].print();	
			return;
		}
	}
	if(newIsbn < 0)
        {
		cout << " " << endl;
        	cout << "that number is negative" << endl;
                return;
        }
        else if(newIsbn < count || newIsbn > count)
        {
		cout << " " << endl;
        	cout << " ISBN of book does not exist " << endl;
                return;
        }
}

void Inventory::search()
{
	char tempPublisher[MAX_STR] = {'\0'};
	char search[MAX_STR] = {'\0'};
	cout << " " << endl;
	cout << "Enter publisher of book: " << endl;
	cin.getline(search, MAX_STR);
	//cin.ignore();
	for(int i = 0; i < count; i++)
	{	
		book[i].getPublisher(tempPublisher);
		if(strcmp(search,tempPublisher) == 0)
		{
			book[i].print();
			return;
		}
	}
		cout << " " << endl;
        	cout << "That publisher does not exist " << endl;
                return;
}

void Inventory::menu()
{
        char choice;
        bool gameOn = true; //breaks the repeating menu when false
        while(gameOn != false)
        {
                printMenu();
                cin >> choice;
		cin.ignore();
                switch(choice)
                {
                        case '1':
                                printAll();
                                break;
                        case '2':
                                search();
                                break;
                        case '3':
                                find();
                                break;
                        case '4':
                                addBook();
                                break;
			case '5':
				modify();
				break;
                        case '6':// quits menu
				cout << " " << endl;
                                cout << "*** END OF PROGRAM **" << endl;
                                gameOn = false;
                                break;
                        default:
				cout << " " << endl;
				cout << "Choose between 1 and 6 " << endl;
                                break;
                }
        }
}

void Inventory::printMenu()
{
	        cout << " " << endl;
                cout << " " << endl;
                cout << "********MAIN MENU******** " << endl;
                cout << "1 - Print Inventory " << endl;
                cout << "2 - Search by Publisher " << endl;
                cout << "3 - Find book by ISBN Number " << endl;
                cout << "4 - Add Book " << endl;
		cout << "5 - Modify " << endl;
                cout << "6 - quit " << endl;
                cout << "Enter choice: " << endl;
}

void Inventory::addBook()
{
	int newIsbn;
        int  newInStock;
        char newTitle[MAX_STR];
        char newAuthor[MAX_STR];
        char newPublisher[MAX_STR];
        double newPrice;
	cout << " " << endl;
        cout << "Book's ISBN? (must be unique) " << endl;
        cin >> newIsbn;
        cin.ignore();
        newIsbn = checkIsbn(newIsbn);
	cout << " " << endl;
        cout << "Title:" << endl;
        cin.getline(newTitle, MAX_STR);
	cout << " " << endl;
        cout << "Author? " << endl;
        cin.getline(newAuthor, MAX_STR);
	cout << " " << endl;
        cout << "Publisher? " << endl;
        cin.getline(newPublisher, MAX_STR);
	cout << " " << endl;
        cout << "Price?" << endl;
        cin >> newPrice;
	cin.ignore();
        newPrice = checkPrice(newPrice);
	cout << " " << endl;
        cout << "In Stock Total?( < 0) " << endl;
        cin >> newInStock;
	cin.ignore();
        newInStock = checkInStock(newInStock);
        addReader(newIsbn, newTitle, newAuthor, newPublisher, newPrice, newInStock);
        count++;
}

void Inventory::addReader(int newIsbn, char newTitle[], char newAuthor[], char newPublisher[], double newPrice, int newInStock)
{
        book[count].setISBN(newIsbn);
        book[count].setTitle(newTitle);
        book[count].setAuthor(newAuthor);
        book[count].setPublisher(newPublisher);
        book[count].setPrice(newPrice);
        book[count].setInStock(newInStock);
}




int Inventory::checkIsbn(int newIsbn)
{
	int i;
	int tempIsbn;
        do
        {
                for(i = 0; i < count; i++)
                {
			tempIsbn = book[i].getISBN();
                        if(newIsbn == tempIsbn)
                        {
				cout << " " << endl;
                                cout << "That ISBN is already in the inventory. ";
                                cout << "Please re-enter." << endl;
                                cin >> newIsbn;
				cin.ignore();
                        }
                }
        }while(tempIsbn == newIsbn);
        return newIsbn;
}

int Inventory::checkInStock(int newInStock)
{
	while(newInStock < 0)
       	{
		cout << " " << endl;
               	cout << "Negative price.  Please re-enter" << endl;
               	cin >> newInStock;
		cin.ignore();
       	}
       	return newInStock;
}

double Inventory::checkPrice(double newPrice)
{
	while(newPrice < 0)
	{
		cout << " " << endl;
		cout << "Negative price.  Please re-enter" << endl;
		cin >> newPrice;
		cin.ignore();
	} 
	return newPrice;
}

void Inventory::modify()
{
	char choice;
        bool gameOn = true; //breaks the repeating menu when false
        while(gameOn != false)
        {
                printModMenu();
                cin >> choice;
                switch(choice)
                {
                        case '1':
                                changeISBN();
                                break;
                        case '2':
                                changeTitle();
                                break;
                        case '3':
                                changeAuthor();
                                break;
                        case '4':
                                changePublisher();
                                break;
                        case '5':
                                changePrice();
                                break;
                        case '6':
				changeInStockTotal();
				break;
			case '7':
				gameOn = false;
				break;
                        default:
                                break;
                }
        }

}

void Inventory::printModMenu()
{
		cout << " " << endl;
                cout << " " << endl;
                cout << "********Modify******** " << endl;
                cout << "1 - ISBN " << endl;
                cout << "2 - title " << endl;
                cout << "3 - author " << endl;
                cout << "4 - publisher " << endl;
                cout << "5 - price " << endl;
                cout << "6 - In Stock Total " << endl;
		cout << "7 - go back to main menu" << endl;
		cout << "Enter choice: " << endl;
}

void Inventory::changeISBN()
{
	int i, tempISBN, newIsbn;
	cout << " " << endl;
	cout << "ISBN number of book to modify? " << endl;
	cin >> newIsbn;		
	cin.ignore();
	for(i = 0; i < count; i++)
        {
	        tempISBN = book[i].getISBN();
                if(newIsbn == tempISBN)
                {
			cout << " " << endl;
			cout << "Book's ISBN? " << endl;
			cin >> tempISBN;
			cin.ignore();
			book[i].setISBN(tempISBN);
			return;
                }
        }
	if(newIsbn < 0)
        {
		cout << " " << endl;
        	cout << "that number is negative" << endl;
                return;
        }
        else if(newIsbn < count || newIsbn > count)
        {
		cout << " " << endl;
        	cout << " ISBN of book does not exist " << endl;
                return;
        }
}

void Inventory::changeTitle()
{
	int i, newIsbn, tempIsbn;
	char tempTitle[MAX_STR] = {'\0'};
	cout << " " << endl;
        cout << "ISBN number of book to modify? " << endl;
        cin >> newIsbn;
	cin.ignore();
        for(i = 0; i < count; i++)
        {
                tempIsbn = book[i].getISBN();
                if(newIsbn == tempIsbn)
                {
			cout << " " << endl;
                        cout << "Title? " << endl;
                        cin.getline(tempTitle, MAX_STR);
                        book[i].setTitle(tempTitle);
			return;
                }
	}	
        if(newIsbn < 0)
        {
		cout << " " << endl;
        	cout << "that number is negative" << endl;
                return;
        }
        else if(newIsbn < count || newIsbn > count)
        {
		cout << " " << endl;
        	cout << " ISBN of book does not exist " << endl;
                return;
        }
}

void Inventory::changeAuthor()
{
	int i, newIsbn, tempIsbn;
        char tempAuthor[MAX_STR] = {'\0'};
	cout << " " << endl;
        cout << "ISBN number of book to modify? " << endl;
        cin >> newIsbn;
	cin.ignore();
        for(i = 0; i < count; i++)
        {
                tempIsbn = book[i].getISBN();
                if(newIsbn == tempIsbn)
                {
			cout << " " << endl;
                        cout << "Author? " << endl;
                        cin.getline(tempAuthor, MAX_STR);
                        book[i].setAuthor(tempAuthor);
			return;
                }
        }
	if(newIsbn < 0)
        {
		cout << " " << endl;
        	cout << "that number is negative" << endl;
                return;
        }
	else if(newIsbn < count || newIsbn > count)
        {
		cout << " " << endl;
        	cout << " ISBN of book does not exist " << endl;
                return;
        }
}

void Inventory::changePublisher()
{
	int i, newIsbn, tempIsbn;
        char tempPublisher[MAX_STR] = {'\0'};
	cout << " " << endl;
        cout << "ISBN number of book to modify? " << endl;
        cin >> newIsbn;
	cin.ignore();
        for(i = 0; i < count; i++)
        {
                tempIsbn = book[i].getISBN();
                if(newIsbn == tempIsbn)
            	{
			cout << " " << endl;
                        cout << "Publisher? " << endl;
                        cin.getline(tempPublisher, MAX_STR);
                        book[i].setPublisher(tempPublisher);
			return;
                }
        }
	if(newIsbn < 0)
        {
		cout << " " << endl;
        	cout << "that number is negative" << endl;
                return;
        }
        else if(newIsbn < count || newIsbn > count)
    	{
		cout << " " << endl;
       		cout << " ISBN of book does not exist " << endl;
        	return;
     	}
}

void Inventory::changeInStockTotal()
{
	int i, tempIsbn, newIsbn, newInStock, tempInStock;
	cout << " " << endl;
        cout << "ISBN number of book to modify? " << endl;
        cin >> newIsbn;
	cin.ignore();
        for(i = 0; i < count; i++)
        {
                tempIsbn = book[i].getISBN();
                if(newIsbn == tempIsbn)
                {
			cout << " " << endl;
                        cout << "In Stock Total? " << endl;
                        cin >> newInStock;
			cin.ignore();
			tempInStock = checkInStock(newInStock);
                        book[i].setInStock(tempInStock);
			return;
                }
		else
		if(newIsbn < 0)
		{
			cout << "  " << endl;
                 	cout << "that number is negative" << endl;
			return;
         	}
         	else if(newIsbn < count || newIsbn > count)
         	{	
			cout << " " << endl;
                 	cout << " ISBN of book does not exist " << endl;
			return;
         	}
	}
}

void Inventory::changePrice()
{
	int i, tempIsbn, newIsbn;
	double tempPrice, newPrice;
	cout << " " << endl;
        cout << "ISBN number of book to modify? " << endl;
        cin >> newIsbn;
	cin.ignore();
        for(i = 0; i < count; i++)
        {
                tempIsbn = book[i].getISBN();
                if(newIsbn == tempIsbn)
                {
			cout << " " << endl;
                        cout << "Price? " << endl;
                        cin >> newPrice;
			cin.ignore();
			tempPrice = checkPrice(newPrice);
                        book[i].setPrice(tempPrice);
			return;
		}
        }
	if(newIsbn < 0)
        {
		cout << " " << endl;
        	cout << "that number is negative" << endl;
                return;
        }
        else if(newIsbn < count || newIsbn > count)    
        {
		cout << " " << endl;
        	cout << " ISBN of book does not exist " << endl;
                return;
        }
}

void Inventory::writeOut()
{
	char tempTitle[MAX_STR] = {'\0'};
        char tempAuthor[MAX_STR] = {'\0'};
        char tempPublisher[MAX_STR] = {'\0'};
        int tempISBN = 0;
        int tempInStock = 0;
        double tempPrice = 0;
	ofstream outfile;
        outfile.open("inventory.txt");
	outfile << count << endl;
        for(int i = 0; i < count; i++)
        {
        	//outfile << "======Book======" << endl;
		tempISBN = book[i].getISBN();
		//outfile << "ISBN: ";
		outfile << tempISBN << endl;
		book[i].getTitle(tempTitle);
		//outfile << "Title: ";
		outfile << tempTitle << endl;
		book[i].getAuthor(tempAuthor);
		//outfile << "Author: ";
		outfile << tempAuthor << endl;
		book[i].getPublisher(tempPublisher);
		//outfile << "Publisher: ";
		outfile << tempPublisher << endl;
		tempPrice = book[i].getPrice();
		//outfile << "Price: ";
                outfile << tempPrice << endl;
		tempInStock = book[i].getInStock();
		//outfile << "In stock total: "; 
                outfile << tempInStock << endl;
        }
        outfile.close();
}
