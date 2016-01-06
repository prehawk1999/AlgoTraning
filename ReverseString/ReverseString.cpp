/*

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

*/



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
    void reverseWords(string& s) {
		string temp;
		string::reverse_iterator iterA, iterB;
		int phase = 0;
		for(string::reverse_iterator riter = s.rbegin();riter != s.rend(); ++riter){
			if(*riter == 0x20){
				if(phase == 1){
					iterB = riter;
					reverse_copy(iterA, iterB, back_inserter(temp));
					temp.push_back(0x20);
					phase = 0;
				}
			}
			else{
				if(phase == 0){
					iterA = riter;
					phase = 1;
				}
			}
		}
		if(phase == 1){
			iterB = s.rend();
			reverse_copy(iterA, iterB, back_inserter(temp));
		}
		while(temp.back() == 0x20){
			temp.pop_back();
		}
		s = temp;

	}
};



} // namespace;


int main(){
	Solution s = Solution();
	string str(" the     sky     is blue ");
	s.reverseWords(str);
	cout << str << "||" << endl;
	return 0;
}
