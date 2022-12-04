#include "ImageViewerWidget.h"
#include "ui_ImageViewerWidget.h"
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QDebug>

ImageViewerWidget::ImageViewerWidget(QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::ImageViewerWidget)
{
    ui->setupUi(this);
    connect(ui->uploadButton, &QPushButton::clicked, this,
            &ImageViewerWidget::onUploadButtonClicked);

    connect(ui->saveButton, &QPushButton::clicked, this,
            &ImageViewerWidget::onSaveButtonClicked);
}

void ImageViewerWidget::onUploadButtonClicked()
{
    QString path = QFileDialog::getOpenFileName(this, "", "", "Image Files (*.png *.jpg)");

    if (!path.isEmpty()) {
        QPixmap pixmap(path);

        QPixmap scaled = pixmap.scaled(ui->imageViewerLabel->size(), Qt::KeepAspectRatio);
        ui->imageViewerLabel->setMinimumSize(scaled.size());
        ui->imageViewerLabel->setMaximumSize(scaled.size());
        ui->imageViewerLabel->setPixmap(scaled);
    }
}

void ImageViewerWidget::onSaveButtonClicked()
{
    QString path = QFileDialog::getSaveFileName(this, "", "", "Image Files (*.png *.jpg)");

    if (!path.isEmpty()) {
        QImage image = ui->imageViewerLabel->getCroppedPixmap().toImage();
        image.save(path);
    }
}
