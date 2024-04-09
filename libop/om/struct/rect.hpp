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

#pragma region e4
	struct e4 {
		friend std::ostream& operator<<(std::ostream& cout, const e4& e) {
			cout << " e4 [" << e._x1 << "," << e._y1 << "," << e._x2 << "," << e._y2 << "] " <<
#ifdef QT_VERSION
				e._remark.toStdString()
#else
				e._remark
#endif 
				;
			return cout;
		}
		friend std::istream& operator>>(std::istream& cin, e4& e) {
			cin >> e._x1 >> e._y1 >> e._x2 >> e._y2;
			return cin;
		}
#ifdef QT_VERSION
		friend QDebug& operator<<(QDebug out, const e4& e) {
			out << QString(" e4{%1,%2,%3,%4} ")
				.arg(e._x1).arg(e._y1).arg(e._x2).arg(e._y2);
			return out;
		}
#endif // QT_VERSION
	public:
		e4() :_x1(0), _y1(0), _x2(0), _y2(0), _w(0), _h(0), _remark("") {}

#ifdef QT_VERSION
		e4(int x1, int y1, int x2, int y2, const QString& remark = "") {
			this->_x1 = x1;
			this->_x2 = x2;
			this->_y1 = y1;
			this->_y2 = y2;
			this->_remark = remark;
			this->_w = std::abs(x2 - x1);
			this->_h = std::abs(y2 - y1);
	}
#else
		e4(int x1, int y1, int x2, int y2, const std::string& remark = "") {
			this->_x1 = x1;
			this->_x2 = x2;
			this->_y1 = y1;
			this->_y2 = y2;
			this->_remark = remark;
			this->_w = std::abs(x2 - x1);
			this->_h = std::abs(y2 - y1);
		}
#endif

		e4(const e4& e) {
			this->_x1 = e._x1;
			this->_x2 = e._x2;
			this->_y1 = e._y1;
			this->_y2 = e._y2;
			this->_remark = e._remark;
			this->_w = std::abs(_x2 - _x1);
			this->_h = std::abs(_y2 - _y1);
		}

		e4(e4&& e) noexcept {
			this->_x1 = e._x1;
			this->_x2 = e._x2;
			this->_y1 = e._y1;
			this->_y2 = e._y2;
			this->_remark = e._remark;
			this->_w = std::abs(_x2 - _x1);
			this->_h = std::abs(_y2 - _y1);
		}

		e4& operator=(const e4& p) {
			auto temp(p);
			std::swap(*this, temp);
			return *this;
		}

		e4& operator=(e4&& e) noexcept {
			if (this != &e) {
				this->_x1 = e._x1;
				this->_x2 = e._x2;
				this->_y1 = e._y1;
				this->_y2 = e._y2;
				this->_remark = e._remark;
				this->_w = e._w;
				this->_h = e._h;
			}
			return *this;
		}

#ifdef QT_VERSION
		QString remark() {
			return this->_remark;
		}

		QString toQString() {
			return QString::fromStdString(toStdString());
		}

		/// <summary>
		/// 用于operator<<重载时打印
		/// </summary>
		/// <returns></returns>
		QString toOperatorString() {
			return QString("%1,%2,%3,%4").arg(_x1).arg(_y1).arg(_x2).arg(_y2);
}
#else
		std::string remark() {
			return this->_remark;
		}
#endif

		std::string toStdString() {
#ifdef QT_VERSION
			return "e4 [" + std::to_string(_x1) + "," + std::to_string(_y1) + "," + std::to_string(_x2) + "," + std::to_string(_y2) + "] " + _remark.toStdString()
				+ " (" + std::to_string(_w) + "," + std::to_string(_h) + ")";
#else
			return "e4 [" + std::to_string(_x1) + "," + std::to_string(_y1) + "," + std::to_string(_x2) + "," + std::to_string(_y2) + "] " + _remark
				+ " (" + std::to_string(_w) + "," + std::to_string(_h) + ")";
#endif            
		}

		int x1() {
			return this->_x1;
		}
		int x2() {
			return this->_x2;
		}
		int y1() {
			return this->_y1;
		}
		int y2() {
			return this->_y2;
		}

		int w() {
			return this->_w;
		}
		int h() {
			return this->_h;
		}

	private:
		int _x1 = 0, _y1 = 0, _x2 = 0, _y2 = 0, _w = 0, _h = 0;
	public:
#ifdef QT_VERSION
		QString _remark = "";
#else
		std::string _remark = "";
#endif
	};

