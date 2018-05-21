#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Data
{
    int __number;
    Data *__next;

    Data(int number = 0) : __number(number), __next(nullptr)
    {

    }
};

class List
{
    Data *__data;
    Data *sinker, *prev;

    unsigned int __count;
    unsigned int __rand_max_value;

public:
    List(unsigned int __count = 0, unsigned int __rand_max_value = 0)
        : __data(new Data()), __count(__count-1), __rand_max_value(__rand_max_value)
    {
        if (this->__count > 1) {
            sinker = nullptr;
            sinker = __data;

            srand(time(0));
            for (unsigned int i = 0; i < this->__count; i++) {
                sinker->__next = (__rand_max_value > 0) ? new Data(rand() % __rand_max_value - 4) : new Data();
                sinker = sinker->__next;
            }
        }
    }

    ~List()
    {
        sinker = __data, prev = nullptr;

        while (sinker->__next) {
            sinker = sinker->__next;
            delete __data;
            __data = sinker;
        }

    }

    unsigned int rand_max_value()
    {
        return this->__rand_max_value;
    }

    unsigned int count()
    {
        return this->__count;
    }

    void show()
    {
        sinker = nullptr;
        sinker = this->__data;

        cout << "Size: " << __count << '\n';
        for (unsigned int i = 0; sinker; i++, sinker = sinker->__next) {
            cout << "[Index: " << i << "] => " << sinker->__number << " | Address: " << sinker << '\n';
        }
    }

    void evaluate()
    {
        sinker = nullptr, prev = nullptr;
        sinker = __data, prev = __data;
        int min_value = sinker->__number;

        while (sinker != nullptr) {
            if ((sinker->__number < min_value) && (sinker->__number > 0)) {
                min_value = sinker->__number;
            }

            Data *newItem = new Data(sinker->__number+1);
            newItem->__next = sinker->__next;
            sinker->__next = newItem;
            sinker = newItem;
            __count++;

            if (__data->__number < 0) {

                if (__data->__next) {
                    __data = __data->__next;
                    sinker = __data;

                    delete prev;
                }

                __count--;
            } else if (sinker->__number < 0) {
                prev->__next = sinker->__next;
                delete sinker;
                sinker = prev->__next;

                __count--;
            } else {
                prev = sinker;
                sinker = sinker->__next;
            }

        }

        cout << '\n' << "Min value: " << min_value << '\n';
    }

};

struct TestList
{
    unsigned int __count;

    TestList (unsigned int __count = 5) : __count(__count)
    {

    }

    void standart()
    {
        cout << "----[Test 1. Standard]--------" << '\n';
        List lst(__count, 10);

        cout << "Before: {" << '\n';
        lst.show();
        cout << "}" << '\n';

        lst.evaluate();

        cout << '\n' << "After: {" << '\n';
        lst.show();
        cout << "}" << '\n';
        cout << "------------------------------" << '\n' << '\n';
    }

};

int main(int argc, char* argv[])
{
    TestList test;
    test.standart();

}
