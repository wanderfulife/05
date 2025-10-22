#ifndef BIGINT
#define BIGINT

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;  // String to store the big integer value
		//std::string result;  // Commented out variable
	public:
		// Default constructor - initializes the bigint to "0"
		bigint();
		// Constructor that takes an unsigned int and converts it to string
		bigint(unsigned int num);
		// Copy constructor - creates a copy of another bigint object
		bigint(const bigint& source);

		// Getter method to retrieve the string representation of the bigint
		std::string getStr()const;

		// Assignment operator - assigns one bigint to another
		bigint& operator=(const bigint& source);

		// Addition operators
		// Addition operator (binary +)
		bigint operator+(const bigint& other)const;
		// Addition assignment operator (+=)
		bigint& operator+=(const bigint& other);

		// Increment operators
		bigint& operator++();       // Pre-increment operator (++x)
		bigint operator++(int);    // Post-increment operator (x++)

		// Bitwise shift operators with unsigned int
		bigint operator<<(unsigned int n)const;  // Left shift by n positions (appends n zeros)
		bigint operator>>(unsigned int n)const;  // Right shift by n positions (removes n digits from right)
		bigint& operator<<=(unsigned int n);     // Left shift assignment
		bigint& operator>>=(unsigned int n);     // Right shift assignment

		// Bitwise shift operators with bigint object
		bigint operator<<(const bigint& other)const;  // Left shift using another bigint as shift amount
		bigint operator>>(const bigint& other)const;  // Right shift using another bigint as shift amount
		bigint& operator<<=(const bigint& other);     // Left shift assignment using another bigint
		bigint& operator>>=(const bigint& other);     // Right shift assignment using another bigint

		// Comparison operators
		bool operator==(const bigint& other) const;  // Equality comparison
		bool operator!=(const bigint& other) const;  // Inequality comparison
		bool operator<(const bigint& other) const;   // Less than comparison
		bool operator>(const bigint& other) const;   // Greater than comparison
		bool operator<=(const bigint& other) const;  // Less than or equal comparison
		bool operator>=(const bigint& other) const;  // Greater than or equal comparison

		// ~bigint();  // Destructor (commented out)

};

// Stream output operator to print bigint objects
std::ostream& operator<<(std::ostream& output, const bigint& obj);

#endif
