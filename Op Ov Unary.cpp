#include <iostream>
#include<cmath>

using namespace std;

class point{
    private:
        int x, y;
    
    public:
        void input()
        {
            cout<<"\nEnter x-coordinate: ";
            cin>>x;
            cout<<"\nEnter y-coordinate: ";
            cin>>y;
        } 
        
        void operator-();
        
        void display()
        {
            cout<<"New coordinates: "<<x<<","<<y;
              
        }
};
void point::operator-()
{
    x--;
    y--;
}
int main()
{
    point p1;
    p1.input();
    -p1;
    p1.display();

    return 0;
}
