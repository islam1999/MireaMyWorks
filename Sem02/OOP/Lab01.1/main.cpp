#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
 * ЗАДАНИЕ
 * В каждом варианте указана некоторая предметная область и задача, которую необходимо решить.
 * Необходимо выделить в предметной области несколько (2-4) классов, а в каждом классе не более 5 свойств и методов, которые помогут в решении данной задачи.
 * Необходимо логически выбрать модификаторы доступа (private или public) для каждого свойства и метода.
 * Разработать UML-диаграмму, реализацию классов. В main привести пример работы с созданными классами, а также выполнить указанный в задании запрос.
 * При проектировании классов необходимо обязательно добавить те поля, которые позволяют решать задачу, и может еще какие-то, которые делают процесс общения с заданными классами удобнее.
 *
 * ОФОРМЛЕНИЕ РЕШЕНИЯ
 * Отчет должен содержать UML-диаграмму классов. Программный код должен содержать описание классов и реализацию заданного запроса.
 *
 * 29.	Есть музыканты, у них есть песни, они попадают в хит-парады.
 * Определить музыканта, который чаще всего находится на первом месте хит-парада.
 */

class Song {
private:
    string title;
    string author;
    string genre;

public:
    Song(string title_, string author_, string genre_) {
        title = title_;
        author = author_;
        genre = genre_;
    }

    ~Song() = default;

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getGenre() const {
        return genre;
    }
};

class HitParade {
private:
    vector<Song> songs;
    map<string, unsigned> authors;

public:
    HitParade(unsigned size = 10) {
        songs.reserve(size);
    }

    ~HitParade() {
        songs.clear();
        authors.clear();
    }

    void addSong(const Song &song) {
        string author = song.getAuthor();
        if (!authors.count(author)) {
            unsigned count = songs.empty() ? 1 : 0;
            authors.insert(make_pair(author, count));
        }

        songs.push_back(song);
    }

    void setSongAt(const Song &song, unsigned position) {
        if (position <= songs.size())
            songs[position - 1] = song;
        string author = song.getAuthor();
        if(position == 1 && authors.count(author))
                authors[author]++;
        else
            authors.insert(make_pair(author, 0));
    }

    Song getSongAt(unsigned position) {
        bool check = position <= songs.size();
        return check ? songs[position - 1] : nullptr;
    }

    string getFamousAuthor() {
        unsigned maxCount = 0;
        string author;
        for (auto temp: authors) {
            if (temp.second >= maxCount) {
                maxCount = temp.second;
                author = temp.first;
            }
        }
        return author;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}