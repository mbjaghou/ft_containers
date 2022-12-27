#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

using std::cout;

void	vector_main(void) {

	cout << "\033[0;32m** constructors **\033[0m\n";
	{
		ft::vector<int> defaultVect;
		ft::vector<int> fillVect(4,100);
		ft::vector<int> rangeVect(fillVect.begin(), fillVect.end());
		ft::vector<int> copyVect(rangeVect);  

		cout << "The contents of the vector are:";
		for (ft::vector<int>::iterator it = copyVect.begin(); it != copyVect.end(); ++it)
			cout << ' ' << *it;
		cout << "\n";
	}

	cout << "\033[0;32m** operator= **\033[0m\n";
	{
		ft::vector<int> origin(3,10);
		ft::vector<int> copy(5,20);

		copy = origin;

		cout << "The contents of the copy are:";
		for (ft::vector<int>::iterator it = copy.begin(); it != copy.end(); ++it)
			cout << ' ' << *it;
		cout << "\n";
	}

	cout << "\033[0;32m** assign **\033[0m\n";
	{
		ft::vector<int>	vect;
		ft::vector<int>	vect2;
		vect.assign(5, 12);
		vect2.assign(vect.begin(), vect.end() - 2);
		
		cout << "The contents of the vector are: ";
		for (size_t i = 0; i < vect2.size(); ++i)
			cout << vect2[i] << ' ';
		cout << '\n';
	}

	cout << "\033[0;32m** get_allocator **\033[0m\n";
	{
		ft::vector<int> vect;
		int*		ptr;

		ptr = vect.get_allocator().allocate(5);

		for (size_t i = 0; i < 5; ++i)
			vect.get_allocator().construct(&ptr[i],i);

		cout << "The allocated array contains:";
		for (size_t i = 0; i < 5; ++i)
			cout << ' ' << ptr[i];
		cout << "\n";

		for (size_t i = 0; i < 5; ++i)
			vect.get_allocator().destroy(&ptr[i]);
		vect.get_allocator().deallocate(ptr,5);
	}

	cout << "\033[0;32m** at **\033[0m\n";
	{
		ft::vector<int> vect(10);

		for (size_t i = 0; i < vect.size(); ++i)
			vect.at(i) = i;

		cout << "the vector contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect.at(i);
		cout << "\n";
	}
	
	cout << "\033[0;32m** operator[] **\033[0m\n";
	{
		ft::vector<int> vect (10);

		for (size_t i = 0; i < vect.size(); ++i)
			vect[i] = i;

		cout << "the vector contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect[i];
		cout << "\n";
	}

	cout << "\033[0;32m** front **\033[0m\n";
	{
		ft::vector<int> vect;

		vect.push_back(8);
		vect.push_back(6);
		cout << "the front of the vector is " << vect.front() << '\n';
	}

	cout << "\033[0;32m** back **\033[0m\n";
	{
		ft::vector<int> vect;
		vect.push_back(10);
		vect.push_back(12);
		cout << "the back of the vector is " << vect.back() << '\n';
	}
	
	cout << "\033[0;32m** data **\033[0m\n";
	{
		ft::vector<int>	vect(3, 10);
		
		cout << "the vector contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect.data()[i];
		cout << '\n';
	}

	cout << "\033[0;32m** begin and end **\033[0m\n";
	{
		ft::vector<int> vect;

		for (int i = 1; i <= 5; ++i)
			vect.push_back(i);

		cout << "the first element in the vector is: " << *vect.begin() << "\n";
		cout << "the last element in the vector is: " << *(vect.end() - 1) << "\n";
	}

	cout << "\033[0;32m** rbegin and rend **\033[0m\n";
	{
		ft::vector<int> vect(5);
		ft::vector<int>::iterator rit = vect.begin();
		for (int i = 0; rit!= vect.end(); ++rit, ++i)
			*rit = i;
		cout << "the vector elements in erverse order:";
		for (ft::vector<int>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it)
			cout << ' ' << *it;
		cout << "\n";
	}

	cout << "\033[0;32m** empty **\033[0m\n";
	{
		ft::vector<int> vect;

		cout << "before filling the vector, vect is empty: ";
		cout << std::boolalpha << vect.empty();
		cout << "\n";
		for (int i = 0; i < 5; ++i)
			vect.push_back(i);
		cout << "after filling the vector, vect is empty: ";
		cout << std::boolalpha << vect.empty();
		cout << "\n";
	}

	cout << "\033[0;32m** size && max_size **\033[0m\n";
	{
		ft::vector<int> vect;
		cout << "after creating a fresh vector, size: " << vect.size() << "\n";

		for (int i = 0; i < 10; ++i)
			vect.push_back(i);
		cout << "after pushing 10 elements, size: " << vect.size() << "\n";

		vect.insert(vect.end(),10,100);
		cout << "after inserting 10 more elements, size: " << vect.size() << "\n";
		
		vect.assign(12, 15);
		cout << "after assigning 12 elements, size: " << vect.size() << "\n";

		vect.pop_back();
		cout << "after removing an element, size: " << vect.size() << "\n";

		cout << "the max size of the vector is: " << vect.max_size() << '\n';
	}

	cout << "\033[0;32m** reserve **\033[0m\n";
	{
		ft::vector<int>	vect(10, 10);
		cout << "capacity before reserving anything: " << vect.capacity() << "\n";
		vect.reserve(20);
		cout << "capacity after reserving 20 elements: " << vect.capacity() << "\n";
		vect.reserve(5);
		cout << "capacity after reserving 5 elements: " << vect.capacity() << "\n";
	}

	cout << "\033[0;32m** capacity **\033[0m\n";
	{
		ft::vector<int> vect;

		cout << "The progress of the capacity:";
		for (int i = 0; i < 20; ++i) {
			vect.push_back(i);
			cout << " " << (int) vect.capacity();
		}
		cout << "\n";
	}

	cout << "\033[0;32m** clear **\033[0m\n";
	{
		ft::vector<int> vect;
		vect.push_back (10);
		vect.push_back (20);
		vect.push_back (30);

		cout << "the vector contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect[i];
		cout << "\n";

		vect.clear();
		vect.push_back (3);
		vect.push_back (17);

		cout << "the vector now contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect[i];
		cout << "\n";
	}

	cout << "\033[0;32m** insert **\033[0m\n";
	{
		ft::vector<int> vect (5,10);
		ft::vector<int>::iterator it;

		it = vect.insert(vect.begin(), 20);

		vect.insert (it,2,30);
		it = vect.begin();

		ft::vector<int> vect2 (2,40);
		vect.insert (it + 2, vect2.begin(), vect2.end());

		cout << "the vector contains:";
		for (it=vect.begin(); it<vect.end(); ++it)
			cout << ' ' << *it;
		cout << "\n";
	}

	cout << "\033[0;32m** erase **\033[0m\n";
	{
		ft::vector<int> vect;

		for (int i = 1; i <= 10; ++i)
			vect.push_back(i);

		vect.erase (vect.begin()+5);
		vect.erase (vect.begin(),vect.begin()+3);

		cout << "the vector contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect[i];
		cout << "\n";
	}

	cout << "\033[0;32m** push_back **\033[0m\n";
	{
		ft::vector<int>	vect;
		for(size_t i = 1; i < 10; ++i)
			vect.push_back(i * 10);
		cout << "the vector contains: ";
		for(size_t i = 0; i < vect.size(); ++i)
			cout << vect[i] << " ";
		cout << "\n";
	}
	
	cout << "\033[0;32m** pop_back **\033[0m\n";
	{
		ft::vector<int> vect;
	
		for(size_t i = 0; i < 10; ++i)
			vect.push_back(i);

		vect.pop_back();	
		vect.pop_back();	
		vect.pop_back();
		
		cout << "the vector contains: ";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << vect[i] << " ";
		cout << "\n";
	}

	cout << "\033[0;32m** resize **\033[0m\n";
	{
		ft::vector<int> vect;

		for (int i = 1; i < 10; ++i)
			vect.push_back(i);

		vect.resize(5);
		vect.resize(8,100);
		vect.resize(12);

		cout << "the vector contains:";
		for (size_t i = 0; i < vect.size(); ++i)
			cout << ' ' << vect[i];
		cout << "\n";
	}

	cout << "\033[0;32m** swap **\033[0m\n";
	{
		ft::vector<int> vect1 (3,10);
		ft::vector<int> vect2 (4,20);

		vect1.swap(vect2);

		cout << "vect1 contains:";
		for (size_t i = 0; i < vect1.size(); ++i)
			cout << ' ' << vect1[i];
		cout << "\n";

		cout << "vect2 contains:";
		for (size_t i = 0; i < vect2.size(); ++i)
			cout << ' ' << vect2[i];
		cout << "\n";
	}

	cout << "\033[0;32m** relational operators **\033[0m\n";
	{
		ft::vector<int> vect1 (3,20);
		ft::vector<int> vect2 (4,10);

		if (vect1==vect2)
			cout << "vect1 and vect2 are equal\n";
		if (vect1!=vect2)
			cout << "vect1 and vect2 are not equal\n";
		if (vect1< vect2)
			cout << "vect1 is less than vect2\n";
		if (vect1> vect2)
			cout << "vect1 is greater than vect2\n";
		if (vect1<=vect2)
			cout << "vect1 is less than or equal to vect2\n";
		if (vect1>=vect2)
			cout << "vect1 is greater than or equal to vect2\n";
	}

	cout << "\033[0;32m** swap (non-member) **\033[0m\n";
	{
		ft::vector<int> vect1 (3,10);
		ft::vector<int> vect2 (4,20);

		swap(vect1, vect2);

		cout << "vect1 contains:";
		for (size_t i = 0; i < vect1.size(); ++i)
			cout << ' ' << vect1[i];
		cout << "\n";

		cout << "vect2 contains:";
		for (size_t i = 0; i < vect2.size(); ++i)
			cout << ' ' << vect2[i];
		cout << "\n";
	}
}

