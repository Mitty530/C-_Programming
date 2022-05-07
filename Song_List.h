#ifndef SONG_H
#define SONG_H
#include <iostream>;
#include <string>;

using namespace std;


// Song h file including the class

class Song_List {
public:
	int songID, songYear, songDuration;
	string songName, songArtist;
	Song_List* next;
	Song_List* prev;

	// Constructor to use it another class


	class Song_List() {
		songID = 0;
		songName = "";
		songArtist = "";
		songYear = 0;
		songDuration = 0;
		next = NULL;
		prev = NULL;
	}
};



#endif