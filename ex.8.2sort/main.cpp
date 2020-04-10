#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
void myswap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

template<class T>
void sort(T* tab, int N, bool (*comp)(T, T))
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (comp(tab[i], tab[j]))
                myswap(tab[i], tab[j]);
}

class point
{
private:
    double x;
    double y;
public:
    point()
    {
        x = double(rand()) / RAND_MAX;
        y = double(rand()) / RAND_MAX;
    }

    friend ostream& operator<<(ostream& out, point p);
    friend bool sort_x(point a, point b);
    friend bool sort_y(point a, point b);
};

ostream& operator<<(ostream& out, point p)
{
    out << "(" << p.x << ",\t" << p.y << ")";
    return out;
}

bool sort_x(point a, point b)
{
    return a.x < b.x;
}

bool sort_y(point a, point b)
{
    return a.y < b.y;
}

int main()
{
    srand(time(NULL));

    point tab[10];

    cout << "BEFORE SORTING" << endl;
    for (int i = 0; i < 10; i++)
        cout << tab[i] << endl;
    cout << endl;

    sort(tab, 10, sort_x);

    cout << "SORT BY X" << endl;
    for (int i = 0; i < 10; i++)
        cout << tab[i] << endl;
    cout << endl;

    sort(tab, 10, sort_y);

    cout << "SORT BY Y" << endl;
    for (int i = 0; i < 10; i++)
        cout << tab[i] << endl;
    cout << endl;

    return 0;
}
