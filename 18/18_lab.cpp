#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyObject {
public:
    MyObject(int value) : value(value) {}

    int value;
};

int main() {
    // Запрашиваем размерности векторов
    int num_objects;
    cout << "Enter the dimension of the vectors: ";
    cin >> num_objects;

    // Создаем исходный вектор из объектов класса
    vector<MyObject> initial_vector;
    for (int i = 0; i < num_objects; i++) {
        initial_vector.push_back(MyObject(rand() % 100));//вставить в конец
    }

    // Выводим исходный вектор
    cout << "source vector:" << endl;
    for (const MyObject& obj : initial_vector) {
        cout << obj.value << " ";
    }
    cout << endl;

    // критерий для перезаписи объектов (перезаписываем объекты, значение которых больше 50)
    vector<MyObject> new_vector;
    for (const MyObject& obj : initial_vector) {
        if (obj.value > 50) {
            new_vector.push_back(obj);
        }
    }

    // Отображаем новый вектор
    cout << "c:" << endl;
    for (const MyObject& obj : new_vector) {
        cout << obj.value << "new vector ";
    }
    cout << endl;

    // Проверяем, не пуст ли новый вектор
    if (new_vector.empty()) {//проверка на пустоту
        cout << "New vector is empty" << endl;
    } else {
        // Сортируем объекты в новом векторе
        sort(new_vector.begin(), new_vector.end(), [](const MyObject& a, const MyObject& b) {
            return a.value < b.value;
        });
        cout << "Sorted new vector::" << endl;
        for (const MyObject& obj : new_vector) {
            cout << obj.value << " ";
        }
        cout << endl;
    }

    return 0;
}