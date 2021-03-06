#ifndef WSEARCHLINEEDIT_H
#define WSEARCHLINEEDIT_H

#include <QLineEdit>
#include <QToolButton>
#include <QLabel>
#include <QTimer>
#include <QDomNode>
#include <QColor>
#include <QEvent>

#include "configobject.h"
#include "skin/skincontext.h"
#include "widget/wbasewidget.h"

class WSearchLineEdit : public QLineEdit, public WBaseWidget {
    Q_OBJECT
  public:
    WSearchLineEdit(ConfigObject<ConfigValue>* pConfig,
                    QWidget* pParent);
    virtual ~WSearchLineEdit();

    void setup(QDomNode node, const SkinContext& context);

  protected:
    void resizeEvent(QResizeEvent*);
    virtual void focusInEvent(QFocusEvent*);
    virtual void focusOutEvent(QFocusEvent*);
    bool event(QEvent* pEvent);

  signals:
    void search(const QString& text);
    void searchCleared();
    void searchStarting();

  public slots:
    void restoreSearch(const QString& text);

  private slots:
    void updateCloseButton(const QString& text);
    void slotSetupTimer(const QString& text);
    void triggerSearch();

  private:
    void showPlaceholder();

    QTimer m_searchTimer;
    QToolButton* m_clearButton;
    bool m_place;
    QColor m_fgc; //Foreground color
};

#endif
