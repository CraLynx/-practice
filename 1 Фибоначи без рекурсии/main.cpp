#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (int i=1; i<1000000; i++)
    {

    double old = 0, value = 1, hold;

	double f = 1, otv = 0;
	double st = 4, fk = 1; per = 1; step = 2; t = 1; // (f1(f) *  4(st) * (1 or 16((t)���������)) * sqrt(2(step))) / (1!(fk))... ��� ������ ������� 
    double e = 0.000000001;

    do
    {
        hold = value; //��������
        value += old;
        old = hold;


        otv = (value * (st * t * sqrt(step))) / fk;	 // ���������� ������� 

		step = step + 1;   //���������� ����� step(���������� �����1)
        st = st * 16;	
		fk = fk * per;	   //���������� ����������
		per = per + 1;     //���������� ����� ��������� � ������ �������� ������������ �� 1
		t = 16;
		
    }
    while ( otv > e );

    }

    return 0;
}
