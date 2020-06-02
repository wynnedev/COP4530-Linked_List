#include <iostream>
#include "tlist.h"
#include <string>

int main()
{
    std::cout << "Program Begin..." << std::endl;
    TList<char> L1;
    TList<char> *L2 = new TList<char>();
    TList<int> L3(10, 5);
    TListIterator<char> L1_Itr = L1.GetIterator();
    TListIterator<char> L2_Itr = L2->GetIterator();

    for(char c = 'A'; c <= 'Z'; c++)
    {
        L1.InsertFront(c);
    }

    std::cout << "L1 InsertFront A-Z :";
    L1.Print(std::cout);

    std::cout << "L1 RemoveBack :";
    L1.RemoveBack();
    L1.Print(std::cout);

    for(char c = 'a'; c <= 'z'; c++)
    {
        L2->InsertBack(c);
    }

    std::cout << "L2 InsertBack Test a - z:";
    L2->Print(std::cout);

    std::cout << "L2 RemoveFront Test: ";
    L2->RemoveFront();
    L2->Print(std::cout);

    std::cout << "L2 First Element is: " << L2->GetFirst() << std::endl;

    std::cout << "L2 Last Element:: " << L2->GetLast() << std::endl;

    std::cout << "L3 Overlaoded Constructor: 10 10 10 10 10: ";
    L3.Print(std::cout);
    std::cout << "L3 has " << L3.GetSize() << " elements" << std::endl;

    std::cout << "L3 Clear : ";

    //This function uses an iterator to traverse the list front to back
    L3.Clear();
    L3.Print(std::cout);
    std::cout << "L3 has " << L3.GetSize() << " elements" << std::endl;

    TList<char> L4(*L2);
    std::cout << "L2->L4 copy constructor test: ";
    L4.Print(std::cout);

    L4 = L1;
    std::cout << "L4=L1 test: ";
    L4.Print(std::cout);

    TList<char> L5;
    L5 = L4 + L1;
    L5.Print(std::cout);

    //Clear L5 from back
    TListIterator<char> current = L5.GetIteratorEnd();

    while(current.HasPrevious())
    {
        L5.RemoveBack();
        current.Previous();
    }
    std::cout << "L5 Cleared now has " << L5.GetSize() << " elements " << std::endl;


    std::cout << "Program Terminated...";

}

