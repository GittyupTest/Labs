#pragma once

#include <QWidget>

#include "Map.h"
#include "MapCellWidget.h"

class QGridLayout;

class MapWidget : public QWidget
{
public:
    MapWidget(const MapParams &params = {}, QWidget *parent = nullptr);

    void fill(const MapParams &params);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Map m_map;
    QGridLayout *m_layout = nullptr;
    QVector<MapCellWidget *>m_cells;
};

