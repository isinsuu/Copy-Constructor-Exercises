#include <iostream>
using namespace std;

class UpDownNumbers{
	private:
		int start;
		int length;
		int *numbers;
		
	public:
		UpDownNumbers(int len, int s);
		UpDownNumbers(const UpDownNumbers &source);
		~UpDownNumbers(){delete [] numbers;}
		void generate();
		void print();
		void SetStart(int x){start=x;}
		int GetStart(){return start;}
		int GetLength(){return length;}
};

UpDownNumbers::UpDownNumbers(int len, int s) //constructor
{
	start=s;
	length=len;
	numbers=new int[length];
	for(int i=0; i<length; ++i)
	{
		numbers[i]=0;
	}
}

UpDownNumbers::UpDownNumbers(const UpDownNumbers &source) //copy constr.
{
	start=source.start;
	length=source.length;
	numbers=new int[length];
	for(int i=0; i<length; ++i)
	{
		numbers[i]=source.numbers[i];
	}
		
}

void UpDownNumbers::generate()
{
	int i;
	numbers[0]=start;
	
	for(i=1; i<length+1; ++i)
	{
		if(numbers[i-1]%2)
		{
			numbers[i]=3*numbers[i-1]-1;			
		}		
		
		else
		{
			numbers[i]=numbers[i-1]/2+5;
		}
	}	
}

void UpDownNumbers::print()
{
	for(int i=0; i<length; ++i)
	{
		cout << numbers[i] << " ";
	}
	
	cout << endl;
}	

int main()
{
	int main_len{0}, main_s{0};
	cout << "Enter length and start for Object A: ";
	cin >> main_len >> main_s;
	
	UpDownNumbers A(main_len, main_s);
	
	A.generate();
	cout << "Object A (start: " << A.GetStart() << ", length: " << A.GetLength() << "): ";
	A.print();
	
	UpDownNumbers B=A;
	
	cout << "Object B (b=a): ";
	B.print();
	
	cout << "Enter new start for Object B: ";
	cin >> main_s;
	
	B.SetStart(main_s);
	B.generate();
	
	cout << "b.start is " << B.GetStart() << " now." << endl;
	
	cout << "Object A (start: " << A.GetStart() << ", length: " << A.GetLength() << "): ";
	A.print();
	
	cout << "Object B (start: " << B.GetStart() << ", length: " << B.GetLength() << "): ";
	B.print();
	
	return 0;
}
















