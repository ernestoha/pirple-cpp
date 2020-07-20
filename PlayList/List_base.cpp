#include "List_base.h"

List_base::List_base()
{
    //ctor
}

void List_base::clear()
{
    // _WIN32 = Both 32 bit and 64 bit
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}

void List_base::pressEnterToContinue()
{
    cout << "Press Enter to Continue";
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

vector<string> List_base::readFile(string fileName)
{
    vector<string> data;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {
            data.push_back(line);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
    return data;
}

void List_base::saveFile(string fileName, vector<string> listOfData)
{
    ofstream myfile;
    // myfile.open(fileName, ios_base::app); //Append
    myfile.open(fileName, ios_base::trunc); //ReWrite
    vector<string>::iterator itName = listOfData.begin();
    while (itName != listOfData.end())
    {
        myfile << *itName << endl;
        itName++;
    }
    myfile.close();
}

void List_base::printVector(vector<string> listOfData)
{
    printVector("", listOfData, false);
}

void List_base::printVector(string title, vector<string> listOfData)
{
    printVector(title, listOfData, false);
}

void List_base::printVector(string title, vector<string> listOfData, bool showMessage)
{
    if (listOfData.size() > 0)
    {
        if (title!="")
            cout << title << endl << endl;
        vector<string>::iterator itName = listOfData.begin();
        while (itName != listOfData.end())
        {
            cout << (std::distance(listOfData.begin(), itName)+1) << " - " << *itName << endl;
            itName++;
        }
        cout << endl;
    }
    else
    {
        if (showMessage==true)
            cout << "No Data Found." << endl << endl;
    }
}

bool List_base::isDuplicated(string newName, vector<string> listOfData)
{
    bool exist = false;
    if (listOfData.size() > 0)
    {
        vector<string>::iterator itName = listOfData.begin();
        while (itName != listOfData.end())
        {
            if (newName == *itName)
            {
                exist = true;
                break;
            }
            itName++;
        }
    }
    return exist;
}

bool List_base::isAValidString(string newName)
{
    bool isOk = true;
    if (newName=="")
        isOk = false;
    // if (!isOk){
    //     cout << "Information is not valid." << endl;
    //     pressEnterToContinue();
    // }
    return isOk;
}

bool List_base::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string List_base::getVectorElement(int pos, vector<string> listOfData)
{
    if (pos<=listOfData.size())
    {
        string &element = listOfData[pos-1];
        return element;
    } else {
        return "";
    }   
}

vector<string> List_base::makeResponse(string value, string errMsg)
{
    vector<string> resp;
    resp.push_back(value);
    resp.push_back((value=="") ? errMsg : "");
    return resp;
}

List_base::~List_base()
{
    //dtor
}
