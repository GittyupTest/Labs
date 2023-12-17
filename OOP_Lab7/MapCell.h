#pragma once

class MapCell
{
public:
    enum Value
    {
        Bomb = -1,
        Value_0,
        Value_1,
        Value_2,
        Value_3,
        Value_4,
        Value_5,
        Value_6,
        Value_7,
        Value_8
    };

public:
    bool isDigit() const;
    bool isOpen() const;
    bool hasFlag() const;
    bool hasBomb() const;
    Value value() const;

    void setOpen(bool isOpen);
    void setFlag(bool hasFlag);
    void setValue(Value value);

private:
    bool m_isOpen = false;
    bool m_hasFlag = false;
    Value m_value = Value_0;
};

