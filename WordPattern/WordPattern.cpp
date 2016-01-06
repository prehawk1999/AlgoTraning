#include <string>
#include <algorithm>
#include <iostream>

namespace
{

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    bool wordPattern(string pattern, string str) {

    }
};



} // namespace;


int main(){
	Solution s = Solution();
	string pattern("aaba");
	string str1("dog dog cat dog");
	string str2("1dog dog cat dog");
	string str3("dog cat cat dog");
	string str4("dog dog    cat dog");

	cout << s.wordPattern(pattern, str1) << endl;
	cout << s.wordPattern(pattern, str2) << endl;
	cout << s.wordPattern(pattern, str3) << endl;
	cout << s.wordPattern(pattern, str4) << endl;
	return 0;
}
