#ifndef TXT_H
#define TXT_H

#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

namespace l1
{
class Txt {
public:
    Txt() : _text{nullptr}, _size{0} {}
    Txt(const char *file);
    Txt(const Txt& other);
    Txt(Txt&& other) noexcept;
    Txt& operator= (const Txt& other);
    Txt& operator= (Txt&& other) noexcept;
    ~Txt();

    char ** text() const;
    size_t size() const;

private:
    char **_text;
    size_t _size;
};
}
#endif // TXT_H
