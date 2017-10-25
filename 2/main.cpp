#include <iostream>
#include <string>
using namespace std; 

struct BikeInfo
{
	string name;
	string fam;
	string ots;
	string typebike;   //!!!!!!!!!!!!!!!!! int с таблицей 
	string tic;	//!!!!!!!!!!!!!!!!!!!!1
}


int main()

	BikeInfo bike[5];  //!!!!!!!!!!!!!!!!!!!!!
	int index, last = 0 ;
	
	Main();
	
void Menu ();
{
	cout << "Enter function" << '\n';
	cout << "1-Add racer" << '\n';
	cout << "2-Delete" << '\n';
	cout << "3-Edit" << '\n';
	cout << "4-View" << '\n';
	while (index = *buffer++)
	{
		switch(c)
		{
			case '1':
			Addracer();
			break;
			case '2':
			Deleteracer();
			case '3':
			Editracer();
			case '4':
			Viewracerlist();
		}
	}
void Addracer();
{

    for (int i = 0; i < 5; i++) {
        cout << "Please enter the name for racer : " << i << '\n'; 
        // сперва получим доступ к элементу массива, используя
        // обычный синтаксис для массивов, затем обратимся к полю структуры
        // с помощью точки
        cin >> bike[ i ].name;
        cout << "Please enter fam " <<  '\n';
        cin >> bike[ i ].fam;
		cout << "Please enter ots " << '\n';
        cin >> bike[ i ].ots;
		cout << "Please enter type of bike " << '\n';
        cin >> bike[ i ].typebike;
		cout << "Please enter the tic " << '\n';
        cin >> bike[ i ].tic;
    }
	
}
void Deleteracer();
{
	cout << "What delet"
}

void Editracer();
{
	cout << "What edit"
}
Viewracerlist();
{
	for (int i = 0; i < 5; ++i) {
        cout << players[ i ].name << " is at skill level " << players[i].skill_level << '\n';
}
	
	}

