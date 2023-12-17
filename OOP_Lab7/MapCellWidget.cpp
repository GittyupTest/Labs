#include <QPainter>

#include "MapCellWidget.h"

MapCellWidget::MapCellWidget(const MapCell *cell, QWidget *parent)
    : QPushButton(parent)
    , m_cell(cell)
{}

void MapCellWidget::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::red));
    painter.fillRect(this->rect(), QBrush(Qt::darkGreen));
}
