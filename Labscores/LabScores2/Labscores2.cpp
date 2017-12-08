//Labscores1.cpp
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

#define MAX_NAME_LENGHT 30


///
///holds and prints the student name
///
class name_t
{
private:
	string last_name;
	string first_name;
	size_t max_name_length;//length of the longest name 

public:
	name_t(string ln, string fn) :last_name{ ln }, first_name{ fn } { max_name_length = MAX_NAME_LENGHT; }
	name_t(string ln, string fn, size_t max_len) :last_name{ ln }, first_name{ fn }, max_name_length{ max_len } {}

	string& get_last_name() { return last_name; }
	void set_last_name(string &ln) { last_name = ln; }

	string& get_first_name() { return first_name; }
	void set_first_name(string &fn) { first_name = fn; }

	string get_full_name() const { return last_name + ", " + first_name; }

	//produces the required output format including the printing of ellipses
	void print_name() { 
		cout << setw(max_name_length) << setfill('.') << left << get_full_name();
	}

	//returns true if the string "lastname, firstname" is lexicographically less than the corresponding string for a right hand side argument
	bool operator < (name_t n1) const {
		
		if (get_full_name().compare(n1.get_full_name()) > 0)
			return true;
		return false;
	}

	bool operator ==(name_t n1) const {

		if (get_full_name().compare(n1.get_full_name()) == 0)
			return true;
		return false;
	}
};


///holds and prints the lab scores and stats
class labscores_t
{
private:
	vector<int> scores;
	int median;
	float mean_scores;

public:
	//adding a lab score
	void add_data(int sc) { scores.push_back(sc); }


	//sorting the lab scores and computing the median and mean scores
	void set_stats() { 
		sort(scores.begin(), scores.end());

		if ((scores.size() % 2) == 0)
		{
			median = *(scores.begin() + (scores.size() + 1) / 2);
		}
		else
		{
			median = *(scores.begin()  + (scores.size() / 2));
		}

		float sum = 0;
		for (int i : scores)
			sum += i;
		mean_scores = sum / scores.size();
	}

	//printing the lab scores and stats to stdout
	void print_labscores() { 
		copy(scores.begin(), scores.end(), ostream_iterator<int>(cout, " ")); 
		cout << ": " << median << " " << setiosflags(ios::fixed) << setprecision(2) << mean_scores;
	}

	bool operator > (labscores_t ls) const {
		return mean_scores > ls.mean_scores;
	}
};




//
class heap_t
{
typedef map<name_t, labscores_t>::iterator map_iterator;

	class data_t
	{
	private:
		map_iterator it;

	public:
		data_t(map_iterator &itr) { it = itr; }
		map_iterator get() { return it; }
		bool operator<(data_t d) const {
			return !(it->second > d.it->second);
		}
	};	

private:
	vector<data_t> heap;

	/*bool greater(map_iterator it1, map_iterator it2) {
		return it1->second > it2->second;
	}*/

public:
	bool empty() { return heap.empty(); }//a function called empty() which returns true if the heap contains no data

	//a function called add_data() which adds a map iterator to a vector object
	//the map iterator should be passed to the function by reference.
	void add_data(map_iterator &it) {
		heap.push_back(data_t{ it });
	}

	//a function called heapify() which reorganizes the vector object data to produce a binary max-heap
	void heapify(){
		//sort(heap.begin(), heap.end(), greater);
		make_heap(heap.begin(), heap.end());
	}

	//a function called extract_top() which pops and returns a copy of the map iterator stored by the max-element at the top the heap. 
	vector<map_iterator> extract_top(unsigned int count=0) {
		vector<map_iterator> rheap;
		if (count == 0 || count >= heap.size()) {
			for (auto it = heap.begin(); it != heap.end(); it++)
				rheap.push_back(it->get());
		}
		else {
			for (auto it = heap.begin(); it != (heap.begin()+count); it++)
				rheap.push_back(it->get());
		}
		return rheap;
	}
};

int main(int argc, char *argv[])
{
	string parameter1{ "-byname/-byrank/-top10" };
	if (argc < 3 || (parameter1.find(argv[1]) ==string::npos)) {
		cerr << "argument is missing or arguments is unknown\n";
		cerr << "Usage: Labscores1 -byname|-byrank|-top10 filename\n";

		return -1;
	}

	ifstream infile(argv[2]);
	if (infile.bad()) {
		cerr << "open file failed.\n";
		return -2;
	}

	//Each line contains a first name and a last name followed by an unknown number of integers representing fictitious CS140 students and their lab scores. 
	string buf;
	char seps[] = " ,\t\n";
	map<name_t, labscores_t> student_scores;//use an std::map container to store pairs of name_t and labscores_t objects. 
	while (getline(infile, buf)) {
		regex regex{ R"([\s]+)" }; // split on space
		string s = buf;
		sregex_token_iterator it{ s.begin(), s.end(), regex, -1 };
		vector<string> line_fields{ it,{} };

		//Your program must silently reject insertion of new data if the map already contains a node with the same name_t object
		//every time make a new name_t object to ensure there is no same name_t object.
		name_t student{ line_fields[1], line_fields[0] };
		labscores_t scores;
		for (auto it = line_fields.begin() + 2; it != line_fields.end(); it++) {
			int s = atoi(it->c_str());
			scores.add_data(s);
		}
		scores.set_stats();

		//******if don't want students have same name, uncomment this block
		//for (auto it = student_scores.cbegin(); it != student_scores.cend(); it++)
		//{
		//	if (it->first == student)
		//		break; 
			student_scores.insert(make_pair(student, scores));// use an std::map container to store pairs of name_t and labscores_t objects.
		//}
	}

	infile.close();


	string byname{ "-byname" };
	string byrank{ "-byrank" };
	heap_t sorted_heap;
	if (byname.compare(argv[1]) == 0) {

		//print	-byname
		for (auto it = student_scores.cbegin(); it != student_scores.cend(); it++) {
			static_cast<name_t>(it->first).print_name();
			static_cast<labscores_t>(it->second).print_labscores();
			cout << std::endl;
		}
	}
	else {
		for (auto it = student_scores.begin(); it != student_scores.end(); it++) {
			sorted_heap.add_data(it);
		}
	}

	if (!sorted_heap.empty()) {
		sorted_heap.heapify();
		unsigned int count = 0;
		if (byrank.compare(argv[1])!=0) {//-top10
			count = 10; 
		}
		
		//print -byrank -top10
		vector<map<name_t, labscores_t>::iterator> pv = sorted_heap.extract_top(count);
		for (auto it : pv) {
			static_cast<name_t>(it->first).print_name();
			static_cast<labscores_t>(it->second).print_labscores();
			cout << std::endl;
		}
	}

	return 0;
}