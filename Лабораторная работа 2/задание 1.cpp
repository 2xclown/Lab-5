#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    // Метод для получения данных от пользователя
    virtual void getdata() {
        cout << "Введите название книги: ";
        cin.ignore();
        getline(cin, title);
        cout << "Введите цену книги: ";
        cin >> price;
    }

    // Метод для вывода данных
    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }

    // Виртуальный деструктор для правильного удаления объектов наследников
    virtual ~Publication() {}
};

class Book : public Publication {
private:
    int page_count;

public:
    // Метод для получения данных от пользователя
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> page_count;
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << page_count << endl;
    }
};

class Type : public Publication {
private:
    float record_time;

public:
    // Метод для получения данных от пользователя
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> record_time;
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << record_time << " минут" << endl;
    }
};

int main() {
    system("chcp 1251");

    Book myBook;
    Type myType;

    // Ввод данных для книги
    cout << "Данные для книги: " << endl;
    myBook.getdata();
    cout << endl;

    // Ввод данных для аудиозаписи
    cout << "Данные для аудиозаписи: " << endl;
    myType.getdata();
    cout << endl;

    // Вывод данных для книги
    cout << "Информация о книге: " << endl;
    myBook.putdata();
    cout << endl;

    // Вывод данных для аудиозаписи
    cout << "Информация о аудиозаписи: " << endl;
    myType.putdata();
    cout << endl;

    return 0;
}
