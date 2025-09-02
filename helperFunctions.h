#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <string>
#include <fstream>

using namespace std;

void multilineboxedstring(const string& str1, const string& str2, const string& str3, const string& str4, const string& str5, const string& str6, const string& str7, const string& str8, const string& str9, const string& str10);

string getCurrentTime();

int generateUniqueID();

void welcome();

void stylishPrint(string text);

bool checkIfUsernameExists(string& u);

bool isPasswordValid(string& p);

ifstream openFile(string path);
#endif // HELPERFUNCTIONS_H