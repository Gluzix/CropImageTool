#pragma once

#include <QLabel>
#include <ImageOverlay.h>

class ImageViewerLabel : public QLabel
{
    Q_OBJECT
public:
    ImageViewerLabel(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void drawOverlay();

    QRect cropRect;
    bool isPressed;

    bool isResizeState;

    QPoint mousePressedPoint;
    QRect cropRectPressedRect;
};
