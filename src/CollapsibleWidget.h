#ifndef COLLAPSIBLEWIDGET_H
#define COLLAPSIBLEWIDGET_H

#include <QParallelAnimationGroup>
#include <QWidget>

namespace Ui
{
class CollapsibleWidget;
}

class CollapsibleWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CollapsibleWidget(QWidget* parent = 0);
	~CollapsibleWidget();

private:
	//! The ui.
	Ui::CollapsibleWidget* _ui;
	//! The duration of the collapse/expand animation.
	int _animationDuration; // [ms]
	//! The toggle animation.
	QParallelAnimationGroup _toggleAnimation;
};

#endif // COLLAPSIBLEWIDGET_H
