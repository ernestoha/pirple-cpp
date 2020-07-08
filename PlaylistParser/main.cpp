#include <iostream>
#include <string.h>

using namespace std;

string trim(string anyString)
{
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

int main()
{
    int pos;
    string fullName;
    string title;
    string artist;
    while(true){
        cout << "Enter a track or ‘q’ to quit: " << endl;
        getline(cin, fullName);
        
        if (!fullName.compare("q"))
            break;
        if (fullName.length() < 6)
        {
            cout << "Please enter a track with more than five characters." << endl;
            // cout << "fullName length = " << fullName.length() << endl;
            continue;
        }
        pos = fullName.find(":");
        if (pos!=-1)//separates the title and the artist, with the artist first
        {
            title = fullName.substr(pos+1);
            artist = fullName.substr(0, pos);
        } 
        else 
        {
            pos = fullName.find("-");
            if (pos!=-1)//First title and the artist
            {
                title = fullName.substr(0, pos);
                artist = fullName.substr(pos+1);
            }
            else
            {
                pos = fullName.find("–");
                if (pos!=-1)//First title and the artist
                {
                    title = fullName.substr(0, pos);
                    artist = fullName.substr(pos+3);
                }
                else
                {
                    // pos = fullName.find(" by ");
                    int posTemp = -1;
                    string temp = fullName;
                    bool found = true;
                    int c = 0;
                    while (found == true)
                    {
                        pos = temp.find(" by ");
                        if (pos == -1)
                        {
                            pos = posTemp + c -1;
                            found = false;
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
                        title = fullName.substr(0, pos);
                        artist = fullName.substr(pos+4);
                    }
                }
            }
        }
        title = trim(title);
        artist = trim(artist);
        cout << "TITLE: " << title << endl;
        cout << "AUTHOR: " << artist << endl;
        cout << endl;
    }
    return 0;
}
/*
    Sail on By - The Spinnakers
    Abby Lane - the Stinkbugs
    Abby Lane – the Stinkbugs
    The BFD and Fiddy Pence: We Rap by Sunlight
    Shooby Dooby by The Wooby Sis by   epa ters
*/