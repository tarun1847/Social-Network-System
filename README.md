# Social Network System

A simple C++ implementation of a social network system that allows users to create accounts, make friends, send messages, and create social groups.

## Features

- **User Management**: Add users with basic details (first name, last name, age, gender).
- **Friendship Management**: Users can become friends with other users.
- **Messaging**: Send messages between users.
- **Social Groups**: Create groups and add members to them.
- **Display Information**: Display all users, friendships, and group details.

## Classes

### 1. Message

Represents a message sent from one user to another.

- **Attributes**:
  - `sender`: The sender of the message.
  - `receiver`: The receiver of the message.
  - `content`: The content of the message.

- **Methods**:
  - `displayMessage()`: Displays the message details.

### 2. User

Represents a user in the social network.

- **Attributes**:
  - `firstName`: The first name of the user.
  - `lastName`: The last name of the user.
  - `age`: The age of the user.
  - `gender`: The gender of the user.

- **Methods**:
  - `displayUser()`: Displays the user's details.

### 3. SocialGroup

Represents a social group that can contain multiple members and messages.

- **Attributes**:
  - `groupName`: The name of the group.
  - `members`: A list of members in the group.
  - `messages`: A list of messages sent in the group.

- **Methods**:
  - `addMember(userName)`: Adds a user to the group.
  - `sendMessage(userName, content)`: Sends a message to the group.
  - `displayGroupInfo()`: Displays the group's information.

### 4. SocialNetworkSystem

Manages users and friendships in the social network.

- **Attributes**:
  - `mapUserName`: A map of usernames to user objects.
  - `friends`: A map of friendships between users.

- **Methods**:
  - `addUser(userName, user)`: Adds a user to the system.
  - `makeFriends(userName1, userName2)`: Makes two users friends.
  - `displayAllUsers()`: Displays all users in the system.
  - `displayAllFriendships()`: Displays all friendships in the system.
 
  
