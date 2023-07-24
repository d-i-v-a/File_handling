#include <iostream>

using namespace std;

class complex
{
    private:
        float x,y;
    
    public:
        complex()
        {
        }
        complex(float real, float imag)
        {
            x=real;
            y=imag;
        }
        complex operator+(complex);//outline parameter
        complex operator-(complex);
        void display();
        void displaysub();
};

complex complex::operator + (complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return temp;
}
complex complex::operator-(complex c)
{
    complex temp;
    temp.x=x-c.x;
    temp.y=y-c.y;
    return temp;
}
void complex::display()
{
    cout<<x<<"+"<<y<<"i"<<endl;
}
void complex::displaysub()
{
    cout<<x<<"-"<<y<<"i"<<endl;
}

int main()
{
    complex c1, c2, c3, c4;
    c1=complex(2.5, 3.2);
    c2=complex(1.6, 2.7);
    c3=c1+c2;
    c4=c1-c2;
    
    c1.display();
    cout<<endl;
    c2.display();
    cout<<endl;
    c3.display();
    cout<<endl;
    c4.displaysub();

    return 0;
}

