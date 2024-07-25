#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

// Creating a Message Class
class Message {
public:
    string sender;
    string receiver;
    string content;

    Message() {}

    Message(string sender, string receiver, string content) {
        this->sender = sender;
        this->receiver = receiver;
        this->content = content;
    }

    void displayMessage() const {
        cout << "From: " << sender << "\nTo: " << receiver << "\nMessage: " << content << "\n";
    }
};

// Creating a User Class
class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {}

    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }

    void displayUser() const {
        cout << "Name: " << firstName << " " << lastName << "\nAge: " << age << "\nGender: " << gender << "\n";
    }
};

// Creating a Social Media Group Class
class SocialGroup {
    string groupName;
    vector<string> members;
    vector<pair<string, string>> messages; 

public:
    SocialGroup() {}

    SocialGroup(string groupName) {
        this->groupName = groupName;
    }

    void addMember(string userName) {
        members.push_back(userName);
    }

    void sendMessage(string userName, string content) {
        messages.push_back({userName, content});
    }

    void displayGroupInfo() const {
        cout << "Group: " << groupName << "\nMembers: ";
        for (const string &member : members) {
            cout << member << " ";
        }
        cout << "\nMessages:\n";
        for (const auto &message : messages) {
            cout << "From " << message.first << ": " << message.second << "\n";
        }
    }
};

// Social Network System Class to manage users and friendships
class SocialNetworkSystem {
    map<string, User> mapUserName;
    map<string, set<string>> friends;

public:
    void addUser(string userName, User user) {
        if (mapUserName.find(userName) == mapUserName.end()) {
            mapUserName[userName] = user;
        } else {
            cout << "Username Already Taken\n";
        }
    }

    void makeFriends(string userName1, string userName2) {
        friends[userName1].insert(userName2);
        friends[userName2].insert(userName1);
    }

    void displayAllUsers() const {
        for (const auto &entry : mapUserName) {
            cout << "Username: " << entry.first << "\n";
            entry.second.displayUser();
            cout << "\n";
        }
    }

    void displayAllFriendships() const {
        for (const auto &entry : friends) {
            cout << entry.first << " is friends with: ";
            for (const auto &friendName : entry.second) {
                cout << friendName << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    SocialNetworkSystem sns;
    string command;

    while (true) {
        cout << "\nEnter command:\n";
        cout << "1. Add User\n";
        cout << "2. Make Friends\n";
        cout << "3. Send Message\n";
        cout << "4. Create Group\n";
        cout << "5. Add Member to Group\n";
        cout << "6. Display Users\n";
        cout << "7. Display Friendships\n";
        cout << "8. Display Group\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, firstName, lastName, gender;
            int age;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;

            User user(firstName, lastName, age, gender);
            sns.addUser(username, user);

        } else if (choice == 2) {
            string userName1, userName2;
            cout << "Enter first username: ";
            cin >> userName1;
            cout << "Enter second username: ";
            cin >> userName2;
            sns.makeFriends(userName1, userName2);

        } else if (choice == 3) {
            string sender, receiver, content;
            cout << "Enter sender username: ";
            cin >> sender;
            cout << "Enter receiver username: ";
            cin >> receiver;
            cout << "Enter message content: ";
            cin.ignore(); // to clear the buffer
            getline(cin, content);

            Message message(sender, receiver, content);
            message.displayMessage();

        } else if (choice == 4) {
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;
            SocialGroup group(groupName);

        } else if (choice == 5) {
            string groupName, userName;
            cout << "Enter group name: ";
            cin >> groupName;
            cout << "Enter username to add to group: ";
            cin >> userName;

        } else if (choice == 6) {
            sns.displayAllUsers();

        } else if (choice == 7) {
            sns.displayAllFriendships();

        } else if (choice == 8) {
            string groupName;
            cout << "Enter group name: ";
            cin >> groupName;


        } else if (choice == 9) {
            break;

        } else {
            cout << "Invalid choice! Please enter a number between 1 and 9.\n";
        }
    }

    return 0;
}

