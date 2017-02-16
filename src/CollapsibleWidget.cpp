#include "CollapsibleWidget.h"
#include "ui_CollapsibleWidget.h"

#include <QPropertyAnimation>

CollapsibleWidget::CollapsibleWidget(QWidget* parent) :
	QWidget(parent),
	_ui(new Ui::CollapsibleWidget),
	_animationDuration(500)
{
	_ui->setupUi(this);

	// animate both the entire widget and the content widget at the same time
	const int titleHeight = _ui->title->sizeHint().height();
	const int contentHeight = _ui->content->sizeHint().height();
	QPropertyAnimation* widgetAnimation = new QPropertyAnimation(this, "maximumHeight");
	widgetAnimation->setDuration(_animationDuration);
	widgetAnimation->setStartValue(titleHeight);
	widgetAnimation->setEndValue(titleHeight + contentHeight);
	_toggleAnimation.addAnimation(widgetAnimation);
	QPropertyAnimation* contentAnimation = new QPropertyAnimation(_ui->content, "maximumHeight");
	contentAnimation->setDuration(_animationDuration);
	contentAnimation->setStartValue(0);
	contentAnimation->setEndValue(contentHeight);
	_toggleAnimation.addAnimation(contentAnimation);

	// when the title is clicked, toggle the animation
	QObject::connect(_ui->title, &QToolButton::clicked, [this](const bool checked)
	{
		_ui->title->setArrowType(checked ? Qt::ArrowType::DownArrow : Qt::ArrowType::RightArrow);
		_toggleAnimation.setDirection(checked ? QAbstractAnimation::Forward : QAbstractAnimation::Backward);
		_toggleAnimation.start();
	});
}

CollapsibleWidget::~CollapsibleWidget()
{
	delete _ui;
}
