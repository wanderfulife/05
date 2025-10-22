/*
 * FILE: vect2.cpp
 * PURPOSE: Implementation of the vect2 class - a 2D vector with integer components
 * FEATURES: Implements all vector operations, arithmetic, comparisons, and output
 * AUTHOR: Vector class implementation
 */

#include "vect2.hpp"

/*
 * CONSTRUCTORS
 */

// Default constructor: initializes both x and y components to 0
// This creates a vector at the origin (0, 0)
// Called when: vect2 v1;  // creates vector (0, 0)
vect2::vect2()
{
    this->x = 0;  // Initialize x component to 0
    this->y = 0;  // Initialize y component to 0
}

// Constructor that takes two integers and sets them as x and y components
// This creates a vector with specified coordinates
// Called when: vect2 v2(1, 2);  // creates vector (1, 2)
vect2::vect2(int num1, int num2)
{
    this->x = num1;  // Set x component to first parameter
    this->y = num2;  // Set y component to second parameter
}

// Copy constructor: creates a copy of another vect2 object
// This creates a new vector with the same components as the source
// Called when: vect2 v3(original_vector);  // creates copy of original_vector
vect2::vect2(const vect2& source)
{
    // Delegate to assignment operator to copy the data
    *this = source;
}

/*
 * ASSIGNMENT OPERATOR
 */

// Assignment operator: assigns one vect2 to another
// This copies the components from the source vector to this vector
// Called when: v1 = v2;  // assigns v2 to v1
// Returns: reference to this vector to allow chaining (v1 = v2 = v3)
vect2& vect2::operator=(const vect2& source)
{
    // Self-assignment protection: prevent v = v scenarios
    if(this != &source)
    {
        this->x = source.x;  // Copy x component from source
        this->y = source.y;  // Copy y component from source
    }
    return(*this);  // Return reference to this object for chaining
}

/*
 * SUBSCRIPT OPERATORS - Access/modify vector components
 */

// Const subscript operator: allows read-only access to vector components by index
// Index 0 returns x component, Index 1 returns y component
// Called when: int val = vector[0];  // gets x component
// Returns: value of the component (not a reference, so cannot be modified)
int vect2::operator[](int index) const
{
    if(index == 0)
        return(this->x);  // Return x component for index 0
    return(this->y);      // Return y component for index 1
}

// Non-const subscript operator: allows modification of vector components by index
// Index 0 returns x component, Index 1 returns y component
// Called when: vector[0] = 5;  // sets x component to 5
// Returns: reference to the component (allowing modification)
int& vect2::operator[](int index)
{
    if(index == 0)
        return(this->x);  // Return reference to x component for index 0
    return(this->y);      // Return reference to y component for index 1
}

/*
 * UNARY OPERATORS
 */

// Unary minus operator: negates both x and y components
// This creates a new vector with opposite direction
// Called when: vect2 neg = -vector;  // creates vector with negated components
// Returns: new vector with both components negated
vect2 vect2::operator-() const
{
    vect2 temp = *this;      // Create copy of current vector
    temp[0] = -temp[0];      // Negate x component
    temp[1] = -temp[1];      // Negate y component
    return(temp);            // Return new negated vector
}

/*
 * SCALAR MULTIPLICATION OPERATORS
 */

// Scalar multiplication operator: multiplies both components by a scalar value
// This creates a new scaled vector without modifying the original
// Called when: vect2 scaled = vector * 5;  // multiplies both components by 5
// Returns: new vector with scaled components
vect2 vect2::operator*(int num) const
{
    vect2 temp;              // Create new vector
    
    temp.x = this->x * num;  // Scale x component by scalar
    temp.y = this->y * num;  // Scale y component by scalar
    return(temp);            // Return new scaled vector
}

// Scalar multiplication assignment operator: multiplies both components by a scalar
// This modifies the current vector by scaling both components
// Called when: vector *= 5;  // multiplies both components by 5 and updates vector
// Returns: reference to this vector for chaining operations
vect2& vect2::operator*=(int num)
{
    this->x *= num;          // Scale x component by scalar and update
    this->y *= num;          // Scale y component by scalar and update
    return(*this);           // Return reference to this object for chaining
}

/*
 * BINARY ARITHMETIC ASSIGNMENT OPERATORS
 */

// Vector addition assignment operator: adds another vector's components to this vector
// This modifies the current vector by adding components from another vector
// Called when: v1 += v2;  // adds v2's components to v1's components
// Returns: reference to this vector for chaining operations
vect2& vect2::operator+=(const vect2& obj)
{
    this->x += obj.x;        // Add x component of other vector to this x component
    this->y += obj.y;        // Add y component of other vector to this y component
    return(*this);           // Return reference to this object for chaining
}

// Vector subtraction assignment operator: subtracts another vector's components from this vector
// This modifies the current vector by subtracting components from another vector
// Called when: v1 -= v2;  // subtracts v2's components from v1's components
// Returns: reference to this vector for chaining operations
vect2& vect2::operator-=(const vect2& obj)
{
    this->x -= obj.x;        // Subtract x component of other vector from this x component
    this->y -= obj.y;        // Subtract y component of other vector from this y component
    return(*this);           // Return reference to this object for chaining
}

// Component-wise multiplication assignment operator: multiplies corresponding components
// This modifies the current vector by multiplying corresponding components with another vector
// Called when: v1 *= v2;  // multiplies corresponding components (v1.x *= v2.x, v1.y *= v2.y)
// Returns: reference to this vector for chaining operations
vect2& vect2::operator*=(const vect2& obj)
{
    this->x *= obj.x;        // Multiply x components and update this x
    this->y *= obj.y;        // Multiply y components and update this y
    return(*this);           // Return reference to this object for chaining
}

/*
 * BINARY ARITHMETIC OPERATORS
 */

