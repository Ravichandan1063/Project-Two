#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class BAccount
{
    private:
    double balance[100];
    int pin[100];
    int mpin;
    double interest[100];

    public:
    BAccount()
    {   
        mpin=1589;
        for(int i=0;i<100;i++)
        balance[i]=-1;
    }

    int managerpin()
    {
        return mpin;
    }

    void computeinterest(double rate)
    {
        int epin;
        cout<<"\n Enter your pin:";
        cin>>epin;
        if(epin==mpin)
        {
            for(int i=0;i<100;i++)
            {
                if(balance[i]!=-1)
                interest[i]=balance[i]*rate/100;
                else
                interest[i]=-1;   
            }
        }
        else
        cout<<"\n Invalid Pin.";
    }

    void printall()
    {
        int epin;
        cout<<"\n Enter your pin:";
        cin>>epin;
        if(epin==mpin)
        {
        for(int i=0;i<100;i++)
        {
            if(balance[i]!=-1)
            {
                cout<<i+1001<<" "<<balance[i];
            }
        }
        }
        else 
        cout<<"\n Invalid Pin.";
    }

    void closeall()
    {
        int epin;
        cout<<"\n Enter your pin:";
        cin>>epin;
        if(epin==mpin)
        {
            for(int i=0;i<100;i++)
            {
                balance[i]=-1;
            }
        }
        else 
        cout<<"\n Invalid Pin.";

    }

    void openaccount()
    {
        int no=-1;
        for(int i=0;i<100;i++)
        {
            if(balance[i]==-1)
        {
            no=i;
            break;
        }
        }

        if(no==-1)
        cout<<"\n Sorry! BankFull";
        else
        {
            
        cout<<"\n Enter initial deposit:"; cin>>balance[no];
        cout<<"\n Enter pin:"; cin>>pin[no];
        cout<<"\n Your account number is:"<<no+1001;
        }

    }

    void closeaccount()
    {   
        int eacc, epin;
        cout<<"\n Enter account no:";
        cin>>eacc;
        cout<<"\n Enter your pin:";
        cin>>epin;
        int tacc;
        tacc=eacc-1001;
        if(balance[tacc]==-1||tacc<1||tacc>100)
        {
            cout<<"\n Account doesnt not exist.";
            return;
        }
        else if(pin[tacc]!=epin)
        {
            cout<<"\n Wrong pin.";
            return;
        }
        else
        {
            balance[tacc]=-1;
        }

    }

    void balanceinq()
    {
        int eacc, epin;
        cout<<"\n Enter account no:";
        cin>>eacc;
        cout<<"\n Enter your pin:";
        cin>>epin;
        int tacc;
        tacc=eacc-1001;
        if(balance[tacc]==-1||tacc<1||tacc>100)
        {
            cout<<"\n Account doesnt not exist.";
            return;
        }
        else if(pin[tacc]!=epin)
        {
            cout<<"\n Wrong pin.";
            return;
        }
        else
        {   
            cout<<"\n Your account number is:"<<eacc;
            cout<<"\n Your remaining balance is:"<<balance[tacc];
        }   

    }

    void transaction(int flag) //flag variable for deposit(1) and withdrawal(0)
    {
        int eacc, epin;
        double amount;
        cout<<"\n Enter account no:";
        cin>>eacc;
        cout<<"\n Enter your pin:";
        cin>>epin;
        cout<<"\n Enter the amount:";
        cin>>amount;

        int tacc;
        tacc=eacc-1001;
        if(balance[tacc]==-1||tacc<1||tacc>100)
        {
            cout<<"\n Account doesnt not exist.";
            return;
        }
        else if(pin[tacc]!=epin)
        {
            cout<<"\n Wrong pin.";
            return;
        }

        else
        {
            if(flag==1)
            {
                balance[tacc]=balance[tacc]+amount;
                cout<<"\n Amount deposited succesfully";
            }
            else
            {   
                int bal;
                bal=balance[tacc] - amount;
                if(bal<0)
                cout<<"\n Insufficient Balance.";
                else
                {
                    balance[tacc]=balance[tacc]-amount;
                    cout<<"\n Amount withdrawn succesfully";
                }
                
            }
            
        }

    }
        
};

int main()
{
    int acc_no, pin_no, tmode;
    double irate;
    int manager;
    double money;
    BAccount b;
    char ch,cm;

    cout<<"\n Welcome to Thala Bank. What can we do for you?";
    cin>>ch;

    while(1)
    {
    
    switch(ch)
    {
        case 'O': {
                    b.openaccount();
                    break;
        }

        case 'B': {
                   b.balanceinq();
                   break; 
        }

        case 'D': {
                    b.transaction(1);
                    break;
        }

        case 'W': {
                    b.transaction(0);
                    break;
        }

        case 'C': {
                    b.closeaccount();
                    break;
        }

        case 'S': {
                    
                    cout<<"\n Please enter the pin:";
                    cin>>manager;
                    if(manager!=b.managerpin())
                    cout<<"\n Invalid pin.";
                    else
                    {
                        cout<<"\n Hello Manager! Command me:";
                        cin>>cm;

                        while(1)
                        {

                        switch(cm)
                        {
                            case 'I': {
                                        cout<<"\n Enter interest rate:";
                                        cin>>irate;
                                        b.computeinterest(irate);
                                        break;
                            }

                            case 'P': {
                                        b.printall();
                                        break;
                            }

                            case 'E': {
                                        b.closeall();
                                        goto last;
                                        break;
                            }
                            default : {
                                        cout<<"\n Invalid Command, Manager.";
                                        break;
                            }
                        }
                        }
                    }
                    
        }

        default:{ 
                cout<<"\n Invalid command.";
                break;
        }


    }
    }

last:

return 0;

}
    
