//#include <iostream>
#include <string>
//#include <cmath>
#include <vector>
//#include <algorithm>
#include <map>
#include <QDebug>
#include <QString>

//1275. Find Winner on a Tic Tac Toe Game
class Solution {
public:
    QMap <int, std::tuple<int, int>> m_MapPregapPostgapIntervals;
    void clear()
    {
        m_MapPregapPostgapIntervals.clear();
    }
//    std::string tictactoe(std::vector<std::vector<int>>& moves)
//    {
//        const uint8_t border = 3;

//        std::string outMess = "The game wasn't finished!";;
//        bool winner;
//        if (moves.size() >= 5)
//        {
//            winner = moves.size() % 2;
//            std::vector<int> temp = moves.back();
//            for (size_t i = moves.size() - 1; i >= 0; i -= 2)
//            {
//                int lastStepY = temp - moves[i];
//                int lastStepX = temp.

//            }
//        }

//        return outMess;
//    }

//1863. Sum of All Subset XOR Totals
//[3,4,5,6,7,8] = 480
    int xReq(const std::vector<int>& nums, const int& element, size_t iteration)
    {
        int result = 0;
        for (size_t tempIndex = iteration; tempIndex < nums.size(); ++tempIndex)
        {
            int tempXor = element ^ nums[tempIndex];
            result += tempXor;
            if (iteration != nums.size())
            {
                result += xReq(nums, tempXor, tempIndex + 1);
            }
        }

        return result;
    }

    int xReqFast(const std::vector<int>& nums, int toXor, size_t iteration)
    {
        if (iteration == nums.size()) {
            return toXor;
        }

        int temp = xReqFast(nums, toXor, iteration + 1);
        int xTemp = xReqFast(nums, toXor ^ nums[iteration], iteration + 1);

        return temp + xTemp;
    }

    int subsetXORSum(std::vector<int>& nums)
    {
        int result = 0;
        for (size_t iteration = 0; iteration < nums.size(); ++iteration)
        {
            int testElem = nums[iteration];
            result += testElem;
            result += xReq(nums, testElem, iteration + 1);
        }

        return result;
    }

    int subsetXORSumFast(std::vector<int>& nums)
    {
        int result = 0;

        result = xReqFast(nums, 0, 0);


        return result;
    }

    //696. Count Binary Substrings
    static int countBinarySubstrings(std::string s)
    {
        int res = s.size() - s.size() % 2;
        qDebug() << "Input"<< res << " " << QString::fromStdString(s);
        QStringList result;
        int resInt = 0;
        std::string::iterator iter = s.begin();
        while(iter + (res - 1) < s.end()){
            std::string temp(iter, iter + res);
            qDebug() << "SRC" <<QString::fromStdString(temp);
            bool state = false;
            for (int st = 0; st < res / 2; ++st)
            {
                if (*(temp.begin() + st) == *((temp.end() - 1) - st))
                {
                    state = false;
                    break;
                }
                state = true;
            }
            if (state){
                result.push_back(QString::fromStdString(temp));
                ++resInt;
                if (!((temp.size() / 2) % 2)){
                    qDebug() << "ibnfo" <<temp.size() % 2;
                     std::string newStr(temp.begin() + 1, temp.end() - 1);
                    resInt += countBinarySubstrings(temp);
                }
            }
            ++iter;
        }
        qDebug() << result;
        return resInt;
    }


//////2042. Check if Numbers Are Ascending in a Sentence
//bool areNumbersAscending(string s) {
//    int k = INT_MIN;
//    for(int i = 0; i < s.length(); ++i){
//        if(s[i] >= '0' && s[i] <= '9')
//        {
//            int n = 0;
//            int j = i;
//            while(s[j] >= '0' && s[j] <= '9' && j < s.length())
//            {
//                n = n * 10 + (s[j] - '0');
//                ++j;
//            }
//            if(n > k){
//                k = n;
//            } else {
//                return false;
//            }
//            i = j;
//        }
//    }
//    return true;
//}
    static void addNumber(std::vector<int>& vec, const std::string& st)
    {
        try
        {
            vec.push_back(std::stoi(st));
        }
        catch (std::logic_error const& ex) {
            qDebug() << "std::invalid_argument::what(): " << ex.what() << '\n';
        }
    }

    static bool areNumbersAscending(std::string s)
    {
        std::vector<int> vals;
        addNumber(vals, s);
        std::string::size_type iter = s.find(" ");
        while (iter != s.npos)
        {
            ++iter;
            addNumber(vals, s.substr(iter));
            iter = s.find(" ", iter);
        }
        bool state = true;
        for(size_t item = 1; item < vals.size(); ++item)
        {
            if (vals[item - 1] >= vals[item])
            {
                state &= false;
            }
        }
        return state;
    }
    ////////

    //1646. Get Maximum in Generated Array
    static int getMaximumGenerated(int n)
    {
        if (n < 2) {
            return n;
        }
        std::vector<int> out(n + 1);
        out[0] = 0;
        out[1] = 1;
        int val;
        int outMax = out[1];
        for (size_t item = 2; item < out.size(); ++item)
        {
            if (item & 1) {
                val = out[item / 2] + out[item / 2 + 1];
            } else {
                val = out[item / 2];
            }

            if (outMax < val) {
                outMax = val;
            }
            out[item] = val;
        }
        return outMax;
    }
    /////

};


