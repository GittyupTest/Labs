#include <QGridLayout>
#include <QPaintEvent>
#include <QPainter>

#include "MapWidget.h"

MapWidget::MapWidget(const MapParams &params, QWidget *parent)
    : QWidget(parent)
    , m_map(params.rowCount, params.columnCount)
{
    m_layout = new QGridLayout();
    this->setLayout(m_layout);
    fill(params);
}

void MapWidget::fill(const MapParams &params)
{
    for (auto *cell : m_cells) {
        m_layout->removeWidget(cell);
        delete cell;
    }
    m_cells.clear();

    for (int i = 0; i < params.rowCount; ++i) {
        for (int j = 0; j < params.columnCount; ++j) {
            MapCellWidget *cell = new MapCellWidget(&m_map[i][j], this);
            m_layout->addWidget(cell, i, j);
        }
    }
}

void MapWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}
