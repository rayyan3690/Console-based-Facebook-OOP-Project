#define _CRT_SECURE_NO_WARNINGS

#include "class.h"
#include "helperFunctions.h"

#include <iostream>
#include <iomanip>
#include <ctime> //for time() and ctime()
#include <fstream>
#include <cstdlib> //for rand and srand
#include <Windows.h>
#undef max

using namespace std;

Profile::Profile() : name("Some FaceBook User"), password("nothing"), dateOfBirth("not born yet"), aboutMe("Hey ther! I am Using FaceBook"), ID(generateUniqueID()) {}

void Profile::setName(string pname) {
	name = pname;
}

void Profile::setPassword(string pass) {
	password = pass;
}

void Profile::setDOB(string a) {
	dateOfBirth = a;
}

void Profile::setAboutMe(string b) {
	aboutMe = b;
}

string Profile::getName() {
	return name;
}

string Profile::getPassword() {
	return password;
}

string Profile::getAboutMe() {
	return aboutMe;
}

string Profile::getDOB() {
	return dateOfBirth;
}

Settings::Settings() : userPointerForSettings(nullptr) {}

Settings::Settings(User& u) : userPointerForSettings(&u) {}

void Settings::setPersonalInfo() {
personalSettings:
	system("cls");
	cout << endl;
	int choiceOfPersonalSettings;
	multilineboxedstring("_________________Personal_Settings_________________", " ", "1. Change Password", "", "2. Change Date of Birth", "3. Change \"About Me\"", "", "4. Exit to Settings Menu", "", "");
	cout << endl << "Enter Your choice here: ";
	cin >> choiceOfPersonalSettings;
	cin.ignore();

	//validating input_________________________________________________________________
	while (cin.fail() || !(choiceOfPersonalSettings <= 2 && choiceOfPersonalSettings >= 1)) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> choiceOfPersonalSettings;
	}

	switch (choiceOfPersonalSettings) {
	case 1:
	{
	changePassword:
		system("cls");
		cout << "Enter the new password: ";
		string p;
		getline(cin, p);
		if (!(isPasswordValid(p))) {
			cout << "Your Password isn't valid.";
			goto changePassword;
		}
		userPointerForSettings->setPassword(p);
		cout << "\n\nPassword changed Successfully\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Enter the new Date Of Birth (dd-mm-yyyy): ";
		string p;
		getline(cin, p);
		userPointerForSettings->setDOB(p);
		cout << "\n\nChanged Successfully\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		break;
	}
	case 3:
	{
		system("cls");
		cout << "Enter the new About Me: ";
		string p;
		getline(cin, p);
		userPointerForSettings->setAboutMe(p);
		cout << "\n\nChanged Successfully\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		break;
	}
	case 4:
		break;
	}
}

