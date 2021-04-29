#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

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

int main()
{
    TwoToOne cls;
    cls.longest("aretheyhere", "yestheyarehere");
    // aehrsty
    std::vector<unsigned long long> vec = {0, 1, 3, 6, 10};
    // std::vector<int> res =  snail({{1,2,3}, {8,9,4}, {7,6,5}});
    // std::vector<int> res = solve(vec);
    std::vector<unsigned long long> out = partsSum(vec);
    // for (auto i : out) {
    //     std::cout << i << std::endl;
    // }
    // for(auto i: res) {
    //     std::cout << i << std::endl;
    // }
    return 0;
}