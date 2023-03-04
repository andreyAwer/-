#include <iostream>
using namespace std;
class Flat
{
private:
    int x;
    int y;
    //ширина и длина
    int price;
    //цена
public:
    Flat(int x, int y, int price)
    {
        this->x = x;
        this->y = y;
        this->price = price;
    }
    bool operator==(Flat &flat_2) { return (this->x * this->y == flat_2.x * flat_2.y); }
    void operator=(Flat &flat_2)
    {
        this->x = flat_2.x;
        this->y = flat_2.y;
        this->price = flat_2.price;
    }
    bool operator>(Flat &flat_2) { return (this->price > flat_2.price); }
};
int main()
{
    Flat test_1(5, 7, 100);
    Flat test_2(6, 8, 150);

    cout<<(test_1>test_2);
    cout<<(test_2>test_1);

    cout<<(test_2==test_1);
    test_2=test_1;
    cout<<(test_2==test_1);//доказательство работы = и ==
}