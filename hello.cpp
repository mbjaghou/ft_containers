#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    // initialize container
    map<int, int> mp;
 
    // insert elements in random order
    mp[2] = 30;
    mp[1] = 10;
    mp[5] = 50;
    mp[4] = 40;
    mp[6]   = 60;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " <<
                              (*it).second << endl;
    }
 
    // when 2 is present
    map<int, int>::iterator it = mp.upper_bound(1);
    cout << "The lower bound of key 2 is ";
    cout << (*it).first << " " << (*it).second << endl;
 
    // when 3 is not present
    // points to next greater after 3
    it = mp.upper_bound(3);
    cout << "The lower bound of key 3 is ";
    cout << (*it).first << " " << (*it).second;
 
    // when 6 exceeds
    it = mp.upper_bound(5);
    cout << "\nThe lower bound of key 6 is ";
    cout << (*it).first << " " << (*it).second;
    return 0;
}