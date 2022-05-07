#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>;
#include <string>;
#include <iostream>;
#include <string>;
#include "Song_List.h"
#include "Song_Playlist.h"

using namespace std;

// Playlist h file including the class

class Play_list {
public:
	int playlist_ID;
	string playlist_Name;
	Play_list* next;
	Song_Playlist* playlistSongHead;

	// Constructor to use it another class


	class Play_list() {
		playlist_ID = 0;
		playlist_Name = "";
		next = NULL;
		playlistSongHead = NULL;
	}
};



#endif