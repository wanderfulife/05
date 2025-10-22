
#include "bigint.hpp"

// Default constructor: initializes the bigint to "0"
bigint::bigint()
{
	this->str = "0";
}

// Constructor that takes an unsigned int and converts it to string
bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->str = ss.str();
}

// Copy constructor: creates a copy of another bigint object
bigint::bigint(const bigint& source)
{
	(*this) = source;
}

// Assignment operator: assigns one bigint to another
bigint& bigint::operator=(const bigint& source)
{
	// Check for self-assignment
	if(this == &source)
		return(*this);
	this->str = source.str;
	return(*this);
}

// Getter method to retrieve the string representation of the bigint
std::string bigint::getStr() const
{
	return(this->str);
}

// Helper function to reverse a string
std::string reverse(const std::string& str)
{
	std::string revStr;
	// Iterate backwards through the string to reverse it
	for(size_t i = str.length(); i > 0; i--)
	{
		revStr.push_back(str[i - 1]);
	}
	return(revStr);
}

// Helper function to perform addition of two bigints
std::string addition(const bigint& obj1, const bigint& obj2)
{
	// Reverse both strings to start addition from least significant digit
	std::string str1 = reverse(obj1.getStr());
	std::string str2 = reverse(obj2.getStr());
	std::string result;
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	// Pad the shorter string with zeros to match the length of the longer one
	if(len1 > len2)
	{
		int diff = len1 - len2;
		while(diff > 0)
		{
			str2.push_back('0');
			diff--;
		}
	}
	else if(len2 > len1)
	{
		int diff = len2 - len1;
		while(diff > 0)
		{
			str1.push_back('0');
			diff--;
		}
	}

	int carry = 0;  // Carry over from digit addition
	int digit1;     // Current digit from first number
	int digit2;     // Current digit from second number
	size_t len = str1.length();
	// Add digits one by one from right to left
	for(size_t i = 0; i < len; i++)
	{
		digit1 = str1[i] - '0';  // Convert char to int
		digit2 = str2[i] - '0';  // Convert char to int
		int res = digit1 + digit2 + carry;
		if(res > 9)
		{
			carry = res / 10;           // Calculate carry for next position
			result.push_back((res % 10) + '0');  // Add the ones digit
		}
		else
			result.push_back(res + '0');  // Add the result digit
	}
	// If there's still a carry after processing all digits, add it
	if(carry != 0)
		result.push_back(carry + '0');
	return(reverse(result));  // Reverse to get the final result
}

// Addition operator: adds two bigints and returns the result
bigint bigint::operator+(const bigint& other)const
{
	bigint temp(other);
	temp.str.clear();
	std::string result = addition(*this, other);
	temp.str = result;

	return(temp);
}

// Addition assignment operator: adds another bigint to this one
bigint& bigint::operator+=(const bigint& other)
{
	(*this) = (*this) + other;
	return(*this);
}

// Pre-increment operator: increases the value by 1 and returns the new value
bigint& bigint::operator++()
{
	*(this) = *(this) + bigint(1);
	return(*this);
}

// Post-increment operator: returns current value then increases by 1
bigint bigint::operator++(int)
{
	bigint temp = (*this);
	*(this) = *(this) + bigint(1);
	return(temp);
}


// Left shift operator: appends n zeros to the end of the number (effectively multiplying by 10^n)
bigint bigint::operator<<(unsigned int n)const
{
	bigint temp = *this;

	temp.str.insert(temp.str.end(), n, '0');
	return(temp);
}

// Right shift operator: removes n digits from the end of the number (effectively dividing by 10^n)
bigint bigint::operator>>(unsigned int n)const
{
	bigint temp = *this;
	size_t len = temp.str.length();
	if(n >= len)
		temp.str = "0";  // If shift amount is greater than or equal to length, result is 0
	else
	{
		// Remove n digits from the end of the string
		temp.str.erase(temp.str.length() - n, n); 
	}
	return(temp);
}

// Left shift assignment operator: performs left shift and assigns the result back
bigint& bigint::operator<<=(unsigned int n)
{
	(*this) = (*this) << n;
	return(*this);
}

// Right shift assignment operator: performs right shift and assigns the result back
bigint& bigint::operator>>=(unsigned int n)
{
	(*this) = (*this) >> n;
	return(*this);
}

// Helper function to convert string to unsigned int
unsigned int stringToUINT(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

// Left shift operator using another bigint as the shift amount
bigint bigint::operator<<(const bigint& other)const
{
	bigint temp;
	temp = (*this) << stringToUINT(other.str);
	return(temp);
}

// Right shift operator using another bigint as the shift amount
bigint bigint::operator>>(const bigint& other)const
{
	bigint temp;
	temp = (*this) >> stringToUINT(other.str);
	return(temp);
}

// Left shift assignment operator using another bigint as the shift amount
bigint& bigint::operator<<=(const bigint& other)
{
	(*this) = (*this) << stringToUINT(other.str);
	return(*this);
}

// Right shift assignment operator using another bigint as the shift amount
bigint& bigint::operator>>=(const bigint& other)
{
	(*this) = (*this) >> stringToUINT(other.str);
	return(*this);
}


// Equality comparison operator: checks if two bigints are equal
bool bigint::operator==(const bigint& other) const
{
	if(this->getStr() == other.getStr())
		return(true);
	return(false);
}

// Inequality comparison operator: checks if two bigints are not equal
bool bigint::operator!=(const bigint& other) const
{
	return(!((*this) == (other)));
}

// Less than comparison operator: compares two bigints
bool bigint::operator<(const bigint& other) const
{
	std::string str1 = this->str;
	std::string str2 = other.getStr();
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	// Compare lengths first - shorter number is smaller (if both positive)
	if(len1 != len2)
		return(len1 < len2);
	// If lengths are equal, compare lexicographically
	return(str1 < str2);
}

// Greater than comparison operator: checks if one bigint is greater than another
bool bigint::operator>(const bigint& other) const
{
	return(!(((*this) < other)));
}

// Less than or equal comparison operator: checks if one bigint is less than or equal to another
bool bigint::operator<=(const bigint& other) const
{
	return((((*this) < other) || ((*this) == other)));
}

// Greater than or equal comparison operator: checks if one bigint is greater than or equal to another
bool bigint::operator>=(const bigint& other) const
{
	return((((*this) > other) || ((*this) == other)));
}


// Non-member function: stream output operator to print bigint objects
// Allows using cout << bigint_object
std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();  // Output the string representation of the bigint
	return(output);
}
