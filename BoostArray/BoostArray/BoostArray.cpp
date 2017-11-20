//BoostArray.cpp
//
//With boost::array, an array can be created that exhibits the same properties as a C array. 
//In addition, boost::array conforms to the requirements of C++ containers, 
//which makes handling such an array as easy as handling any other container. 
//In principle, one can think of boost::array as the container std::vector, 
//except the number of elements in boost::array is constant.

#include <boost/array.hpp> //defines boost::array

#include <string>
#include <iostream>

#include <algorithm>

int main()
{
	typedef boost::array<std::string, 3> array; //defines a string array, whose size/max_size is 3;
	array a;

	a[0] = "cat";
	a.at(1) = "shark";
	*a.rbegin() = "dog";
	
	//in the boost/arrys.hpp, here is subscript check.
	//// operator[]
	//reference operator[](size_type i)
	//{
	//	return BOOST_ASSERT_MSG(i < N, "out of range"), elems[i];
	//}
	//a[3] = "fish"; //error while run.

	std::sort(a.begin(), a.end());

	for (const std::string s : a)
		std::cout << s << std::endl;

	std::cout << a.size() << std::endl;
	std::cout << a.max_size() << std::endl;
	//size & max_size are equal.
	//

	std::getchar();
	return 0;
}
