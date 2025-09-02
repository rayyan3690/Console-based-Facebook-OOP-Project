#include "class.h"
#include "helperFunctions.h"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	system("cls");
	system("pause");
	welcome();
	User u1;
	BusinessUser b1;
	string loginType;
	string u, p, a, d, inputPassword, manual;
	string n;
	ifstream fin;

	multilineboxedstring("1. Signup", "2. Login", "3. Trouble Using Facebook? press 3", " ", "4. Exit", "", "", "", "", "");
	cout << endl << "Enter Your choice here: ";
	int choiceOfPreMainMenu;
	cin >> choiceOfPreMainMenu;

	while (cin.fail() || !(choiceOfPreMainMenu <= 4 && choiceOfPreMainMenu >= 1)) {
		cin.clear();
		cin.ignore();
		cout << "INVALID INPUT\n";
		cout << "\nEnter again: ";
		cin >> choiceOfPreMainMenu;
	}

	switch (choiceOfPreMainMenu) {
	case 1:
	signup:
		system("cls");
		multilineboxedstring("ThankYou For Signing up to facebook", " ", "Press 1 to register as a regular user", "Press 2 to register as a business user", "", "", "", "", "", "");
		int choiceOfSignup;
		cin >> choiceOfSignup;

		//validating input____________________________________________________
		while (cin.fail() || !(choiceOfSignup <= 2 && choiceOfSignup >= 1)) {
			cin.clear();
			cin.ignore();
			cout << "INVALID INPUT\n";
			cout << "\nEnter again: ";
			cin >> choiceOfSignup;
		}
		switch (choiceOfSignup) {
		case 1:
			u1.Register();
			Sleep(500);
			main();
			break;
		case 2:
			b1.Register();
			Sleep(500);
			main();
			break;
		default:
			break;
		}
		break;
	case 2:
		system("cls");
		cout << "Enter the Username: ";
		cin.ignore();
		getline(cin, n);
		fin = openFile("./" + n + "_data.txt");
		if (fin.is_open()) {
			getline(fin, u);
			getline(fin, p);
			getline(fin, a);
			getline(fin, d);
			getline(fin, loginType);
			cout << "Enter the password: ";
			getline(cin, inputPassword);
			if (inputPassword == p) {
				if (loginType == "business") {
					b1.setName(u);
					b1.setAboutMe(a);
					b1.setDOB(d);
					b1.setPassword(p);
				}
				else if (loginType == "regular") {
					u1.setName(u);
					u1.setAboutMe(a);
					u1.setDOB(d);
					u1.setPassword(p);
				}
				else {
					cout << "Must be a problem in register function";
				}
				multilineboxedstring("Welcome Back " + n, "Your Account Information has been restored successfully.", "", "", "", "", "", "", "", "");
				Sleep(1000);
				fin.close();
			}
			else {
				cout << "Invalid Password";
				Sleep(500);
				fin.close();
				main();
			}
		}
		else {
			cout << "Enter an existing account username or signup for new one.";
			Sleep(500);
			main();
		}

		if (loginType == " ") {
			main();
		}
		else if (loginType == "business") {
		mainMenuOfBusiness:
			system("cls");
			multilineboxedstring("____________________________MAIN_MENU____________________________", " ", "1. See What's New in the market", "2. Sell something online", "3. Settings", "4. See Profile Details", "", "", " ", "5. Logout");
			cout << endl;
			cout << "Enter your Choice here: ";
			int choiceOfMainMenu;
			cin >> choiceOfMainMenu;

			//validating input_____________________________________________________________________
			while (cin.fail() || !(choiceOfMainMenu <= 5 && choiceOfMainMenu >= 1)) {
				cin.clear();
				cin.ignore();
				cout << "INVALID INPUT\n";
				cout << "\nEnter again: ";
				cin >> choiceOfMainMenu;
			}

			switch (choiceOfMainMenu) {
			case 1:
			menuOfMarketPlaceInteraction:
				Post::displayMarketPlace();
				cout << "\n\n";
				multilineboxedstring("________________________MarketPlace_Interactions________________________", "", "1. Buy an item", "", "", "", " ", "2. Exit to Main Menu", "", "");
				cout << "\nEnter your choice here: ";
				int choiceOfPostInteraction;
				cin >> choiceOfPostInteraction;

				//validating input_____________________________________________________________________
				while (cin.fail() || !(choiceOfPostInteraction <= 2 && choiceOfPostInteraction >= 1)) {
					cin.clear();
					cin.ignore();
					cout << "INVALID INPUT\n";
					cout << "\nEnter again: ";
					cin >> choiceOfPostInteraction;
				}

				switch (choiceOfPostInteraction) {
				case 1:
					b1.buyItem();
					goto menuOfMarketPlaceInteraction;
					break;
				case 2:
					goto mainMenuOfBusiness;
					break;
				default:
					cout << "Impossible condition achieved.";
					break;
				}
				break;
			case 2:
				system("cls");
				b1.createPost_ByUser();
				system("pause");
				goto mainMenuOfBusiness;
				break;
			case 3:
			bsettingsMenu:
				system("cls");
				multilineboxedstring("_______________User_Settings_______________", " ", "1. Set Personal Information", "2. Set FaceBook Theme", "3. Manage Balance", " ", "4. Back to Main Menu.", "", "", "");
				cout << "Enter your choice: ";
				int choiceOfSettingsMenu;
				cin >> choiceOfSettingsMenu;

				//validating input______________________________________________________________
				while (cin.fail() || !(choiceOfSettingsMenu <= 4 && choiceOfSettingsMenu >= 1)) {
					cin.clear();
					cin.ignore();
					cout << "INVALID INPUT\n";
					cout << "\nEnter again: ";
					cin >> choiceOfSettingsMenu;
				}

				switch (choiceOfSettingsMenu) {
				case 1:
					b1.personalSettings_ByUser();
					goto bsettingsMenu;
					break;
				case 2:
					b1.themeSettings_ByUser();
					goto bsettingsMenu;
					break;
				case 3:
				manageBalance:
					system("cls");
					multilineboxedstring("______________________Manage Balance______________________", " ", "1. Add Amount", "2. Withdraw Amount", " ", "3. Exit to User Settings Menu", "", "", "", "");
					int choiceOfManageBalance;
					cin >> choiceOfManageBalance;

					while (cin.fail() || !(choiceOfManageBalance <= 3 && choiceOfManageBalance >= 1)) {
						cin.clear();
						cin.ignore();
						cout << "INVALID INPUT\n";
						cout << "\nEnter again: ";
						cin >> choiceOfManageBalance;
					}

					switch (choiceOfManageBalance) {
					case 1:
						cout << "Enter the amount : ";
						float amount;
						cin >> amount;
						b1.setbalance(b1.getbalance() + amount);
						cout << "Added Successfully";
						Sleep(500);
						goto manageBalance;
						break;
					case 2:
						cout << "No API connected";
						Sleep(500);
						goto manageBalance;
						break;
					case 3:
						goto bsettingsMenu;
						break;
					}
					break;
				case 4:
					goto mainMenuOfBusiness;
				}

				goto mainMenuOfBusiness;
				break;
			case 4:
				displayBusinessInformation(b1);
				system("pause");
				goto mainMenuOfBusiness;
				break;
			case 5:
				b1.logout();
				main();
			}
		}
		else {
		mainMenu:
			system("cls");
			multilineboxedstring("____________________________MAIN_MENU____________________________", " ", "1. Display Feed", "2. Share What's Happening", "3. Settings", "4. See Profile Analytics", "", "", " ", "5. Logout");
			cout << endl;
			cout << "Enter your Choice here: ";
			int choiceOfMainMenu;
			cin >> choiceOfMainMenu;

			//validating input_____________________________________________________________________
			while (cin.fail() || !(choiceOfMainMenu <= 5 && choiceOfMainMenu >= 1)) {
				cin.clear();
				cin.ignore();
				cout << "INVALID INPUT\n";
				cout << "\nEnter again: ";
				cin >> choiceOfMainMenu;
			}

			switch (choiceOfMainMenu) {
			case 1:
			menuOfPostInteraction:
				Post::displayFeed();
				multilineboxedstring("________________________Post_Interactions________________________", "", "1. React on a Post", "2. Comment on a Post", "3. View Comments", "4. View Reactions", " ", "5. Exit to Main Menu", "", "");
				cout << "\nEnter your choice here: ";
				int choiceOfPostInteraction;
				cin >> choiceOfPostInteraction;

				//validating input_____________________________________________________________________
				while (cin.fail() || !(choiceOfPostInteraction <= 5 && choiceOfPostInteraction >= 1)) {
					cin.clear();
					cin.ignore();
					cout << "INVALID INPUT\n";
					cout << "\nEnter again: ";
					cin >> choiceOfPostInteraction;
				}

				switch (choiceOfPostInteraction) {
				case 1:
					u1.reactToPost_ByUser();
					goto menuOfPostInteraction;
					break;
				case 2:
					u1.commentToPost_ByUser();
					goto menuOfPostInteraction;
					break;
				case 3:
					u1.viewComments();
					goto menuOfPostInteraction;
					break;
				case 4:
					u1.viewReactions();
					goto menuOfPostInteraction;
					break;
				case 5:
					goto mainMenu;
				default:
					cout << "Impossible condition achieved.";
					break;
				}
				break;
			case 2:
				system("cls");
				u1.createPost_ByUser();
				system("pause");
				goto mainMenu;
				break;
			case 3:
			settingsMenu:
				system("cls");
				multilineboxedstring("_______________User_Settings_______________", " ", "1. Set Personal Information", "2. Set FaceBook Theme", "", " ", "3. Back to Main Menu.", "", "", "");
				cout << "Enter your choice: ";
				int choiceOfSettingsMenu;
				cin >> choiceOfSettingsMenu;

				//validating input______________________________________________________________
				while (cin.fail() || !(choiceOfSettingsMenu <= 3 && choiceOfSettingsMenu >= 1)) {
					cin.clear();
					cin.ignore();
					cout << "INVALID INPUT\n";
					cout << "\nEnter again: ";
					cin >> choiceOfSettingsMenu;
				}

				switch (choiceOfSettingsMenu) {
				case 1:
					u1.personalSettings_ByUser();
					goto settingsMenu;
					break;
				case 2:
					u1.themeSettings_ByUser();
					goto settingsMenu;
					break;
				case 3:
					goto mainMenu;
				}

				goto mainMenu;
				break;
			case 4:
				u1.showAnalytics();
				cout << "\n\n\n\n\n";
				system("pause");
				goto mainMenu;
				break;
			case 5:
				u1.logout();
				main();
			}
		}
			break;
	case 3:
		//display user manual
		manual =
			"Console Based Facebook User Manual\n"
			"Introduction\n"
			"Welcome to the Console Based Facebook application! This manual\n"
			"provides instructions to navigate and utilize the application's\n"
			"features effectively.\n\n"
			"Getting Started\n"
			"Launching the Application: Run the executable file to start the\n"
			"application.\n"
			"Main Menu: You will be presented with options to create a post,\n"
			"view feed, react to posts, comment on posts, and access user\n"
			"settings.\n\n"
			"User Profile\n"
			"Setting Up Profile: Enter your name, password, date of birth, and a\n"
			"brief \"About Me\" description.\n"
			"Editing Profile: Access the settings menu to update your personal\n"
			"information.\n\n"
			"Creating Posts\n"
			"Create Post: Select the option to create a post, type your message,\n"
			"and it will be added to your feed.\n\n"
			"Viewing and Interacting with Posts\n"
			"View Feed: Display posts from all users.\n"
			"React to Posts: Choose a reaction type and apply it to a post.\n"
			"Comment on Posts: Add comments to posts to engage with other\n"
			"users.\n\n"
			"User Settings\n"
			"Personal Information: Change your password, username, date of birth,\n"
			"or \"About Me\" section.\n"
			"Theme Settings: Customize the appearance of the console using\n"
			"predefined themes like \"Hacker,\" \"Sunset,\" and more.\n\n"
			"Exiting the Application\n"
			"Exit: Select the option to safely close the application.\n\n"
			"For further assistance, refer to the detailed instructions provided\n"
			"in each menu option. Enjoy your experience with Console Based\n"
			"Facebook!";
		stylishPrint(manual);
		system("pause");
		main();
		break;
	case 4:
		break;
	default:
		break;
	}
}