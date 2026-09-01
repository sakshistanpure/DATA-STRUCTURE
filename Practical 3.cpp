#include <iostream>
#include <string>
using namespace std;
struct Song
{
    string title;
    Song *prev;
    Song *next;
    Song(string t)
    {
        title = t;
        next = NULL;
        prev = NULL;
    }
};
class Playlist
{
private:
    Song *head;
    Song *tail;
    Song *current;
public:
    Playlist()
    {
        head = tail = current = NULL;
    }
    void addSong(string title)
    {
        Song *newSong = new Song(title);
        if (head == NULL)
        {
            head = tail = current = newSong;
        }
        else
        {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }
    void playCurrentSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else
        {
            cout << "Playing: " << current->title << endl;
        }
    }
    void forwordSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else if (current->next == NULL)
        {
            cout << "Already at the last song." << endl;
        }
        else
        {
            current = current->next;
            playCurrentSong();
        }
    }
    void backwordSong()
    {
        if (current == NULL)
        {
            cout << "Playlist is empty." << endl;
        }
        else if (current->prev == NULL)
        {
            cout << "Already at the first song." << endl;
        }
        else
        {
            current = current->prev;
            playCurrentSong();
        }
    }
    void display()
    {
        Song *temp = head;
        cout << "\nPlaylist:" << endl;
        while (temp != NULL)
        {
            if (temp == current)
            {
                cout << "-> ";
            }
            cout << temp->title << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    Playlist playlist;
    playlist.addSong("Believer");
    playlist.addSong("Perfect");
    playlist.addSong("Shape of You");
    playlist.addSong("Senorita");
    playlist.display();
    cout << "\nCurrent Song:" << endl;
    playlist.playCurrentSong();
    cout << "\nForward:" << endl;
    playlist.forwordSong();
    cout << "\nBackward:" << endl;
    playlist.backwordSong();
    cout << "\nFinal Playlist:" << endl;
    playlist.display();
    return 0;
}


