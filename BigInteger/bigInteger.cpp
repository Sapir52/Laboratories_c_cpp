#include "Ex3_header.h" 
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

/** Auxiliary function-swap **/
char* BigInteger::swapFunc(char *str,int end)
{
	int start{};

	while (start < end)
	{
		swap(*(str + start), *(str + end));
		start++;
		end--;
	}
	return str;
}

/** Auxiliary function for a connection operator **/

char * BigInteger::connectionFunc(char * str, int size1, int size2, int ind1, int ind2, const BigInteger& obj)
{
	int temp{};
	int k{};

	while (ind2 != -1)
	{
		str[k] = (number[ind1] - '0' + obj.number[ind2] - '0') +'0';
		k++;
		ind1--;
		ind2--;
	}

	temp = size1 - size2;
	ind1 = temp - 1;

	if (temp != 0)
	{
		for (int j = ind1; j != -1; j--)
		{
			str[k] = number[j];
			k++;
		}
	}

	temp = size1 - 1;

	for (k = 0; k != size1; k++)
	{
		if (str[k] > 57)
		{
			str[k] = str[k] - 10;
			str[k + 1] = str[k + 1] + 1;
		}
		if (k == temp)
		{
			str[k + 1] = '\0';
		}
	}
	return str;
}

/** Auxiliary function for subtraction operator **/
char * BigInteger::subtractionFunc(char * str, int size1, int size2, int ind1, int ind2,int temp, const BigInteger &obj)
{

	int k{};
	int end{};
	while (ind2 != -1)
	{
		str[k] = (number[ind1] - obj.number[ind2]) + '0';
		k++;
		ind1--;
		ind2--;
	}
	temp = size1 - size2;
	ind1 = temp - 1;

	if (temp != 0)
	{
		for (int j = ind1; j != -1; j--)
		{
			str[k] = number[j];
			k++;
		}
	}

	temp = size1 - 1;

	for (k = 0; k != size1; k++)
	{
		if (str[k] < '0')
		{
			str[k] = str[k] + 10;
			str[k + 1] = str[k + 1] - 1;
		}
	}

	end = size1 - 1;
	BigInteger b(str);
	str = b.swapFunc(str, end);

	return str;

}

/**  Difult constructor **/
BigInteger::BigInteger()
{
	setValue(0);
}

/**  Non-difult constructor for int **/
BigInteger::BigInteger(int number)
{
	setValue(number);
}

/**  Non-difult constructor for string **/
BigInteger::BigInteger(const char* number)
{
	setValue(number);
}

/**   Copy constructor **/
BigInteger::BigInteger(const BigInteger&obj)
{
	setValue(obj);
}

/** Move constructor **/
BigInteger::BigInteger(BigInteger&&obj)
{
	this->number = obj.number;
	if (obj.number != nullptr)
	{
		obj.number = number;
	}

}

/** Destructor **/
BigInteger::~BigInteger()
{
	if ((this->number) != nullptr)
	{
		delete[](this->number);
	}
}


/******** set functions of the class ********/
void BigInteger::setValue(int numb)
{
	int temp{};
	int length{};
	int countLength{};
	int size{};

	temp = numb;
	while (temp != 0)
	{
		temp = temp / 10;
		countLength++;
	}

	size = numb;
	length = countLength + 1;
	(this->number) = nullptr;
	(this->number) = new char[length];

	for (int i{}; size != 0; i++)
	{
		temp = size % 10;
		size = size / 10;
		(this->number)[i] = (temp + 48);
		if (size == 0)
		{
			number[i + 1] = '\0';
		}
	}

}

void BigInteger::setValue(const char*num)
{
	int size{};
	size = strlen(num);
	number = nullptr;
	number = new char[size + 1];
	for (int i = 0;num[i] != '\0'; i++)
	{
		number[i] = num[i];
		if (num[i + 1] == '\0')
		{
			number[i + 1] = '\0';
		}
	}
	
}

void BigInteger::setValue(const BigInteger&obj)
{
	setValue(obj.number);
}

