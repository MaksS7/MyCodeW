#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <QDebug>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};
std::string TwoToOne::longest(const std::string &s1, const std::string &s2) 
{
    std::string temp(s1 + s2);
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
    return temp;
}

class ExampleClass
{

private:

public:
    int returnedFunction();
    void increment(){
        *temporary += 1;
        std::cout << *temporary << std::endl;
    }
    int* temporary;
    int NotPointerVar;
};

int ExampleClass::returnedFunction() 
{
    int temp;
    NotPointerVar = 5;
    temporary = &NotPointerVar;
    temp = *temporary;
    std::cout << temp << std::endl;
    return temp;
}



std::string SeriesSum(int loop)
{
    int dev = 4;
    double res = 0.00;
    if (loop == 0) {
        return std::string("0.00");
    }
    res = 1.00;
    loop--;
    while(loop) {
        res += 1.0/dev;
        dev += 3;
        loop--;
    }
    // std::cout << std::round(res*100) << std::endl;
    std::string str(std::to_string((int)res) + '.');
    int temp = static_cast<int>(std::round(res*100.0));
    str.append(std::to_string(temp % 100 / 10) + std::to_string(temp % 10));
    return str;
}

long long rowSumOddNumbers(unsigned n){

    int res = 0;
    int l = 0;
    for (int i(0); i < n; i++) {
        l += i;
    }
    while(n--){
        res += 1 + (l++ * 2);
    }
    return res;
}

int square_sum(const std::vector<int>& numbers)
{
    std::cout<<numbers.size()<<std::endl;
    int res = 0;
    for(int i: numbers) {
        res += i*i;
    }
    return res;
}

bool set_alarm(const bool& employed,const bool& vacation){
    // return employed?vacation!=true:false;
    // return employed?!vacation:false;
    return employed && !vacation;
}

bool XO(const std::string& str)
{
    std::string xo("xXoO");
    int x= 0, o = 0;
    for (auto elem: str) {
        if (xo.find(elem) <= xo.length()) {
            std::cout<< xo.find(elem) <<std::endl;
            xo.find(elem) < 2 ? x++:o++;
        }
    }
    return x == o;
}

std::vector<std::string> permutations(std::string s) {
    int loop = 0;
    int k = 0;
    std::vector<std::string> res;
    res.push_back(s);
    std::string copy;

    for (int i(1); i < s.length(); i++) {
        copy = s;
        s.replace(i, 1, copy, i - 1, 1);
        s.replace(i - 1, 1, copy, i, 1);
        if (!std::count(res.begin(), res.end(), s)) {
            res.push_back(s);
            k = 0;
        } else {
            k++;
        }

        if (i == s.length() - 1) {
            copy = s;
            loop++;
            i = 0;
            s.replace(s.length() - 1, 1, copy, 0, 1);
            s.replace(0, 1, copy, copy.length() - 1, 1);
            if (!std::count(res.begin(), res.end(), s)) {
                res.push_back(s);
                k = 0;
            } else {
                k++;
            }
        }
        if(k >= s.length()){
            break;
        }
    }
    for ( auto i: res) {
        std::cout << i << std::endl;
    }
    std::cout << res.size() << std::endl;
    return res;
}

std::vector<int> solution(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    return nums;
}

std::vector<int> solve(const std::vector<int> &vec) {
    std::vector<int> tempVec = vec;
    std::sort(tempVec.begin(), tempVec.end());
    int prev = -1;
    std::vector<std::pair<int, int>> count;
    for (size_t i(0); i < tempVec.size(); i++) {
        if (prev != tempVec[i]) {
            count.push_back(std::make_pair(std::count(tempVec.begin(), tempVec.end(), tempVec[i]), tempVec[i]));
        }
        prev = tempVec[i];
    }
    std::sort(count.begin(), count.end());
    tempVec.clear();
    for(auto i: count) {
        // tempVec.insert(,,i.second);
        std::cout << i.first << ":" <<i.second <<std::endl;
    }
     
    return tempVec;
}

int countOneBitInNumber(int number)
{
    int count = 0;
    while (number) {
        count++;
        number = number&(number - 1);
    }
    return count;
} // 11 -> 1011 return 3 one bits;

