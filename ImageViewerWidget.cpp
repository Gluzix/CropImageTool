#include "ImageViewerWidget.h"
#include "ui_ImageViewerWidget.h"
#include <QFileDialog>
#include <QPixmap>

ImageViewerWidget::ImageViewerWidget(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::ImageViewerWidget)
{
    ui->setupUi(this);
    connect(ui->uploadButton, &QPushButton::clicked, this,
            &ImageViewerWidget::onUploadButtonClicked);
}

void ImageViewerWidget::onUploadButtonClicked()
{
    QString path = QFileDialog::getOpenFileName(this, "", "", "");
    QPixmap pixmap(path);
    pixmap = pixmap.scaled(ui->imageViewerLabel->size(), Qt::KeepAspectRatio);
    ui->imageViewerLabel->setPixmap(pixmap);
}
