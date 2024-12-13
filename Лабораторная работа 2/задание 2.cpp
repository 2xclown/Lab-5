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

    virtual ~Publication() {}
};

class Sales {
protected:
    float sales[3];

public:
    // Метод для получения данных о продажах
    void getSalesData() {
        cout << "Введите общую стоимость продаж за 3 последних месяца:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    // Метод для вывода данных о продажах
    void putSalesData() const {
        cout << "Продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << " руб." << endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int page_count; 

public:
    // Метод для получения данных от пользователя
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> page_count;
        getSalesData();
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << page_count << endl;
        putSalesData();
    }
};

class Type : public Publication, public Sales {
private:
    float record_time;

public:
    // Метод для получения данных от пользователя
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> record_time;
        getSalesData();
    }

    // Метод для вывода данных
    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << record_time << " минут" << endl;
        putSalesData();
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
