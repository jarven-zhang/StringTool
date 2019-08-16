/*************************************************************************
#	> File Name:string.cpp
#	> Author: jarven
#	> Mail: whuaw@aliyun.com
#	> Created Time: 2019年08月08日 星期四 14时29分59秒
 ************************************************************************/

#include<iostream>
#include<exception>

using namespace std;

#define INT_RANGE 2147483647
/**
 * convert string to int
 *   "-111"      --------> -111
 *   "1234.1234" --------> 1234
 *
 * if the source string is empty , return 0;
 * throw except:
 *  -1 : the format is wrong, there are illegal characters
 *  -2 : the length of the src is too lang for a int number
 */
int stoi(const char *srcstr) 
{
	if(nullptr == srcstr)
	{
		return 0;	
	}

	int sign = 1;
	int total_number = 0;
	const char *p = srcstr;

	//To check if it's a negative number
	if('-' == *p)
	{
		sign = -1;
		p++;
	}
	else if ('+' == *p)  
	{
		p++;
	}

	if('0' > *p || *p > '9')
	{
		throw -1;
	}

	while(*p != '\0')
	{
		cout << "*p:" << *p << endl;
		if('.' == *p)
		{
			break;
		}

		if('0' > *p || *p > '9')
		{
			throw -1;
		}  

		if((total_number == INT_RANGE / 10 && *p > '7')
				|| (total_number > INT_RANGE / 10))    
		{
			cout << "too large!!!!!!!!!!!!!" << endl;
			throw -2;
		}

		cout << "total_number:" << total_number << endl;

		total_number = total_number * 10 + (*p++ - '0');
	}

	total_number *= sign;

	return total_number;
}

int main(int argc, char *argv[])  
{
	try
	{
		int test = stoi(argv[1]);
		cout << "test:" << test << endl;
	}
	catch (int& e)
   	{
        cout << e << endl;
    }

	return 0;
}
