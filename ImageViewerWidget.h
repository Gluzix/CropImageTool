#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewerWidget; }
QT_END_NAMESPACE

class ImageViewerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewerWidget(QWidget *parent = nullptr);

private slots:
    void onUploadButtonClicked();

private:
    Ui::ImageViewerWidget *ui;
};
