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
	EDIT_BIKE_FIO = 1,
	EDIT_BIKE_TYPE,
	EDIT_BIKE_STAGE,
	EDIT_BACK
};

void __pause()
{
	cout << "Press any key...";
	cin.get();
	cin.ignore();
}

int main(int argc, char* argv[])
{
	DataBase data_base;
	unsigned int input = 0;
	
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
					string fio = "", type = "";
					int stage = 0;
					
					bool not_add = true;
					while (not_add) {
		
						if (fio.empty()) {
							cout << "Enter bike fio: ";
							cin >> fio;
						}
						
						if (type.empty()) {
							cout << "Enter bike type: ";
							cin >> type;
						}

						while (stage <= 0 or cin.fail()) {
							cout << "Enter bike type: ";
							cin >> type ;

							if (cin.good()) {
								
								if (stage < 0) {
									cerr << "Stage wasn't <= 0" << '\n';
								}

							} else if (cin.fail()) {
								cin.clear();
								cin.sync();
								cin.ignore(INT_MAX, '\n');
							}
						}

						if (!fio.empty() && !type.empty() && (stage > 0)) {
							data_base.add(
								new Bike(fio, type, stage)
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
						cerr << "Database is empty" << '\n';
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
								Bike *edit_bike_entry = data_base.edit(id);
								
								bool is_edit = true;
								while (is_edit) {
									string fio = "", type = "";
									int stage = 0;
									int edit_input = 0;

									data_base.view(id);
									cout << setfill('-') << setw(80) << '\n';
									cout << EDIT_BIKE_FIO << ". Change bike fio" << '\n';
									cout << EDIT_BIKE_TYPE <<   ". Change bike type" << '\n';
									cout << EDIT_BIKE_STAGE <<   ". Change bike stage" << '\n';
									cout << EDIT_BACK <<    ". Back" << '\n';

									cout << ">: ";
									cin >> edit_input;
									
									system("clear");
									if (cin.good()) {
										
										switch (edit_input) {
											case EDIT_BIKE_FIO: {
												
												do {
													
													cout << "Enter new bike fio: ";
													cin >> fio;
													
												} while (fio.empty());
												
												edit_bike_entry->setFio(fio);
												
											} break;
											case EDIT_BIKE_TYPE: {
												
												do {
													
													cout << "Enter new bike type: ";
													cin >> type;
													
												} while (type.empty());
												
												edit_bike_entry->setType(type);
												
											} break;
											case EDIT_BIKE_STAGE: {
												
												do {
													
													cout << "Enter new bike stage: ";
													cin >> stage;
													
													if (cin.good()) {
														
														if (stage < 0) {
															cout << "Stage wasn't <= 0" << '\n';
														}
														
													} else if (cin.fail()) {
														cin.clear();
														cin.sync();
														cin.ignore(INT_MAX, '\n');
													}
													
												} while (stage == 0 or cin.fail());
												
												edit_bike_entry->setStage(stage);
												
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

