#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for (auto i=1; i<1000000; i++)
    {

    auto old = 0.0, value = 1.0, hold;

	auto f = 1.0, otv = 0.0;
	auto st = 4.0, fk = 1.0; per = 1.0; step = 2.0; t = 1.0; // (f1(f) *  4(st) * (1 or 16((t)êðàòíîñòü)) * sqrt(2(step))) / (1!(fk))... ïðè ïåðâîì ïðîõîäå 
    auto e = 0.000000001;

    do
    {
        hold = value; //Ôèáîíà÷è
        value += old;
        old = hold;


        otv = (value * (st * t * sqrt(step))) / fk;	 // âû÷èñëåíèå ïðèìåðà 

		step = step + 1;   //Óâåëè÷åíèå ÷èñëà step(èçâëå÷åíèå êîðíÿ1)
        st = st * 16;	
		fk = fk * per;	   //Âû÷èñëåíèå ôàêòîðèàëà
		per = per + 1;     //Óâåëè÷åíèå ÷èñëà ôàêòîðèëà ñ êàæäûì ïðîõîäîì óâëè÷èâàåòñÿ íà 1
		t = 16;
		
    }
    while ( otv > e );

    }
}
