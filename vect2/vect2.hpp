#ifndef VECT2_HPP
#define VECT2_HPP

class vect2
{
    private:
        int x;
        int y;
    public:

    vect2();
    vect2(int x, int y);
    vect2(const vect2& source);
    vect2& operator=(const vect2& soucrce);
};

#endif