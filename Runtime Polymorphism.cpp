#include <iostream>
#include <string.h>

using namespace std;

class media
{
    protected:
        char *title;
        float price;
        
    public:
        media(char *s, float a)
        {
            title = new char[strlen(s) + 1];
            strcpy(title, s);
            price=a;
        }
        virtual void display()
        {}
};
class book:public media
{
    protected:
        int pages;
    
    public:  
        book(char *s, float a, int p) : media(s, a)
            {
                pages = p;
            }
        void display();
};

class cd:public media
{
    protected:
        int playtime;
        
    public:
        cd(char *s, float a, int t) : media(s, a)
        {
            playtime = t;
        }
        void display();
};

void book::display()
{
    cout<<"\nBook details";
    cout<<"\nTitle: "<<title;
    cout<<"\nPrice: "<<price;
    cout<<"\nTotal Pages: "<<pages;
}

void cd::display()
{
    cout<<"\nCD details";
    cout<<"\nTitle: "<<title;
    cout<<"\nPrice: "<<price;
    cout<<"\nTotal Playtime: "<<playtime;
}

int main()
{
    char *title=new char[10];
    float price;
    int pages;
    int time_play;
    //Book details
    cout<<"Enter Title: ";
    cin>>title;
    cout<<"Enter Price: ";
    cin>>price;
    cout<<"Enter Total pages: ";
    cin>>pages;
    book book1(title, price, pages);
    //CD details
    cout<<"Enter Title: ";
    cin>>title;
    cout<<"Enter Price: ";
    cin>>price;
    cout<<"Enter Total playtime: ";
    cin>>time_play;
    
    cd cd1(title, price, time_play);
    
    media *list[2];
    list[0]=&book1;
    list[1]=&cd1;
    list[0]->display();
    list[1]->display();
    return 0;
}



