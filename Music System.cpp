#include <iostream>;
#include <string>;
#include <stdio.h>;
#include <stdlib.h>;
#include <limits>;
#include "Song_List.h"
#include "Play_list.h"
#include "Song_Playlist.h"
#include "windows.h"


using namespace std;



// defining the global variable out of the classes. 
int choice, choice1, id, idp;
int opt = -1;
string cont, cont1;
Song_List* selectedSong;

// function to make the user easy the choose
int getOption()
{
    int choice;
    do {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (cin.fail());

    return choice;
}

// Songlinkedlist class
class SongLinkedList {
public:
    Song_List* head;

    SongLinkedList() {
        head = NULL;
    }

    SongLinkedList(Song_List* s) {
        head = s;
    }

    //Check for song ID if it is duplicated or not.
    Song_List* songExists(int id) {
        Song_List* temp = NULL;
        Song_List* current = head;

        while (current != NULL)
        {
            if (current->songID == id)
            {
                temp = current;
            }
            current = current->next;
        }
        return temp;
    };

    //Check if there any existing Songs in Collection.
    bool isAnySongsExist() {
        bool SongsExist = false;
        Song_List* current = head;

        if (head != NULL)
        {
            SongsExist = true;
            return SongsExist;
        }
        else {
            return SongsExist;
        }
    }

    //Adding Song to the Collection.
    void addSong(Song_List* s) {
        int year = 0;
        int sec = 0;

        if (songExists(s->songID) != NULL) {
            cout << "Song ID 3" << s->songID << " already exists!" << endl;
        }
        else {
            if (head == NULL) {

                head = s;

                cout << "Enter Song Title: ";
                cin.ignore();
                getline(cin, s->songName);

                cout << "Enter Song Artist: ";
                getline(cin, s->songArtist);

                do {
                    cout << "Enter Song Released Year: ";
                    cin >> year;
                    if (year < 1000 || year > 2021) {
                        cout << "Please Enter Valid Year!\n";
                    }
                } while (year < 1000 || year > 2021);
                s->songYear = year;

                do {
                    cout << "Enter Song Duration (seconds): ";
                    cin >> sec;
                    if (sec < 1) {
                        cout << "Please Enter Valid Duration!\n";
                    }
                } while (sec < 1);
                s->songDuration = sec;

                cout << "Song added!" << endl;
            }
            else {
                Song_List* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = s;
                s->prev = current;

                cout << "Enter Song Title: ";
                cin.ignore();
                getline(cin, s->songName);

                cout << "Enter Song Artist: ";
                getline(cin, s->songArtist);

                do {
                    cout << "Enter Song Released Year: ";
                    cin >> year;
                    if (year < 1000 || year > 2021) {
                        cout << "Please Enter Valid Year!\n";
                    }
                } while (year < 1000 || year > 2021);
                s->songYear = year;

                do {
                    cout << "Enter Song Duration (seconds): ";
                    cin >> sec;
                    if (sec < 1) {
                        cout << "Please Enter Valid Duration!\n";
                    }
                } while (sec < 1);
                s->songDuration = sec;

                cout << "Song added!" << endl;
            }
        }
    };

    //Viewing songs to the collection
    void viewCollection() {

        Song_List* current = head;

        if (head == NULL)
        {
            cout << "Collection is Empty!, Add Songs to Enjoy! \n";
        }
        else {
            cout << "\n\t\t\t\t\t\t~~Song Collection~~";
            cout << ("\n\n");

            while (current != NULL)
            {
                cout << "Song ID: " << current->songID << "\t";
                cout << "Title: " << current->songName << "\t";
                cout << "Artist: " << current->songArtist << "\t";
                cout << "Year: " << current->songYear << "\t";
                cout << "Duration: " << current->songDuration << "s\n\n";

                current = current->next;
            }
        }
    };

    // Deleting Song from the Collection
    void deleteSong(Song_List* s) {

        if (s == NULL) {
            cout << "Song with ID " << s->songID << " does not exist!!" << endl;
        }
        else {

            if (head->songID == s->songID) {
                head = head->next;
                cout << "Song with ID " << s->songID << " succesfully deleted!" << endl;
            }
            else {
                Song_List* nextSong = s->next;
                Song_List* prevSong = s->prev;
                if (nextSong == NULL) {

                    prevSong->next = NULL;
                    cout << "Song with ID " << s->songID << " succesfully deleted!" << endl;
                }
                else {
                    prevSong->next = nextSong;
                    nextSong->prev = prevSong;
                    cout << "Song with ID " << s->songID << " succesfully deleted!" << endl;
                }
            }
        }

    }
};

// Playlinkedlist class
class PlaylistLinkedList {
public:
    Play_list* head;

    PlaylistLinkedList() {
        head = NULL;
    }

    PlaylistLinkedList(Play_list* p) {
        head = p;
    }

    //Checking if there any Playlist ID Duplicated.

    Play_list* plExists(int id) {
        Play_list* temp = NULL;
        Play_list* current = head;

        while (current != NULL)
        {
            if (current->playlist_ID == id)
            {
                temp = current;
            }
            current = current->next;
        }
        return temp;
    }

    //Checking if there are any existing Playlists 
    bool isAnyPlaylistExist() {
        bool PlaylistsExist = false;
        Play_list* current = head;

        if (head != NULL)
        {
            PlaylistsExist = true;
            return PlaylistsExist;
        }
        else {
            return PlaylistsExist;
        }
    }

    //Getting Selected the Playlist Name
    string getPlaylistName(int id) {
        string name;
        Play_list* current = head;

        while (current != NULL)
        {
            if (current->playlist_ID == id)
            {
                name = current->playlist_Name;
            }
            current = current->next;
        }
        return name;
    }

    //Creating new Playlist
    void addPlaylist(Play_list* p) {

        if (plExists(p->playlist_ID) != NULL) {
            cout << "Playlist ID " << p->playlist_ID << " already exists!" << endl;
        }
        else {
            if (head == NULL) {

                head = p;

                cout << "Enter Playlist Name: ";
                cin.ignore();
                getline(cin, p->playlist_Name);

                cout << "Playlist Created!" << endl;
            }
            else {
                Play_list* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = p;

                cout << "Enter Playlist Name: ";
                cin.ignore();
                getline(cin, p->playlist_Name);

                cout << "Playlist Created!" << endl;
            }
        }
    }

    //Viewing all existing and available Playlists
    void viewAllPlaylists() {

        Play_list* current = head;

        if (head == NULL)
        {
            cout << "Soory there is no available Playlist.\n";
        }
        else {
            cout << "\t\t\t\t\t\t$$$$$Playlists$$$$$";
            cout << ("\n\n");

            while (current != NULL)
            {
                cout << "Playlist ID: " << current->playlist_ID << "\t\t";
                cout << "Playlist Name: " << current->playlist_Name << "\n";

                current = current->next;
            }
        }
    }

    //Displaying Songs of a particular Playlist
    void displayPlaylistSongs(Play_list* p) {
        int i = 1;
        Play_list* current = head;
        Song_Playlist* currentSong;
        currentSong = p->playlistSongHead;

        if (currentSong == NULL) {

            cout << "They Playlist has no Songs.\n";
        }
        else {
            if (currentSong != NULL) {
                cout << "Songs: \n";
                while (currentSong != NULL) {
                    cout << "\t" << i << ". " << "Song ID: " << currentSong->currentSong->songID << "\tTitle: " << currentSong->currentSong->songName << "\n";
                    currentSong = currentSong->next;
                    i++;
                }
                current = current->next;
            }
        }
    }

    //Delete playlist
    void deletePlaylist(Play_list* p) {

        if (head == p) {
            head = head->next;
            cout << "Playlist with ID " << p->playlist_ID << " is succesfully deleted!" << endl;
        }
        else {
            Play_list* temp = NULL;
            Play_list* prevPL = head;
            Play_list* current = head->next;
            while (current != NULL) {
                if (current == p) {
                    temp = current;
                    current = NULL;
                }
                else {
                    prevPL = prevPL->next;
                    current = current->next;
                }
            }
            if (temp != NULL) {
                prevPL->next = temp->next;
                cout << "Playlist with ID " << p->playlist_ID << " is succesfully deleted!" << endl;
            }
            else {
                cout << "Playlist with ID " << p->playlist_ID << " does not exist to the library." << endl;
                cout << "Please Create new Playlist to add Songs" << endl;
            }
        }
    }
};


// SOng into the Playlist class.

class SongPlaylistLinkedList {
public:
    Song_Playlist* head;

    SongPlaylistLinkedList() {
        head = NULL;
    }

    SongPlaylistLinkedList(Song_Playlist* sp) {
        head = sp;
    }



    //Adding songs to a particular Playlist.

    void addSongtoPlaylist(Play_list* p, Song_Playlist* sp, Song_List* s) {
        Song_Playlist* temp = NULL;
        Song_Playlist* songPlaylist = p->playlistSongHead;

        while (songPlaylist != NULL) {
            if (songPlaylist->currentSong->songID == s->songID) {
                temp = songPlaylist;
            }
            songPlaylist = songPlaylist->next;
        }

        if (temp == NULL) {
            if (p->playlistSongHead == NULL) {
                p->playlistSongHead = sp;
                p->playlistSongHead->currentSong = s;
                cout << s->songName << " succesfully added to the Playlist with name : " << p->playlist_Name << " !" << endl;
            }
            else {
                Song_Playlist* inplaylistSong = p->playlistSongHead;
                while (inplaylistSong->next != NULL) {
                    inplaylistSong = inplaylistSong->next;
                }
                inplaylistSong->next = sp;
                sp->prev = inplaylistSong;
                sp->currentSong = s;
                cout << s->songName << " succesfully added to the Playlist with name :  " << p->playlist_Name << " !" << endl;
            }
        }
        else {
            cout << "Song with ID " << opt << " already exists in playlist" << endl;
        }
    }

    //Removing Song from a particular playlists.
    void removeSongfromPlaylist(Play_list* p, Song_Playlist* sp, Song_List* s) {
        Song_Playlist* temp = NULL;
        Song_Playlist* songPlaylist = p->playlistSongHead;

        while (songPlaylist != NULL) {
            if (songPlaylist->currentSong->songID == s->songID) {
                temp = songPlaylist;
            }
            songPlaylist = songPlaylist->next;
        }
        if (temp != NULL) {
            if (p->playlistSongHead->currentSong->songID == s->songID) {
                p->playlistSongHead = p->playlistSongHead->next;
                cout << s->songName << " succesfully removed from Playlist with name :  " << p->playlist_Name << " !" << endl;
            }
            else {
                Song_Playlist* nextSP = temp->next;
                Song_Playlist* prevSP = temp->prev;
                if (nextSP == NULL) {

                    prevSP->next = NULL;
                    cout << s->songName << " succesfully removed from Playlist with name :  " << p->playlist_Name << " !" << endl;
                }
                else {
                    prevSP->next = nextSP;
                    nextSP->prev = prevSP;
                    cout << s->songName << " succesfully removed from Playlist with name : " << p->playlist_Name << " !" << endl;
                }
            }
        }
        else {
            cout << "Song with ID " << opt << " does not exist into a particular playlist" << endl;
        }
    }

    //Navigatation of the Playlist
    void navigatePlaylist(Play_list* p) {
        int choice = 0;
        int choice1 = 0;
        Song_Playlist* current = p->playlistSongHead;
        Song_Playlist* headSP = p->playlistSongHead;
        Song_Playlist* nextSP = current->next;
        Song_Playlist* prevSP = current->prev;

        do {
            system("cls");
            cout << "\t\t\t\t@$$$$@Navigate Playlist@$$$$@\n\n";
            cout << "\t\t\tSelected Playlist: " << p->playlist_Name << "\n";
            cout << "----------------------------------------------------------------------------------------\n";
            if (current == headSP && nextSP == NULL) {
                cout << "\t\t\t\ Song: " << current->currentSong->songName << "\n\n\t\t\t\tArtist\t: " << current->currentSong->songArtist << "\n\n";
            }
            else if (current == headSP && nextSP != NULL) {
                cout << "\t\t\t\ Song: " << current->currentSong->songName << "\n\t\t\t\t\t\t\t\tNext Song: " << nextSP->currentSong->songName << "\n\t\t\t\tArtist: " << current->currentSong->songArtist << "\n\n";
            }
            else if (current == current && nextSP == NULL) {
                cout << "\t\t\t\ Song: " << current->currentSong->songName << "\nPrevious Song: " << prevSP->currentSong->songName << "\n\t\t\t\tArtist: " << current->currentSong->songArtist << "\n\n";
            }
            else if (current == current && nextSP == current->next && prevSP == current->prev) {
                cout << "\t\t\t\ Song: " << current->currentSong->songName << "\nPrevious Song: " << prevSP->currentSong->songName << " \t\t\t\t\t\tNext Song: " << nextSP->currentSong->songName << "\n\t\t\t\tArtist: " << current->currentSong->songArtist << "\n\n";
            }


            do {
                choice1 = 0;
                cout << "----------------------------------------------------------------------------------------\n";
                cout << "[1] Previous Song\t\t\t\t[2] Next Song\n\t\t\t\t\t\t[-1] Exit\n";
                cout << "Enter Option: ";
                cin >> choice1;

                if (choice1 == 1) {
                    if (current == headSP && (nextSP == NULL || prevSP == NULL)) {
                        cout << "No more songs in playlist!\n";
                    }
                    else if (current == headSP && nextSP != NULL && prevSP != NULL) {
                        prevSP = current;
                        current = nextSP;
                        nextSP = current->next;
                    }
                    else if (current == current && nextSP == NULL) {
                        nextSP = current;
                        current = prevSP;
                        prevSP = prevSP->prev;
                        choice1 = -1;
                    }
                    else if (current == current && nextSP == current->next && prevSP == current->prev) {
                        nextSP = current;
                        current = prevSP;
                        prevSP = current->prev;
                        choice1 = -1;
                    }
                }
                else if (choice1 == 2) {
                    if (current == headSP && nextSP == NULL) {
                        cout << "No more songs into playlist!\n";
                    }
                    else if (current == headSP && nextSP != NULL) {
                        prevSP = current;
                        current = nextSP;
                        nextSP = current->next;
                        choice1 = -1;
                    }
                    else if (current == current && nextSP == NULL) {
                        cout << " last song of playlist!\n";
                    }
                    else if (current == current && nextSP == current->next && prevSP == current->prev) {
                        prevSP = current;
                        current = nextSP;
                        nextSP = current->next;
                        choice1 = -1;
                    }
                }
                else if (choice1 == -1) {
                    choice = -1;
                }
                else {
                    cout << "Invalid Choice!\n";
                }
            } while (choice1 != -1);


        } while (choice != -1);
    }

};

int main() {

   
    
   

    system("cls");
    
    do {
        cout << "\t\t$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "\t\t			  MUSIC MANAGEMENT SYSTEM		\n";
        cout << "\t\t$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "\t\t\t\t\t@@@Main Menu@@@\n";
        cout << "\n";
        cout << "Please press [1] to see many features to enjoy the System. " << endl;
        cout << "\n";
        choice = getOption();
        switch (choice) {
        
        case 1:

            do {
                
                SongLinkedList sl;
                PlaylistLinkedList pl;
                SongPlaylistLinkedList slp;
                Song_Playlist* sp = new Song_Playlist();
                Play_list* p = new Play_list();
                Song_List* s = new Song_List();

                cout << "\t\t$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
                cout << ("$                                                                      $ \n");
                cout << " $\t\t			  MUSIC MANAGEMENT SYSTEM		                         $\n";
                cout << ("$                                                                      $ \n");
                cout << " $\t\t$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@@@@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
                cout << ("\n");
                cout << "\t\t\t\t\t@@@Main Menu@@@\n";
                cout << ("\n");
                cout << "\t\t[1] Add Song to Collection \t\t[3] Delete Song from Collection\n\t\t[2] View Song Collection\t\t[4] Playlist Contain Search\n";
                cout<<  "\t\t[5] Create New Playlist\t\t\t[9] Remove Songs from Playlist\n\t\t[6] View All Playlists\t\t\t[10] Playlist Navigation\n";
                cout << "\t\t[7] Add songs into existing Playlist\t[11] Delete Playlist\n\t\t[8] View Songs in Playlist\n\n";
                cout << "\t\t\t\t[0] Main Menu\n\n";
                cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
                cout << "\n";
                cout << "\t\tEnter a Number to see the see his Characteristics: ";

                choice = getOption();

                switch (choice)
                {
                case 1:
                    do {
                        cout << "Enter Song ID: ";
                        cin >> id;
                        if (id < 1) {
                            cout << "Please Enter Valid ID!\n";
                        }
                    } while (id < 1);
                    s->songID = id;
                    sl.addSong(s);
                    break;
                case 2:
                    sl.viewCollection();
                    break;
                case 3:
                    sl.viewCollection();

                    if (!sl.isAnySongsExist()) {
                        cout << "Collection is already empty!" << endl;
                        break;
                    }
                    else {
                        cout << "Please enter Song ID to delete: ";
                        cin >> id;

                        Play_list* currentPL = pl.head;

                        while (currentPL != NULL) {
                            Song_Playlist* currentSP = currentPL->playlistSongHead;
                            while (currentSP != NULL) {
                                if (currentSP->currentSong == sl.songExists(id)) {
                                    slp.removeSongfromPlaylist(currentPL, currentSP, sl.songExists(id));
                                }
                                currentSP = currentSP->next;
                            }
                            currentPL = currentPL->next;
                        }

                        sl.deleteSong(sl.songExists(id));

                    }

                    break;
                case 4:
                    do {
                        int count = 1;

                        sl.viewCollection();
                        if (sl.isAnySongsExist()) {
                            cout << "Select Song ID to search for playlists that contains this song: ";
                            cin >> id;
                            if (sl.songExists(id) == NULL) {
                                cout << "Song with ID" << id << " does not exist!\n";
                                break;
                            }
                            else {
                                Play_list* currentPL = pl.head;

                                while (currentPL != NULL) {
                                    Song_Playlist* currentSP = currentPL->playlistSongHead;
                                    while (currentSP != NULL) {
                                        if (currentSP->currentSong == sl.songExists(id)) {
                                            cout << count << ". " << currentPL->playlist_Name << "\n";
                                            count++;
                                        }
                                        currentSP = currentSP->next;
                                    }
                                    currentPL = currentPL->next;
                                }
                                if (count == 1) {
                                    cout << "No Playlists contains song with ID: " << id << endl;
                                }
                                break;
                            }
                        }
                        else {
                            break;
                        }


                    } while (opt != -1);
                    break;
                case 5:
                    do {
                        cout << "Enter Playlist ID: ";
                        cin >> id;
                        if (id < 1) {
                            cout << "Please Enter Valid ID!\n";
                        }
                    } while (id < 1);
                    p->playlist_ID = id;
                    pl.addPlaylist(p);
                    break;
                case 6:
                    pl.viewAllPlaylists();
                    break;
                case 7:
                    do {
                        pl.viewAllPlaylists();

                        if (pl.isAnyPlaylistExist()) {
                            cout << "Select Playlist ID to add songs: ";
                            cin >> idp;
                            p->playlist_ID = idp;
                            if (pl.plExists(p->playlist_ID) == NULL) {
                                cout << "Playlist ID " << p->playlist_ID << " does not exists!" << endl;
                            }
                            else {
                                system("cls");
                                cout << "\t\t\t\t~~Add Songs to Playlist~~\n";
                                cout << "Selected Playlist: " << pl.getPlaylistName(idp) << "\n\n";
                                pl.displayPlaylistSongs(pl.plExists(p->playlist_ID));
                                cout << "--------------------------------------------------------\n";

                                cout << "Available Songs\n";
                                sl.viewCollection();
                                cout << "--------------------------------------------------------\n";
                                cout << "Enter Song ID to add to " << pl.getPlaylistName(idp) << ", or -1 to exit: ";
                                cin >> opt;
                                if (opt != -1) {
                                    selectedSong = sl.songExists(opt);
                                    if (selectedSong == NULL) {
                                        cout << "Song with ID " << opt << " does not exist!!" << endl;
                                        break;
                                    }
                                    else {
                                        slp.addSongtoPlaylist(pl.plExists(p->playlist_ID), sp, selectedSong);
                                        break;
                                    }
                                }
                                else {
                                    cout << "Successfully Exited!\n";
                                    break;
                                }

                            }
                        }
                        else {
                            break;
                        }
                    } while (opt != -1);
                    break;
                case 8:
                    pl.viewAllPlaylists();
                    if (pl.isAnyPlaylistExist()) {
                        do {
                            cout << "Enter Playlist ID: ";
                            cin >> id;
                            if (pl.plExists(id) == NULL) {
                                cout << "Playlist with ID " << id << " does not exist!\n";
                                break;
                            }
                        } while (pl.plExists(id) == NULL);
                        pl.displayPlaylistSongs(pl.plExists(id));
                        break;
                    }
                    else {
                        break;
                    }

                case 9:
                    do {
                        pl.viewAllPlaylists();

                        if (pl.isAnyPlaylistExist()) {
                            cout << "Select Playlist ID to remove songs: ";
                            cin >> idp;
                            p->playlist_ID = idp;
                            if (pl.plExists(p->playlist_ID) == NULL) {
                                cout << "Playlist ID " << p->playlist_ID << " does not exists!" << endl;
                            }
                            else {
                                system("cls");
                                cout << "\t\t\t\t~~Remove Songs to Playlist~~\n";
                                cout << "Selected Playlist: " << pl.getPlaylistName(idp) << "\n\n";
                                pl.displayPlaylistSongs(pl.plExists(p->playlist_ID));
                                cout << "--------------------------------------------------------\n";
                                cout << "Enter Song ID to remove from " << pl.getPlaylistName(idp) << ", or -1 to exit: ";
                                cin >> opt;
                                if (opt != -1) {
                                    selectedSong = sl.songExists(opt);
                                    if (selectedSong == NULL) {
                                        cout << "Song with ID " << opt << " does not exist!!" << endl;
                                        break;
                                    }
                                    else {
                                        slp.removeSongfromPlaylist(pl.plExists(p->playlist_ID), sp, selectedSong);
                                        break;
                                    }
                                }
                                else {
                                    cout << "Successfully Exited!\n";
                                    break;
                                }

                            }
                        }
                        else {
                            break;
                        }
                    } while (opt != -1);
                    break;
                case 10:
                    do {
                        pl.viewAllPlaylists();

                        if (pl.isAnyPlaylistExist()) {
                            cout << "Select Playlist ID to navigate: ";
                            cin >> idp;
                            p->playlist_ID = idp;
                            if (pl.plExists(p->playlist_ID) == NULL) {
                                cout << "Playlist ID " << p->playlist_ID << " does not exists!" << endl;
                            }
                            else {
                                slp.navigatePlaylist(pl.plExists(p->playlist_ID));

                                cout << "Successfully Exited!\n";
                                break;
                            }
                        }
                        else {
                            cout << "No existing playlists!\n";
                            break;
                        }
                    } while (opt != -1);
                    break;
                case 11:
                    do {
                        pl.viewAllPlaylists();

                        if (pl.isAnyPlaylistExist()) {
                            cout << "Select Playlist ID to delete, or -1 to exit: ";
                            cin >> idp;
                            if (idp != -1) {
                                p->playlist_ID = idp;
                                if (pl.plExists(p->playlist_ID) == NULL) {
                                    cout << "Playlist ID " << p->playlist_ID << " does not exists!" << endl;
                                }
                                else {
                                    pl.deletePlaylist(pl.plExists(p->playlist_ID));
                                    break;
                                }
                            }
                            else {
                                cout << "Succesfully Exited!\n";
                                break;
                            }
                        }

                    } while (opt != -1);

                    break;


                case 99:
                    cout << "Are you sure you want to exit to Main Menu?\n";
                    break;
                default:
                    cout << "Invalid Choice!" << endl;
                }
                cout << "-------------------------------------------------------------------------------------\n";
                cout << "Enter \"Y\" to continue managing collection, or any other key to exit to Main Menu:  ";
                cin >> cont;
                system("cls");
            } while (cont == "y" || cont == "Y");
            break;
        
            system("cls");
            cout << "Invalid Choice! Please Key In Again!" << endl;
            break;
        }
    } while (choice != -1);

    return 0;
};

