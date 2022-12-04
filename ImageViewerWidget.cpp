#include "ImageViewerWidget.h"
#include "ui_ImageViewerWidget.h"

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

}