void	map_main(void) {

	cout << "\033[0;32m** Constructors && operator= **\033[0m\n";
	{
		ft::map<char,int> map1;

		map1['a'] = 1;
		map1['b'] = 7;
		map1['c'] = -2;
		map1['d'] = 3;

		ft::map<char,int> map2 (map1.begin(),map1.end());
		map1['e'] = 10;
		ft::map<char,int> map3 (map2);
		map3 = map1;

		for(ft::map<char,int>::iterator i = map3.begin(); i !=  map3.end(); ++i)
			cout << i->first << " = " <<  i->second << "\t";
		cout << "\n";
	}

	cout << "\033[0;32m** get_allocator **\033[0m\n";
	{
		ft::map<int,int> mp;
		ft::pair<const int,int>* pr;

		pr = mp.get_allocator().allocate(5);
		for (int i = 0; i < 5; ++i)
			mp.get_allocator().construct(pr + i, ft::make_pair(i, i*10));
		for (int i = 0; i < 5; ++i)
			cout << pr[i].first << " = " << pr[i].second << '\t';
		cout << '\n';
		for (int i = 0; i < 5; ++i)
			mp.get_allocator().destroy(pr + i);
		mp.get_allocator().deallocate(pr, 5);
	}

	cout << "\033[0;32m** operator[] && at **\033[0m\n";
	{
		ft::map<char,std::string> mp;

		mp['a'] = "something";
		mp['b'] = "something else";
		mp['c'] = mp['b'];

		cout << "mp['a'] contains " << mp.at('a') << "\n";
		cout << "mp['b'] contains " << mp.at('b') << "\n";
		cout << "mp['c'] contains " << mp['c'] << "\n";
		cout << "mp['d'] contains " << mp['d'] << "\n";
	}

	cout << "\033[0;32m** Begin && end **\033[0m\n";
	{
		ft::map<char,int> mp;

		mp['b'] = 10;
		mp['a'] = 20;
		mp['c'] = 30;

		for (ft::map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- iterator\n";
		for (ft::map<char,int>::const_iterator it = mp.begin(); it != mp.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- const_iterator\n";
	}

	cout << "\033[0;32m** rbegin && rend **\033[0m\n";
	{
		ft::map<char,int> mp;

		mp['a'] = 10;
		mp['b'] = 20;
		mp['c'] = 30;

		for (ft::map<char,int>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); ++rit)
			cout << rit->first << " = " << rit->second << '\t';
		cout << " <-- reverse_iterator\n";
		for (ft::map<char,int>::const_reverse_iterator rit = mp.rbegin(); rit != mp.rend(); ++rit)
			cout << rit->first << " = " << rit->second << '\t';
		cout << " <-- const_reverse_iterator\n";
	}

	cout << "\033[0;32m** empty && size && max_size **\033[0m\n";
	{
		ft::map<char,int> mp;
		cout << "after creating a fresh map: the map is emoty: ";
		cout << std::boolalpha << mp.empty() << "\n";
		cout << "the size of the map is " << mp.size() << "\n";
		
		mp['a'] = 10;
		cout << "after adding an element: the map is emoty: ";
		cout << std::boolalpha << mp.empty() << "\n";
		cout << "the size of the map is " << mp.size() << "\n";
		
		// mp.erase('a');
		cout << "after removing the element: the map is emoty: ";
		cout << std::boolalpha << mp.empty() << "\n";
		cout << "the size of the map is " << mp.size() << "\n";

		cout << "the max size of the map is: " << mp.max_size() << '\n';
	}

	cout << "\033[0;32m** clear **\033[0m\n";
	{
		ft::map<char,int> mp;

		mp['x'] = 10;
		mp['y'] = 20;
		mp['z'] = 30;

		for (ft::map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- before\n";

		// mp.clear();
		mp['a'] = 3;
		mp['b'] = 7;

		for (ft::map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- after\n";
	}
	
	cout << "\033[0;32m** insert **\033[0m\n";
	{
		ft::map<char,int> map1;

		map1.insert (ft::pair<char,int>('a', 10));
		map1.insert (ft::pair<char,int>('z', 20));

		ft::pair<ft::map<char,int>::iterator,bool> pr;
		pr = map1.insert(ft::pair<char,int>('z', 50));
		if (pr.second == false) {
			cout << "element 'z' is already in the map";
			cout << " with a value of " << pr.first->second << '\n';
		}

		ft::map<char,int>::iterator it = map1.begin();
		map1.insert(it, ft::pair<char,int>('b', 30));
		map1.insert(it, ft::pair<char,int>('c', 40));

		ft::map<char,int> map2;
		map2.insert(map1.begin(), map1.find('c'));

		for (it = map1.begin(); it != map1.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- map1\n";

		for (it = map2.begin(); it != map2.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- map2\n";
	}
	
	// cout << "\033[0;32m** erase **\033[0m\n";
	// {
	// 	ft::map<char,int> mp;

	// 	mp['a'] = 10;
	// 	mp['b'] = 20;
	// 	mp['c'] = 30;
	// 	mp['d'] = 40;
	// 	mp['e'] = 50;
	// 	mp['f'] = 60;

	// 	ft::map<char,int>::iterator it = mp.find('b');
	// 	mp.erase(it);
	// 	mp.erase('c');

	// 	it = mp.find('e');
	// 	mp.erase(it, mp.end());

	// 	for (it = mp.begin(); it != mp.end(); ++it)
	// 		cout << it->first << " = " << it->second << '\t';
	// 	cout << "\n";
	// }

	cout << "\033[0;32m** swap **\033[0m\n";
	{
		ft::map<char,int> map1, map2;

		map1['x'] = 1;
		map1['y'] = 2;

		map2['a'] = 3;
		map2['b'] = 5;
		map2['c'] = 7;

		map1.swap(map2);

		for (ft::map<char,int>::iterator it = map1.begin(); it != map1.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- map1\n";

		for (ft::map<char,int>::iterator it = map2.begin(); it != map2.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- map2\n";
	}

	cout << "\033[0;32m** count **\033[0m\n";
	{
		ft::map<char,int> mp;

		mp['a'] = 10;
		mp['b'] = 20;
		mp['c'] = 30;
		
		cout << "number of elements with key 'a': " << mp.count('a') << '\n'; 
		cout << "number of elements with key 'z': " << mp.count('z') << '\n'; 
	}

	cout << "\033[0;32m** find **\033[0m\n";
	{
		ft::map<char,int> mp;
		ft::map<char,int>::iterator it;

		mp['a'] = 3;
		mp['b'] = 5;
		mp['c'] = 7;


		cout << "a = " << mp.find('a')->second << '\t';
		cout << "b = " << mp.find('b')->second << '\t';
		cout << "c = " << mp.find('c')->second << '\t';
		cout << '\n';
	}
	
	cout << "\033[0;32m** lower_bound && upper_bound **\033[0m\n";
	{
		ft::map<char,int> mp;
		ft::map<char,int>::iterator low, up;

		mp['a'] = 10;
		mp['b'] = 20;
		mp['c'] = 30;
		mp['d'] = 40;
		mp['e'] = 50;

		low = mp.lower_bound('b');
		up = mp.upper_bound('c');

		cout << "The lower bound of 'b' : " << low->first << " = " << low->second << '\n';
		cout << "The upper bound of 'c' : " << up->first << " = " << up->second << '\n';
	}

	cout << "\033[0;32m** equal_range **\033[0m\n";
	{
		ft::map<char,int> mp;

		mp['a'] = 10;
		mp['b'] = 20;
		mp['c'] = 30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> pr;
		pr = mp.equal_range('b');

		cout << "The lower bound of 'b' : ";
		cout << pr.first->first << " = " << pr.first->second << '\n';
		cout << "The upper bound of 'b' : ";
		cout << pr.second->first << " = " << pr.second->second << '\n';
	}

	// cout << "\033[0;32m** key_comp **\033[0m\n";
	// {
	// 	ft::map<char,int> mp;

	// 	ft::map<char,int>::key_compare cmpfun = mp.key_comp();

	// 	mp['a'] = 20;
	// 	mp['b'] = 10;
	// 	mp['c'] = 30;

	// 	char last = mp.rbegin()->first;

	// 	ft::map<char,int>::iterator it = mp.begin();
	// 	do {
	// 		cout << it->first << " = " << it->second << '\t';
	// 	} while (cmpfun((*it++).first, last));
	// 	cout << '\n';
	// }

	// cout << "\033[0;32m** value_comp **\033[0m\n";
	// {
	// 	ft::map<char,int> mp;

	// 	mp['a'] = 20;
	// 	mp['b'] = 10;
	// 	mp['c'] = 30;

	// 	ft::pair<char,int> last = *mp.rbegin();

	// 	ft::map<char,int>::iterator it = mp.begin();
	// 	do {
	// 		cout << it->first << " = " << it->second << '\t';
	// 	} while (mp.value_comp()(*it++, last));
	// 	cout << '\n';
	// }

	cout << "\033[0;32m** relational operators **\033[0m\n";
	{
		ft::map<char, int> map1;
		ft::map<char, int> map2;
		map1['a'] = 10;
		map1['b'] = 20;
		map2['c'] = 30;

		if (map1 == map2)
			cout << "map1 and map2 are equal\n";
		if (map1 != map2)
			cout << "map1 and map2 are not equal\n";
		if (map1 < map2)
			cout << "map1 is less than map2\n";
		if (map1 > map2)
			cout << "map1 is greater than map2\n";
		if (map1 <= map2)
			cout << "map1 is less than or equal to map2\n";
		if (map1 >= map2)
			cout << "map1 is greater than or equal to map2\n";
	}

	cout << "\033[0;32m** swap (non-member) **\033[0m\n";
	{
		ft::map<char,int> map1, map2;

		map1['x'] = 1;
		map1['y'] = 2;

		map2['a'] = 3;
		map2['b'] = 5;
		map2['c'] = 7;

		swap(map1, map2);

		for (ft::map<char,int>::iterator it = map1.begin(); it != map1.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- map1\n";

		for (ft::map<char,int>::iterator it = map2.begin(); it != map2.end(); ++it)
			cout << it->first << " = " << it->second << '\t';
		cout << " <-- map2\n";
	}
}

void	stack_main(void) {

	cout << "\033[0;32m** Constructors && operator= && size **\033[0m\n";
	{
		ft::vector<int> vect (3,10);

		ft::stack<int, ft::vector<int> > stk(vect);
		ft::stack<int, ft::vector<int> > stk2(stk);
		ft::stack<int, ft::vector<int> > stk3;

		stk3 = stk;
		cout << "size of the first stack: " << stk.size() << '\n';
		cout << "size of the second stack: " << stk2.size() << '\n';
		cout << "size of the third stack: " << stk3.size() << '\n';
	}

	cout << "\033[0;32m** empty **\033[0m\n";
	{
		ft::stack<int, ft::vector<int> > stk;
		cout << "after creating a fresh stack, the stack is empty: ";
		cout << std::boolalpha << stk.empty() << "\n";

		for(int i = 0;i < 3; ++i)
			stk.push(i);
		cout << "after adding 3 elements, the stack is empty: ";
		cout << std::boolalpha << stk.empty() << "\n";

		stk.pop();
		stk.pop();
		stk.pop();
		cout << "after removing 3 elements, the stack is empty: ";
		cout << std::boolalpha << stk.empty() << "\n";
	}

	cout << "\033[0;32m** top && push && pop **\033[0m\n";
	{
		ft::stack<int, ft::vector<int> > stk;

		stk.push(3);
		cout << "the top of the stack after pushing 3 is: " << stk.top() << "\n";
		stk.push(4);
		cout << "the top of the stack after pushing 4 is: " << stk.top() << "\n";
		stk.pop();
		cout << "the top of the stack after popping 4 is: " << stk.top() << "\n";
	}

	cout << "\033[0;32m** relational operators **\033[0m\n";
	{
		ft::vector<int>	vect1(3, 10);
		ft::vector<int>	vect2(4, 20);
		ft::stack<int, ft::vector<int> > stack1(vect1);
		ft::stack<int, ft::vector<int> > stack2(vect2);

		if (stack1 == stack2)
			cout << "stack1 and stack2 are equal\n";
		if (stack1 != stack2)
			cout << "stack1 and stack2 are not equal\n";
		if (stack1 < stack2)
			cout << "stack1 is less than stack2\n";
		if (stack1 > stack2)
			cout << "stack1 is greater than stack2\n";
		if (stack1 <= stack2)
			cout << "stack1 is less than or equal to stack2\n";
		if (stack1 >= stack2)
			cout << "stack1 is greater than or equal to stack2\n";
	}
}

int	main(void) {
	
	cout << "\033[0;31m** ft_vector tests **\033[0m\n";
	vector_main();
	cout << "\033[0;31m** ft_map tests **\033[0m\n";
	map_main();
	cout << "\033[0;31m** ft_stack tests **\033[0m\n";
	stack_main();
	
	return 0;
}

