
#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int x;  // x component of the 2D vector
		int y;  // y component of the 2D vector
	public:
		// Default constructor: initializes both components to 0
		vect2();
		// Constructor with two parameters: sets x and y components
		vect2(int num1, int num2);
		// Copy constructor: creates a copy of another vect2 object
		vect2(const vect2& source);
		// Assignment operator: assigns one vect2 object to another
		vect2& operator=(const vect2& source);

		// Const subscript operator: access vector components by index (0 for x, 1 for y)
		int operator[](int index) const;
		// Non-const subscript operator: modify vector components by index (0 for x, 1 for y) - NON-COST
		int& operator[](int index); // NON-COST

		// Unary minus operator: negates both components of the vector
		vect2 operator-() const;
		// Scalar multiplication operator: multiplies vector by a scalar value
		vect2 operator*(int num) const;

		// Scalar multiplication assignment operator: multiplies both components by a scalar
		vect2& operator*=(int num);

		// Vector addition assignment operator: adds another vector's components
		vect2& operator+=(const vect2& obj);
		// Vector subtraction assignment operator: subtracts another vector's components
		vect2& operator-=(const vect2& obj);
		// Component-wise multiplication assignment operator: multiplies corresponding components
		vect2& operator*=(const vect2& obj);

		// Vector addition operator: adds two vectors component-wise
		vect2 operator+(const vect2& obj) const;
		// Vector subtraction operator: subtracts one vector from another component-wise
		vect2 operator-(const vect2& obj) const;
		// Component-wise multiplication operator: multiplies corresponding components of two vectors
		vect2 operator*(const vect2& obj) const;

		// Pre-increment operator: increments both components by 1
		vect2& operator++();
		// Post-increment operator: returns current value then increments both components by 1
		vect2 operator++(int);
		// Pre-decrement operator: decrements both components by 1
		vect2& operator--();
		// Post-decrement operator: returns current value then decrements both components by 1
		vect2 operator--(int);

		// Equality comparison operator: checks if both components are equal
		bool operator==(const vect2& obj) const;
		// Inequality comparison operator: checks if vectors are not equal
		bool operator!=(const vect2& obj) const;

		// Destructor: cleans up the object
		~vect2();
};

// Non-member scalar multiplication operator: multiplies scalar by vector (scalar on the left)
vect2 operator*(int num, const vect2& obj);

// Stream output operator: allows printing the vector in format {x, y}
std::ostream& operator<<(std::ostream& os,const vect2& obj);

#endif

