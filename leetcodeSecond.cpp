#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <vector>
#include <QDebug>

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
};


