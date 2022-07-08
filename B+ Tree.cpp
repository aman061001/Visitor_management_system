#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
//#include <filesystem>
#include "B+ Tree.h"

#define _CRT_SECURE_NO_DEPRECATE  //for VS 2019

void insertionMethod(BPTree** bPTree) {
    int age, salary, empno;
    string fname,lname, mobileno, department;
    cout << "Please provide the employee number to be inserted in the record: ";
    cin >> empno;
    cout << "\n\tFNAME:";
    cin >> fname;
    cout << "\tLNAME:";
    cin >> lname;
    cout << "\tAGE:";
    cin >> age;
    cout << "\tSALARY:";
    cin >> salary;
    cout << "\tMOBILE NO.:";
    cin >> mobileno;
    cout << "\tDEPARTMENT:";
    cin >> department;
    string fileName = "Visitor_record/";
    fileName += to_string(empno) + ".txt";
    FILE* filePtr = fopen(fileName.c_str(), "w");
    string userTuple = fname + " " +lname + " " + to_string(age) + " " + to_string(salary) + " " + department + " " + mobileno + " " + to_string(empno) + "\n";
    fprintf(filePtr, userTuple.c_str());
    (*bPTree)->insert(empno, filePtr);
    fclose(filePtr);
    cout << "Insertion of record for employee no: " << empno << " is successful" << endl;
}

void searchMethod(BPTree* bPTree) {
    int empno;
    cout << "Which employee want to search? ";
    cin >> empno;
    bPTree->search(empno);
}

void printMethod(BPTree* bPTree) {
    int opt;
    cout << "Press \n\t1.Hierarical-Display \n\t2.Sequential-Display\n";
    cin >> opt;

    cout << "\nHere is your File Structure" << endl;
    if (opt == 1)
        bPTree->display(bPTree->getRoot());
    else
        bPTree->seqDisplay(bPTree->getRoot());
}

void deleteMethod(BPTree* bPTree) {
    cout << "Showing you the Tree, Choose a key from here: " << endl;
    bPTree->display(bPTree->getRoot());
 
    int tmp;
    cout << "Enter a key to delete: " << endl;
    cin >> tmp;
    bPTree->removeKey(tmp);
    bPTree->display(bPTree->getRoot());
}

int main() {
    cout << "************************************************************************************************************************";
    cout << "\n\t\t\t\t\t***Teacher Record Management***"<< endl;
    cout << "************************************************************************************************************************";

    bool flag = true;
    int option;

    int maxChildInt = 4, maxNodeLeaf = 3;

    cout << "Please provide the value to limit maximum child Internal Nodes can have: ";
    cin >> maxChildInt;
    cout << "\nAnd Now Limit the value to limit maximum Nodes Leaf Nodes can have: ";
    cin >> maxNodeLeaf;

    BPTree* bPTree = new BPTree(maxChildInt, maxNodeLeaf);

    do {
        cout << "\nPlease provide the queries with respective keys : " << endl;
        cout << "\tPress 1: Insertion of new record \n\tPress 2: Search for any record \n\tPress 3: Print the tree based on the employee id\n\tPress 4: Delete record In Tree\n\tPress 5: Exit from the application" << endl;
        cin >> option;
        switch (option) {
            case 1:
                insertionMethod(&bPTree);
                break;
            case 2:
                searchMethod(bPTree);
                break;
            case 3:
                printMethod(bPTree);
                break;
            case 4:
                deleteMethod(bPTree);
                break;
            default:
                flag = false;
                break;
        }
    }while (flag);

    return 0;
}
