#include "PolynominalError.hpp"
#include <cstring>

PolynominalError::PolynominalError() { cout << "Error exception! " << endl; }
void PolynominalError::SetMessage(const char *Message)
{
    if (Message != nullptr && strcmp(Message, "") != 0)
        this->Message = Message;
}
void PolynominalError::PrintInfo() const
{
    cout << Message << endl;
}

MemoryError::MemoryError(const char *Message)
{
    SetMessage(Message);
    PrintInfo();
}

RangeError::RangeError(const char *Message)
{
    SetMessage(Message);
    PrintInfo();
}
