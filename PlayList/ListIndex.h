#ifndef LISTINDEX_H
#define LISTINDEX_H

#include <string>
#include <vector>
#include <algorithm>
#include "List_base.h"
#include "Playlist.h"
#include "PlayListParser.h"

using namespace std;

//manage the menus and storage for a file that contains the name of all playlists.
class ListIndex : public List_base
{
    public:
        ListIndex();
        int mainPage();
        virtual ~ListIndex();

    protected:

    private:
        static const string fileName;
        void addElement(string playlist);
        void delElement(int pos);
        string showMenu(string msg);
        vector<string> listOfPlayList;
        vector<string> getPlayListbyNumber(string strpos);
        vector<string> createPlayList();
};

#endif // LISTINDEX_H
