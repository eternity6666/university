#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool is24 = false;
const int TWOFOUR = 24;
vector<double> ser;
const double minValue = 0.0000001;

void IsOk(vector<double> &nums)
{
    if (fabs(nums[0] + nums[1] - TWOFOUR) < minValue)
    {
        is24 = true;
    }
    else if (fabs(nums[0] - nums[1] - TWOFOUR) < minValue || fabs(nums[1] - nums[0] - TWOFOUR) < minValue)
    {
        is24 = true;
    }
    else if (fabs(nums[0] * nums[1] - TWOFOUR) < minValue)
    {
        is24 = true;
    }
    else if ((nums[1] != 0 && fabs(nums[0] - nums[1] * TWOFOUR) < minValue) || (nums[1] != 0 && fabs(nums[1] - nums[0] * TWOFOUR) < minValue))
    {
        is24 = true;
    }
}
void Dfs(vector<double> &nums)
{
    if (nums.size() == 2)
    {
        IsOk(nums);
        return;
    }
    if (is24)
    {
        return;
    }
    vector<double> nextnums;
    vector<double> secondnums;
    double nextValue, value1, value2;
    for (int i = 0; i < nums.size(); i++)
    {
        nextnums = nums;
        value1 = nums[i];
        nextnums.erase(nextnums.begin() + i);
        for (int j = 0; j < nextnums.size(); j++)
        {
            secondnums = nextnums;
            value2 = nextnums[j];
            secondnums.erase(secondnums.begin() + j);
            nextValue = value1 + value2;
            secondnums.push_back(nextValue);
            Dfs(secondnums);
            secondnums.pop_back();
            nextValue = value1 - value2;
            secondnums.push_back(nextValue);
            Dfs(secondnums);
            secondnums.pop_back();
            nextValue = value1 * value2;
            secondnums.push_back(nextValue);
            Dfs(secondnums);
            secondnums.pop_back();
            if (value2 == 0)
                break;
            nextValue = value1 / value2;
            secondnums.push_back(nextValue);
            Dfs(secondnums);
            secondnums.pop_back();
        }
    }
}
bool judgePoint24(vector<int> &nums)
{
    if (nums.size() != 4)
        return false;
    for (int i = 0; i < nums.size(); i++)
    {
        ser.push_back(nums[i]);
    }
    Dfs(ser);
    if (is24)
    {
        return true;
    }
    return false;
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