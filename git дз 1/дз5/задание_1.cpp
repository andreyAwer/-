#include <iostream>
using namespace std;
enum types
{
    undershirt,
    jacket,
    sweater
};
//описания типа types
class Overcoat
{
private:
    int price;
    //цена
    types type;
    //типы:майка,куртка,свитер

    // price и types не инициалзированы потому
    //что их значение важно только после
    //работы перегруженного конструктора
public:
    Overcoat(int price, enum types type)
    {
        this->price = price;
        this->type = type;
    }
    //неявно отцувствует возможность
    //создать обьект класса
    //конструктором по умолчанию
    bool operator==(Overcoat &Overcoat_2)
    {
        return this->type == Overcoat_2.type;
    }
    void operator=(Overcoat &Overcoat_2)
    {
        this->price = Overcoat_2.price;
        this->type = Overcoat_2.type;
    }
    bool operator>(Overcoat &Overcoat_2)
    {
        return ((this->price > Overcoat_2.price) && (this->type == Overcoat_2.type));
        //возвращает true только когда типы одинаковы и
        //у левого обьекта цена выше правого обьекта
    }
};
int main()
{
    Overcoat test_1(100, undershirt);
    Overcoat test_2(150, jacket);
    Overcoat test_3(125, jacket);

    std::cout << (test_1 == test_2) << '\n';
    //типы не равны

    std::cout << (test_2 == test_3) << '\n';

    std::cout << (test_2 > test_1) << '\n';
    //типы не совпадают

    std::cout << (test_3 > test_2) << '\n';
    //цена у test_3 меньше чем у test_2

    std::cout << (test_2 > test_3) << '\n';

    test_1 = test_3;

    std::cout << (test_2 > test_1) << '\n';
    //доказательство работы оператора =
}