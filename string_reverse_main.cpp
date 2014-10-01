// created and modified by Saeid Bagheri, September 30, 2014

//------------------------******string reversal function with unit tests******----------------------------------
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//the function to reverse the string
//input: pointer to the input string to reverse
//the string will be reversed in-place
void reverse_string(string input)
{
	if (input.empty())
	{
		cout<<"input array is empty!"<<endl;
		return;
	}
	try
	{
		int length=input.length();
		char temp;
		for(int i=0;i<(length/2);i++)
		{
			temp=input[i];
			input[i]=input[length-1-i];
			input[length-1-i]=temp;
		}
	}
	catch (exception& e)
	{
		cout<<"exception thrown!"<<e.what()<<endl;
	}

	return;
}

//Create a class for unit testing
class unit_test_class
{
private:
	string simple_test;
	string all_same;
	string palindrome;
	string numbers_and_symbols;
	string with_slashes;
	string long_string;
	string empty_string;
protected:
	int counter;
	int passed;
	double percentage;
public:
	unit_test_class()
	{
		simple_test="I am Saeid";
		all_same="aaaaaaaaaa";
		palindrome="abcddcba";
		numbers_and_symbols="1278%27136%^%@__&^@^%6%@^%^5@#6627q138778";
		with_slashes="hhh\\/\]]s";
		empty_string="";
		long_string="This project is aimed at visualizing data obtained from multiple surveillance cameras for the purpose of re-identification. ";
		counter=0;
		passed=0;
	}
	bool unit_test_simple()
	{
		reverse_string(simple_test);
		if(simple_test.compare("dieaS ma I"))
		{
			cout<<"simple test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}
	}
	bool unit_test_repeated()
	{
		reverse_string(all_same);
		if(simple_test.compare("aaaaaaaaaa"))
		{
			cout<<"repeated string test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}	
	}
	bool unit_test_palindrome()
	{
		reverse_string(palindrome);
		if(simple_test.compare(palindrome))
		{
			cout<<"palindrome string test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}	
	}
	bool unit_test_numbers_and_symbols()
	{
		reverse_string(numbers_and_symbols);
		if(simple_test.compare("877831q7266#@5^%^@%6%^@^&__@%^%63172%8721"))
		{
			cout<<"numbers and symbols string test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}	
	}
	bool unit_test_slashes()
	{
		reverse_string(with_slashes);
		if(simple_test.compare("s]]\/\\hhh"))
		{
			cout<<"string containing slashes test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}	
	}
	bool unit_test_empty_string()
	{
		reverse_string(empty_string);	
		if(simple_test.compare(""))
		{
			cout<<"null string test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}	
	}
	bool unit_test_long_string()
	{
		reverse_string(long_string);	
		if(simple_test.compare(" .noitacifitnedi-er fo esoprup eht rof saremac ecnallievrus elpitlum morf deniatbo atad gnizilausiv ta demia si tcejorp sihT"))
		{
			cout<<"long string test passed!"<<endl;
			counter++;
			passed++;
			return true;
		}
		else
		{
			
			counter++;
			return false;
		}	
	}
	double unit_test_all()
	{
		unit_test_simple();
		unit_test_repeated();
		unit_test_palindrome();
		unit_test_numbers_and_symbols();
		unit_test_slashes();
		unit_test_empty_string();
		unit_test_long_string();
		try
		{
			if (counter==0)
			{
				percentage=0;
			}
			else
				percentage=(passed/counter)*100;
			cout<<"success rate is: "<<percentage<<endl;
			return percentage;
		}
		catch(exception& e)
		{
			cout<< "exception while calculating test results!"<<endl;
		}

	}
};


//Driver function
int main()
{
	char input[]="";
	unit_test_class unit_test;
	unit_test.unit_test_all();
	scanf("%s",input);
	return 0;
}