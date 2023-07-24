#include <iostream>

using namespace std;
typedef char str[50];

class account
{
    private:
        string name;
        long phoneno;
        float balance;
    
    public:
        void inputdata()
        {
            cout<<"Enter name: ";
            cin>>name;
            cout<<"\nEnter phone number: ";
            cin>>phoneno;
            cout<<"\nEnter balance: ";
            cin>>balance;

        }
        void display()
        {
         cout<<"\nName: "<< name;
         cout<<"\nContact no: "<<phoneno;
         cout<<"\nBalance: "<<balance;
         
        }
        void withdraw(float aw)
        {
            if ((balance-aw)>1000)
            {    balance-=aw;}
            else
            { cout<<"\nAmount not sufficient!";}
        }
        void deposit(float ad)
        {
            balance=balance+ad;
        }
};
//end of class

int main()
{
    account cust1;
    cust1.inputdata();
    int ch=1;
    while (ch!=4)
    {
        cout<<"\nWelcome!\n1.Deposit\n2.Withdraw\n3.Display\n4.Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                float ad;
                cout<<"Enter amount to be deposited: ";
                cin>>ad;
                cust1.deposit(ad);
                cout<<"Done!";
                break;
                
            case 2:
                float aw;
                cout<<"Enter amount to be withdrawn: ";
                cin>>aw;
                cust1.withdraw(ad);
                cout<<"Done!";
                break;
            
            case 3:
                cust1.display();
                break;
            
            case 4:
                cout<<"Thank you!";
                break;
        }
    }
    
    return 0;
}

