#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*


class MinStack {
public:
    MinStack() {
        min_st.push(INT_MAX);
    }

    void push(int val) {
        st.push(val);
        min_st.push(min(min_st.top(), val));

    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
public:
    stack<int> st;
    stack<int> min_st;
    //int min = INT_MAX;
};

int main()
{
    MinStack ms;
    cout << "[]" << endl;
    //MinStack minStack = new MinStack();
    ms.push(2147483646);
    cout << "[]" << endl;
    ms.push(2147483646);
    cout << "[]" << endl;
    ms.push(2147483647);
    cout << "[]" << endl;
    cout << ms.top() << endl; 
    ms.pop();
    cout << "[]" << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << "[]" << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << "[]" << endl;
    ms.push(2147483647);
    cout << "[]" << endl;
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.push(-2147483648);
    cout << "[]" << endl;
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    ms.pop();
    cout << "[]" << endl;
    cout << ms.getMin() << endl;

}
*/


/*
class Solution {
public:
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        int i = 0;
        int j = 0;
        stack<int> st;
        while (i < pushV.size())
        {
            if (i < pushV.size()&&pushV[i] != popV[j])
            {
                st.push(pushV[i]);
                i++;
            }
            else
            {
                i++;
                j++; 
                while(!st.empty()&&st.top() == popV[j])
                {
                    st.pop();
                    j++;
                }
            }
            
        }
        return st.empty();
    }
};
     
int main()
{
    Solution s;
    vector<int> v1 = { 2,1,0 };
    vector<int> v2 = { 1,2,0 };
    cout << s.IsPopOrder(v1, v2) << endl;

} */



/*
class Solution {
public:
    int play(int num1, int num2, string ch)
    {
        int p1 = num1;
        int p2 = num2;
        if (ch == "+")
        {
            return p1 + p2;
        }
        if (ch == "-")
        {
            return p1 - p2;
        }
        if (ch == "*")
        {
            return p1 * p2;
        }
        if (ch == "/")
        {
            return p1 / p2;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_st;
        stack<string> sig_st;
        for (int i=0;i<tokens.size();i++)
        {
            if (!(tokens[i]=="+"||tokens[i] == "-"||tokens[i] == "*"||tokens[i] == "/"))
            {
                num_st.push(atoi(tokens[i].c_str()));
            }
            else
            {
                int num2 = num_st.top();
                num_st.pop();
                int num1 = num_st.top();
                num_st.pop();
                string way = tokens[i];
                int pu = play(num1, num2, way);
                num_st.push(pu);
                //sig_st.push(tokens[i]);
            }
        }
        return num_st.top();

    }
};

int main()
{
    Solution s;
    vector<string> vt = { "4","13","5","/","+" };
    cout<<s.evalRPN(vt);
}  */



/*
#include<algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k; i++)
        {
            pop_heap(nums.begin(), nums.end() - i);
        }
        return nums[nums.size() - k];
    }
};

int main()
{
    Solution s;
    vector<int> num = { 3,2,3,1,2,4,5,5,6 };
    cout<<s.findKthLargest(num, 4);
} 
*/



/*杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            ret[i].resize(i + 1);
        }
        if (numRows == 1)
            ret[0][0] = 1;
        else
        {
            ret[0][0] = 1;
            ret[1][0] = 1;
            ret[1][1] = 1;
            if (numRows > 2)
            {
                for (int i = 2; i < numRows; i++)
                {
                    for (int j = 0; j < ret[i].size(); j++)
                    {
                        if (j == 0 || j == i)
                            ret[i][j] = 1;
                        else {
                            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
                        }
                    }
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> re=s.generate(1);
    return 0;
} 
*/




/*删除多余数字
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int only = 0;
        int tem = nums[0];
        vector<int>::iterator it = nums.begin();
        vector<int>::iterator it_mark = nums.begin();
        while (it!=nums.end())
        {
            if (it  == nums.end()-1)
            {
                //if(it != it_mark + 1)
                    nums.erase(it_mark, it);
                break;
            }
            if (*it != *(it+1))
            {   //if(it_mark!=nums.begin())
                //it_mark++;
                it_mark = nums.erase(it_mark, it);
                it_mark++;
                it = it_mark-1;
                
            }
            if(it!=nums.end())
                it++;
        }
        return nums.size();
    }
};

void main()
{
    Solution s;
    vector<int> nums = { 1,2,3 };
    cout<<s.removeDuplicates(nums);
    return;
} */



/*只出现一次的数字II*/
class Solution{
public:
    int singleNumber(vector<int>&nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (const auto& e : nums)
            {
                if ((e >> i) & 1)
                    count++;
            }
            if (count % 3)
            {
                ret = ret | (1 << i);
            }
        }
        return ret;
    }

};