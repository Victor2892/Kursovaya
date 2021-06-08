#include "Generator.h"

void Generator::useDefaultRegister ()
{
    for (size_t i =0; i < defaultRegister.size(); i++)
        baseRegister.push_back(defaultRegister.at(i));
}

void Generator::setBaseRegister(const string Register)
{
    vector<uint32_t> perevod (bitDepth);

    const size_t sizeRegister = Register.size();

    if(sizeRegister != bitDepth)
        throw GeneratorError("Ошибка: недопустимая длина регистра.");

    for (size_t i=0; i < sizeRegister; i++) {
        if (Register[i] != '1' and Register[i] != '0') {
            throw GeneratorError("Ошибка: в вашем регистре используется недопустимый символ.");
        }
    }
    for (size_t i=0; i < sizeRegister; i++) {
        uint32_t bit = 0;
        if (Register[i] == '1') {
            bit = 1;
            perevod.at(i) = bit;
        } else {
            perevod.at(i) = bit;
        }
    }
    int sumRegister= 0;
    for(size_t i = 0; i < sizeRegister; i++) {
        sumRegister += perevod.at(i);
    }
    if(sumRegister == 0)
        throw GeneratorError("Ошибка: ваш регистр состоит полностью из нулей.");

    for (size_t i = 0; i < sizeRegister; i++)
        this->baseRegister.push_back(perevod.at(i));
}

void Generator::generation(const int count)
{
    if (count <= 0)
        throw GeneratorError("Ошибка: вы ввели некорректное количество генерируемых чисел. При вводе используйте натуральные числа.");

    for (int nomer = 0; nomer < count; nomer++) {

        vector<uint32_t> result;
        
        uint32_t xorNum;

        for(uint32_t i = 0; i < bitDepth; i++) {
            result.push_back(baseRegister.at(bitDepth - 1));

            xorNum = baseRegister.at(31) ^ baseRegister.at(6) ^ baseRegister.at(4) ^ baseRegister.at(2) ^ baseRegister.at(1) ^ baseRegister.at(0);

            for(size_t i = bitDepth - 1; i > 0; i--) {
                baseRegister.at(i) = baseRegister.at(i-1);
            }
            baseRegister.at(0) = xorNum;
        }
        
        cout << nomer+1 << " число: ";
        for (size_t j = 0; j < result.size(); j++ ) {
            cout << result.at(j);
        }
        cout << endl;
    }
}