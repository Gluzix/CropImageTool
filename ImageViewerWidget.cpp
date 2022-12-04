#include "ImageViewerWidget.h"
#include "ui_ImageViewerWidget.h"
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>

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

    QPixmap scaled = pixmap.scaled(ui->imageViewerLabel->size(), Qt::KeepAspectRatio);
    ui->imageViewerLabel->setMinimumSize(scaled.size());
    ui->imageViewerLabel->setMaximumSize(scaled.size());
    ui->imageViewerLabel->setPixmap(scaled);
}
