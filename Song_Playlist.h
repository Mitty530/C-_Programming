#ifndef SONGPLAYLIST_H
#define SONGPLAYLIST_H
#include "Song_List.h"

using namespace std;

// Song into to the playlist h file including the class
class Song_Playlist {
public:
	Song_List* currentSong;
	Song_Playlist* next;
	Song_Playlist* prev;
	// Constructor to use it another class
	class Song_Playlist() {
		currentSong = NULL;
		next = NULL;
		prev = NULL;
	}
};

#endif