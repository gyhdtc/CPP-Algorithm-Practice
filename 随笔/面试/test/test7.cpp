// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <iterator>

// using std::string;

// int main()
// {
// 	std::ifstream ifs("H:/code/C++/Cpp_Primer_Answers/data/books.txt");
// 	std::istream_iterator<string> in(ifs), eof;
// 	std::vector<string> vec;
// 	std::copy(in, eof, back_inserter(vec));

// 	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<string>(std::cout, "\n"));
// 	return 0;
// }
  
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> l = { 1, 2, 0, 4, 5, 6, 7, 0, 9 };
	
    // auto it = find(l.crbegin(), l.crend(), 0);
	// cout << distance(it, l.crend()) << endl;
	
    auto it = find(l.cbegin(), l.cend(), 0);
	cout << distance(it, l.cbegin()) << endl;
    return 0;
}