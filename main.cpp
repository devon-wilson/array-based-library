//A program of two classes, one is information of an individual book, the other is all the function(in menu)
#include "inventory.h"
using namespace std;
int main()
{
	Inventory inv;
	inv.readIn();
	inv.menu();
	inv.writeOut();  
  return 0;
}
