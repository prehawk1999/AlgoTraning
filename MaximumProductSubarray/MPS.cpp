/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>

namespace {

using std::list;
using std::pair;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Solution {
public:
    Solution(): last(false), prevNum(0), product(0){}
    ~Solution(){}

public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        initNum(nums[0]);
        for(auto it=nums.begin() + 1; it!=nums.end(); ++it) {
            int &number = *it;

            if(last && prevNum != 0) {
                product = prevNum * number;
                if(number>prevNum) sumVec.push_back(product);
                last = false;
            }
            else {
                initNum(number);
                last = true;
            }
        }

        if(!last) {
            sumVec.push_back(product);
        }
        else {
            sumVec.push_back(prevNum);
        }

        int ret = *std::max_element(sumVec.begin(), sumVec.end());
        return ret;
    }

private:
    void initNum(int number) {
        prevNum = number;
        last = true;
    }

private:
    bool         last;
    int          prevNum;
    int          product;
    vector<int>  sumVec;

};



} // namespace



int main() {
    auto s = Solution();
    int intvec[] = {3,-1,4};
    vector<int> input(intvec, intvec + sizeof(intvec)/sizeof(int));
    cout << "Vector is:" << input.size() << endl;
    cout << "maxProduct is:" << s.maxProduct(input) << endl;
}