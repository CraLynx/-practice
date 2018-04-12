#include <iostream>
#include <iomanip>
#include <string>

#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <limits.h>

#include "db.cpp"
using namespace std;

enum INPUTS {
	ADD = 1,
	VIEW_DATA,
	EDIT_DATA,
	REMOVE,
	EXIT
};

enum EDIT_MENU_COMMANDS {
	EDIT_CAPTION = 1,
	EDIT_PRICE,
	EDIT_COUNT,
	EDIT_DATE,
	EDIT_BACK
};

void system(char *command)
{
	for (int i = 0; i < 25; i++) cout << endl;
}

void __pause()
{
	cout << "Press any key...";
	cin.get();
	cin.ignore();
}

int main()
{
	DataBase data_base;
	unsigned int input = 0;
	
	string s_date = "", e_date = "", b_station = "", e_station = "";
	
	system("clear");
	cout << "Welcome to DataBae" << '\n';
	cout << setfill('-') << setw(50) << '\n';

	bool is_input = true;
	while (is_input) {
	
		cout << "[" << ADD << "] -> Add" << '\n';
		cout << "[" << VIEW_DATA << "] -> View" << '\n';
		cout << "[" << EDIT_DATA << "] -> Edit" << '\n';
		cout << "[" << REMOVE << "] -> Remove" << '\n';
		cout << "[" << EXIT << "] -> Exit" << '\n';
	
		cout << ">: ";
		cin >> input;
	
	
		if (cin.good()) {
			system("clear");
			switch (input) {
				case ADD: {
					s_date = "", e_date = "", b_station = "", e_station = "";
					
					bool not_add = true;
					while (not_add) {
		
						if (s_date.empty()) {
							cout << "Enter start date: ";
							cin >> s_date;
						}

						if (e_date.empty()) {
							cout << "Enter end date: ";
							cin >> e_date;
						}
						
						if (b_station.empty()) {
							cout << "Enter begin station: ";
							cin >> b_station;
						}
						
						if (e_station.empty()) {
							cout << "Enter end station: ";
							cin >> e_station;
						}

						if (!s_date.empty() && !e_date.empty() && !b_station.empty() && !e_station.empty()) {
							data_base.add(
								new TrainPath(s_date, e_date, b_station, e_station)
							);
							not_add = false;
						} else {
							cerr << "Someone data is empty";
						}
					}
				} break;
				case VIEW_DATA: {

					if (data_base.count() > 0) {
						data_base.view();
					} else {
						cerr << "Databae is empty" << '\n';
					}

					__pause();
				} break;
				case EDIT_DATA: {
				
					if (data_base.count() > 0) {
						int id = 0;
						data_base.view();

						cout << "Enter entry ID: ";
						cin >> id;

						system("clear");
						if (cin.good()) {
							if (id > 0) {
								TrainPath *edit_train_entry = data_base.edit(id);
								
								bool is_edit = true;
								while (is_edit) {
									s_date = "", e_date = "", b_station = "", e_station = "";
									int edit_input = 0;

									data_base.view(id);
									cout << setfill('-') << setw(80) << '\n';
									cout << EDIT_CAPTION << ". Change start date" << '\n';
									cout << EDIT_PRICE <<   ". Change end date" << '\n';
									cout << EDIT_COUNT <<   ". Change start station" << '\n';
									cout << EDIT_DATE <<    ". Change end station" << '\n';
									cout << EDIT_BACK <<    ". Back" << '\n';

									cout << ">: ";
									cin >> edit_input;
									
									system("clear");
									if (cin.good()) {
										
										switch (edit_input) {
											case EDIT_CAPTION: {
												
												do {
													
													cout << "Enter new start date: ";
													cin >> s_date;
													
												} while (s_date.empty());
												
												edit_train_entry->setStartDate(s_date);
												
											} break;
											case EDIT_PRICE: {
												
												do {
													
													cout << "Enter new end date: ";
													cin >> e_date;
													
												} while (e_date.empty());
												
												edit_train_entry->setEndDate(e_date);
											} break;
											case EDIT_COUNT: {
												
												do {
													
													cout << "Enter end station: ";
													cin >> b_station;
													
												} while (b_station.empty());
												
												edit_train_entry->setBeginStation(b_station);
											} break;
											case EDIT_DATE: {
												
												do {
													
													cout << "Enter end station: ";
													cin >> e_station;
													
												} while (e_station.empty());
												
												edit_train_entry->setEndStation(e_station);
											} break;
											case EDIT_BACK: {
												is_edit = false;
											} break;
										}
										
									} else if (cin.fail()) {
										cin.clear();
										cin.sync();
										cin.ignore(INT_MAX, '\n');
									}
									
									system("clear");
								}
																
							} else {
								cerr << "ID wasn't be <= 0" << '\n';
								__pause();
							}
						} else {
							cerr << "Incorrect input" << '\n';
							cin.clear();
							cin.sync();
							__pause();
						}
					} else {
						cerr << "Database is empty" << '\n';
						__pause();
					}

				} break;
				case REMOVE: {
					if (data_base.count() > 0) {
						int id = 0;
				
						data_base.view();
						cout << "Enter entry ID: ";
						cin >> id;

						if (cin.good()) {
							if (id > 0) {
								data_base.remove(id);
							} else {
								cerr << "ID wasn't be <= 0" << '\n';
								__pause();
							}
						} else {
							cerr << "Incorrect input" << '\n';
							cin.clear();
							cin.sync();
							__pause();
						}

					} else {
						cerr << "Database is empty" << '\n';
					}

					__pause();
				} break;
				case EXIT: {
					is_input = false;
				} break;
			}
		} else {
			cerr << "Incorrect input" << '\n';
			cin.clear();
			cin.sync();
			__pause();
		}
		system("clear");
		
	}

}
