#include "Playlist.h"

Playlist::Playlist()
{
    //ctor
}

Playlist::Playlist(string fileName)
{
    this->fileName = fileName + ".playlist";
}

char Playlist::getTrack()
{
    int pos;
    vector<string> listOfArtTit;
    string fullName;
    cin.ignore();
    clear();
    cout << "Create a track" << endl;
    cout << "  Enter a track or ‘q’ to quit: " << endl;
    getline(cin, fullName);
    if (!fullName.compare("q"))
        return 'b';//break;
    if (fullName.length() < 6)
    {
        cout << "Please enter a track with more than five characters." << endl;
        // cout << "fullName length = " << fullName.length() << endl;
        return 'c';//continue;
    }
    listOfArtTit = TrackParser::parse(fullName);
    string title = *listOfArtTit.begin();
    string artist = *(++listOfArtTit.begin());

            cout << "TITLE: " << title << endl;
            cout << "AUTHOR: " << artist << endl;
            cout << endl;
            pressEnterToContinue();

    return 'o'; //Ok
}

int Playlist::mainPage()
{
    return mainPage("");
}

int Playlist::mainPage(string fileName)
{
    if (fileName!="")
        this->fileName = fileName + ".playlist";
    this->listOfTracks = readFile(this->fileName);
    vector<string> response;
    this->delPlayList = false;
    string msg = "";
    clear();
    while(true){
        string resp = showMenu(msg);
        msg = "Invalid choice. Please try again.";
        if (!is_number(resp))
        {
            if (resp=="x")
            {
                break;
            }
            if (resp=="a")
            {
                response = createTrack();
                msg = *(++response.begin());
            }
            if (resp=="d")
            {
                this->delPlayList = true;
                break;
            }
        } 
        else
        {
            if (resp.length()<4)
            {
                response = getTrackbyNumber(resp);
                string track = *response.begin();
                msg = *(++response.begin());
                if (msg=="")
                {
                    // cout << "epa";
                    // pressEnterToContinue();
                    while(true){
                        string rsp = showTrackMenu(track, msg);
                        // char rsp = showTrackMenu(track, msg);
                        msg = "Invalid choice. Please try again.";
                        if (rsp=="x")
                        {
                            break;
                        }
                        if (rsp=="d")
                        {
                            delElement(std::stoi(resp));
                            msg = "TrackName '"+ track +"' Deleted.";
                            break;
                        }
                    }
                }
            }
            else
            {
                msg = "Invalid Number, too long to process...";
            }
        } 
    }
    return 0;
}

string Playlist::showMenu()
{
    return showMenu("");
}

string Playlist::showMenu(string msg)
{
    string opc;
    clear();
    if (msg!="")
        cout << msg << endl << endl;    
    cout << "Playlist '" << this->fileName.substr(0, this->fileName.find(".playlist")) << "' Menu:" << endl << endl;    
    cout << "a. Add track(s) to the playlist." << endl;
    cout << "d. Delete this playlist." << endl;
    cout << "x. Exit to main menu." << endl << endl;
    printVector("Select Playlist #", this->listOfTracks);
    cout << "Your choice: ";
    // cin >> opc;
    getline(cin, opc);
    // cout << "typed = " << opc << endl; pressEnterToContinue();
    return opc;
}

// char Playlist::showTrackMenu(string track, string msg)
string Playlist::showTrackMenu(string track, string msg)
{
    // char opc;
    string opc;
    clear();
    if (msg!="")
        cout << msg << endl << endl;    
    cout << "Playlist '" << this->fileName.substr(0, this->fileName.find(".playlist")) << "'" << endl << endl;
    cout << "Track '" << track << "' Menu:" << endl << endl;
    cout << "d. Delete this playlist." << endl;
    cout << "x. Exit to main menu." << endl << endl;
    cout << "Your choice: ";
    getline(cin, opc);
    // cin >> opc;
    return opc;
}

vector<string> Playlist::createTrack()
{
    string track;
    // cin.ignore();
    cout << endl << endl;
    cout << "Enter a title and artist, or 'x' to exit." << endl;
    getline(cin, track);

    if (track=="")
    {
        return makeResponse("", "No text entered. Please try again.");
    }
    if (track=="x")
    {
        return makeResponse("Exit", "");
    }
    if (track.length()<6)
    {
        return makeResponse("", "Please enter a track with more than five characters. Please try again.");
    }
    // if (!isAValidString(track))
    //     return makeResponse("", "Invalid Track Name.");
    vector<string> listOfTrack = TrackParser::parse(track);
    string title = *listOfTrack.begin();
    string artist = *(++listOfTrack.begin());
    if (title=="" || artist=="")
    {
        // cout << "...0...";
        // pressEnterToContinue();
        return makeResponse("", "Unrecognized format. Please try again.");//Sorry Track Name is invalid, please try again.
    }
    else
    {
        track = artist + " : " + title;
    }
    if (!isDuplicated(track, this->listOfTracks))
    {
        addElement(track);
    } else {
        return makeResponse("", "That track already exists. Please try again.");//Sorry. That Track Name already exists. Please try again.
    }
    return makeResponse("Track Added.", "");
}

bool Playlist::isDelPlayList()
{
    return this->delPlayList;
}

/*void Playlist::setDelPlayList(bool val)
{
    this->delPlayList = val;
}*/

/*
Output Vector
 Pos 0 = elemnt value
 Pos 1 = Error Message
*/
vector<string> Playlist::getTrackbyNumber(string strpos)
{
    int pos = std::stoi(strpos);//Convert from String to Int
    string value = getVectorElement(pos, this->listOfTracks);
    return makeResponse(getVectorElement(pos, this->listOfTracks), "Invalid Track number. Please try again.");//Playlist number not found.
}


void Playlist::addElement(string track)
{
    this->listOfTracks.push_back(track);
    sort(this->listOfTracks.begin(), this->listOfTracks.end());// sortVector....
    saveFile(this->fileName, this->listOfTracks);
}

void Playlist::delElement(int pos)
{
    this->listOfTracks.erase(this->listOfTracks.begin() + pos -1);
    sort(this->listOfTracks.begin(), this->listOfTracks.end());// sortVector....
    saveFile(this->fileName, this->listOfTracks);
}

Playlist::~Playlist()
{
    //dtor
}
