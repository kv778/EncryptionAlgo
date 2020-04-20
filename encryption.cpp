#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

using namespace std;

/*This the class used to the encrypt the file or the entered string*/

class Encrypt
{
public:
    int choice,key1,ctr=0,k=0,flag=0;
    string s;
    unsigned char ctemp;
    double number,enc,Log,store[100];
    fstream f;                         //creating an object f of the fstream class

    void EncryptData()
    {
        cout<<"\t\tENCRYPTION\n\n";
        cout<<"How would you like the file to be encrypted?\n";
        cout<<"1.Entering the string\n";
        cout<<"2.Encrypting an existing file\n";
        cout<<"\n\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 :
                      {
                        cout<<"\nEncrypting an entered string\n";
                        cout<<"\nPlease enter the string : ";
                        cin.ignore();
                        getline(cin,s);                          //taking the string as input
                        cout<<"\nThe entered string : "<<s<<endl;
                        break;
                      }

            case 2 :
                     {
                        cout<<"\nEncrypting an existing file\n";
                        f.open("example.txt");                 //opening the existing file
                        getline(f,s,'\0');
                        cout<<"\nContents of the file before encrypting : \n";
                        cout<<s<<endl;
                        f.close();                            //closing the file
                        flag=1;
                        break;
                     }
            default : cout<<"Please enter a valid choice!\n";
        }

        cout<<endl<<"Please enter the key : ";
        cin>>key1;

        cout<<"The encrypted value : "<<endl<<endl;

        for(int i=0;i<s.length();i++)
        {

            enc=0.0;
            ctemp = s[i];
            number = (int)ctemp;
            enc = ((pow(number,2)*key1));
            Log = log10(enc);
            store[i]=Log;
            ctr++;
            cout<<store[i];
        }

        if(flag==1)
        {
            f.open("example.txt");
            while(k<ctr)
            {
                f<<store[k];                         //writing the encrypted data to the file
                k++;
            }
            f.close();
        }

        cout<<endl;
    }

};

/*This the class used to the decrypt the file or the entered string*/

class Decrypt : public Encrypt                    //using inheritance
{
public:
    int l=0;
    double number2,dec;
    unsigned char ctemp2;
    char store2[100];

    void DecryptData()
    {
        cout<<"\n\n\t\t DECRYPTION \n\n";
        cout<<"The Decrypted Value : "<<endl;
        for(int j=0;j<ctr;j++)
        {

            number2 = 0;
            number2 = pow(10,store[j]);               //taking the antilog
            number2 = number2/key1;
            dec = pow(number2,(0.5));
            ctemp2 = (char)dec;
            store2[j]=ctemp2;
            cout<<ctemp2<<endl;                      //displaying the original characters

        }

        cout<<endl<<endl;

        if(flag==1)
        {
            f.open("example.txt",ios::out|ios::trunc);
            while(l<ctr)
            {
                f<<store2[l];     //writing the decrypted data to the file
                l++;
            }
            f.close();
        }

    }

};

int main()
{
    char ch;
    Decrypt obj;                                 //creating an object of the Decrypt class
    obj.EncryptData();
    cout<<endl<<"Do you want to decrypt the string right now? Y/N  : ";
    cin>>ch;
    if(ch=='Y'||ch=='y')
        obj.DecryptData();
    return 0;
}
