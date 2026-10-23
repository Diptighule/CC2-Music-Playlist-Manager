Music Playlist Manager Using Doubly Linked List

Project Information

- Assignment: CC2 – Data Structures and Algorithms
- Project Name: Music Playlist Manager
- Programming Language: C++
- Data Structure: Doubly Linked List

Introduction

The Music Playlist Manager is a menu-driven C++ program that manages songs using a doubly linked list. Each node stores the song title and artist, along with pointers to the previous and next nodes.

Features

- Add a song to the playlist
- Delete a song from the playlist
- Display songs in forward order
- Display songs in reverse order
- Play the current song
- Navigate to the next song
- Navigate to the previous song
- Play the complete playlist
- Repeat the playlist
- Display the current song

Files in This Repository

- "main.cpp" – C++ source code.
- "DIAGRAMS.md" – Diagrams of the doubly linked list and its operations.
- "README.md" – Project description and instructions.

How It Works

A doubly linked list stores songs in connected nodes.

- "prev" points to the previous node.
- "next" points to the next node.
- "head" points to the first node.
- "current" points to the currently selected song.

This structure allows navigation in both forward and backward directions.

How to Compile and Run

You need a C++ compiler such as g++.

Step 1: Compile the program

g++ main.cpp -o music_playlist

Step 2: Run the program

For Windows:

music_playlist.exe

For Linux/macOS:

./music_playlist

Learning Outcomes

- Understand doubly linked lists.
- Learn node creation and pointer connections.
- Perform insertion and deletion.
- Traverse a linked list in both directions.
- Implement navigation using pointers.

Conclusion

This project demonstrates how a doubly linked list can be used to manage a music playlist and navigate between songs efficiently.

