//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Song.h
//  @ Date : 09.04.18
//  @ Author :
//
//


#if !defined(_SONG_H)
#define _SONG_H

#include "Music.h"

class Song : public Music
{
public:
    Song(string caption, string compositor, string poem);
    string getPoem();
    void show();

private:
    string poem;
};

#endif  //_SONG_H
