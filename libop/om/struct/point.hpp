#pragma once

#include <string>
#include <vector>
#include <iostream>
#ifdef QT_VERSION
#include <QString>
#include <QList>
#include <QDebug>

#endif // QT_VERSION

namespace om {
#pragma region point
	struct point {
		friend std::ostream& operator<<(std::ostream& cout, const point& p) {
			cout << " point[" << p._x << "," << p._y << "] ";
			return cout;
		}
		friend std::istream& operator>>(std::istream& cin, point& date) {
			cin >> date._x >> date._y;
			return cin;
		}
#ifdef QT_VERSION
		friend QDebug& operator<<(QDebug out, const point& p) {
			out << QString(" point{%1,%2} ")
				.arg(p._x).arg(p._y);
			return out;
		}
#endif // QT_VERSION
	public:
		point() :_x(0), _y(0) {}

		point(int x, int y) {
			this->_x = _x;
			this->_y = _y;
		}

		point(const point& e) {
			this->_x = e._x;
			this->_y = e._y;
		}

		~point() {}

		int x() { return this->_x; }

		int y() { return this->_y; }

		point& operator=(const point& p) {
			auto temp(p);
			std::swap(*this, temp);
			return *this;
		}

		point(point&& e) noexcept {
			this->_x = e._x;
			this->_y = e._y;
		}

		point& operator=(point&& e) noexcept {
			if (this != &e) {
				this->_x = e._x;
				this->_y = e._y;
			}
			return *this;
		}

		std::string toStdString() {
			return "point[" + std::to_string(_x) + "," + std::to_string(_y) + "]";
		}

#ifdef QT_VERSION
		QString toQString() {
			return QString::fromStdString(toStdString());
		}
#endif

	private:
		int _x = 0, _y = 0;
	};

#pragma endregion
}