void Settings::themeSettings() {
	HANDLE consoleColour = GetStdHandle(STD_OUTPUT_HANDLE);
themeMenu:
	system("cls");
	multilineboxedstring("_________________Theme_Settings_________________", " ", "1. Hacker Feel", "2. Sunset", "3. Winter Night", "4. Ocean", "5. Neon", " ", "6. Back To Main Settings Menu", "");
	cout << endl << "Enter Your choice here: ";
	int choiceOfTheme;
	cin >> choiceOfTheme;

	//validating input_________________________________________________________________
	while (!((choiceOfTheme <= 6) && (choiceOfTheme >= 1)) || !cin) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> choiceOfTheme;
	}

	switch (choiceOfTheme) {
	case 1:
		SetConsoleTextAttribute(consoleColour, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case 2:
		SetConsoleTextAttribute(consoleColour, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY);
		break;
	case 3:
		SetConsoleTextAttribute(consoleColour, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	case 4:
		SetConsoleTextAttribute(consoleColour, FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
		break;
	case 5:
		SetConsoleTextAttribute(consoleColour, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
		break;
	case 6:
		break;
	}
}

Settings::~Settings() {
	delete userPointerForSettings;
}

void User::createPost_ByUser() {
	if (!post) {
		post = new Post(*this);
	}
	post->createPost();
}

void User::displayFeed_ByUser() {
	if (!post) {
		post = new Post(*this);
	}
	post->displayFeed();
}

void User::reactToPost_ByUser() {
	if (!reaction) {
		reaction = new Reactions(*this);
	}
	reaction->react();
}

void User::commentToPost_ByUser() {
	if (!comment) {
		comment = new Comments(*this);
	}
	comment->comment();
}

void User::viewComments() {
	if (!comment) {
		comment = new Comments(*this);
	}
	comment->displayComments();
}

void User::viewReactions() {
	if (!reaction) {
		reaction = new Reactions(*this);
	}
	reaction->displayReactions();
}

void User::personalSettings_ByUser() {
	if (!settings) {
		settings = new Settings(*this);
	}
	settings->setPersonalInfo();
}

void User::themeSettings_ByUser() {
	if (!settings) {
		settings = new Settings(*this);
	}
	settings->themeSettings();
}

void User::Register() {
	system("cls");
	multilineboxedstring("Note that usernames are unique and cannot be changed afterwards", "", "", "", "", "", "", "", "", "");

setNameOnSignup:
	cout << "\nEnter the new Username: ";
	string p;
	cin.ignore();
	getline(cin, p);
	if (checkIfUsernameExists(p)) {
		cout << "This username is taken already." << endl;
		goto setNameOnSignup;
	}
	setName(p);

takePassword:
	system("cls");
	multilineboxedstring("___________________________Password Rules___________________________", " ", "1. Password can have spaces but prefer not to enter spacecharacter", "2. Must have atleast one uppercase letter.", "3. Must have atleast one lowercase letter.", "4. Must have atleast one special letter.", "5. Must have atleast one number.", "", "", "");
	cout << endl << "Enter the Password of your account: ";
	string pass;
	getline(cin, pass);
	if (!isPasswordValid(pass)) {
		cout << "Your Password isn't valid.";
		Sleep(500);
		goto takePassword;
	}

takeDob:
	system("cls");
	cout << "Enter Your date of birth (dd-mm-yyyy): ";
	string dob;
	cin >> dob;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> dob;
	}

	system("cls");
	cout << "Enter your about me information: ";
	cin.ignore();
	string about;
	getline(cin, about);

	setAboutMe(about);
	setName(p);
	setPassword(pass);
	setDOB(dob);

	ofstream usedusernames("./usedusernames.txt", ios::app);
	usedusernames << p << endl;
	ofstream fout("./" + p + "_data.txt");
	if (fout.is_open()) {
		fout << p << endl << pass << endl << about << endl << dob << endl << "regular";
		fout.close();
	}
	else {
		cout << "Error opening user data file";
		cout << "\nServers are down. User can't be registered at the moment";
	}

	system("cls");
	multilineboxedstring("                 Congratulations!                 ", " ", "User Registered Successfully.", "", "", "", "", "", "", "");
}

void User::logout() {
	ofstream fout("./" + getName() + "_data.txt");
	if (fout.is_open()) {
		fout << getName() << endl << getPassword() << endl << getAboutMe() << endl << getDOB() << endl << "regular";
		fout.close();
		return;
	}
	else {
		cout << "Error logging out\n";
	}
}

void User::showAnalytics() {
	if (!post) {
		post = new Post(*this);
	}
	system("cls");
	cout << "                                         Regular Account                                         \n";
	cout << "Name:              " << getName() << endl;
	cout << "Date Of Birth:     " << getDOB() << endl;
	cout << "About:             " << getAboutMe() << endl;
	cout << "Password:          " << getPassword() << endl;
	post->postAnalytics();
}

User::User() :Profile(), post(nullptr), reaction(nullptr), comment(nullptr), settings(nullptr) {}

User::~User() {
	delete post;
	delete reaction;
	delete comment;
	delete settings;
}

Post::Post() : user(nullptr), postID(generateUniqueID()), idForPostAnalytics(nullptr) {
	author = user->getName();
}

Post::Post(User& u) : timeStamp(getCurrentTime()), user(&u), postText(""), postID(generateUniqueID()), idForPostAnalytics(nullptr) {
	author = user->getName();
}

void Post::displayFeed() {
	system("cls");
	ifstream readPosts("./post.txt");
	if (readPosts.is_open()) {
		char ch;
		while (readPosts.get(ch)) {
			cout << ch;
		}
		readPosts.close();
	}
	else {
		cerr << "Error opening file \"post.txt\"\n";
	}
}

void Post::displayMarketPlace() {
	system("cls");
	string id;
	ifstream itemidsfile("./itemIDs.txt");
	if (itemidsfile.is_open()) {
		while (getline(itemidsfile, id)) {
			ifstream readPosts("./item_" + id + ".txt");
			if (readPosts.is_open()) {
				char ch;
				while (readPosts.get(ch)) {
					cout << ch;
				}
				readPosts.close();
			}
		}
	}
	else {
		cerr << "Can't open the item ids listfile";
	}
}

Post::~Post() {
	delete user;
	delete idForPostAnalytics;
}

void Post::createPost() {
	ofstream writeToPost("./post.txt", ios::app);
	if (writeToPost.is_open()) {
		cout << "Write to Post:\t\t\t(enter, then ^,then enter to post)\n\t";
		string postText;
		string line;
		while (getline(cin, line)) {
			if (!line.empty() && line.back() == '^') {
				line.pop_back();
				postText += line;
				break;
			}
			postText += line + '\n';
		}
		writeToPost << author << " Posted: \t\t\t\t\t\t\tID: " << postID << "\n" << postText << endl << "\t\t\t\t\t\t\t" << timeStamp << endl << "                        __________________________________________________                         \n\n";
		writeToPost.close();
		cout << endl << endl << "Post Created Successfully.";
	}
	else {
		cerr << "Error opening the post file to write";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n";
}

void Post::postAnalytics() {
	// will be altered after creating the group functionality
	ifstream fin("./post.txt");
	string line;
	int* idForPostAnalytics = new int[20]; // Allocate an array for up to 20 IDs
	int NumberOfPublicPosts = 0;
	int NumberOfReactionsOnAllPosts = 0;
	int NumberOfCommentsOnAllPosts = 0;
	int i = 0;

	while (getline(fin, line) && i < 20) { // Ensure we do not exceed the array size
		if (line.find(user->getName() + " Posted: ") != string::npos) {
			if (!line.empty() && line.back() == '\n') {
				line.pop_back();
			}
			string lastSix = line.substr(line.size() - 6);

			idForPostAnalytics[i] = stoi(lastSix);
			NumberOfPublicPosts += 1;

			ifstream fin_reactions("./post_" + to_string(idForPostAnalytics[i]) + "_reactions.txt");
			ifstream fin_comments("./post_" + to_string(idForPostAnalytics[i]) + "_comments.txt");
			if (!fin_comments || !fin_reactions) {
				cout << "\n\nAnalyzing...";
				Sleep(1000);
				multilineboxedstring("__________________________User Successfully Analyzed Publically__________________________", " ", "Number of total Public Posts: " + to_string(NumberOfPublicPosts), "Number of total Comments on ID and Posts: " + to_string(NumberOfCommentsOnAllPosts), "Number of total Reactions on ID and Posts: " + to_string(NumberOfReactionsOnAllPosts), "", "", "", "", "");
				delete[] idForPostAnalytics; // Clean up dynamically allocated memory
				return;
			}
			string tmpforreactions;
			while (getline(fin_reactions, tmpforreactions)) {
				NumberOfReactionsOnAllPosts += 1;
			}
			while (getline(fin_comments, tmpforreactions)) {
				NumberOfCommentsOnAllPosts += 1;
			}
			fin_comments.close();
			fin_reactions.close();
			NumberOfCommentsOnAllPosts /= 7;
			i++; // Increment the index after processing the post
		}
	}
	fin.close();

	cout << "\n\nAnalyzing...\n\n";
	Sleep(1000);
	multilineboxedstring("__________________________User Successfully Analyzed Publically__________________________", " ", "Number of total Public Posts: " + to_string(NumberOfPublicPosts), "Number of total Comments on ID and Posts: " + to_string(NumberOfCommentsOnAllPosts), "Number of total Reactions on ID and Posts: " + to_string(NumberOfReactionsOnAllPosts), "", "", "", "", "");

	delete[] idForPostAnalytics; // Clean up dynamically allocated memory
}

void Reactions::setReactionType(string type) {
	reactionType = type;
}

string Reactions::getReactionType() {
	return reactionType;
}

void Reactions::react() {
	int id;
	system("cls");
	do {
		cout << "Enter the ID of the post you want to react to (wrong id will be ignored silently): ";
		cin >> id;
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
	} while (!cin);
labelReactionChoice:
	multilineboxedstring("1. Like", "2. Love", "3. Laughter", "4. Anger", "5. Wonder", "", "", "", "", "");
	cout << "Enter the reaction number you wish to send: ";
	int choiceOfReaction;
	cin >> choiceOfReaction;

	//validating input_____________________________________________________________________
	while (cin.fail() || !(choiceOfReaction <= 5 && choiceOfReaction >= 1)) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> choiceOfReaction;
	}

	switch (choiceOfReaction) {
	case 1:
		setReactionType("Like");
		break;
	case 2:
		setReactionType("Love");
		break;
	case 3:
		setReactionType("Laughter");
		break;
	case 4:
		setReactionType("Anger");
		break;
	case 5:
		setReactionType("Wonder");
		break;
	}
	if (u) {
		ofstream writeToReactionsFile("./post_" + to_string(id) + "_reactions.txt", ios::app);
		if (writeToReactionsFile.is_open()) {
			writeToReactionsFile << (*u).getName() << " " << getReactionType() << "ed on this post\n";
			writeToReactionsFile.close();
			cout << endl << "Reaction Added Successfully";
		}
		else {
			cout << "Error opening reactions file for post: " << id;
		}
	}
	else {
		cout << "No user assigned to react";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
}

Reactions::Reactions() : u(nullptr), reactionID(generateUniqueID()) {}

Reactions::Reactions(User& u) : u(&u), reactionType("Like"), reactionID(generateUniqueID()) {}

Reactions::~Reactions() {
	delete u;
}

void Reactions::displayReactions() {
	int id;
	while (cin.fail())
		cin.clear();
	cin.ignore();
	cout << "INVALID INPUT\n";
	cout << "\nEnter again: ";
	cin >> id;
}
ifstream readFile("./post_" + to_string(id) + "_reactions.txt");
if (readFile.is_open()) {
	char ch;
	cout << endl;
	while (readFile.get(ch)) {
		cout << ch;
	}
	readFile.close();
}
else {
	cout << "\nINVALID ID: No such post exists\n";
}
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
system("pause");
}

void Comments::comment() {
	int id;
	system("cls");
	do {
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
		cout << "Enter the ID of the post you want to comment to (wrong id will be ignored silently): ";
		cin >> id;
	} while (!cin);

	if (userpointer) {
		ofstream writeToCommentsFile("./post_" + to_string(id) + "_comments.txt", ios::app);
		if (writeToCommentsFile.is_open()) {
			system("cls");
			cout << "Write to Comment:\t\t\t(enter, then ^,then enter to post comment)\n\t";
			string postText;  //comment Text actually
			string line;
			while (getline(cin, line)) {
				if (!line.empty() && line.back() == '^') {
					line.pop_back();
					postText += line;
					break;
				}
				postText += line + '\n';
			}
			writeToCommentsFile << (*userpointer).getName() << " Commented: \t\t\t\t\t\t\t\t\tID: " << commentID << "\n" << postText << endl << "\t\t\t\t\t\t\t" << timeStamp << endl << "                        __________________________________________________                         \n\n";
			writeToCommentsFile.close();
			cout << endl << endl << "Comment Posted Successfully.\n\n\n\n\n\n\n\n\n\n";
		}
		else {
			cout << "Error opening post file for post: " << id;
		}
	}
	else {
		cout << "No user assigned to react";
	}
	system("pause");
}

Comments::Comments() : userpointer(nullptr), commentID(generateUniqueID()), timeStamp("") {}

Comments::Comments(User& u) : userpointer(&u), commentID(generateUniqueID()), timeStamp(getCurrentTime()) {}

Comments::~Comments() {
	delete userpointer;
}

void Comments::displayComments() {
	int id;
	do {
		if (!cin) {
			cin.clear();
			cin.ignore();
		}
		system("cls");
		cout << "Enter the id of the post (wrong id will be ignored silently): ";
		cin >> id;
	} while (!cin);
	ifstream readFile("./post_" + to_string(id) + "_comments.txt");
	if (readFile.is_open()) {
		char ch;
		cout << endl;
		while (readFile.get(ch)) {
			cout << ch;
		}
		readFile.close();
	}
	else {
		cout << "\nINVALID ID: No such post exists\n";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
}

void BusinessUser::createPost_ByUser() {
	cin.ignore();
	int id = generateUniqueID();
	ofstream writeToPost("./item_" + to_string(id) + ".txt");
	if (writeToPost.is_open()) {
		string itemName, specs;
		int  itemsInStock, itemPrice;

		cout << "Enter the item name: ";
		getline(cin, itemName);

		cout << "Enter the item details: ";
		getline(cin, specs);

		do {
			if (!cin) {
				cin.clear();
				cin.ignore();
			}
			cout << "Enter the items in stock: ";
			cin >> itemsInStock;
		} while (!cin);

		do {
			if (!cin) {
				cin.clear();
				cin.ignore();
			}
			cout << "Enter the items price: ";
			cin >> itemPrice;
		} while (!cin);


		writeToPost << getName() << " Posted: \t\t\t\t\t\t\tID: " << id << "\n\n" << "Name:              " << itemName << endl << "Specifications:    " << specs << endl << "Price:             " << itemPrice << endl << "In Stock:          " << itemsInStock << endl << "\t\t\t\t\t\t\t" << getCurrentTime() << endl << "                        __________________________________________________                         \n";
		writeToPost.close();
		ofstream itemidsfile("./itemIDs.txt", ios::app);
		itemidsfile << id << endl;
		itemidsfile.close();
		cout << endl << endl << "Post Created Successfully.";
	}
	else {
		cerr << "Error opening the marketplace file to write";
	}
	cout << "\n\n\n\n\n\n\n\n\n\n";
}

void BusinessUser::Register() {
	system("cls");
	multilineboxedstring("Note that usernames are unique and cannot be changed afterwards", "", "", "", "", "", "", "", "", "");

setbNameOnSignup:
	cout << "\nEnter the new Username: ";
	string p;
	cin.ignore();
	getline(cin, p);
	if (checkIfUsernameExists(p)) {
		cout << "This username is taken already." << endl;
		goto setbNameOnSignup;
	}

takebPassword:
	system("cls");
	multilineboxedstring("___________________________Password Rules___________________________", " ", "1. Password can have spaces but prefer not to enter spacecharacter", "2. Must have atleast one uppercase letter.", "3. Must have atleast one lowercase letter.", "4. Must have atleast one special letter.", "5. Must have atleast one number.", "", "", "");
	cout << endl << "Enter the Password of your account: ";
	string pass;
	getline(cin, pass);
	if (!isPasswordValid(pass)) {
		cout << "Your Password isn't valid.";
		Sleep(500);
		goto takebPassword;
	}

takebDob:
	system("cls");
	cout << "Enter Your date of birth (dd-mm-yyyy): ";
	string dob;
	cin >> dob;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> dob;
	}

	system("cls");
	cout << "Enter your about me information: ";
	cin.ignore();
	string about;
	getline(cin, about);

	setAboutMe(about);
	setName(p);
	setPassword(pass);
	setDOB(dob);

	ofstream usedusernames("./usedusernames.txt", ios::app);
	usedusernames << p << endl;
	ofstream fout("./" + p + "_data.txt");
	if (fout.is_open()) {
		fout << p << endl << pass << endl << about << endl << dob << endl << "business";
		fout.close();
		system("cls");
		multilineboxedstring("                 Congratulations!                 ", " ", "User Registered Successfully.", "", "", "", "", "", "", "");
	}
	else {
		cout << "Error opening user data file";
		cout << "\nServers are down. User can't be registered at the moment";
	}
}

void BusinessUser::logout() {
	ofstream fout("./" + getName() + "_data.txt");
	if (fout.is_open()) {
		fout << getName() << endl << getPassword() << endl << getAboutMe() << endl << getDOB() << endl << "business";
		fout.close();
		return;
	}
	else {
		cout << "Error logging out\n";
	}
}

void BusinessUser::personalSettings_ByUser() {
bpersonalSettings:
	system("cls");
	cout << endl;
	int choiceOfPersonalSettings;
	multilineboxedstring("_________________Personal_Settings_________________", " ", "1. Change Password", "", "2. Change Date of Birth", "3. Change \"About Me\"", " ", "4. Exit to Settings Menu", "", "");
	cout << endl << "Enter Your choice here: ";
	cin >> choiceOfPersonalSettings;
	cin.ignore();

	//validating input_________________________________________________________________
	while (cin.fail() || !(choiceOfPersonalSettings <= 4 && choiceOfPersonalSettings >= 1)) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> choiceOfPersonalSettings;
	}

	switch (choiceOfPersonalSettings) {
	case 1:
	{
	changePassword:
		system("cls");
		cout << "Enter the new password: ";
		string p;
		getline(cin, p);
		if (!(isPasswordValid(p))) {
			cout << "Your Password isn't valid.";
			goto changePassword;
		}
		setPassword(p);
		cout << "\n\nPassword changed Successfully\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Enter the new Date Of Birth (dd-mm-yyyy): ";
		string p;
		getline(cin, p);
		setDOB(p);
		cout << "\n\nChanged Successfully\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		break;
	}
	case 3:
	{
		system("cls");
		cout << "Enter the new About Me: ";
		string p;
		getline(cin, p);
		setAboutMe(p);
		cout << "\n\nChanged Successfully\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
		break;
	}
	case 4:
		break;
	}
}

void BusinessUser::themeSettings_ByUser() {
	if (!bsettings) {
		bsettings = new Settings;
	}
	bsettings->themeSettings();
}

BusinessUser::BusinessUser() : bsettings(nullptr), balance(100) {}

BusinessUser::~BusinessUser() {
	delete bsettings;
}

void BusinessUser::buyItem() {
	system("cls");
	cout << "Enter the id of the product you want to buy: ";
	int givenId;
	cin >> givenId;

	//validating Input_____________________________________________________________
	if (!cin) {
		cin.clear();
		cin.ignore();
		buyItem();
	}

	cout << "How much of these do you want? ";
	int numberOfItems;
	cin >> numberOfItems;
	if (!cin) {
		cin.clear();
		cin.ignore();
		buyItem();
	}

	int intprice, intinStock;
	ifstream item("./item_" + to_string(givenId) + ".txt");
	if (item.is_open()) {
		string price, inStock, discard;
		while (getline(item, discard)) {
			if (discard.find("Price:           ") != string::npos) {
				cout << discard;
				price = discard.substr(19);
				cout << endl << price;
			}
			if (discard.find("In Stock:       ") != string::npos) {
				cout << discard;
				inStock = discard.substr(19);
				cout << endl << inStock;
			}
		}
		intprice = stoi(price);
		intinStock = stoi(inStock);
		if (getbalance() >= intprice && numberOfItems <= intinStock) {
			setbalance(getbalance() - intprice);
			cout << "Item bought successfully";
			item.close();
			Sleep(500);
		}
		else {
			cout << "You can not buy the item.";
			Sleep(500);
		}
	}
	else {
		cout << "No such item";
		Sleep(500);
	}
}

void BusinessUser::setbalance(float a) {
	balance = a;
}

float BusinessUser::getbalance() {
	return balance;
}

void displayBusinessInformation(BusinessUser& obj) {
	system("cls");
	cout << "                                         Business Account                                         \n";
	cout << "Name:              " << obj.getName() << endl;
	cout << "Date Of Birth:     " << obj.getDOB() << endl;
	cout << "About:             " << obj.getAboutMe() << endl;
	cout << "Password:          " << obj.getPassword() << endl;
	cout << "Account Balance:   " << obj.getbalance() << endl;
	cout << "\n\n\n\n\n";
}

void multilineboxedstring(const string& str1, const string& str2, const string& str3, const string& str4, const string& str5, const string& str6, const string& str7, const string& str8, const string& str9, const string& str10)
{
	size_t max_length = 0;
	max_length = max(max_length, str1.length());
	max_length = max(max_length, str2.length());
	max_length = max(max_length, str3.length());
	max_length = max(max_length, str4.length());
	max_length = max(max_length, str5.length());
	max_length = max(max_length, str6.length());
	max_length = max(max_length, str7.length());
	max_length = max(max_length, str8.length());
	max_length = max(max_length, str9.length());
	max_length = max(max_length, str10.length());

	cout << setw((100 - (max_length + 4)) / 2) << setfill(' ') << " " << "+";
	for (size_t i = 0; i < max_length + 2; ++i) {
		cout << "-";
	}
	cout << "+" << endl;

	if (str1.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str1;
		for (size_t i = str1.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str2.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str2;
		for (size_t i = str2.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str3.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str3;
		for (size_t i = str3.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str4.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str4;
		for (size_t i = str4.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str5.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str5;
		for (size_t i = str5.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str6.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str6;
		for (size_t i = str6.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str7.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str7;
		for (size_t i = str7.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str8.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str8;
		for (size_t i = str8.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str9.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str9;
		for (size_t i = str9.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	if (str10.length() != 0)
	{
		cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "| " << str10;
		for (size_t i = str10.length(); i < max_length; ++i) {
			cout << " ";
		}
		cout << " |" << endl;
	}

	cout << setw((100 - max_length - 4) / 2) << setfill(' ') << " " << "+";
	for (size_t i = 0; i < max_length + 2; ++i) {
		cout << "-";
	}
	cout << "+" << endl;
}

string getCurrentTime() {
	time_t t = time(NULL);
	string formatted = ctime(&t);
	formatted.erase(formatted.find("\n"), 1);
	return formatted;
}

int generateUniqueID() {
	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));         seeded = true;
	}

	ifstream readUsedIDsFile("./usedidsfile.txt");
	int new_id;

	do {
		new_id = rand() % 900000 + 100000;
		if (readUsedIDsFile.is_open()) {
			readUsedIDsFile.seekg(ios::beg);             int used_id;
			while (readUsedIDsFile >> used_id) {
				if (new_id == used_id) {
					break;
				}
			}
		}
	} while (readUsedIDsFile.is_open() && readUsedIDsFile.tellg() != -1 && readUsedIDsFile.peek() != EOF && !readUsedIDsFile.eof());
	readUsedIDsFile.close();
	ofstream writeUsedIDsFile("./usedidsfile.txt", ios::app);
	if (writeUsedIDsFile.is_open()) {
		writeUsedIDsFile << new_id << endl;
	}
	else {
		cerr << "Error opening file for writing used IDs." << endl;
	}

	return new_id;
}

// Function to display text with a stylish effect
void stylishPrint(string text) {
	string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789uvwxyzABCDERSTUVWXYZ01234567abcdefghijkabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789uvwxyzABCDERSTUVWXYZ01234567abcdefghijkabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789uvwxyzABCDERSTUVWXYZ01234567abcdefghijkabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789uvwxyzABCDERSTUVWXYZ01234567abcdefghijk ";
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t";
	for (int i = 0; i < text.size(); ++i) {
		for (char ch : characters) {
			cout << ch << '\b';
		}
		cout << text[i];
	}
	cout << endl;
}

// Function to display the welcome message
void welcome() {
	string title = "CONSOLE BASED FACEBOOK\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tFrom:\n\t\t\t\t\t\t\t\tZain Bin Khalid\n\t\t\t\t\t\t\t\tUmair Ahmed\n\t\t\t\t\t\t\t\tUmme Tubarka";
	stylishPrint(title);
	cout << "\n\n\n\n\n\n\n";
}

bool checkIfUsernameExists(string& u) {
	ifstream fin("./usedusernames.txt");
	if (fin.is_open()) {
		string line;
		while (getline(fin, line)) {
			if (line == u) {
				fin.close();
				return true;
			}
		}
	}
	else {
		cout << "Error opening usernames file";
	}
	fin.close();
	return false;
}

bool isPasswordValid(string& p) {
	int uppercaseLetters = 0, lowercaseLetters = 0, specialCharacters = 0, numbers = 0;
	string numbersList = "0123456789", specialCharactersList = "!@#$%^&*()-_=+|<>";
	for (int i = 0; i < p.length(); ++i)
	{
		if (isupper(p[i]))
		{
			uppercaseLetters += 1;
		}
		if (islower(p[i]))
		{
			lowercaseLetters += 1;
		}
		if (numbersList.find(p[i]) != string::npos)
		{
			numbers += 1;
		}
		if (specialCharactersList.find(p[i]) != string::npos)
		{
			specialCharacters += 1;
		}
	}
	if (uppercaseLetters == 0 || lowercaseLetters == 0 || numbers == 0 || specialCharacters == 0)
	{
		return false;
	}
	else {
		return true;
	}
}

ifstream openFile(string path) {
	ifstream inputFile(path);
	return inputFile;
}