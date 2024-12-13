#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

// Базовый класс
class Base {
public:
    virtual void showBehavior() const {
        cout << "Base behavior" << endl;
    }
    virtual ~Base() = default;
};

// Производный класс
class Derived : public Base {
public:
    void showBehavior() const override {
        cout << "Derived behavior" << endl;
    }
};

// Функция для добавления объектов в хранилище
void add(vector<unique_ptr<Base>>& storage, unique_ptr<Base> obj) {
    storage.push_back(move(obj));
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<unique_ptr<Base>> storage;

    // Создание объектов
    for (int i = 0; i < 10; ++i) {
        if (rand() % 2 == 0) {
            add(storage, make_unique<Base>());
        }
        else {
            add(storage, make_unique<Derived>());
        }
    }

    // Демонстрация поведения объектов
    for (const auto& obj : storage) {
        obj->showBehavior();
    }

    // Все ресурсы будут автоматически освобождены благодаря unique_ptr
    return 0;
}
