/**
* @file GeneratorError.h
* @author Мещеряков В.А.
* @version 1.0
* @date 08.05.2021
* @copyright ИБСТ ПГУ
* @brief Описание класса "GeneratorError"
*/
#pragma once
#include <string>
#include <stdexcept>
using namespace std;
/// @brief Класс для обработки ошибок, которые могут возникнуть при взаимодействии пользователя с программой
/// @details Класс является наследником существующего класса для обработки исключений с именем "invalid_argument"
class GeneratorError: public invalid_argument
{
public:
     /// @brief Запрещающий конструктор без параметров
     GeneratorError() = delete;
    /** @brief  Конструктор с параметром
     *  @details Данный конструктор перегружается вызовом конструктора базового класса с именем "invalid_argument"
    *   @param std::string what_arg - строка, хранящая описание ошибки
    */
    explicit GeneratorError (const string& what_arg) : invalid_argument(what_arg) {}
};