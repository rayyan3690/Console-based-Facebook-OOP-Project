Console-Based Facebook
A C++ console application simulating core Facebook features with a text-based interface. This project showcases object-oriented programming, file-based data persistence, and user interaction management, serving as a learning tool or foundation for console-based social media applications.
Features

User Accounts:
Register as a regular or business user with unique usernames.
Password validation (requires uppercase, lowercase, numbers, special characters).
Store and retrieve profile info (name, date of birth, about me).


Posts:
Create posts with timestamps and unique IDs.
View a public feed of all posts.


Interactions:
React to posts (e.g., like, love).
Comment on posts and view comments/reactions.


Marketplace (Business Users):
Create and buy items with price and stock management.
Manage account balance for transactions.


Settings:
Update personal info (password, DOB, about me).
Customize console themes (e.g., Hacker, Sunset, Neon).


Analytics:
Display profile details and post statistics (reactions, comments).


User Manual:
Built-in guide for navigating the application.


Data Persistence:
Stores user data, posts, reactions, comments, and marketplace items in text files.



Technologies

Language: C++ (using <iostream>, <fstream>, <Windows.h>, etc.).
Storage: Text files for data persistence (no external database).
OOP: Classes for profiles, posts, reactions, comments, settings; inheritance for user types; dynamic memory management with pointers.
Platform: Windows-specific (uses Windows.h for console styling), adaptable for other platforms with modifications.

Prerequisites

C++ compiler (e.g., g++ via MinGW for Windows or other platforms).
Windows OS for full functionality (due to Windows.h for console colors and pauses).

Installation

Clone the repository:git clone https://github.com/yourusername/console-based-facebook.git


Navigate to the project directory:cd console-based-facebook


Compile the code:g++ main.cpp classfunctionsimplementation.cpp -o facebook


Run the executable:./facebook

On Windows, use facebook.exe.

Usage

Launch the app to see the welcome screen and main menu.
Choose options to:
Sign up (regular/business user).
Log in with username and password.
Create/view posts, react, comment, or manage marketplace items.
Adjust settings (personal info, themes).
View analytics or the user manual.
Exit the application.


Follow on-screen prompts for input validation and navigation.

File Structure

main.cpp: Entry point with the main menu and user flow.
class.h: Header file defining classes (Profile, User, BusinessUser, Post, etc.).
classfunctionsimplementation.cpp: Implementation of class methods.
helperFunctions.h: Utility functions (e.g., multilineboxedstring, getCurrentTime).
Data files (generated at runtime):
usedusernames.txt: Tracks registered usernames.
<username>_data.txt: Stores user profile data.
post.txt: Stores all posts.
item_<ID>.txt: Stores marketplace items.
usedidsfile.txt: Tracks unique IDs.



Limitations

No real-time networking or multiplayer support (local data only).
Basic error handling and input validation.
Windows-specific console features (e.g., color themes via Windows.h).
No graphical UI – text-based console interface.

Contributing

Fork the repository.
Create a feature branch (git checkout -b Ascending branch name origin/main).
Make changes and test thoroughly.
Submit a pull request with a clear description of changes.

Authors

Zain Bin Khalid
Muhammad Rayyan

Acknowledgments
Built as a learning project to demonstrate C++ programming concepts and file handling. Contributions and feedback are welcome!
