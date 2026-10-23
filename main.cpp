#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a) {
        title = t;
        artist = a;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* current;

public:
    DoublyLinkedList() {
        head = NULL;
        current = NULL;
    }

    void addSong(string t, string a) {
        Node* p = new Node(t, a);

        if (head == NULL) {
            head = p;
            current = p;
        } else {
            Node* q = head;

            while (q->next != NULL) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song Added Successfully\n";
    }

    void deleteSong(string t) {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* q = head;

        if (q->title == t) {
            Node* p = head;
            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            }

            if (current == p) {
                current = head;
            }

            delete p;
            cout << "Song Deleted\n";
            return;
        }

        while (q->next != NULL) {
            if (q->next->title == t) {
                Node* p = q->next;
                q->next = p->next;

                if (p->next != NULL) {
                    p->next->prev = q;
                }

                if (current == p) {
                    if (q->next != NULL) {
                        current = q->next;
                    } else {
                        current = q;
                    }
                }

                delete p;
                cout << "Song Deleted\n";
                return;
            }

            q = q->next;
        }

        cout << "Song not found\n";
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* q = head;
        int i = 1;

        cout << "\nPlaylist:\n";

        while (q != NULL) {
            cout << i << ". " << q->title
                 << " - " << q->artist;

            if (q == current) {
                cout << " (Playing)";
            }

            cout << "\n";
            q = q->next;
            i++;
        }
    }

    void displayBackward() {
        Node* q = head;

        if (q == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        while (q->next != NULL) {
            q = q->next;
        }

        cout << "\nPlaylist in Reverse:\n";

        while (q != NULL) {
            cout << q->title << " - "
                 << q->artist << "\n";
            q = q->prev;
        }
    }

    void playCurrent() {
        if (current == NULL) {
            cout << "No song playing\n";
        } else {
            cout << "Playing: " << current->title
                 << " by " << current->artist << "\n";
        }
    }

    void playNext() {
        if (current == NULL) {
            cout << "Playlist is empty\n";
        } else if (current->next == NULL) {
            cout << "End of playlist reached\n";
        } else {
            current = current->next;
            playCurrent();
        }
    }

    void playPrevious() {
        if (current == NULL) {
            cout << "Playlist is empty\n";
        } else if (current->prev == NULL) {
            cout << "Beginning of playlist reached\n";
        } else {
            current = current->prev;
            playCurrent();
        }
    }

    void playComplete() {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        Node* q = head;

        cout << "\nPlaying all songs:\n";

        while (q != NULL) {
            cout << q->title << " - "
                 << q->artist << "\n";
            q = q->next;
        }
    }

    void repeatAll(int n) {
        if (head == NULL) {
            cout << "Playlist is empty\n";
            return;
        }

        for (int i = 1; i <= n; i++) {
            cout << "\nLoop " << i << ":\n";

            Node* q = head;

            while (q != NULL) {
                cout << q->title << " - "
                     << q->artist << "\n";
                q = q->next;
            }
        }
    }

    void showCurrent() {
        if (current == NULL) {
            cout << "No current song\n";
        } else {
            cout << "Current Song: " << current->title
                 << " - " << current->artist << "\n";
        }
    }
};

int main() {
    DoublyLinkedList list;

    int choice;
    string title, artist;
    int r;

    do {
        cout << "\n--- Music Playlist Manager ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);

                cout << "Enter artist: ";
                getline(cin, artist);

                list.addSong(title, artist);
                break;

            case 2:
                cout << "Enter title to delete: ";
                getline(cin, title);

                list.deleteSong(title);
                break;

            case 3:
                list.displayForward();
                break;

            case 4:
                list.displayBackward();
                break;

            case 5:
                list.playCurrent();
                break;

            case 6:
                list.playNext();
                break;

            case 7:
                list.playPrevious();
                break;

            case 8:
                list.playComplete();
                break;

            case 9:
                cout << "Enter repetitions: ";
                cin >> r;

                list.repeatAll(r);
                break;

            case 10:
                list.showCurrent();
                break;

            case 11:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 11);

    return 0;
}
