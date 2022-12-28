#include "map.hpp"
#include <iostream>
#include <map>
using namespace std;
  
int main()
{
  
    // Creating a map named m;

    ft::map<char, int> m;
    
    m['a'] = 1;
    m['b'] = 1;
    m['c'] = 1;
    m['d'] = 1;
    m['e'] = 1;
  
    ft::pair<char, int> last = *m.rbegin();
    cout << last.first << endl;
    ft::map<char, int>::iterator i = m.begin();
  
    cout << "Map contains "
         << "following elements"
         << endl;
  
    do {
  
        cout << i->first
             << " = "
             << i->second
             << endl;
    } while (m.value_comp()(*i++, last));
  
    return 0;
}