#include<iostream>
#include<string>

using namespace std;


/*
单词反转
class Solution {
public:
    void swap_s(string& s, int begin, int end)
    {
        while (begin < end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int left, right;
        left = right = 0;
        int old_left = left;
        int old_right = right;
        while (left <= s.size())
        {
            left++;
            right++;
            right++;
            if (s.size() < k)
            {
                swap_s(s, left-1, s.size() - 1);
                return s;
            }
            if ((right - old_left) == 2 * k)
            {
                if (left > s.size())
                {
                    left = s.size();
                }
                swap_s(s, old_left, left-1);
                left = right;
                old_left = left;
                if ((s.size() - left) < k)
                {
                    swap_s(s, left, s.size()-1);
                    return s;
                }
                if ((s.size() - left) >= k && (s.size() - left) < 2 * k)
                {
                    swap_s(s, left, left + k-1);
                    return s;
                }
            }
            
        }
        return s;
    }
};


int main()
{
    Solution st;
    string s = "a";
    s=st.reverseStr(s, 2);
    //swap_s(s, 0, 3);

    for (const auto& e : s)
    {
        cout << e << "";
    }
    cout << endl;
}
*/



/*
交换每一个单词的字母

class Solution {
public:
    void reverse(string& s, int begin, int end)
    {
        while (begin < end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
public:
    string reverseWords(string s)
    {
        int first = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverse(s, first, i - 1);
                first = i + 1;
            }
            if (i == s.size() - 1)
            {
                reverse(s, first, s.size()-1);
            }
        }
        return s;
    }
};

int main()
{
    Solution st;
    string s = "Let's take LeetCode contest";
    s = st.reverseWords(s);
    //swap_s(s, 0, 3);

    for (const auto& e : s)
    {
        cout << e << "";
    }
    cout << endl;
} 
*/


/*字符串相乘
class Solution {
public:
    //int sign = 0;

    string add_result;
    string result;
public:
    string numti_step(string num, char n)
    {
        int sign = 0;
        string muti_result;
        int sum = 0;
        for (int i = 0; i < num.size(); i++)
        {
            sum = (n - '0') * (num[i] - '0') + sign;
            if (sum >= 10)
            {
                sign = sum / 10;
                sum = sum % 10;
            }
            else
                sign = 0;
            muti_result.push_back(sum + '0');
        }
        if (sign > 0)
        {
            muti_result.push_back(sign + '0');
            //sign = 0;
        }
        return muti_result;
    }
    char add_s(char a, char b, int& sign)
    {
        int res = 0;
        res = (a - '0') + (b - '0') + sign;
        if (res >= 10)
        {
            res = res - 10;
            sign = 1;
        }
        else
            sign = 0;
        return res + '0';
    }
    string add_move(string num1, string num2, int n)
    {
        int i = n;
        int j = 0;
        int sign = 0;
        int size_num1 = num1.size();
        int size_num2 = num2.size();
        while (i < num1.size() && j < num2.size())
        {
            num1[i] = add_s(num1[i], num2[j], sign);
            i++;
            j++;
        }
        while (j < size_num2)
        {
            char temp = add_s(0 + '0', num2[j], sign);
            num1.push_back(temp);
            j++;
        }
        while (i < size_num1)
        {
            char temp = add_s(num1[i], 0 + '0', sign);
            num1.push_back(temp);
            i++;
        }
        if (sign > 0)
        {
            num1.push_back(sign+'0');
        }
        result = num1;
        sign = 0;
        return result;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num2.size(); i++)
        {
            string wait_add;
            wait_add = numti_step(num1, num2[i]);
            add_move(result, wait_add, i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution so;
    string num1 = "123456789";
    string num2 = "987654321";
    string reserve=so.multiply(num1, num2);
    cout << reserve << endl;
} 
*/