#pragma endregion

#pragma region e8
	struct e8 {
		friend std::ostream& operator<<(std::ostream& cout, const e8& e) {
#ifdef QT_VERSION
			cout << "e8 [" << e._x1 << "," << e._y1 << "," << e._x2 << "," << e._y2 << ","
				<< e._cx1 << "," << e._cy1 << "," << e._cx2 << "," << e._cy2 << "]" << e._remark.toStdString();
			return cout;
#else
			cout << "e8 [" << e._x1 << "," << e._y1 << "," << e._x2 << "," << e._y2 << ","
				<< e._cx1 << "," << e._cy1 << "," << e._cx2 << "," << e._cy2 << "]" << e._remark;
			return cout;
#endif // QT_VERSION

	}
		friend std::istream& operator>>(std::istream& cin, e8& e) {
			cin >> e._x1 >> e._y1 >> e._x2 >> e._y2 >> e._cx1 >> e._cy1 >> e._cx2 >> e._cy2;
			return cin;
		}
#ifdef QT_VERSION
		friend QDebug& operator<<(QDebug out, const e8& e) {
			out << QString(" e8{%1,%2,%3,%4,%5,%6,%7,%8} ")
				.arg(e._x1).arg(e._y1).arg(e._x2).arg(e._y2).arg(e._cx1).arg(e._cy1).arg(e._cx2).arg(e._cy2);
			return out;
		}
#endif // QT_VERSION
	public:
		e8() :_x1(0), _y1(0), _x2(0), _y2(0), _cx1(0), _cy1(0), _cx2(0), _cy2(0), _w(0), _h(0), _remark(""), _valueValid(true) {}

#ifdef QT_VERSION
		e8(int x1, int y1, int x2, int y2, int cx1, int cy1, int cx2, int cy2, const QString& remark = "") {
			this->_x1 = x1;
			this->_x2 = x2;
			this->_y1 = y1;
			this->_y2 = y2;
			this->_cx1 = cx1;
			this->_cx2 = cx2;
			this->_cy1 = cy1;
			this->_cy2 = cy2;
			this->_remark = remark;
			this->_w = std::abs(x2 - x1);
			this->_h = std::abs(y2 - y1);
		}
#else
		e8(int x1, int y1, int x2, int y2, int cx1, int cy1, int cx2, int cy2, const std::string& remark = "") {
			this->_x1 = x1;
			this->_x2 = x2;
			this->_y1 = y1;
			this->_y2 = y2;
			this->_cx1 = cx1;
			this->_cx2 = cx2;
			this->_cy1 = cy1;
			this->_cy2 = cy2;
			this->_remark = remark;
			this->_w = std::abs(x2 - x1);
			this->_h = std::abs(y2 - y1);
		}
#endif

		e8(const e8& e) {
			this->_x1 = e._x1;
			this->_x2 = e._x2;
			this->_y1 = e._y1;
			this->_y2 = e._y2;
			this->_cx1 = e._cx1;
			this->_cx2 = e._cx2;
			this->_cy1 = e._cy1;
			this->_cy2 = e._cy2;
			this->_remark = e._remark;
			this->_w = std::abs(e._x2 - e._x1);
			this->_h = std::abs(e._y2 - e._y1);
		}

		~e8() {}

		e8& operator=(const e8& e) {
			this->_x1 = e._x1;
			this->_x2 = e._x2;
			this->_y1 = e._y1;
			this->_y2 = e._y2;
			this->_cx1 = e._cx1;
			this->_cx2 = e._cx2;
			this->_cy1 = e._cy1;
			this->_cy2 = e._cy2;
			this->_remark = e._remark;
			this->_w = std::abs(e._x2 - e._x1);
			this->_h = std::abs(e._y2 - e._y1);
			//auto temp(p);
			//std::swap(*this, temp);
			return *this;
		}

		e8(e8&& e) noexcept {
			this->_x1 = e._x1;
			this->_x2 = e._x2;
			this->_y1 = e._y1;
			this->_y2 = e._y2;
			this->_cx1 = e._cx1;
			this->_cx2 = e._cx2;
			this->_cy1 = e._cy1;
			this->_cy2 = e._cy2;
			this->_remark = e._remark;
			this->_w = std::abs(e._x2 - e._x1);
			this->_h = std::abs(e._y2 - e._y1);
		}

		e8& operator=(e8&& e) noexcept {
			if (this != &e) {
				this->_x1 = e._x1;
				this->_x2 = e._x2;
				this->_y1 = e._y1;
				this->_y2 = e._y2;
				this->_cx1 = e._cx1;
				this->_cx2 = e._cx2;
				this->_cy1 = e._cy1;
				this->_cy2 = e._cy2;
				this->_remark = e._remark;
				this->_w = std::abs(e._x2 - e._x1);
				this->_h = std::abs(e._y2 - e._y1);
			}
			return *this;
		}

		std::string toStdString() {
#ifdef QT_VERSION
			return "e8 [" + std::to_string(_x1) + "," + std::to_string(_y1) + "," + std::to_string(_x2) + "," + std::to_string(_y2) + "]" + " (" + std::to_string(_cx1) + "," + std::to_string(_cy1) + "," + std::to_string(_cx2) + "," + std::to_string(_cy2) + ")" + "【" + std::to_string(_w) + "," + std::to_string(_h) + "】" + _remark.toStdString();
#else
			return "e8 [" + std::to_string(_x1) + "," + std::to_string(_y1) + "," + std::to_string(_x2) + "," + std::to_string(_y2) + "]"
				+ " (" + std::to_string(_cx1) + "," + std::to_string(_cy1) + "," + std::to_string(_cx2) + "," + std::to_string(_cy2) + ")"
				+ "【" + std::to_string(_w) + "," + std::to_string(_h) + "】" + _remark;
#endif // QT_VERSION

		}

		int x1() {
			return this->_x1;
		}
		int x2() {
			return this->_x2;
		}
		int y1() {
			return this->_y1;
		}
		int y2() {
			return this->_y2;
		}

		int cx1() {
			return this->_cx1;
		}
		int cx2() {
			return this->_cx2;
		}
		int cy1() {
			return this->_cy1;
		}
		int cy2() {
			return this->_cy2;
		}


#ifdef QT_VERSION
		QString remark() {
			return this->_remark;
		}

		QString toQString() {
			return QString::fromStdString(toStdString());
		}

		/// <summary>
		/// 用于operator<<重载时打印
		/// </summary>
		/// <returns></returns>
		QString toOperatorString() {
			return QString("%1,%2,%3,%4,%5,%6,%7,%8").arg(_x1).arg(_y1).arg(_x2).arg(_y2).arg(_cx1).arg(_cy1).arg(_cx2).arg(_cy2);
		}
#else
		std::string remark() {
			return this->_remark;
		}
#endif

		int w() {
			return this->_w;
		}
		int h() {
			return this->_h;
		}

		bool valueValid() {
			return _valueValid;
		}

	private:
		int _x1 = 0;
		int _y1 = 0;
		int _x2 = 0;
		int _y2 = 0;
		int _cx1 = 0;
		int _cy1 = 0;
		int _cx2 = 0;
		int _cy2 = 0;
		int _w = 0;
		int _h = 0;
		bool _valueValid = false;
	public:
#ifdef QT_VERSION
		QString _remark = "";
#else
		std::string _remark = "";
#endif
	};

#pragma endregion

}