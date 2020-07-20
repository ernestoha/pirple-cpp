#ifndef TRACKPARSER_H
#define TRACKPARSER_H

#include <vector>
#include <string>

using namespace std;

class TrackParser
{
    public:
        TrackParser();
        static vector<string> parse(string anyString);
        virtual ~TrackParser();
    protected:

    private:
        static string trim(string anyString);
};

#endif // TRACKPARSER_H
