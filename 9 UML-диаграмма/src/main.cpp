#include <iostream>
#include <iomanip>
#include <vector>
#include "Music.h"
#include "Song.h"
using namespace std;

int main()
{
    vector<Music*> musics;
    string caption = "", compositor = "";

    int input = -1;
    int sub_input = -1;

    do {
        cout << "[1] => Add music"           << '\n';
        cout << "[2] => View all musics"     << '\n';
        cout << "[3] => View musics with A*" << '\n';
        cout << "[0] => Exit"                  << '\n';
        cout << '\n' << ":>";
        cin >> input;

        if (cin.good()) {

            system("cls");
            switch (input) {
                case 1: {

                    cout << "Enter caption: ";
                    cin >> caption;
                    cout << "Enter compositor: ";
                    cin >> compositor;

                    cout << "Choose music type for create: " << '\n';
                    cout << "[1] => Regular music"           << '\n';
                    cout << "[2] => Poem music"              << '\n';
                    cout << "[0] => Back"                    << '\n';
                    cin >> sub_input;

                    do {

                        if (cin.good()) {

                            switch (sub_input) {
                                case 1: {

                                    musics.push_back(
                                        new Music(caption, compositor)
                                    );

                                } break;
                                case 2: {
                                    string poem = "";
                                    cout << "Enter poem author: ";
                                    cin >> poem;

                                    musics.push_back(
                                        new Song(caption, compositor, poem)
                                    );
                                } break;
                            }

                            sub_input = 0;
                        }  else if (cin.fail()) {
                            cin.clear();
                            cin.sync();
                            sub_input = -1;
                        } else if (cin.bad()) {
                            cerr << "Fatal error. Standard input stream is broken" << '\n';
                        }

                    } while (sub_input != 0);

                    system("cls");
                } break;
                case 2: {
                    if (!musics.empty()) {
                        unsigned int number = 0;
                        for (Music *i : musics) {
                            if (i != nullptr) {
                                cout << "Music ¹" << number << '\n';
                                i->show();
                                cout << setfill('-') << setw(50) << '\n';
                            } else {
                                cerr << "Pointer ¹" << number << " in [musics] array  is null" << '\n';
                            }
                            number++;
                        }
                    } else {
                        cout << "musics not found" << '\n';
                    }
                    system("pause");
                } break;
                case 3: {
                    if (!musics.empty()) {

                        unsigned int number = 0;
                        for (Music *i : musics) {
                            if (i != nullptr) {
                                if (i->getCaption()[0] == 'A' || i->getCaption()[0] == 'a') {
                                    cout << "Music ¹" << number << '\n';
                                    i->show();
                                    cout << setfill('-') << setw(50) << '\n';
                                }
                            } else {
                                cerr << "Pointer ¹" << number << " in [musics] array  is null" << '\n';
                            }
                            number++;
                        }

                    } else {
                        cout << "musics not found" << '\n';
                    }
                    system("pause");
                } break;
            }

        } else if (cin.fail()) {
            cin.clear();
            cin.sync();
            input = -1;
        } else if (cin.bad()) {
            cerr << "Fatal error. Standard input stream is broken" << '\n';
        }

        system("cls");
    } while(input != 0);

    try
    {
        if (!musics.empty()) {
            unsigned int number = 0;
            for (Music *i : musics) {
                if (i != nullptr) {
                    delete i;
                } else {
                    cerr << "Pointer ¹" << number << " in [musics] array  is null" << '\n';
                }
                number++;
            }
        }
    } catch (out_of_range &e) {
        cerr << e.what() << '\n';
    }

}
