#include <iostream>
#include <stdexcept>
#include <memory> 

using namespace std;

// Базовый класс для всех людей
class Person {
public:
    virtual void print() const = 0;
    virtual ~Person() {}
};

// Производные классы от Person
class Preschooler : public Person {
public:
    void print() const override {
        cout << "I am a Preschooler." << endl;
    }
};

class Schoolgirl : public Person {
public:
    void print() const override {
        cout << "I am a Schoolgirl." << endl;
    }
};

class Student : public Person {
public:
    void print() const override {
        cout << "I am a Student." << endl;
    }
};

class Worker : public Person {
public:
    void print() const override {
        cout << "I am a Worker." << endl;
    }
};

// Шаблонный класс для хранения массива указателей на объекты
template <typename T>
class Array {
private:
    T** data;
    size_t size;

public:
    // Конструктор
    Array(size_t size) : size(size) {
        data = new T * [size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = nullptr;
        }
    }

    // Деструктор
    ~Array() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i]; // Освобождаем память для каждого объекта
        }
        delete[] data;
    }

    // Перегрузка оператора []
    T*& operator[](size_t index) {
        if (index >= size) {
            throw runtime_error("Index out of bounds!");
        }
        return data[index];
    }

    // Метод для получения размера массива
    size_t getSize() const {
        return size;
    }
};

int main() {
    try {
        // Создаем массив указателей на объекты Person
        Array<Person> persons(4);

        // Заполняем массив объектами разных типов
        persons[0] = new Preschooler();
        persons[1] = new Schoolgirl();
        persons[2] = new Student();
        persons[3] = new Worker();

        // Выводим информацию о каждом человеке
        for (size_t i = 0; i < persons.getSize(); ++i) {
            persons[i]->print();
        }

        // Попытка обращения к несуществующему индексу (выброс исключения)
        persons[5] = new Worker();  // Это вызовет исключение

    }
    catch (const runtime_error& e) {
        // Обработка исключения
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
