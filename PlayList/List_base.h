#ifndef LIST_BASE_H
#define LIST_BASE_H

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class List_base
{
    public:
        List_base();
        virtual ~List_base();

    protected:
        void clear();
        void pressEnterToContinue();
        vector<string> readFile(string fileName);
        void saveFile(string fileName, vector<string> listOfData);
        void printVector(vector<string> listOfData);
        void printVector(string title, vector<string> listOfData);
        void printVector(string title, vector<string> listOfData, bool showMessage);
        bool isDuplicated(string newName, vector<string> listOfData);
        bool isAValidString(string newName);
        bool is_number(const std::string& s);
        string getVectorElement(int pos, vector<string> listOfData);
        vector<string> makeResponse(string value, string errMsg);
    private:
};

#endif // LIST_BASE_H
