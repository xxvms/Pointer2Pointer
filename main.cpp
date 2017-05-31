/*
 * sorting person object with array of pointers
 */
#include <iostream>
#include <string>                                       // for string class
class Person                                // class person
{
protected:
    std::string name;                       // person name
public:
    void setName()                          // set the name
    {
        std::cout << "Enter name: ";
        std::cin >> name;
    }
    void printName()                        // display the name
    {
        std::cout << name << std::endl;
    }
    std::string getName()                   // return the name
    { return name;}
};

int main()
{
    void bsort(Person**, int);              // prototype
    Person* personPointer[100];             // array of pointers to persons
    int n = 0;                              // number of person in array
    char choice;                            // input char
    
    do {                                    // put person in array
        personPointer[n] = new Person;      // make new object
        personPointer[n] ->setName();       // set person name
        n++;                                // count new person
        std::cout << "Enter another? (y/n)?";
        std::cin >> choice;
    } while (choice == 'y');                // quit on n
    
    std::cout << "\nUnsorted list: ";
    for (int i = 0; i < n ; ++i)            // print unsorted list
    {
        personPointer[i] ->printName();
    }
    
    bsort(personPointer, n);                 // sort pointers
    std::cout << "\nSorted list: ";
    for (int j = 0; j < n ; ++j)
    {
        personPointer[j]->printName();
    }
    std::cout << std::endl;
    
    system("pause");
    return 0;
}
void bsort(Person** pPerson, int n)         // sort pointers to person
{
    void order(Person**, Person**);         // prototype
    int j, k;                               // index to array
    
    for (j = 0; j < n-1 ; j++) {            // outer loop
        for (k = j+ 1; k < n; k++) {        // inner loop starts at outer
            order(pPerson+j, pPerson+k);     // order the pointer contents
        }
    }
}
void order(Person** pPerson1, Person** pPerson2)    // orders two pointers
{
    if ((*pPerson1)->getName() > (*pPerson2)->getName())    // if 1st person is larger then 2nd
    {
        Person* tempPtr = *pPerson1;        // swap the pointers
        *pPerson1 = *pPerson2;
        *pPerson2 = tempPtr;                // why tempPtr is without * ???
    }
}