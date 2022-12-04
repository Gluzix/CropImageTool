#include "ImageOverlay.h"
#include <QPainter>

ImageOverlay::ImageOverlay(QRect *cropRect, QWidget *parent)
    : QWidget{parent}
    , mCropRect(cropRect)
{
    this->setGeometry(0, 0, 200, 400);
}

void ImageOverlay::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(0, 0, 0, 0));
    painter.drawRect(this->rect());
}
