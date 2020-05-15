#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void helper(vector<double> &nums, double eps, bool &res)
{
    if (res)
        return;
    if (nums.size() == 1)
    {
        if (abs(nums[0] - 24) < eps)
            res = true;
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            double p = nums[i], q = nums[j];
            vector<double> t;
            t.push_back(p+q);
            t.push_back(p-q);
            t.push_back(q-p);
            t.push_back(p*q);
            // {p + q, p - q, q - p, p * q};
            if (p > eps)
                t.push_back(q / p);
            if (q > eps)
                t.push_back(p / q);
            nums.erase(nums.begin() + i);
            nums.erase(nums.begin() + j);
            int len = t.size();
            for(int mm = 0; mm < len; ++mm)
            {
                double k = t[mm];
                nums.push_back(k);
                helper(nums, eps, res);
                nums.pop_back();
            }
            nums.insert(nums.begin() + j, q);
            nums.insert(nums.begin() + i, p);
        }
    }
}

bool judgePoint24(vector<int> &nums)
{
    bool res = false;
    double eps = 0.001;
    vector<double> arr(nums.begin(), nums.end());
    helper(arr, eps, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        vector<int> ve;
        for (int i = 0; i < 4; ++i)
        {
            int tmp;
            cin >> tmp;
            ve.push_back(tmp);
        }
        cout << (judgePoint24(ve) ? "YES" : "Oops") << endl;
    }
}