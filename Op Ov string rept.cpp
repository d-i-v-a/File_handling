#include <iostream>
#include<cmath>

using namespace std;

class point
{
    private:
        int x;
        string s;
    
    public:
        void input()
        {
            cout<<"\nEnter string: ";
            cin>>s;
            cout<<"\nEnter repitition number: ";
            cin>>x;
        } 
        
        void operator*();
};
void point::operator*()
{
    for (int i=0; i<x; i++)
    {
        cout<<s;
    }
}
int main()
{
    point p1;
    p1.input();
    *p1;

    return 0;
}

