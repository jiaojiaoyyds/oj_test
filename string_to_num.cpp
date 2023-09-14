#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
/*
class Solution {
public:
    bool is_number(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }
    bool is_np(char ch)
    {
        return (ch == '-' || ch == '+');
    }
    bool in_range(char ch)
    {
        return is_number(ch) || is_np(ch);
    }
public:
    int strToInt(string str) {
        //int index = 0;
        int mark = 0;
        const int str_size = str.size();
        vector<int> accord = {0};
        for (int i = 0; i < str.size(); i++)
        {
            while(in_range(str[i]))
            {
                if (is_np(str[i]))
                {
                   if (str[i] == '-')
                      mark = 0;
                   else
                      mark = 1;
                }
                if (is_number(str[i]))
                {
                   accord.push_back((int)str[i]);
                }
            }
        }
        int ret = 0;
        int num_size = accord.size();
        int ix;
        for (ix = 0; ix < num_size; ix++);
        {
            ret = accord[ix] * pow(10, num_size);
            num_size--;
        }
    }
};
 */



/*
//字符串数字相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int sum = 0;
        int i, j;
        i = j = 0;
        int sign = 0;
        string ret;
        while (i < num1.size() && j < num2.size())
        {
            sum = (num1[i] - '0') + (num2[j] - '0') + sign;
            if (sum >= 10)
            {
                sum = sum - 10;
                sign = 1;
            }
            else
                sign = 0;
            ret.push_back(sum + '0');
            i++;
            j++;
        }
        while (j < num2.size())
        {
            sum = num2[j] - '0' + sign;
            if (sum >= 10)
            {
                sum = sum - 10;
                sign = 1;
            }
            else
                sign = 0;
            j++;
            ret.push_back(sum + '0');
        }
        while (i < num1.size())
        {
            sum = num1[i] - '0' + sign;
            if (sum >= 10)
            {
                sum = sum - 10;
                sign = 1;
            }
            else
                sign = 0;
            i++;
            ret.push_back(sum + '0');
        }

        if (sign > 0)
        {
            ret.push_back(sign + '0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    Solution s;
    string num1 = "456";
    string num2 = "77";
    string c=s.addStrings(num1, num2);
    for (const auto& e : c)
    {
        cout << e << " ";
    }
    cout << endl;
}
*/

/*
//仅反转字母
class Solution {
public:
    bool isabc(char ch)
    {
        bool x = ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z';
        return x;

    }
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (left < right && !isabc(s[left]))
            {
                left++;
                break;
            }
            if (left < right && !isabc(s[right]))
            {   
                right--;
                break;      
            }    
            //std::swap(s.at(left),s.at(right));
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string ret=s.reverseOnlyLetters("7_28]");
    for (const auto& e : ret)
    {
        cout << e << " ";
    }
    cout << endl;
}
*/


/*
//找到唯一的一个字母
class Solution {
public:
    int firstUniqChar(string s) {
        int s_time[26] = { 0 };
        for (const auto& e : s)
        {
            s_time[e - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s_time[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
 
int main()
{
    string st = "leecode";
    Solution s;
    int index=s.firstUniqChar(st);
    cout << index << endl;
}
*/


/*
//求出最后一个单词的长度
class Solution {
public:
    int find_last_word(string s)
    {
        int index = s.rfind(' ');
        return index;
    }
};

int main() {
    Solution s;         
    string st;
    getline(cin, st);         //因为字符串中包含空格所以得使用getline（），而不是cin，切记！！！
    int last_index = s.find_last_word(st);
    cout << st.size() - last_index - 1 << endl;
}
*/

class Solution {
public:
    void A_to_a(string& s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + 'a' - 'A';
            }
        }
    }
    bool in_range(char s)
    {
        return (s >= 'a' && s <= 'z');

    }
    bool isPalindrome(string s) {
        A_to_a(s);
        vector<char> s_new;
        stack<char> v_s;
        for (int i = 0; i < s.size(); i++)
        {
            if (in_range(s[i]))
            {
                v_s.push(s[i]);
                s_new.push_back(s[i]);
            }
        }
        int index = 0;
        while (!v_s.empty())
        {
            char ch = v_s.top();
            v_s.pop();
            if (ch != s_new[index])
                return false;
            index++;
        }
        return true;
    }
};

int main()
{
    Solution so;
    string st = "0P";
    bool result=so.isPalindrome(st);
    cout << result << endl;
}