/**********************************************************/
/**   Function fromString   **/
BigInteger BigInteger::fromString(const char *number)
{
	return BigInteger(number);
}

/***** Implementation of arithmetic operators *****/
const BigInteger BigInteger::operator+(const BigInteger & obj) const
{
		int sizeNumber = strlen(this->number);
		int sizeObj = strlen(obj.number);

		int index1 = sizeNumber - 1;
		int index2 = sizeObj - 1;

		int end{};
		int start{};
		char* str;
		int temp{};
		int k{};

		if (sizeNumber > sizeObj)
		{
			str = nullptr;
			str = new char[sizeNumber + 1];

			BigInteger a(this->number);
			str = a.connectionFunc(str, sizeNumber, sizeObj, index1, index2, obj.number);

			end = sizeNumber - 1;
			BigInteger b(str);
			str = b.swapFunc(str, end);

			return 	BigInteger(str);
		}
		else if (sizeObj > sizeNumber)
		{
			str = nullptr;
			str = new char[sizeObj + 1];

			BigInteger a(obj.number);
			str = a.connectionFunc(str, sizeObj, sizeNumber, index2, index1, this->number);

			end = sizeObj - 1;
			BigInteger b(str);

			str = b.swapFunc(str, end);

			return 	BigInteger(str);
		}
		if (sizeNumber == sizeObj)
		{
			str = nullptr;
			str = new char(sizeNumber + 2);
			memset(str, '0', sizeNumber + 1);   // initialize " 0 " //
			str[sizeNumber + 1] = '\0';

			index1 = sizeNumber - 1;
			index2 = sizeObj - 1;

			while (index2 != -1)
			{
				str[k] = (number[index1] - '0' + obj.number[index2] - '0') + '0';
				k++;
				index1--;
				index2--;
			}

			temp = sizeNumber;

			for (k = 0; k != sizeNumber; k++)
			{
				if (str[k] > 57)
				{
					str[k] = str[k] - 10;
					str[k + 1] = str[k + 1] + 1;
				}
			}
			if (str[k] == '0')
			{
				str[k] = '\0';
			}

			end = strlen(str) - 1;
			BigInteger b(str);
			str = b.swapFunc(str, end);

			return BigInteger(str);
		}
		else
		{
			return BigInteger("0");
		}
	
}

		
const BigInteger BigInteger::operator-(const BigInteger&obj) const
{
	char* str;
	int counter{};
	int temp{};
	int cmp{};
	int end{};
	int k{};

	cmp = strcmp(this->number, obj.number);

	int sizeNumber = strlen(this->number);						
	int	sizeObj = strlen(obj.number);
	
	int index1 = sizeNumber - 1;
	int index2 = sizeObj - 1;


	if (sizeNumber == sizeObj)
	{
		if (cmp == 0)
		{
			return BigInteger("0");
		}
		else if (cmp < 0)
		{
			temp = sizeNumber;
			sizeNumber = sizeObj;
			sizeObj = temp;
		}
	}

	if (sizeNumber > sizeObj)									
	{
		str = nullptr;
		str = new char[sizeNumber + 1];
		memset(str, '0', sizeNumber);					// initialize " 0 " //

		str[sizeNumber] = '\0';
		
		BigInteger a(this->number);
		a.subtractionFunc(str, sizeNumber, sizeObj, index1, index2, temp, obj.number);

		return BigInteger(str);
	}
	else if (sizeObj > sizeNumber)
	{
		str = nullptr;
		str = new char[sizeObj + 1];
		memset(str, '0', sizeObj);					// initialize " 0 " //

		str[sizeObj] = '\0';

		BigInteger a(obj.number);
		a.subtractionFunc(str, sizeObj, sizeNumber, index2, index1, temp, this->number);
		
		return BigInteger(str);

	}
	else if (sizeNumber == sizeObj)
	{
		str = nullptr;
		str = new char[sizeNumber + 1];
		memset(str, '0', sizeNumber);					// initialize " 0 " //
		str[sizeNumber] = '\0';

		index1 = sizeNumber - 1;
		index2 = sizeObj - 1;

		while (index2 != -1)					
		{
			str[k] = (number[index1] - obj.number[index2]) + '0';
			k++;
			index1--;
			index2--;
		}

		temp = sizeNumber - 1;

		for (k = 0; k != sizeNumber; k++)								
		{
			if (str[k] < 48)							
			{
				str[k] = str[k] + 10;					
				str[k + 1] = str[k + 1] - 1;			
			}
		}

		end = sizeNumber-1 ;

		BigInteger b(str);
		str = b.swapFunc(str, end);


		for (int i{}; str[i] <= '0'; i++)
		{
			counter++;
		}
		temp = sizeNumber + 1 - counter;

		char *nstr = nullptr;
		nstr = new char[temp];

		for (int i=0; str[counter] != '\0'; i++)
		{
			nstr[i] = str[counter];
			if (str[counter + 1] == '\0')
			{
				nstr[i + 1] = '\0';
			}
			counter++;
		}
		delete[] str;
		return BigInteger(nstr);

	}

	

}


