#include "ReadDataFromFile.h"

std::vector<unsigned char> ReadDataFromFile(const std::string& path) {
    // открываем файл в бинарном режиме
    std::ifstream file(path, std::ios::binary);

    if (!file) {
        throw std::runtime_error("cant open " + path);
    }

    // перемещаем указатель на конец файла
    file.seekg(0, std::ios::end);
    // определяем размер файла
    std::streamsize size = file.tellg();
    // возвращаем указатель в начало файла
    file.seekg(0, std::ios::beg);

    // создаем вектор нужного размера
    std::vector<unsigned char> buffer(size);

    // читаем данные из файла в вектор
    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
        throw std::runtime_error("error reading file: " + path);
    }

    return buffer;
}