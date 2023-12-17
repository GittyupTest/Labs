#pragma once

#include <QPushButton>

#include "MapCell.h"

class MapCellWidget : public QPushButton
{
    Q_OBJECT

public:
    MapCellWidget(const MapCell *cell = nullptr, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const MapCell *m_cell = nullptr;
};

