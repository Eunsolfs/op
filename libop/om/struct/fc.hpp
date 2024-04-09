#pragma once

#include <string>
#include <iostream>
#include "rect.hpp"
#ifdef QT_VERSION
#include <QString>
#include <QList>
#include <QDebug>

#endif // QT_VERSION

namespace om {
#pragma region fc
	struct fc {
		friend std::ostream& operator<<(std::ostream& cout, const fc& ee) {
			fc e = ee;
#ifdef QT_VERSION
			cout << " fc:[" << e.m_e4f << "," << e.m_color.toStdString() << ","
				<< e.m_sim << "," << e.m_dir << "," << "] ";
			return cout;
#else
			cout << " fc:[" << e.m_e4f << "," << e.m_color << ","
				<< e.m_sim << "," << e.m_dir << "] ";
			return cout;
#endif
		}

#ifdef QT_VERSION
		friend QDebug& operator<<(QDebug out, fc info) {
			out << QString("fc{%1,%2,%3,%4}")
				.arg(info.m_e4f.toOperatorString())
				.arg(info.m_color).arg(info.m_sim).arg(info.m_dir);
			return out;
	}
#endif // QT_VERSION

	public:
		fc() : m_e4f(e4()), m_color(""), m_sim(1.0), m_dir(0), m_needModifyOffsetColor(true) {}

#ifdef QT_VERSION
		fc(int _x1, int _y1, int _x2, int _y2,
		   const QString& _color, double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true) {
			this->m_e4f = e4{_x1, _y1, _x2, _y2};
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
			this->m_color = _color;
		}

		fc(const e4& _edge, const QString& _color, double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true) {
			this->m_e4f = _edge;
			this->m_color = _color;
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
}
#else
		fc(int _x1, int _y1, int _x2, int _y2,
		   const std::string& _color, double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true) {
			this->m_e4f = e4{_x1, _y1, _x2, _y2};
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
			this->m_color = _color;
		}

		fc(const e4& _edge, const std::string& _color, double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true) {
			this->m_e4f = _edge;
			this->m_color = _color;
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
		}
#endif

		fc(const fc& f) {
			this->m_e4f = f.m_e4f;
			this->m_color = f.m_color;
			this->m_sim = f.m_sim;
			this->m_dir = f.m_dir;
			this->m_needModifyOffsetColor = f.m_needModifyOffsetColor;
		}

		fc(fc&& other) noexcept {
			this->m_e4f = other.m_e4f;
			this->m_color = other.m_color;
			this->m_sim = other.m_sim;
			this->m_dir = other.m_dir;
			this->m_needModifyOffsetColor = other.m_needModifyOffsetColor;
		}

		fc& operator=(const fc& f) {
			auto temp(f);
			std::swap(*this, temp);
			return *this;
		}

		fc& operator=(fc&& other) noexcept {
			if (this != &other) {
				this->m_e4f = other.m_e4f;
				this->m_color = other.m_color;
				this->m_sim = other.m_sim;
				this->m_dir = other.m_dir;
				this->m_needModifyOffsetColor = other.m_needModifyOffsetColor;
			}
			return *this;
		}

		~fc() {}

		e4 edge4() { return this->m_e4f; }

		int x1() { return this->m_e4f.x1(); }
		int x2() { return this->m_e4f.x2(); }
		int y1() { return this->m_e4f.y1(); }
		int y2() { return this->m_e4f.y2(); }

#ifdef QT_VERSION

		void set_color(const QString& t) { this->m_color = t; }

		QString color() { return m_color; }

		QString toQString() { return QString::fromStdString(toStdString()); }
#else
		std::string color() { return m_color; }

		void set_color(const std::string& t) { this->m_color = t; }

#endif

		int dir() { return this->m_dir; }

		double sim() { return this->m_sim; }

		bool needModifyOffsetColor() { return this->m_needModifyOffsetColor; }

		void set_needModifyOffsetColor(bool t) { this->m_needModifyOffsetColor = t; }


		fc set_e4(const e4& e) { return fc{e, this->m_color, this->m_sim, this->m_dir, this->m_needModifyOffsetColor}; }

		std::string toStdString() {
#ifdef QT_VERSION
			return "fc {" +
				std::to_string(m_e4f.x1()) + "," +
				std::to_string(m_e4f.y1()) + "," +
				std::to_string(m_e4f.x2()) + "," +
				std::to_string(m_e4f.y2()) + "," +
				m_color.toStdString() + "," +
				std::to_string(m_sim) + "," +
				std::to_string(m_dir) + "}";
#else
			return "fc {" +
				std::to_string(m_e4f.x1()) + "," +
				std::to_string(m_e4f.y1()) + "," +
				std::to_string(m_e4f.x2()) + "," +
				std::to_string(m_e4f.y2()) + "," +
				m_color + "," +
				std::to_string(m_sim) + "," +
				std::to_string(m_dir) + "}";
#endif // QT_VERSION

		}

	private:
		bool m_needModifyOffsetColor = true;
		double m_sim = 1.0;
		int m_dir = 0;
		e4 m_e4f;
#ifdef QT_VERSION
		QString m_color = "";
#else
		std::string m_color = "";
#endif
	};

#pragma endregion
}