#include <iostream>
#include <vector>
#include<limits>
#include <cstdlib>
using namespace std;

bool isValid();

class my_vector
{
    vector<int>V;

public:

    void read()
    {  int N;
           do{

        cout<<"Give amount of elements"<<endl;
        cin>>N;
    }while(!(isValid()));
        for(int i =0;i<N; i++)
        {  //cout<<"Enter"<<i+1<<"element"<<endl;
            int x;
            do{
                cout<<"Enter"<<i+1<<"element"<<endl;

            cin>>x;
        }while(!(isValid()));
            V.push_back(x);


        }



    }

    int size() const
    {
        return V.size();
    }


    operator[](int n) const
    {
        return V[n];
    }



};

class sparse_vector
{
    vector<bool>Ord;
    vector<int>Val;


public:
    void change(const my_vector& V)
    {
        for(int i=0;i<V.size();i++)
        {
            if(V[i]==0)
            {
                Ord.push_back(0);
            }
            else if(V[i]!=0)
               {
                   Ord.push_back(1);
                Val.push_back(V[i]);
               }
        }
    }
    void print()
    {
         cout<<"Order vector : "<<endl;

        for(int i=0;i<Ord.size();i++)
        {
            cout<<Ord[i];
        }
        cout<<endl;
        cout<<"Vector of values : "<<endl;

        for(int i=0;i<Val.size();i++)
        {
            cout<<Val[i];
        }
        cout<<endl;


    }


int  operator *( const  sparse_vector & obj) const
    {

        int answer=0;
           int it1=0;
            int it2=0;

        int tmp= min( obj.Ord.size() , Ord.size() );

        for(int i=0;i<tmp;i++)
        {
            if(Ord[i]&&obj.Ord[i])
            {
                answer= answer + obj.Val[it1]*Val[it2];
            }
          if(Ord[i])
            it2++;
        if(obj.Ord[i])
            it1++;

        }

     return answer;

    }


};





    int main()

{
    my_vector v1;
    my_vector v2;

    v1.read();
    v2.read();

    sparse_vector s1;
    sparse_vector s2;
    s1.change(v1);
    s2.change(v2);
    s1.print();
    s2.print();
    cout<<"Scalar product = ";
    cout<<s1*s2;


return 0;



}


bool isValid()
{
    if (cin.rdstate())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //system ("cls");
        return false;
    }

    return true;
}
