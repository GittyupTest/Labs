#include "MapCell.h"



bool MapCell::isOpen() const
{
    return m_isOpen;
}

bool MapCell::hasFlag() const
{
    return m_hasFlag;
}

bool MapCell::hasBomb() const
{
    return m_value == Bomb;
}

MapCell::Value MapCell::value() const
{
    return m_value;
}

void MapCell::setOpen(bool isOpen)
{
    m_isOpen = isOpen;
}

void MapCell::setFlag(bool hasFlag)
{
    m_hasFlag = hasFlag;
}

void MapCell::setValue(Value value)
{
    m_value = value;
}