const BigInteger BigInteger::operator*(const BigInteger&obj) const
{


	char* str;
	int temp{};
	int start{};
	int end{};
	int k{};

	int sizeNumber = strlen(this->number);
	int sizeObj = strlen(obj.number);
	int index1 = sizeNumber - 1;
	int index2 = sizeObj - 1;


	str = new char[sizeNumber + sizeObj + 1];
	memset(str, '0', sizeNumber + sizeObj);
	str[sizeNumber + sizeObj] = '\0';

	if (sizeNumber == 0 || sizeObj == 0)
	{
		return "0";
	}

	while (start < index1)
	{
		swap(*(number + start), *(number + index1));
		start++;
		index1--;
	}
	start = 0;
	while (start < index2)
	{
		swap(*(obj.number + start), *(obj.number + index2));
		start++;
		index2--;
	}
	
	for (int i = 0; i < sizeObj; i++)
	{
		int dig2 = obj.number[i] - '0';
		int carry = 0;
		for (int j = 0; j < sizeNumber; j++)
		{
			int dig1 = this->number[j] - '0';

			int temp = str[i + j] - '0';
			int numb = dig1*dig2 + temp + carry;
			str[i + j] = numb % 10 + '0';
			carry = numb / 10;
		}
		str[i + sizeNumber] = carry + '0';
	}


	int sz = strlen(str) - 1;
	BigInteger a(str);
	str = a.swapFunc(str, sz);

	char *nstr = nullptr;
	nstr = new char[sz];
	nstr[sz] = '\0';

	for (int i = 1; i <=sz; i++, k++)
	{
		nstr[k] = str[i];
	}
	delete[] str;
	return BigInteger(nstr);


}

const BigInteger BigInteger::operator/(const BigInteger&obj) const
{
	
	int sizeNumber = strlen(this->number);
	int sizeObj = strlen(obj.number);
	int index1 = sizeNumber-1;
	int index2 = sizeObj-1;
	int k{};
	
	if (sizeNumber < sizeObj)
	{
		return BigInteger("0");
	}

	char*  str;
	str = new char[index2];
	str[index2-1] = '\0';

	int index{};
	long long int value;
	value = atoll(obj.number);

	long long int temp = this->number[index] - '0';
	while (temp < value)
	{
		temp = temp * 10 + (number[++index] - '0');
	}
	
	for(int i=0;i<index1 && index1>index2;i++,index1--,index2--)
	{
		str[i]= (temp / value) + '0';
		temp = (temp % value) * 10 + number[++index] - '0';
		
	}

	int sz = strlen(str) - 1;
	char *nstr = nullptr;
	nstr = new char[sz];
	nstr[sz] = '\0';

	for (int i = 0; i < sz; i++,k++)
	{
		nstr[k] = str[i];
	}
	delete[] str;
	return BigInteger(nstr);

}
/*********************************************************/

