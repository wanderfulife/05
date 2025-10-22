#include "vect2sol.hpp"

// Default constructor: initializes both x and y components to 0
vect2::vect2()
{
	this->x = 0;
	this->y = 0;
}

// Constructor that takes two integers and sets them as x and y components
vect2::vect2(int num1, int num2)
{
	this->x = num1;
	this->y = num2;
}

// Copy constructor: creates a copy of another vect2 object
vect2::vect2(const vect2& source)
{
	*this = source;
}

// Assignment operator: assigns one vect2 to another
vect2& vect2::operator=(const vect2& source)
{
	if(this != &source)  // Check for self-assignment
	{
		this->x = source.x;
		this->y = source.y;
	}
	return(*this);
}

// Const subscript operator: allows access to vector components by index (0 for x, 1 for y)
int vect2::operator[](int index) const
{
	if(index == 0)
		return(this->x);  // Return x component
	return(this->y);      // Return y component
}

// Non-const subscript operator: allows modification of vector components by index (0 for x, 1 for y)
int& vect2::operator[](int index)
{
	if(index == 0)
		return(this->x);  // Return reference to x component
	return(this->y);      // Return reference to y component
}

// Unary minus operator: negates both x and y components
vect2 vect2::operator-() const
{
	vect2 temp = *this;
	temp[0] = -temp[0];  // Negate x component
	temp[1] = -temp[1];  // Negate y component
	return(temp);
}


// Scalar multiplication operator: multiplies both components by a scalar value
vect2 vect2::operator*(int num) const
{
	vect2 temp;

	temp.x = this->x * num;  // Multiply x component by scalar
	temp.y = this->y * num;  // Multiply y component by scalar
	return(temp);
}

// Scalar multiplication assignment operator: multiplies both components by a scalar
vect2& vect2::operator*=(int num)
{
	this->x *= num;  // Multiply x component by scalar
	this->y *= num;  // Multiply y component by scalar
	return(*this);
}

// Vector addition assignment operator: adds another vector's components to this vector
vect2& vect2::operator+=(const vect2& obj)
{
	this->x += obj.x;  // Add x component of other vector
	this->y += obj.y;  // Add y component of other vector
	return(*this);
}

// Vector subtraction assignment operator: subtracts another vector's components from this vector
vect2& vect2::operator-=(const vect2& obj)
{
	this->x -= obj.x;  // Subtract x component of other vector
	this->y -= obj.y;  // Subtract y component of other vector
	return(*this);
}

// Component-wise multiplication assignment operator: multiplies corresponding components
vect2& vect2::operator*=(const vect2& obj)
{
	this->x *= obj.x;  // Multiply x components
	this->y *= obj.y;  // Multiply y components
	return(*this);
}

// Vector addition operator: adds two vectors component-wise
vect2 vect2::operator+(const vect2& obj) const
{
	vect2 temp = *this;

	temp.x += obj.x;  // Add x components
	temp.y += obj.y;  // Add y components
	return(temp);
}

// Vector subtraction operator: subtracts one vector from another component-wise
vect2 vect2::operator-(const vect2& obj) const
{
	vect2 temp = *this;
	temp.x -= obj.x;  // Subtract x components
	temp.y -= obj.y;  // Subtract y components
	return(temp);
}

// Component-wise multiplication operator: multiplies corresponding components of two vectors
vect2 vect2::operator*(const vect2& obj) const
{
	vect2 temp = *this;
	temp.x *= obj.x;  // Multiply x components
	temp.y *= obj.y;  // Multiply y components
	return(temp);
}

// Pre-increment operator: increments both x and y components by 1
vect2& vect2::operator++()
{
	this->x += 1;  // Increment x component
	this->y += 1;  // Increment y component
	return(*this);
}

// Post-increment operator: returns current value then increments both components by 1
vect2 vect2::operator++(int)
{
	vect2 temp = *this;

	++(*this);  // Call pre-increment
	return(temp);
}

// Pre-decrement operator: decrements both x and y components by 1
vect2& vect2::operator--()
{
	this->x -= 1;  // Decrement x component
	this->y -= 1;  // Decrement y component
	return(*this);
}

// Post-decrement operator: returns current value then decrements both components by 1
vect2 vect2::operator--(int)
{
	vect2 temp = *this;

	--(*this);  // Call pre-decrement
	return(temp);
}

// Equality comparison operator: checks if both components are equal
bool vect2::operator==(const vect2& obj) const
{
	if((this->x == obj.x) && (this->y == obj.y))  // Compare both x and y components
		return(true);
	return(false);
}

// Inequality comparison operator: checks if either component is different
bool vect2::operator!=(const vect2& obj) const
{
	return(!(obj == *this));  // Use equality operator to determine inequality
}

// Destructor: cleans up the object (empty in this case)
vect2::~vect2()
{

}


// Stream output operator: allows printing the vector in format {x, y}
std::ostream& operator<<(std::ostream& os,const vect2& obj)
{
	std::cout << "{" << obj[0] << ", " << obj[1] << "}";  // Print in format {x, y}
	return(os);
}


// Scalar multiplication operator (with scalar on the left): multiplies vector by scalar
vect2 operator*(int num, const vect2& obj)
{
	vect2 temp(obj);  // Create a copy of the vector
	temp *= num;      // Use the *= operator
	return(temp);
}

