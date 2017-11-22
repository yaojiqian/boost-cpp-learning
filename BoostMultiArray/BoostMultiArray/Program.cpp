// Program.cpp
//
//Exercise boost::multiarray
//Boost.MultiArray is a library that simplifies using arrays with multiple dimensions.

#include <boost/multi_array.hpp>

#include <iostream>


int main()
{
	/*-----------------------------------------------------------------
	//1. One-dimensional array with boost::multi_array
	//
	boost::multi_array<char, 1> a{ boost::extents[6] }; 
	//uses the global object boost::extents to set dimension sizes.

	a[0] = 'B';
	a[1] = 'o';
	a[2] = 'o';
	a[3] = 's';
	a[4] = 't';
	a[5] = '\0';

	std::cout << a.origin() << " " << a.size();
	// origin() returns a pointer to the first element.
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------
	//2. Views and subarrays of a two-dimensional array
	//
	boost::multi_array<char, 2> a{ boost::extents[2][6] }; //creates a two - dimensional array.
	//uses the global object boost::extents to set dimension sizes.
	typedef boost::multi_array<char, 2>::array_view<1>::type array_view;
	typedef boost::multi_array_types::index_range range;

	//a view is created which spans exactly five elements of the array.
	// The range starts at index 0 and ends at index 5– excluding the element at index 5. 
	//The sixth element in the first dimension is ignored.
	array_view view = a[boost::indices[0][range{ 0,5 }]];

	std::memcpy(view.origin(), "tsooB", 6); // 't','s','o','o','B','\0' are copied.
	std::reverse(view.begin(), view.end()); // 't','s','o','o','B' are reversed. because the view's range from 0 to 4;

	std::cout << view.origin() << std::endl;

	boost::multi_array<char, 2>::reference subarray = a[1];
	std::memcpy(subarray.origin(), "C++", 4); //4 chars, include '\0'
	//std::reverse(subarray.begin(), subarray.end());
	std::cout << subarray.origin() << std::endl;

	std::cout << a.origin() << " " << a.size() << std::endl;
	std::cout << a[1].origin() << std::endl;
	// origin() returns a pointer to the first element.
	/*-----------------------------------------------------------------*/

	/*-----------------------------------------------------------------*/
	//3. Wrapping a C array with boost::multi_array_ref
	//
	char c[12] =
	{
		't', 's', 'o', 'o', 'B', '\0',
		'C', '+', '+', '\0', '\0', '\0'
	};
	boost::multi_array_ref<char, 2> a{c, boost::extents[2][6] }; //creates a two - dimensional array.
														   //uses the global object boost::extents to set dimension sizes.
	typedef boost::multi_array<char, 2>::array_view<1>::type array_view;
	typedef boost::multi_array_types::index_range range;

	//a view is created which spans exactly five elements of the array.
	// The range starts at index 0 and ends at index 5– excluding the element at index 5. 
	//The sixth element in the first dimension is ignored.
	array_view view = a[boost::indices[0][range{ 0,5 }]];

	std::reverse(view.begin(), view.end()); // 't','s','o','o','B' are reversed. because the view's range from 0 to 4;

	std::cout << view.origin() << std::endl;

	boost::multi_array<char, 2>::reference subarray = a[1];
	std::cout << subarray.origin() << std::endl;

	std::cout << a.origin() << " " << a.size() << std::endl;
	std::cout << a[1].origin() << std::endl;
	// origin() returns a pointer to the first element.
	/*-----------------------------------------------------------------*/

	std::getchar();
	return 0;
}