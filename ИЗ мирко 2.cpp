﻿#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
/**
 * @brief Преобразует количество нулей в соответствующую букву алфавита
 * @param k Количество нулей перед единицей (должно быть в диапазоне 0-25)
 * @return char Строчная буква английского алфавита от 'a' до 'z'
 * @throw out_of_range Если количество нулей выходит за допустимый диапазон
 *
 * Примеры:
 *   k = 0 → 'a' (соответствует строке "1")
 *   k = 1 → 'b' (соответствует строке "01")
 *   k = 25 → 'z' (соответствует 25 нулям + "1")
 */
char groupToLetter(int k) {
    if (k < 0 || k > 25)
        throw out_of_range("Invalid zero count: " + to_string(k));
    return 'a' + k;
}
/**
 * @brief Сжимает бинарную строку по алгоритму замены групп
 * @param binary Входная строка из символов '0' и '1'
 * @return string Сжатая строки из строчных букв английского алфавита
 * @throw invalid_argument Если строка имеет недопустимый формат
 *
 * Алгоритм сжатия:
 *   1. Последовательно обрабатываем группы вида [0..0]1
 *   2. Для каждой группы:
 *        - Считаем количество нулей (zeros)
 *        - Преобразуем zeros в букву с помощью groupToLetter()
 *   3. Объединяем все буквы в результирующую строку
 *
 * Примеры:
 *   "1" → "a"
 *   "01" → "b"
 *   "101" → "ab"
 *   "000000000000000000000001" → "y"
 */
string compress(const string& binary) {
    string result;
    size_t i = 0;

    while (i < binary.length()) {
        int zeros = 0;

        // Считаем нули перед единицей
        while (i < binary.length() && binary[i] == '0') {
            zeros++;
            i++;
        }

        // Обрабатываем завершающую единицу
        if (i < binary.length() && binary[i] == '1') {
            result += groupToLetter(zeros);
            i++;
        }
        else {
            throw invalid_argument("Invalid binary format");
        }
    }
    return result;
}
/**
 * @brief Главная функция программы
 * @return int Код завершения программы (0 - успех, 1 - ошибка)
 *
 * Логика работы:
 *   1. Чтение входной строки из стандартного ввода
 *   2. Вызов функции сжатия compress()
 *   3. Вывод результата или обработка ошибок
 *
 * Особенности:
 *   - Обрабатывает все исключения стандартным образом
 *   - Выводит понятные сообщения об ошибках
 */
int main() {
    string binary;
    cin >> binary;
    
            try {
                cout << compress(binary) << endl;
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                return 1;
            }
            return 0;
        }
    
