#ifndef CLASS_H
#define CLASS_H

#include <string>

using namespace std;

//classes used as pointers are post declared to avoid runtime errors
class Post;
class Reactions;
class Comments;
class Settings;
class User;

class AbstractUser {

	virtual void createPost_ByUser() = 0;
	virtual void Register() = 0;
	virtual void logout() = 0;
	virtual void personalSettings_ByUser() = 0;
	virtual void themeSettings_ByUser() = 0;

};

class Profile {
private:
	string name;
	string password;
	string dateOfBirth;
	string aboutMe;
	int ID;

public:
	Profile();

	void setName(string pname);
	void setPassword(string pass);
	void setDOB(string a);
	void setAboutMe(string b);

	string getName();
	string getPassword();
	string getAboutMe();
	string getDOB();
};

class Settings {
	User* userPointerForSettings;

public:
	Settings();

	Settings(User& u);

	void setPersonalInfo();

	void themeSettings();

	~Settings();
};

class User : public Profile, public AbstractUser {
	Post* post;
	Reactions* reaction;
	Comments* comment;
	Settings* settings;

public:
	User();

	void createPost_ByUser();
	void displayFeed_ByUser();
	void reactToPost_ByUser();
	void commentToPost_ByUser();
	void viewReactions();
	void viewComments();
	void Register();
	void logout();
	void personalSettings_ByUser();
	void themeSettings_ByUser();
	void showAnalytics();

	~User();
};

class Post {
private:
	string author;
	User* user;
	string timeStamp;
	string postText;
	int postID;
	int* idForPostAnalytics;

public:
	Post();
	
	Post(User& u);

	static void displayFeed();

	static void displayMarketPlace();

	void createPost();

	void postAnalytics();

	~Post();
};

class Reactions {
private:
	string reactionType;
	int reactionID;
	User* u;

public:
	Reactions();
	Reactions(User& u);

	void setReactionType(string type);
	string getReactionType();

	void react();
	void displayReactions();
	
	~Reactions();
};

class Comments {
	User* userpointer;
	int commentID;
	string timeStamp;

public:
	Comments();
	Comments(User& u);

	void comment();
	void displayComments();

	~Comments();
};

class BusinessUser:public Profile, public AbstractUser {
private:
	Settings* bsettings;
	float balance;
public:
	BusinessUser();

	void setbalance(float a);
	float getbalance();
	void createPost_ByUser();
	void Register();
	void logout();
	void personalSettings_ByUser();
	void themeSettings_ByUser();
	void buyItem();
	friend void displayBusinessInformation(BusinessUser& obj);

	~BusinessUser();
};
#endif // CLASS_H