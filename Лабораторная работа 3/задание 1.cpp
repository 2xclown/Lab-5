#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Базовый класс "Деталь"
class Detail {
protected:
    Detail() {} 
public:
    virtual ~Detail() = default; 
    virtual void print() const = 0;
};

// Производный класс "Сборка"
class Assembly : public Detail {
protected:
    Assembly() {} 
public:
    virtual ~Assembly() = default;
    void print() const override {
        cout << "Assembly object" << endl;
    }
};

// Дружественная шаблонная функция для создания объектов
template <typename T>
shared_ptr<T> createObject() {
    struct Creator : public T {
        Creator() : T() {}
    };
    return make_shared<Creator>();
}

int main() {
    // Хранилище объектов
    vector<shared_ptr<Detail>> storage;

    // Создание объектов через дружественную шаблонную функцию
    storage.push_back(createObject<Assembly>());

    // Вывод информации о каждом объекте
    for (const auto& obj : storage) {
        obj->print();
    }

    return 0;
}
