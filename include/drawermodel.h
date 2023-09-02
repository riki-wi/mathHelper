#pragma once

#include <QAbstractListModel>
#include <vector>

class DrawerModel: public QAbstractListModel
{
    Q_OBJECT

private:
    struct Cell
    {
    private:
        QString m_title;
        QString m_source;

    public:
        Cell() = default;
        Cell(QString title, QString source):
            m_title(std::move(title)),
            m_source(std::move(source)){}

        QString title() const;
        QString source() const;
    };

    std::vector<Cell> m_cells;

    enum Roles
    {
        TitleRole = Qt::UserRole + 1,
        SourceRole
    };

public:
    DrawerModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QString getTitleAt(int index) const;
    Q_INVOKABLE QString getSourceAt(int index) const;
};