int poweredNum(std::vector<int> vec, int n)
{
    if(vec.size() < n) {
        return -1;
    }
    return pow(vec[n], n);
}

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    std::vector<int> res;
    for (int i(0); i < snail_map.size(); i++) {
        for (int j(0); j < snail_map[i].size(); i++) {

        }
    }

    return res;
}

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls){
    std::vector<unsigned long long> temp;
    temp.push_back(std::accumulate(ls.begin(), ls.end(), 0));
    
    for (size_t i(1); i < ls.size(); i++) {
        temp.push_back(temp[i - 1] - ls[i - 1]);
    }
    temp.push_back(0);
    return temp;
}
/*
 * A Narcissistic Number is a positive number which is the sum of its own digits, each raised
 * to the power of the number of digits in a given base. In this Kata, we will restrict ourselves to decimal (base 10).
 */
bool narcissistic(int value)
{
    int tempValue = value;
    bool state = true;
    if (tempValue < 0) {
        state = false;
    } else if (!tempValue) {
        state = true;
    } else {
        int dec = 10;
        int numberDigits = 0;
        std::vector<int> number;
        while (tempValue) {
            number.push_back(tempValue % dec);
            tempValue = tempValue / 10;
            ++numberDigits;
        }
        int res = 0;
        for (auto item : number) {
            res += std::pow(item, numberDigits);
        }
        if (res != value)
            state = false;
    }
    return state;
}

class Node
{
public:
    Node() {}
    void setNext(Node* _next)
    {
        next = _next;
    }
    Node* getNext() const
    {
        return next;
    }
private:
    Node* next;
};

/*
 *You are given a node that is the beginning of a linked list. This list always contains
 *a tail and a loop. Your objective is to determine the length of the loop.
 *    Node n1, n2, n3, n4, n5;
    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n5);
    n5.setNext(&n4);
    n4.setNext(&n1);
    std::cout << getLoopSize(&n1) << std::endl;
 */

int getLoopSize(Node* startNode)
{
    int loop = 1;
    std::vector<Node*> nodeVector;
    Node *firstNode = startNode->getNext();
    if (firstNode == startNode) {
        return loop;
    }
    nodeVector.push_back(firstNode);
    Node *tempNode = firstNode->getNext();
    while (true) {
        if (tempNode == firstNode) {
            return loop;
        }
        auto res = std::find(nodeVector.begin(), nodeVector.end(), tempNode);
        if (res != nodeVector.end()) {
            return nodeVector.end() - res;
        }
        nodeVector.push_back(tempNode);

        firstNode = tempNode;
        tempNode = tempNode->getNext();

    }
    return 0;
}


/*
 * josephus([1,2,3,4,5,6,7],3)==[3,6,2,7,5,1,4]
 */
std::vector <int> josephus(std::vector <int> items, int k)
{
    std::vector<int> resultVector = {};
    int temp = 1;
    if (k == 1) {
        return items;
    } else if (items.empty()) {
        return resultVector;
    }
    while (!items.empty()) {
        if (items.size() == 1) {
            resultVector.push_back(items.front());
            break;
        }
        for (size_t item(0); item < items.size(); ++item) {
            if (temp >= (k)) {
                temp = 1;
                resultVector.push_back(items.at(item));
                items.erase(items.begin() + item);
                --item;
            } else {
                ++temp;
            }
        }
    }
    return resultVector;
}

std::vector <int> josephusMod(std::vector <int> items, int k)
{
    std::vector<int> resultVector = {};
    int tempK = k - 1;
    tempK %= items.size();
    std::cout << 4 % 7 << std::endl;
    while (items.size())
    {
        tempK %= items.size();
        resultVector.push_back(items[tempK]);
        items.erase(items.begin()+tempK);
        tempK += k-1;
    }
    return resultVector;
}
/// leetcode
// 123 -> 321
int reversDigits(int32_t source)
{
    int32_t temp = source;
//    const int8_t shift = sizeof(source) * 8 - 1;
//    const int8_t sign = source >> shift;
    const int dec = 10;
    int32_t lastValue = 0;

    while (temp != 0)
    {
        lastValue = lastValue * dec + temp % dec;
        qDebug() << lastValue;
        temp = temp / dec;
        if (lastValue && /*(sign != (lastValue >> shift) ||*/
                          (temp && (INT32_MAX / std::abs(lastValue) < dec)))
        {
            lastValue = 0;
            break;
        }
    }
    return lastValue;
}
/*
1,1,1,1,1 -> 1,2,3,4,5
1 2 3 -> 1 3 6
1 5 4 -> 1 6 10
*/
std::vector<int> sum1dArray(const std::vector<int>& srcArray)
{
    std::vector<int> outArray = srcArray;

    for (size_t iter = 1; iter < srcArray.size(); ++iter)
    {
        outArray[iter] = outArray[iter - 1] + srcArray[iter];
    }

    return outArray;
}

