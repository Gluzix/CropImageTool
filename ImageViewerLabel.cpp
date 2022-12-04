#include "ImageViewerLabel.h"
#include <QPainter>
#include <QPaintDevice>
#include <QPaintEngine>
#include <QMouseEvent>
#include <QDebug>

ImageViewerLabel::ImageViewerLabel(QWidget *parent)
    : QLabel{parent}
{
    cropRect.setRect(this->width()/2, this->height()/2, 200, 400);
}

void ImageViewerLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    drawOverlay();
}

void ImageViewerLabel::mousePressEvent(QMouseEvent *event)
{
    mousePressedPoint = event->pos();
    cropRectPressedRect = cropRect;

    if (cropRect.contains(event->pos())) {
        isPressed = true;
        mousePressedPoint = event->pos();
        cropRectPressedRect = cropRect;
    }

    QRect handleRect;
    handleRect.setRect(cropRect.x()+cropRect.width()-16,
                       cropRect.y()+cropRect.height()-16,
                       16, 16);

    if (handleRect.contains(event->pos())) {
        isResizeState = true;
    } else {
        isResizeState = false;
    }
}

void ImageViewerLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    isPressed = false;
}

void ImageViewerLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (!isPressed) {
        return;
    }

    QPoint mousePointDifference = event->pos() - mousePressedPoint;

    if (isResizeState) {
        cropRect.setRect(cropRect.x(),
                         cropRect.y(),
                         cropRectPressedRect.width() + mousePointDifference.x(),
                         cropRectPressedRect.height() + mousePointDifference.y());

    } else {
        cropRect.setRect(cropRectPressedRect.x() + mousePointDifference.x(),
                         cropRectPressedRect.y() + mousePointDifference.y(),
                         cropRect.width(),
                         cropRect.height());
    }

    repaint();
}

void ImageViewerLabel::drawOverlay()
{
    if (!this->pixmap()) {
        return;
    }

    QPainter painter(this);

    painter.setBrush(QBrush(QColor(0, 0, 0, 150)));
    QPoint point = mapFromParent(this->pos());
    painter.setPen(Qt::NoPen);

    painter.drawRect(point.x(), point.y(),
                     this->width(), this->height());

    QPen pen;
    pen.setColor(Qt::white);
    pen.setStyle(Qt::PenStyle::DashLine);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(pixmap());
    painter.drawRect(cropRect);
}
