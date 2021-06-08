#include "Generator.h"
int main()
{
    string mode,setRegister;
    int count_numbers;
    vector<uint32_t> result;
    string Register;
    bool end = true;
    cout << "Добро пожаловать в программу для генерации псевдослучайной последовательности чисел.\n";
    cout << "В программе используется регистр, длина которого 32 бит.\n";
    cout << "Введите \"set\", чтобы вручную ввести регистр, или \"default\", чтобы воспользоваться регистром по умолчанию.\n";
    cout << "Регистр по умолчанию: 10101000111001010110111110011001\n";
    cout << "Чтобы завершить работу программы, введите любую текстовую последовательность.\n";
    do {
        cout << "Выбор регистра (регистр по умолчанию или свой): ";
        cin >> setRegister;
        if (setRegister == "default") {
            Generator gen;
            gen.useDefaultRegister();
            cout << "Регистр выбран по умолчанию.\n";
            cout << "Укажите количество генерируемых чисел: ";
            cin >> count_numbers;
            try {
                gen.generation(count_numbers);
                cout << "Генерация прошла успешно." << endl;
                end = false;
            } catch (const GeneratorError & error) {
                cout << error.what() << endl;
            }
        }
        if (setRegister == "set") {
            cout << "Введите регистр в виде строки, состоящей единичных и нулевых битов.\n";
            cout << "Длина регистра - 32 бита и регистр не может полностью состоять из 0.\n";
            cin >> Register;
            Generator gen;
            try {
                gen.setBaseRegister(Register);
                cout << "Регистр успешно заполнен.\n";
                cout << "Укажите количество генерируемых чисел: ";
                cin >> count_numbers;
                gen.generation(count_numbers);
                cout << "Генерация прошла успешно." << endl;
                end = false;
            } catch (const GeneratorError &error) {
                cout << error.what() << endl;
            }
        }
        if (setRegister != "set" and setRegister != "default") {
            cout << "Программа завершила работу." << endl;
            end = false;
        }
    } while (end != false);
    return 0;
}
