#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class BookType { Fiction, Technical };

class Book {
private:
    string author;
    string title;
    BookType type;

public:
    Book(const string& author, const string& title, BookType type)
        : author(author), title(title), type(type) {
        if (author.empty() || title.empty()) {
            throw invalid_argument("Имя автора и название книги не могут быть пустыми.");
        }
    }

    BookType getType() const {
        return type;
    }
};

class Library {
private:
    vector<Book*> books;

public:
    void addBook(const string& author, const string& title, BookType type) {
        books.push_back(new Book(author, title, type));
    }

    void printBookCounts() const {
        int fictionCount = 0;
        int technicalCount = 0;

        for (const auto& book : books) {
            switch (book->getType()) {
            case BookType::Fiction:
                fictionCount++;
                break;
            case BookType::Technical:
                technicalCount++;
                break;
            }
        }

        cout << "Количество художественных книг: " << fictionCount << endl;
        cout << "Количество технических книг: " << technicalCount << endl;
    }

    ~Library() {
        for (auto& book : books) {
            delete book;
        }
    }
};

int main() {
    system("chcp 1251");
    try {
        Library library;

        library.addBook("Лев Толстой", "Война и мир", BookType::Fiction);
        library.addBook("Джордж Оруэлл", "1984", BookType::Fiction);
        library.addBook("Брайан Керниган", "Язык программирования C", BookType::Technical);
        library.addBook("Герхардт Вайнберг", "История Второй мировой войны", BookType::Technical);

        library.printBookCounts();
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