/** Implementing a placement operator **/

BigInteger & BigInteger::operator=(const BigInteger &obj)
{
	int theSize = strlen(obj.number);

	delete[] this->number;
	this->number = nullptr;
	this->number = new char[theSize + 1];
	for (int index = 0; index < theSize + 1; index++)
	{
		this->number[index] = obj.number[index];
		if (index == theSize + 1)
		{
			this->number[theSize + 1] = '/0';
		}
	}

	return *this;
}

/** Move constructor - Implementing a placement operator **/
BigInteger& BigInteger::operator=(BigInteger&&obj)
{
	this->number = move(obj.number);
	return *this;

}

/* Implementation operator [] */
int BigInteger::operator[](int numb) const
{
	int temp = this->number[numb] - '0';
	return temp;
}

/***** Implementation of arithmetic operators *****/
BigInteger & BigInteger::operator+=(const BigInteger &obj)
{
	*this = (*this) + obj;
	return *this;
}

BigInteger & BigInteger::operator-=(const BigInteger &obj)
{
	if (*this > obj)
	{
		*this -= obj;
		return *this;
	}
	else if (*this == obj)
	{
		return BigInteger("0");
	}
	else
	{
		(*this) = obj - (*this);
		return *this;
	}
}


BigInteger & BigInteger::operator*=(const BigInteger &obj)
{
	*this = (*this) * obj;
	return *this;
}

BigInteger & BigInteger::operator/=(const BigInteger &obj)
{
	*this = (*this) / obj;
	return *this;
}
/****************************************************************/

/***** Implementation of boolean operators *****/
bool BigInteger::operator==(const BigInteger &obj) const
{
	int sizeNumber = strlen(this->number);
	int sizeObj = strlen(obj.number);
	bool is_equal = true;

	if (sizeNumber == sizeObj)
	{
		for (int i = 0; i < sizeNumber; i++)
		{
			if (this->number[i] != obj.number[i])
			{
				is_equal = false;
			}

		}
	}
	else
	{
		is_equal = false;

	}
	return is_equal;
}

bool BigInteger::operator!=(const BigInteger &obj) const
{
	return !(*this == obj);
}

bool BigInteger::operator<(const BigInteger &obj) const
{
	int sizeNumber = strlen(this->number);
	int sizeObj = strlen(obj.number);
	int temp = strcmp(this->number, obj.number);

	if (sizeNumber == sizeObj)
	{
		if (temp>0||temp==0)
		{
			return false;
		}
		else if (temp < 0)
		{
			return true;
		}
	}
	else if (sizeNumber > sizeObj)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool BigInteger::operator>(const BigInteger &obj) const
{
	int sizeNumber = strlen(this->number);
	int sizeObj = strlen(obj.number);

	int temp = strcmp(this->number, obj.number);

	if (sizeNumber == sizeObj)
	{
		if (temp>0)
		{
			return true;
		}
		else if (temp < 0 || temp==0)
		{
			return false;
		}
	}
	else if (sizeNumber > sizeObj)
	{
		return true;
	}
	else
	{
		return false;

	}

}

bool BigInteger::operator<=(const BigInteger &obj) const
{
	if (*this == obj)
	{
		return true;
	}
	else if (*this < obj)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool BigInteger::operator>=(const BigInteger &obj) const
{

	if (*this > obj)
	{
		return true;
	}
	else if (*this == obj)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*****************************************************/

/* Implementation operator prefix */

BigInteger & BigInteger::operator++()
{
	*this = *this + 1;
	return *this;

}
/* Implementation operator postfix */
BigInteger BigInteger::operator++(int)
{
	BigInteger temp (*this);
	*this = *this + 1;
	return temp;

}

/* Implementation operator ostream */
std::ostream& operator<<(std::ostream&out, const BigInteger&obj)
{
	out << obj.number;
	return out;
}

/* Implementation operator istream */
std::istream& operator >> (std::istream&in, BigInteger&obj)
{
	in >> obj.number;
	return in;
}
