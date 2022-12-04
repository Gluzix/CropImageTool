#pragma once

#include <QWidget>

class ImageOverlay : public QWidget
{
    Q_OBJECT
public:
    explicit ImageOverlay(QRect *cropRect, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QRect *mCropRect;
};
