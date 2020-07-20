#include "TrackParser.h"

TrackParser::TrackParser()
{
    //ctor
}
/*
Vector
 Pos 0 = Title
 Pos 1 = Artist
*/
vector<string> TrackParser::parse(string anyString){
    vector<string> listOfArtTit;
    int pos = anyString.find(":");
    string title;
    string artist;
    if (pos!=-1)//separates the title and the artist, with the artist first
    {
        title = anyString.substr(pos+1);
        artist = anyString.substr(0, pos);
    } 
    else 
    {
        pos = anyString.find("-");
        if (pos!=-1)//First title and the artist
        {
            title = anyString.substr(0, pos);
            artist = anyString.substr(pos+1);
        }
        else
        {
            pos = anyString.find("–");
            if (pos!=-1)//First title and the artist
            {
                title = anyString.substr(0, pos);
                artist = anyString.substr(pos+3);
            }
            else
            {
                pos = anyString.find(" by ");
                if (pos!=-1)
                {
                    int posTemp = -1;
                    string temp = anyString;
                    int c = 0;
                    while (true)
                    {
                        pos = temp.find(" by ");
                        if (pos == -1)
                        {
                            pos = posTemp + c -1;
                            break;
                        }
                        else
                        {
                            c++;
                            posTemp = pos;
                            temp = temp.erase(pos, 1);
                            // cout << temp << " <-" << endl;
                        }
                    }
                    // cout << pos << endl;
                    // break;
                    if (pos!=-1)//the LAST occurrence of 'by' separates the title and the artist, with the title . first.
                    {
                        title = anyString.substr(0, pos);
                        artist = anyString.substr(pos+4);
                    }
                }
                else
                {
                    //Invalid Artis:Title
                    listOfArtTit.push_back("");
                    listOfArtTit.push_back("");
                    return listOfArtTit;
                }
            }
        }
    }
    // listOfArtTit.push_back("Ok");
    listOfArtTit.push_back(trim(title));//TrackParser::trim(title)
    listOfArtTit.push_back(trim(artist));
    return listOfArtTit;
}


string TrackParser::trim(string anyString){
    string retVal = anyString;
    int lastPos = retVal.length() -1;
    bool found = true;
    while(found == true && lastPos >= 0)
    {
        if(retVal.substr(lastPos, 1) == " ")
        {
            retVal = retVal.erase(lastPos, 1);
        }
        else if (retVal.substr(0, 1) == " ")
        {
            retVal = retVal.erase(0, 1);
        }
        else
        {
            found = false;
        }
        lastPos = retVal.length() -1;
    }
    return retVal;
}


TrackParser::~TrackParser()
{
    //dtor
}
