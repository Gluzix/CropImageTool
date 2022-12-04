#include "ImageViewerLabel.h"
#include <QPainter>
#include <QPaintDevice>
#include <QPaintEngine>
#include <QDebug>
#include <QMouseEvent>

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
    Q_UNUSED(event);

    if (cropRect.contains(event->pos())) {
        isPressed = true;
    }

    qDebug() << __FUNCTION__;
}

void ImageViewerLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    isPressed = false;
    qDebug() << __FUNCTION__;
}

void ImageViewerLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (!isPressed) {
        return;
    }

    if (cropRect.contains(event->pos())) {
        qDebug() << event->pos();
    }

    cropRect.setRect(event->pos().x(), event->pos().y(), cropRect.width(), cropRect.height());

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

    painter.setBrush(pixmap());
    painter.drawRect(cropRect);
}
