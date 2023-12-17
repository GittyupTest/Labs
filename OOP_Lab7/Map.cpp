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
        auto neighbours = _neighbours(row, column);
        for (const auto &coords : neighbours) {
            MapCell &cell = m_cells[coords.first][coords.second];
            if (!cell.hasBomb()) {
                cell.setValue(MapCell::Value(cell.value() + 1));
            }
        }

        --bombCount;
    }

    return true;
}

void Map::switchFlag(int row, int column)
{
    m_cells[row][column].setFlag(!m_cells[row][column].hasFlag());
}

bool Map::open(int row, int column)
{
    std::queue<std::pair<int, int>> cellsToOpen({{row, column}});
    while (!cellsToOpen.empty()) {
        row = cellsToOpen.front().first;
        column = cellsToOpen.front().second;
        cellsToOpen.pop();

        MapCell &cell = m_cells[row][column];
        cell.setOpen(true);

        if (cell.hasBomb()) {
            return false;
        }

        if (!cell.isOpen()) {
            auto neighbours = _neighbours(row, column);
            for (const auto &coords : neighbours) {
                MapCell &cell = m_cells[coords.first][coords.second];
                if (cell.value() == MapCell::Value_0) {
                    cellsToOpen.push(coords);
                }
            }
        }
    }
    return true;
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

std::vector<std::pair<int, int>> Map::_neighbours(int row, int column)
{
    std::vector<std::pair<int, int>> cells;
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = column - 1; j <= column + 1; ++j) {
            bool isNeighbour = i >= 0 && j >= 0 && i < rowCount() && j < columnCount()
                            && !(i == row && j == column);
            if (isNeighbour) {
                cells.push_back({i, j});
            }
        }
    }
    return cells;
}
