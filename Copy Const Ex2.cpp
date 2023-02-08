#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class NumbersClass{
	private:
		int *numbers;
		int length;
		bool isPrime(int x);
		
	public:
		NumbersClass(){};
		NumbersClass(int len);
		NumbersClass(const NumbersClass &source);
		~NumbersClass(){delete [] numbers;}
		void generate();
		void filter(string str);
		void print();
};

NumbersClass::NumbersClass(int len)
{
	length=len;
	numbers=new int[length];
	for(int i=0; i<length; ++i)
	{
		numbers[i]=0;
	}
}

NumbersClass::NumbersClass(const NumbersClass &source)
{
	length=source.length;
	numbers=new int[length];
	for(int i=0; i<length; ++i)
	{
		numbers[i]=source.numbers[i];
	}
}

bool NumbersClass::isPrime(int x)
{
	int k{2}, flag{1};

	while(k<x && flag==1)
	{
		if(x%k==0)
		{
			flag=0;
		}
				
		++k;		
	}	
	
	if(flag)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void NumbersClass::generate()
{	
	srand(time(NULL));
	
	for(int i=0; i<length; ++i)
	{
		numbers[i]=1+(rand()%10000);
	}
}

void NumbersClass::filter(string str)
{
	int i{0};
	
	if(str=="prime")
	{
		for(i=0; i<length; ++i)
		{
			if(isPrime(numbers[i])==false)
			{
				numbers[i]=-1;
			}
		}
	}
	
	else if(str=="nonprime")
	{
		for(i=0; i<length; ++i)
		{
			if(isPrime(numbers[i]))
			{
				numbers[i]=-1;
			}
		}
	}
}

void NumbersClass::print()
{
	for(int i=0; i<length; ++i)
	{
		if(numbers[i]==-1)
		{
			continue;
		}
		
		else
		{
			cout << numbers[i] << " ";
		}
	}
}

int main()
{
	int main_len;
	
	cout << "Enter length: ";
	cin >> main_len;
	
	cout << endl;
	
	NumbersClass A(main_len);
	A.generate();
	
	NumbersClass B=A;
	NumbersClass C=A;
	
	B.filter("prime");
	C.filter("nonprime");
	
	cout << "A: ";
	A.print();
	cout << endl;
	cout << "B: ";
	B.print();
	cout << endl;
	cout << "C: ";
	C.print();
	
	return 0;
}







