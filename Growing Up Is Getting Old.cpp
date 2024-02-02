// Growing Up Is Getting Old.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>

class Str {
private:
    char* text;
    int size;

public:
    Str() : text(nullptr), size(0) {}

    Str(const char* text) {
        this->size = strlen(text);
        this->text = new char[size + 1];
        strncpy(this->text, text, size);
        this->text[size] = '\0';
    }

    Str(const Str& str) {
        this->size = str.size;
        this->text = new char[size + 1];
        strncpy(this->text, str.text, size);
        this->text[size] = '\0';
    }

    ~Str() {
        delete[] text;
    }

    friend std::ostream& operator<<(std::ostream& out, const Str& text) {
        out << text.text;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Str& str) {
        str.clear();
        char* tmp = new char[10000];
        in.getline(tmp, 10000);
        str.push_back(tmp);
        return in;
    }

    void push_back(char c) {
        char* tmp = new char[size + 1];
        strncpy(tmp, text, size);
        tmp[size] = c;
        size++;
        delete[] text;
        text = tmp;
        tmp = nullptr;
    }

    void append(int space, char value) {
        char* tmp = new char[size + 2];
        strncpy(tmp, text, size);
        char last = tmp[size - 1];

        for (int i = space; i < size; i++) {
            tmp[i + 1] = tmp[i];
        }

        tmp[space] = value;
        tmp[size] = last;
        tmp[size + 1] = '\0';
        size++;
        delete[] text;
        text = tmp;
        tmp = nullptr;
    }

    void push_back(const char* c) {
        int NEWsize = size + strlen(c);
        char* tmp = new char[NEWsize + 1];

        strncpy(tmp, text, size);
        strncpy(tmp + size, c, NEWsize - size);

        tmp[NEWsize] = '\0';
        size = NEWsize;
        delete[] text;
        text = tmp;
        tmp = nullptr;
    }

    void replace(int start, int end, const char* value) {
        for (int i = start; i <= end; i++) {
            text[i] = *value;
        }
    }

    bool operator==(const Str& str) const {
        if (size != str.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (text[i] != str.text[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator>(const Str& rightStr) const {
        if (*this == rightStr) {
            return false;
        }

        int minSize = size < rightStr.size ? size : rightStr.size;
        int numberLeft = 0;
        int numberRight = 0;

        for (int i = 0; i < minSize; i++) {
            if (text[i] > rightStr.text[i]) {
                numberLeft++;
            }
            if (text[i] < rightStr.text[i]) {
                numberRight++;
            }
        }

        return numberLeft > numberRight;
    }

    bool operator<(const Str& rightStr) const {
        if (*this == rightStr) {
            return false;
        }

        int minSize = size < rightStr.size ? size : rightStr.size;
        int numberLeft = 0;
        int numberRight = 0;

        for (int i = 0; i < minSize; i++) {
            if (text[i] < rightStr.text[i]) {
                numberLeft++;
            }
            if (text[i] > rightStr.text[i]) {
                numberRight++;
            }
        }

        return numberLeft > numberRight;
    }

    bool operator>=(const Str& str) const {
        return !(*this < str);
    }

    bool operator<=(const Str& str) const {
        return !(*this > str);
    }

    Str operator+(const Str& str) const {
        Str result(*this);
        result.push_back(str.text);
        return result;
    }

    Str operator+(const char* c) const {
        Str result(*this);
        result.push_back(c);
        return result;
    }

    void clear() {
        delete[] text;
        text = nullptr;
        size = 0;
    }

    void resize(int newSize) {
        if (newSize < 0) return;

        char* tmp = new char[newSize + 1];
        int copySize = newSize < size ? newSize : size;
        strncpy(tmp, text, copySize);
        tmp[copySize] = '\0';
        delete[] text;
        text = tmp;
        size = newSize;
    }

    void push_front(char c) {
        char* tmp = new char[size + 2];
        tmp[0] = c;
        strncpy(tmp + 1, text, size);
        tmp[size + 1] = '\0';
        delete[] text;
        text = tmp;
        size++;
    }
};

int main() {
    Str s1 = "ZZZ";
    Str s2 = "AAAA";

    std::cout << (s1 > s2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
