#include <assert.h>
#include <queue>

#include "Map.h"

Map::Map(int rowCount, int columnCount)
    : m_cells(rowCount, std::vector<MapCell>(columnCount, MapCell()))
{
    assert(rowCount > 0 && columnCount > 0);
}

int Map::rowCount() const
{
    return static_cast<int>(m_cells.size());
}

int Map::columnCount() const
{
    assert(m_cells.size() > 0);
    return static_cast<int>(m_cells[0].size());
}

bool Map::fill(const MapParams &params)
{
    m_cells.resize(params.rowCount);
    for (std::vector<MapCell> &row : m_cells) {
        row.resize(params.columnCount);
    }
    return fill(params.bombCount);
}

bool Map::fill(int bombCount)
{
    if (bombCount > rowCount() * columnCount()) {
        return false;
    }

    for (std::vector<MapCell> &row : m_cells) {
        for (MapCell &cell : row) {
            cell.setValue(MapCell::Value_0);
        }
    }

    while (bombCount) {
        int row = rand() % rowCount();
        int column = rand() % columnCount();

        if (m_cells[row][column].value() == MapCell::Bomb) {
            continue;
        }

        m_cells[row][column].setValue(MapCell::Bomb);
        //TODO: метод получения соседей
        // получаем соседей, увеличиваем их счётчик на 1.

        --bombCount;
    }

    return true;
}

void Map::switchFlag(int row, int column)
{
    m_cells[row][column].setFlag(!m_cells[row][column].hasFlag());
}

void Map::open(int row, int column)
{
    //TODO: метод получения соседей
    // получаем соседей, открываем, нулевые ячейки которые были закрыты добавляем в очередь.
    std::queue<MapCell> cellsToOpen({m_cells[row][column]});
    while (!cellsToOpen.empty()) {
        MapCell cell;
    }
}

void Map::open()
{
    for (std::vector<MapCell> &row : m_cells) {
        for (MapCell &cell : row) {
            cell.setOpen(true);
        }
    }
}

const std::vector<MapCell> &Map::operator[](int row) const
{
    return m_cells.at(row);
}
