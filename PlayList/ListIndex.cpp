#include "ListIndex.h"

const string ListIndex::fileName = "index.txt";

ListIndex::ListIndex()
{
    //ctor
}

int ListIndex::mainPage()
{
    this->listOfPlayList = readFile(this->fileName);
    Playlist pl;
    vector<string> response;
    string msg = "";
    clear();
    while(true){
        string resp = showMenu(msg);
        msg = "";
        if (!is_number(resp))
        {
            if (resp=="x")
            {
                cout << "Farewell" << endl;
                break;
            }
            if (resp=="c")
            {
                // resp = pl.getTrack();
                response = createPlayList();
                msg = *(++response.begin());
                // if (resp=='b')
                //     continue;// break;
                // if (resp=='c'){
                //     pressEnterToContinue();
                //     continue;
                // }
            }
        } 
        else
        {
            if (resp.length()<4)
            {
                response = getPlayListbyNumber(resp);
                string track = *response.begin();
                msg = *(++response.begin());
                if (msg=="")
                {
                    // Playlist pl(track);
                    // pl.showMenu();
                    pl.mainPage(track);
                    if (pl.isDelPlayList()==true)
                    {
                        // this->listOfPlayList.push_back(playlist);
                        delElement(std::stoi(resp));
                        msg = "Playlist '"+ track +"' Deleted.";
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

string ListIndex::showMenu(string msg)
{
    string opc;
    clear();
    if (msg!="")
        cout << msg << endl << endl;    
    cout << "Main Menu" << endl << endl;
    cout << "c. Create a playlist" << endl;
    cout << "x. Exit the program" << endl << endl;
    printVector("Select Playlist #", this->listOfPlayList);
    cout << "Your choice: ";
    // cin >> opc;
    getline(cin, opc);
    // cout << "typed = " << opc << endl; pressEnterToContinue();
    return opc;
}

vector<string> ListIndex::createPlayList()
{
    string playlist;
    // cin.ignore();
    cout << endl << endl;
    cout << "Please enter a name for your new playlist" << endl;
    getline(cin, playlist);
    // if (!isAValidString(playlist))
    //     return makeResponse("", "Invalid Name.");
    vector<string> listOfPlayList = PlayListParser::parse(playlist);
    playlist = *listOfPlayList.begin();
    if ((*(++listOfPlayList.begin()))!="")
    {
        return listOfPlayList;
    }
    if (!isDuplicated(playlist, this->listOfPlayList))
    {
        addElement(playlist);
    } else {
        return makeResponse("", "Sorry. That Playlist already exists. Please try again.");
    }
    return makeResponse(playlist, "");
}

/*
Output Vector
 Pos 0 = elemnt value
 Pos 1 = Error Message
*/
vector<string> ListIndex::getPlayListbyNumber(string strpos)
{
    int pos = std::stoi(strpos);//Convert from String to Int
    string value = getVectorElement(pos, this->listOfPlayList);
    return makeResponse(getVectorElement(pos, this->listOfPlayList), "Invalid Play List number. Please try again.");//Playlist number not found.
    // resp.push_back(value);
    // resp.push_back((value=="") ? "Playlist number not found." : "");
    // return resp;
}

void ListIndex::addElement(string playlist)
{
    this->listOfPlayList.push_back(playlist);
    sort(this->listOfPlayList.begin(), this->listOfPlayList.end());// sortVector....
    saveFile(this->fileName, this->listOfPlayList);
}

void ListIndex::delElement(int pos)
{
    this->listOfPlayList.erase(this->listOfPlayList.begin() + pos -1);
    sort(this->listOfPlayList.begin(), this->listOfPlayList.end());// sortVector....
    saveFile(this->fileName, this->listOfPlayList);
}

ListIndex::~ListIndex()
{
    //dtor
}