//205. Isomorphic Strings

bool isomorphicStrings(std::string s, std::string t)
{
    bool state = true;
    std::vector<char> charCountS;
    std::vector<char> charCountT;

    if (s.size() == t.size())
    {
        if (s.size() > 1)
        {
            for (size_t item = 0; item < s.size(); ++item)
            {
                const char tempCharS = s[item];
                const char tempCharT = t[item];

                auto sRes = std::find(charCountS.begin(), charCountS.end(), tempCharS);
                auto tRes = std::find(charCountT.begin(), charCountT.end(), tempCharT);

                if (sRes == charCountS.end() && tRes == charCountT.end())
                {
                    charCountS.push_back(tempCharS);
                    charCountT.push_back(tempCharT);
                }
                else
                {
                    auto disT = std::distance(charCountT.begin(), tRes);
                    auto disS = std::distance(charCountS.begin(), sRes);
                    if ((sRes == charCountS.end() || tRes == charCountT.end())
                        || (tempCharS != *sRes && tempCharT != *tRes)
                        || disS != disT)
                    {
                        state = false;
                        break;
                    }
                }
            }
        }
    }
    return state;
}

bool isomorphicStrings2(std::string s, std::string t)
{
    bool state = true;
    std::vector<char> charCountS;
    std::vector<char> charCountT;

    if (s.size() == t.size())
    {
        if (s.size() > 1)
        {
            for (size_t item = 0; item < s.size(); ++item)
            {
                const char tempCharS = s[item];
                const char tempCharT = t[item];

                auto sRes = std::find(charCountS.begin(), charCountS.end(), tempCharS);
                auto tRes = std::find(charCountT.begin(), charCountT.end(), tempCharT);

                if (sRes == charCountS.end() && tRes == charCountT.end())
                {
                    charCountS.push_back(tempCharS);
                    charCountT.push_back(tempCharT);
                }
                else
                {
                    if (sRes != charCountS.end() && tRes != charCountT.end())
                    {
                        auto disT = std::distance(charCountT.begin(), tRes);
                        auto disS = std::distance(charCountS.begin(), sRes);
                        if ((tempCharS != *sRes && tempCharT != *tRes) || disS != disT)
                        {
                            state = false;
                            break;
                        }
                    }
                    else
                    {
                        state = false;
                        break;
                    }
                }
            }
        }
    }
    return state;
}

/*
 * 704. Binary Search
*/

int binarySearch(const std::vector<int>& nums, int target)
{
    int pos = -1;
    if (!nums.empty()) {
        size_t size = nums.size();
        int lBorder = 0;
        int rBorder = size - 1;
        int num = 0;

        if (nums[rBorder] >= target && nums[lBorder] <= target)
        {
            int midl = size / 2;

            while (lBorder <= rBorder)
            {
                num = nums[midl];
                if (num == target)
                {
                    pos = midl;
                    break;
                }

                if (num <= target)
                {
                    lBorder = midl + 1;

                }
                else
                {
                    rBorder = midl - 1;
                }

                size = rBorder - lBorder;
                midl = size / 2 + lBorder;
            }
        }

    }

    return pos;
}

