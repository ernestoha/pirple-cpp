#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <algorithm>
#include "List_base.h"
#include "TrackParser.h"

using namespace std;

//manage the menus and storage for each file containing tracks for an individual playlist
class Playlist : public List_base
{
    public:
        Playlist();
        Playlist(string fileName);
        int mainPage();
        int mainPage(string fileName);
        virtual ~Playlist();
        bool isDelPlayList();
        // void setDelPlayList(bool val);
    protected:

    private:
        string fileName;
        bool delPlayList;

        vector<string> listOfTracks;
        vector<string> getTrackbyNumber(string strpos);

        void addElement(string track);
        void delElement(int pos);
        string showMenu();
        string showMenu(string msg);
        string showTrackMenu(string track, string msg);
        vector<string> createTrack();
        char getTrack();
};

#endif // PLAYLIST_H
