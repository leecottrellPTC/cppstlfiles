

#include <iostream>
#include "Country.h"
using namespace std;
#include <forward_list>


int main()
{
    forward_list<Country> countryList;
    forward_list<Country>::iterator itr;
    Country USA("US", 37.09024, -95.712891, "United States");
    Country Canada("CA", 56.130366, -106.346771, "Canada");
    Country Mexico("MX", 23.634501, -102.552784, "Mexico");

    countryList.push_front(USA);
    countryList.push_front(Canada);
    countryList.push_front(Mexico);

    countryList.sort();//must have comparisons built

    for (itr = countryList.begin(); itr != countryList.end(); itr++) {
        cout << *itr << endl;
    }


}