int binarySearch2(const std::vector<int>& nums, int target)
{
    int pos = -1;
    if (!nums.empty()) {
        size_t size = nums.size();
        int lBorder = 0;
        int rBorder = size - 1;
        if (nums[rBorder] >= target && nums[lBorder] <= target)
        {
            int midl = size / 2;
            if (nums[midl] == target)
            {
                pos = midl;
            }
            else
            {
                while (lBorder != rBorder)
                {
                    int num = nums[midl];

                    if (nums[rBorder] == target)
                    {
                        pos = rBorder;
                        break;
                    }
                    else if (nums[lBorder] == target)
                    {
                        pos = lBorder;
                        break;
                    }
                    else if (num == target)
                    {
                        pos = midl;
                        break;
                    }

                    if (num <= target)
                    {
                        if (midl != lBorder)
                        {
                            lBorder = midl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else if (num >= target)
                    {
                        if(midl != rBorder)
                        {
                            rBorder = midl;
                        }
                        else
                        {
                            break;
                        }
                    }

                    size = rBorder - lBorder;

                    midl = size / 2 + lBorder;
                }
            }
        }
    }

    return pos;
}


/*
 * 278. First Bad Version
 */

bool isBadVersion(int val)
{
    return 1 == val;
}

int firstBadVersion(int n)
{
    int res = 0;

    int mid = n / 2;
    int lBorder = 1;
    int rBorder = n;

    while(lBorder <= rBorder)
    {
        if (isBadVersion(mid))
        {
            rBorder = mid - 1;
            res = mid;
        }
        else
        {
            lBorder = mid + 1;
        }
        mid = (rBorder - lBorder) / 2 + lBorder;
    }
    return res;
}

//202. Happy Number
bool isHappy(int n)
{
    if (n != 1)
    {
        const int dec = 10;
        std::vector<int> splitedValue;
        int temp = n;
        int powedNum = 0;
        if (n == 4)
        {
            return false;
        }
        while (temp)
        {
            powedNum += std::pow(temp % dec, 2);
            temp /= dec;
        }
        return isHappy(powedNum);
    }
    return true;
}
//

//1706. Where Will the Ball Fall

std::vector<int> findBall(std::vector<std::vector<int>>& grid)
{
    std::vector<int> outVec(grid.front().size(), 0);

    for (size_t cols = 0; cols < grid.front().size(); ++cols)
    {
        size_t tempCols = cols;

        for (size_t row = 0; row < grid.size(); ++row)
        {
            size_t localCols  = tempCols + grid[row][tempCols];

            if (localCols < 0 || localCols >= grid.front().size() || grid[row][tempCols] != grid[row][localCols])
            {
                outVec[cols] = -1;
                break;
            }
            outVec[cols] = localCols;
            tempCols = localCols;
        }
    }

    return outVec;
}

//1. Two Sum

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> out(2);
    for (size_t i = 0; i < nums.size() - 1; ++i)
    {
        int temp = nums[i];

        for (size_t j = i + 1; j < nums.size(); ++j)
        {
            if (nums[j] + temp == target)
            {
                out[0] = i;
                out[1] = j;
                return out;
            }
        }
    }
    return out;
}

//

///////////////////////////////////////

int main()
{
    // ExampleClass cls;
    // int returnedNumber = cls.returnedFunction();
    // std::cout << returnedNumber << std::endl;
    // cls.increment();
    // std::cout << returnedNumber << std::endl;
    // TwoToOne cls;
    // cls.longest("aretheyhere", "yestheyarehere");
    // // aehrsty
    // std::vector<unsigned long long> vec = {0, 1, 3, 6, 10};
    // // std::vector<int> res =  snail({{1,2,3}, {8,9,4}, {7,6,5}});
    // // std::vector<int> res = solve(vec);
    // std::vector<unsigned long long> out = partsSum(vec);
    // for (auto i : out) {
    //     std::cout << i << std::endl;
    // }
    // for(auto i: res) {
    //     std::cout << i << std::endl;
    // }
//    std::vector<int> out = josephus({1, 2, 3, 4, 5, 6, 7}, 5);
//    std::vector<int> out = test({1, 2, 3, 4, 5, 6, 7}, 5);
//    for (auto item : out) {
//        std::cout << item;
//    }
//    std::cout << std::endl;
//    qDebug() << firstBadVersion(1);
    std::vector<int> test = {3,4,4};
    qDebug() << twoSum(test, 6);

    return 0;
}
