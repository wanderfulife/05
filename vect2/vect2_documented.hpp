#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
    private:
        int x;  // x component of the 2D vector
        int y;  // y component of the 2D vector

    // PUBLIC INTERFACE
    public:
        /*
         * CONSTRUCTORS
         */
        
        // Default constructor: initializes both components to 0
        // Usage: vect2 v1;  // creates vector (0, 0)
        vect2();
        
        // Parameterized constructor: sets x and y components
        // Usage: vect2 v2(1, 2);  // creates vector (1, 2)
        vect2(int num1, int num2);
        
        // Copy constructor: creates a copy of another vect2 object
        // Usage: vect2 v3(original_vector);  // creates copy of original_vector
        vect2(const vect2& source);
        
        // Assignment operator: assigns one vect2 object to another
        // Usage: v1 = v2;  // assigns v2 to v1
        vect2& operator=(const vect2& source);

        /*
         * SUBSCRIPT OPERATORS - Access vector components
         * Index 0 = x component, Index 1 = y component
         */
        
        // Const subscript operator: access vector components by index (0 for x, 1 for y)
        // Returns value for reading only: std::cout << vector[0];
        int operator[](int index) const;
        
        // Non-const subscript operator: modify vector components by index (0 for x, 1 for y)
        // Returns reference allowing modification: vector[0] = 5;
        int& operator[](int index); // NON-COST (allows modification)

        /*
         * UNARY OPERATORS
         */
        
        // Unary minus operator: negates both components of the vector
        // Usage: -vector;  // negates both x and y components
        vect2 operator-() const;
        
        // Scalar multiplication operator: multiplies vector by a scalar value
        // Usage: vector * 5;  // multiplies both components by 5
        vect2 operator*(int num) const;

        /*
         * ASSIGNMENT OPERATORS - Modify current vector
         */
        
        // Scalar multiplication assignment operator: multiplies both components by a scalar
        // Usage: vector *= 5;  // multiplies both components by 5 and assigns back
        vect2& operator*=(int num);

        // Vector addition assignment operator: adds another vector's components
        // Usage: v1 += v2;  // adds v2's components to v1
        vect2& operator+=(const vect2& obj);
        
        // Vector subtraction assignment operator: subtracts another vector's components
        // Usage: v1 -= v2;  // subtracts v2's components from v1
        vect2& operator-=(const vect2& obj);
        
        // Component-wise multiplication assignment operator: multiplies corresponding components
        // Usage: v1 *= v2;  // multiplies corresponding components (v1.x *= v2.x, v1.y *= v2.y)
        vect2& operator*=(const vect2& obj);

        /*
         * BINARY ARITHMETIC OPERATORS - Return new vector
         */
        
        // Vector addition operator: adds two vectors component-wise
        // Usage: v3 = v1 + v2;  // creates new vector with component-wise addition
        vect2 operator+(const vect2& obj) const;
        
        // Vector subtraction operator: subtracts one vector from another component-wise
        // Usage: v3 = v1 - v2;  // creates new vector with component-wise subtraction
        vect2 operator-(const vect2& obj) const;
        
        // Component-wise multiplication operator: multiplies corresponding components of two vectors
        // Usage: v3 = v1 * v2;  // creates new vector with component-wise multiplication
        vect2 operator*(const vect2& obj) const;

        /*
         * INCREMENT/DECREMENT OPERATORS
         */
        
        // Pre-increment operator: increments both components by 1
        // Usage: ++vector;  // increments both x and y by 1, returns modified vector
        vect2& operator++();
        
        // Post-increment operator: returns current value then increments both components by 1
        // Usage: vector++;  // returns original vector value, then increments both components
        vect2 operator++(int);
        
        // Pre-decrement operator: decrements both components by 1
        // Usage: --vector;  // decrements both x and y by 1, returns modified vector
        vect2& operator--();
        
        // Post-decrement operator: returns current value then decrements both components by 1
        // Usage: vector--;  // returns original vector value, then decrements both components
        vect2 operator--(int);

        /*
         * COMPARISON OPERATORS
         */
        
        // Equality comparison operator: checks if both components are equal
        // Usage: v1 == v2;  // returns true if both x and y components are equal
        bool operator==(const vect2& obj) const;
        
        // Inequality comparison operator: checks if vectors are not equal
        // Usage: v1 != v2;  // returns true if any component differs
        bool operator!=(const vect2& obj) const;

        /*
         * DESTRUCTOR
         */
        
        // Destructor: cleans up the object when it goes out of scope
        ~vect2();
};

/*
 * NON-MEMBER OPERATORS - Not part of the class but related functionality
 */

// Non-member scalar multiplication operator: multiplies scalar by vector (scalar on the left)
// Usage: 5 * vector;  // equivalent to vector * 5, allows scalar on left side
vect2 operator*(int num, const vect2& obj);

// Stream output operator: allows printing the vector in format {x, y}
// Usage: std::cout << vector;  // prints vector as {x, y}
std::ostream& operator<<(std::ostream& os,const vect2& obj);

#endif // VECT2_HPP