#include <iostream>
#include <cstdlib>
#

using namespace std;

int main()
{

    int**A=new int*[6];


    for(int i=0;i<5;i++)
    {
        A[i]=new int[6];
    }


    for(int i =0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            A[i][j]=0;
        }
    }


    int amount,person,product,valPerDay;





        do
        {
        cout << "Give amount of slips " << endl;
        cin>>amount;
        }while(amount<0);


    for(int i =0;i<amount;i++)
{
          do{
        cout << "Give salesperson number (1-5) " << endl;
        cin>>person;
        }while(person<1&&person>5);


         do{
        cout << "Give product number (1-4)" << endl;
        cin>>product;
        }while(product<1&&product>4);

         do{
        cout << "Give total value of that product sold that day " << endl;
        cin>>valPerDay;
        }while(valPerDay<0);

        A[product-1][person-1]=valPerDay;

}

int tmp;

for(int i=0;i<5;i++)

{
   int sum=0;
    for(int j=0;j<4;j++)
    {

        sum=sum+A[j][i];
        A[4][i]=sum;
    }


}

for(int i=0;i<4;i++)

{
     int sum =0;
    for(int j=0;j<5;j++)
    {

        sum=sum+A[i][j];
        A[i][5]=sum;
    }

}



for(int i =0;i<5;i++)
{
    for(int j=0;j<6;j++)

    {
        cout<<A[i][j];
        cout.width(2);
    }
    cout<<endl;
}

for(int i=0;i<5;i++)
{
    delete[]A;
}



    return 0;
}
