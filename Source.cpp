#include <cstddef>
#include<iostream>
#include"SOLList.h"
using namespace std;






//The insert operation scans the entire list to verify that the item is not already present and
//then inserts the item at the end of the list.


int main()
{\
    cout << "Test cases\n";

    bool repeat = true;
    while (repeat)
    {
        int choice = 0;

        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Which search function would you like to test (1: linear, 2: mtf, 3: t, -1: exit)? ";
            cin >> choice;
            if (choice == -1)
            {
                return 0;
            }
        }

        SOLList< char > list;

        if (choice == 1)
        {
            cout << "\nYou chose: Linear Search\n";
            list.insert('A');
            list.insert('C');
            list.insert('B');
            list.search('C');
            list.insert('D');
            list.search('A');
            list.search('D');
            list.search('A');
            list.search('C');
            list.search('A');
            list.search('C');
            list.search('C');
            list.insert('E');
            list.search('E');
            list.ShowSOLL();

        }
        else if (choice == 2)
        {
            cout << "\nYou chose: Move-To-Front Search\n";
            list.insert('A');
            list.insert('C');
            list.insert('B');
            list.search_mtf('C');
            list.insert('D');
            list.search_mtf('A');
            list.search_mtf('D');
            list.search_mtf('A');
            list.search_mtf('C');
            list.search_mtf('A');
            list.search_mtf('C');
            list.search_mtf('C');
            list.insert('E');
            list.search_mtf('E');
            list.ShowSOLL();
        }
        else {
            cout << "\nYou chose: Transpose Search\n";
            list.insert('A');
            list.insert('C');
            list.insert('B');
            list.search_t('C');
            list.insert('D');
            list.search_t('A');
            list.search_t('D');
            list.search_t('A');
            list.search_t('C');
            list.search_t('A');
            list.search_t('C');
            list.search_t('C');
            list.insert('E');
            list.search_t('E');
            list.ShowSOLL();
        }

        bool getResponse2 = true;
        char repeatResponse = 'n';
        while (getResponse2)
        {
            cout << "\n\nTry Another (y/n)? ";
            cin >> repeatResponse;

            if (repeatResponse == 'y' || repeatResponse == 'Y')
            {
                cout << "You chose: " << repeatResponse << "\n";

                getResponse2 = false;

                repeat = true;

            }
            else if (repeatResponse == 'n' || repeatResponse == 'N')
            {
                cout << "You chose: " << repeatResponse << "\n";

                getResponse2 = false;

                repeat = false;
            }
            else
            {
                cout << "You chose: " << repeatResponse << "\n";
                getResponse2 = true;
            }

        }
    }

}