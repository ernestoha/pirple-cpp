#include "PlayListParser.h"

PlayListParser::PlayListParser()
{
    //ctor
}

/*
Vector
 Pos 0 = PlayList
 Pos 1 = Err Msg
*/
vector<string> PlayListParser::parse(string anyString){
    vector<string> listOfPlayList;
    anyString = trim(anyString);
    for (int i = 0; anyString[i] != '\0'; i++)
    {
        if (!isalnum(anyString[i]))
        {
            listOfPlayList.push_back("");
            listOfPlayList.push_back("Invalid PlayList Name.");
            return listOfPlayList;
        }
    }
    listOfPlayList.push_back(anyString);//PlayListParser::trim(title)
    listOfPlayList.push_back("");
    return listOfPlayList;
}

string PlayListParser::trim(string anyString){
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

PlayListParser::~PlayListParser()
{
    //dtor
}
