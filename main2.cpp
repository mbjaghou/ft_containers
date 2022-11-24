#include "vector.hpp"
#include "stack.hpp"

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

	// cout << "\033[0;32m** rbegin and rend **\033[0m\n";
	// {
	// 	ft::vector<int> vect(5);
	// 	ft::vector<int>::iterator rit = vect.begin();
	// 	for (int i = 0; rit!= vect.end(); ++rit, ++i)
	// 		*rit = i;
	// 	cout << "the vector elements in erverse order:";
	// 	for (ft::vector<int>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it)
	// 		cout << ' ' << *it;
	// 	cout << "\n";
	// }

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

	// cout << "\033[0;32m** relational operators **\033[0m\n";
	// {
	// 	ft::vector<int> vect1 (3,20);
	// 	ft::vector<int> vect2 (4,10);

	// 	if (vect1==vect2)
	// 		cout << "vect1 and vect2 are equal\n";
	// 	if (vect1!=vect2)
	// 		cout << "vect1 and vect2 are not equal\n";
	// 	if (vect1< vect2)
	// 		cout << "vect1 is less than vect2\n";
	// 	if (vect1> vect2)
	// 		cout << "vect1 is greater than vect2\n";
	// 	if (vect1<=vect2)
	// 		cout << "vect1 is less than or equal to vect2\n";
	// 	if (vect1>=vect2)
	// 		cout << "vect1 is greater than or equal to vect2\n";
	// }







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

int	main(void) {
	
	cout << "\033[0;31m** ft_vector tests **\033[0m\n";
	vector_main();
	// map_main();
	// cout << "\033[0;31m** ft_stack tests **\033[0m\n";
	// stack_main();
	
	return 0;
}