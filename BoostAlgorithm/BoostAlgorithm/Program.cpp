// Program.cpp
//
//Boost.Algorithm
//

#include <iostream>
#include <array>
#include <vector>
#include <boost/algorithm/cxx11/one_of.hpp>
#include <boost/algorithm/cxx11/all_of.hpp>
#include <boost/algorithm/cxx11/none_of.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>


#include <boost/algorithm/cxx11/iota.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx11/copy_if.hpp>

#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/algorithm/cxx14/mismatch.hpp>

#include <boost/algorithm/hex.hpp>

using namespace boost::algorithm;

int main()
{
	/*------------------------------------------------------------------
	//1. Testing for exactly one value with boost::algorithm::one_of_equal()
	std::array<int, 6> a{ {0,5,2,1,4,3} };
	auto predicate = [](int i) {return i == 4; };
	std::cout.setf(std::ios::boolalpha);
	//boost::algorithm::one_of() tests whether a condition is met exactly once. 
	std::cout << one_of(a.begin(), a.end(), predicate) << std::endl;
	std::cout << one_of_equal(a.begin(), a.end(), 4) << std::endl;

	std::array<int, 4> aa{ {1,1,2,1} };
	auto allPre = [](int i) {return i == 1; };
	std::cout << boost::algorithm::all_of(aa.begin(), aa.end(), allPre) << std::endl;
	std::cout << all_of_equal(aa.begin(), aa.end(), 1) << std::endl;

	std::array<int, 5> a1{ {1,2,3,4,5} };
	auto nonePre = [](int i) {return i == 6; };
	std::cout << boost::algorithm::none_of(a1.begin(), a1.end(), nonePre) << std::endl;
	std::cout << none_of_equal(a1.begin(), a1.end(), 6) << std::endl;

	std::array<int, 5> a2{ {1,2,1,3,5} };
	std::cout << any_of_equal(a2.begin(), a2.end(), 1) << std::endl;
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//2. More variants of C++11 algorithms
	std::vector<int> v;
	iota_n(std::back_inserter(v), 5, 10);
	std::cout.setf(std::ios::boolalpha);
	std::cout << is_increasing(v) << std::endl;
	std::ostream_iterator<int> out{ std::cout, "," };
	int n = 9;
	copy_until(v, out, [n](int i) {return i == n; });
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------
	//3. C++14 algorithms from Boost.Algorithm
	std::vector<int> v{ 1,2,3 };
	std::vector<int> w{ 1,2,3,4};
	std::cout.setf(std::ios::boolalpha);
	std::cout << boost::algorithm::equal(v.begin(), v.end(), w.begin(), w.end()) << std::endl;
	auto pair = boost::algorithm::mismatch(v.begin(), v.end(), w.begin(), w.end());
	if (pair.first != v.end())
		std::cout << *pair.first << std::endl;
	if (pair.second != w.end())
		std::cout << *pair.second << std::endl;
	/*------------------------------------------------------------------*/

	/*------------------------------------------------------------------*/
	//4. Using boost::algorithm::hex() and boost::algorithm::unhex()
	std::vector<char> v{ 'C','+','+' };
	hex(v, std::ostream_iterator<char>{std::cout, ""});
	std::cout << std::endl;

	std::string s = "C++";
	std::cout << hex(s) << std::endl;

	std::vector<char> w{ '4','3','2','B','2','B' };
	unhex(w, std::ostream_iterator<char>{std::cout, ""});
	std::cout << std::endl;

	std::string t = "432B2B";
	std::cout << unhex(t) << std::endl;
	/*------------------------------------------------------------------*/



	std::getchar();
	return 0;
}