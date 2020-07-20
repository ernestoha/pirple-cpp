#ifndef PLAYLISTPARSER_H
#define PLAYLISTPARSER_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PlayListParser
{
    public:
        PlayListParser();
        static vector<string> parse(string anyString);
        virtual ~PlayListParser();

    protected:

    private:
        static string trim(string anyString);
};

#endif // PLAYLISTPARSER_H
