#include "txt.h"

using namespace l1;

char ** Txt::text() const {
    return _text;
}

size_t Txt::size() const {
    return _size;
}

Txt &Txt::operator=(Txt &&other) noexcept {
    _size = other._size;
    _text = other._text;

    other._size = 0;
    other._text = nullptr;

    return *this;
}

Txt &Txt::operator=(const Txt &other) {
    _size = other.size();
    _text = new char *[_size];
    for (int i = 0; i < _size; ++i) {
        _text[i] = new char[1024];
    }

    for (int i = 0; i < _size; ++i) {
        strcpy(_text[i], other.text()[i]);
    }

    return *this;
}

Txt::Txt(Txt &&other) noexcept {
    _size = other._size;
    _text = other._text;

    other._size = 0;
    other._text = nullptr;
}

Txt::Txt(const Txt &other) {
    _size = other.size();
    _text = new char *[_size];
    for (int i = 0; i < _size; ++i) {
        _text[i] = new char[1024];
    }

    for (int i = 0; i < _size; ++i) {
        strcpy(_text[i], other.text()[i]);
    }
}

Txt::Txt(const char *file)  {
    std::ifstream in;
    in.open(file);


    // посчитать количество строк
    std::string temp;
    temp.resize(1024);
    _size = 0;
    while (!in.eof()) {
        in.getline(temp.data(), 1024);
        _size++;
    }

    // выделяем память под текст
    _text = new char *[_size];
    for (int i = 0; i < _size; ++i) {
        _text[i] = new char[1024];
    }

    in.close();
    in.open(file);

    // записываем данные из файла
    for (int i = 0; i < _size; ++i) {
        in.getline(_text[i], 1024);
    }
}

~Txt::Txt()
{
    if (_text == nullptr) {
        return;
    }

    for (int i = 0; i < _size - 1; ++i) {
        delete[] _text[i];
    }
    delete[] _text;
}