// Vector addition operator: adds two vectors component-wise
// This creates a new vector with component-wise addition without modifying operands
// Called when: vect2 result = v1 + v2;  // creates new vector (v1.x+v2.x, v1.y+v2.y)
// Returns: new vector with component-wise addition
vect2 vect2::operator+(const vect2& obj) const
{
    vect2 temp = *this;      // Create copy of current vector
    
    temp.x += obj.x;         // Add x components: temp.x = temp.x + obj.x
    temp.y += obj.y;         // Add y components: temp.y = temp.y + obj.y
    return(temp);            // Return new vector with added components
}

// Vector subtraction operator: subtracts one vector from another component-wise
// This creates a new vector with component-wise subtraction without modifying operands
// Called when: vect2 result = v1 - v2;  // creates new vector (v1.x-v2.x, v1.y-v2.y)
// Returns: new vector with component-wise subtraction
vect2 vect2::operator-(const vect2& obj) const
{
    vect2 temp = *this;      // Create copy of current vector
    temp.x -= obj.x;         // Subtract x components: temp.x = temp.x - obj.x
    temp.y -= obj.y;         // Subtract y components: temp.y = temp.y - obj.y
    return(temp);            // Return new vector with subtracted components
}

// Component-wise multiplication operator: multiplies corresponding components of two vectors
// This creates a new vector with component-wise multiplication without modifying operands
// Called when: vect2 result = v1 * v2;  // creates new vector (v1.x*v2.x, v1.y*v2.y)
// Returns: new vector with component-wise multiplication
vect2 vect2::operator*(const vect2& obj) const
{
    vect2 temp = *this;      // Create copy of current vector
    temp.x *= obj.x;         // Multiply x components: temp.x = temp.x * obj.x
    temp.y *= obj.y;         // Multiply y components: temp.y = temp.y * obj.y
    return(temp);            // Return new vector with multiplied components
}

/*
 * INCREMENT/DECREMENT OPERATORS
 */

// Pre-increment operator: increments both x and y components by 1
// This modifies the current vector and returns the modified version
// Called when: ++vector;  // increments both components and returns modified vector
// Returns: reference to this vector after incrementing
vect2& vect2::operator++()
{
    this->x += 1;            // Increment x component by 1
    this->y += 1;            // Increment y component by 1
    return(*this);           // Return reference to modified vector
}

// Post-increment operator: returns current value then increments both components by 1
// This returns the original value before incrementing the vector
// Called when: vector++;  // returns original vector, then increments both components
// Returns: copy of vector before incrementing (int parameter distinguishes from pre-increment)
vect2 vect2::operator++(int)
{
    vect2 temp = *this;      // Store original value
    
    ++(*this);               // Call pre-increment to increment current vector
    return(temp);            // Return original value before incrementing
}

// Pre-decrement operator: decrements both x and y components by 1
// This modifies the current vector and returns the modified version
// Called when: --vector;  // decrements both components and returns modified vector
// Returns: reference to this vector after decrementing
vect2& vect2::operator--()
{
    this->x -= 1;            // Decrement x component by 1
    this->y -= 1;            // Decrement y component by 1
    return(*this);           // Return reference to modified vector
}

// Post-decrement operator: returns current value then decrements both components by 1
// This returns the original value before decrementing the vector
// Called when: vector--;  // returns original vector, then decrements both components
// Returns: copy of vector before decrementing (int parameter distinguishes from pre-decrement)
vect2 vect2::operator--(int)
{
    vect2 temp = *this;      // Store original value
    
    --(*this);               // Call pre-decrement to decrement current vector
    return(temp);            // Return original value before decrementing
}

/*
 * COMPARISON OPERATORS
 */

// Equality comparison operator: checks if both components are equal
// This compares the components of two vectors
// Called when: if (v1 == v2)  // checks if both vectors have identical components
// Returns: true if both x and y components are equal, false otherwise
bool vect2::operator==(const vect2& obj) const
{
    if((this->x == obj.x) && (this->y == obj.y))  // Compare both x and y components
        return(true);         // Both components match, so vectors are equal
    return(false);            // At least one component differs, so vectors are not equal
}

// Inequality comparison operator: checks if either component is different
// This is the logical opposite of equality
// Called when: if (v1 != v2)  // checks if vectors have different components
// Returns: true if vectors are not equal, false if they are equal
bool vect2::operator!=(const vect2& obj) const
{
    return(!(obj == *this));  // Return the inverse of equality comparison
}

/*
 * DESTRUCTOR
 */

// Destructor: cleans up the object when it goes out of scope
// Since we don't have dynamic memory, this is empty
// Called automatically when vector object is destroyed
vect2::~vect2()
{
    // Empty destructor: no dynamic memory to clean up
    // The x and y integers are automatically cleaned up by the system
}


/*
 * NON-MEMBER OPERATORS
 */

// Stream output operator: allows printing the vector in format {x, y}
// This enables syntax like: std::cout << vector;
// Parameters: output stream and vector to print
// Returns: reference to output stream for chaining operations
std::ostream& operator<<(std::ostream& os,const vect2& obj)
{
    std::cout << "{" << obj[0] << ", " << obj[1] << "}";  // Print in format {x, y}
    return(os);              // Return stream reference for chaining: cout << v1 << v2;
}


// Scalar multiplication operator (with scalar on the left): multiplies vector by scalar
// This enables syntax like: 5 * vector (instead of just vector * 5)
// This is a non-member function and must be declared outside the class
// Parameters: scalar value and vector
// Returns: new vector with scaled components
vect2 operator*(int num, const vect2& obj)
{
    vect2 temp(obj);         // Create a copy of the vector
    temp *= num;             // Use the *= operator to scale the vector
    return(temp);            // Return new scaled vector
}