#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "rect.hpp"

#ifdef QT_VERSION
#include <QString>
#include <QList>
#include <QDebug>
#endif // QT_VERSION

namespace om {
#pragma region fmc
	struct fmc {
		friend std::ostream& operator<<(std::ostream& cout, const fmc& ee) {
#ifdef QT_VERSION
			fmc e = ee;
			cout << " fmc:[" << e.m_e8 << "," << e.m_firstColor.toStdString() << "," << e.m_offectColor.toStdString() << ","
				<< e.m_sim << "," << e.m_dir << "," << e.m_remark.toStdString() << "] ";
			return cout;
#else
			fmc e = ee;
			cout << " fmc:[" << e.m_e8 << "," << e.m_firstColor << "," << e.m_offectColor << ","
				<< e.m_sim << "," << e.m_dir << "," << e.m_remark << "] ";
			return cout;
#endif
		}

#ifdef QT_VERSION
		friend QDebug& operator<<(QDebug out, fmc info) {
			out << QString(" fmc{%1,%2,%3,%4,%5,%6} ")
				.arg(info.m_e8.toOperatorString())
				.arg(info.m_firstColor).arg(info.m_offectColor).arg(info.m_sim).arg(info.m_dir).arg(info.m_remark);
			return out;
		}
#endif // QT_VERSION
	public:
		fmc() :m_e8(e8()), m_firstColor(""), m_offectColor(""), m_sim(1.0), m_dir(0), m_needModifyOffsetColor(true), m_remark("") {}

#ifdef QT_VERSION
		fmc(int _x1, int _y1, int _x2, int _y2, int _cx1, int _cy1, int _cx2, int _cy2,
			const QString& _firstColor, const QString& _offectColor,
			double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true, const QString& _remark = "") {
			this->m_e8 = e8(_x1, _y1, _x2, _y2, _cx1, _cy1, _cx2, _cy2);
			this->m_firstColor = _firstColor;
			this->m_offectColor = _offectColor;
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
			this->m_remark = _remark;
		}

		fmc(const e8& _edge, const QString& _firstColor, const QString& _offectColor,
			double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true, const QString& _remark = "") {
			this->m_e8 = _edge;
			this->m_firstColor = _firstColor;
			this->m_offectColor = _offectColor;
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
			this->m_remark = _remark;
		}
#else
		fmc(int _x1, int _y1, int _x2, int _y2, int _cx1, int _cy1, int _cx2, int _cy2,
			const std::string& _firstColor, const std::string& _offectColor,
			double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true, const std::string& _remark = "") {
			this->m_e8 = e8(_x1, _y1, _x2, _y2, _cx1, _cy1, _cx2, _cy2);
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
			this->m_firstColor = _firstColor;
			this->m_offectColor = _offectColor;
			this->m_remark = _remark;
		}

		fmc(const e8& _edge, const std::string& _firstColor, const std::string& _offectColor,
			double _sim = 1.0, int _dir = 0, bool _needModifyOffsetColor = true, const std::string& _remark = "") {
			this->m_e8 = _edge;
			this->m_sim = _sim;
			this->m_dir = _dir;
			this->m_needModifyOffsetColor = _needModifyOffsetColor;
			this->m_firstColor = _firstColor;
			this->m_offectColor = _offectColor;
			this->m_remark = _remark;
		}
#endif // QT_VERSION

		fmc(const fmc& f) {
			this->m_e8 = f.m_e8;
			this->m_sim = f.m_sim;
			this->m_dir = f.m_dir;
			this->m_needModifyOffsetColor = f.m_needModifyOffsetColor;
			this->m_firstColor = f.m_firstColor;
			this->m_offectColor = f.m_offectColor;
			this->m_remark = f.m_remark;
		}

		fmc& operator=(const fmc& f) {
			auto temp(f);
			std::swap(*this, temp);
			return *this;
		}

		fmc(fmc&& other) noexcept {
			m_needModifyOffsetColor = other.m_needModifyOffsetColor;
			m_firstColor = other.m_firstColor;
			m_offectColor = other.m_offectColor;
			m_sim = other.m_sim;
			m_dir = other.m_dir;
			m_e8 = other.m_e8;
			m_remark = other.m_remark;
		}

		fmc& operator=(fmc&& other) noexcept {
			if (this != &other) {
				m_needModifyOffsetColor = other.m_needModifyOffsetColor;
				m_firstColor = other.m_firstColor;
				m_offectColor = other.m_offectColor;
				m_sim = other.m_sim;
				m_dir = other.m_dir;
				m_e8 = other.m_e8;
				m_remark = other.m_remark;
			}
			return *this;
		}

		~fmc() {}

		int x1() {
			return this->m_e8.x1();
		}
		int y1() {
			return this->m_e8.y1();
		}
		int x2() {
			return this->m_e8.x2();
		}
		int y2() {
			return this->m_e8.y2();
		}

		int cx1() {
			return this->m_e8.cx1();
		}
		int cy1() {
			return this->m_e8.cy1();
		}
		int cx2() {
			return this->m_e8.cx2();
		}
		int cy2() {
			return this->m_e8.cy2();
		}

		int dir() {
			return this->m_dir;
		}

		double sim() {
			return this->m_sim;
		}

#ifdef QT_VERSION
		QString remark() {
			return this->m_remark;
		}

		QString firstColor() {
			return this->m_firstColor;
		}

		QString offsetColor() {
			return this->m_offectColor;
		}

		QString toQString() {
			return QString::fromStdString(toStdString());
		}

		void set_FindArea(QList<int> t) {
			this->m_e8 = e8(t.at(0), t.at(1), t.at(2), t.at(3),
							this->m_e8.cx1(), this->m_e8.cy1(), this->m_e8.cx2(), this->m_e8.cy2());
		}

		void set_ClickArea(QList<int> t) {
			this->m_e8 = e8(this->m_e8.x1(), this->m_e8.y1(), this->m_e8.x2(), this->m_e8.y2(),
							t.at(0), t.at(1), t.at(2), t.at(3));
		}

		void set_firstColor(const QString& t) {
			this->m_firstColor = t;
		}

		void set_offsetColor(const QString& t) {
			this->m_offectColor = t;
		}


#else
		std::string remark() {
			return this->m_remark;
		}

		std::string firstColor() {
			return this->m_firstColor;
		}

		std::string offsetColor() {
			return this->m_offectColor;
		}

		void set_firstColor(const std::string& t) {
			this->m_firstColor = t;
		}

		void set_offsetColor(const std::string& t) {
			this->m_offectColor = t;
		}
#endif

		e8 Edge8() {
			return this->m_e8;
		}

		bool needModifyOffsetColor() {
			return this->m_needModifyOffsetColor;
		}

		e4 FindArea() {
			return e4(m_e8.x1(), m_e8.y1(), m_e8.x2(), m_e8.y2());
		}

		e4 ClickArea() {
			if (m_e8.cx1() + m_e8.cy1() + m_e8.cx2() + m_e8.cy2() == 0) {
				std::cout << "错误的请求，返回 get_FindArea" << m_e8.toStdString();
				return FindArea();
			}
			return e4(m_e8.cx1(), m_e8.cy1(), m_e8.cx2(), m_e8.cy2());
		}

		std::string toStdString() {
#ifdef QT_VERSION
			return "fmc {" +
				std::to_string(m_e8.x1()) + "," +
				std::to_string(m_e8.y1()) + "," +
				std::to_string(m_e8.x2()) + "," +
				std::to_string(m_e8.y2()) + "," +
				std::to_string(m_e8.cx1()) + "," +
				std::to_string(m_e8.cy1()) + "," +
				std::to_string(m_e8.cx2()) + "," +
				std::to_string(m_e8.cy2()) + "," +
				m_firstColor.toStdString() + "," +
				m_offectColor.toStdString() + "," +
				std::to_string(m_sim) + "," +
				std::to_string(m_dir) + "}";
#else
			return "fmc {" +
				std::to_string(m_e8.x1()) + "," +
				std::to_string(m_e8.y1()) + "," +
				std::to_string(m_e8.x2()) + "," +
				std::to_string(m_e8.y2()) + "," +
				std::to_string(m_e8.cx1()) + "," +
				std::to_string(m_e8.cy1()) + "," +
				std::to_string(m_e8.cx2()) + "," +
				std::to_string(m_e8.cy2()) + "," +
				m_firstColor + "," +
				m_offectColor + "," +
				std::to_string(m_sim) + "," +
				std::to_string(m_dir) + "}";
#endif
		}

		void set_remark(const std::string& r) {
#ifdef QT_VERSION
			this->m_remark = QString::fromStdString(r);
#else
			this->m_remark = r;
#endif
		}

		void set_Edge8(const e8& e) { this->m_e8 = e; }

		void set_dir(int t) { this->m_dir = t; }

		void set_sim(double t) { this->m_sim = t; }

		void set_needModifyOffsetColor(bool t) {
			this->m_needModifyOffsetColor = t;
		}

		void set_FindArea(std::vector<int> t) {
			this->m_e8 = e8(t.at(0), t.at(1), t.at(2), t.at(3),
							this->m_e8.cx1(), this->m_e8.cy1(), this->m_e8.cx2(), this->m_e8.cy2());
		}

		void set_FindArea(e4 t) {
			this->m_e8 = e8(t.x1(), t.y1(), t.x2(), t.y2(),
							this->m_e8.cx1(), this->m_e8.cy1(), this->m_e8.cx2(), this->m_e8.cy2());
		}

		void set_ClickArea(std::vector<int> t) {
			this->m_e8 = e8(this->m_e8.x1(), this->m_e8.y1(), this->m_e8.x2(), this->m_e8.y2(),
							t.at(0), t.at(1), t.at(2), t.at(3));
		}

		void set_ClickArea(e4 t) {
			this->m_e8 = e8(this->m_e8.x1(), this->m_e8.y1(), this->m_e8.x2(), this->m_e8.y2(),
							t.x1(), t.y1(), t.x2(), t.y2());
		}

		fmc changeEdge(const e8& e) {
			return fmc(e, this->m_firstColor, this->m_offectColor, this->m_sim, this->m_dir, this->m_needModifyOffsetColor);
		}

		fmc changeEdge(int _x1, int _y1, int _x2, int _y2, int _Cx1, int _Cy1, int _Cx2, int _Cy2) {
			return fmc(_x1, _y1, _x2, _y2, _Cx1, _Cy1, _Cx2, _Cy2,
					   this->m_firstColor, this->m_offectColor, this->m_sim, this->m_dir, this->m_needModifyOffsetColor, this->m_remark);
		}

		fmc changeFindEdge(int _x1, int _y1, int _x2, int _y2) {
			return fmc(_x1, _y1, _x2, _y2,
					   this->m_e8.cx1(), this->m_e8.cy1(), this->m_e8.cx2(), this->m_e8.cy2(),
					   this->m_firstColor, this->m_offectColor, this->m_sim, this->m_dir, this->m_needModifyOffsetColor, this->m_remark);
		}

		fmc changeFindEdge(e4 f) {
			return fmc(f.x1(), f.y1(), f.x2(), f.y2(),
					   this->m_e8.cx1(), this->m_e8.cy1(), this->m_e8.cx2(), this->m_e8.cy2(),
					   this->m_firstColor, this->m_offectColor, this->m_sim, this->m_dir, this->m_needModifyOffsetColor, this->m_remark);
		}

	private:
		bool m_needModifyOffsetColor = true;
		double m_sim = 1.0;
		int m_dir = 0;
		e8 m_e8;
#ifdef QT_VERSION
		QString m_firstColor, m_offectColor;
		QString m_remark = "";
#else
		std::string m_firstColor, m_offectColor;
		std::string m_remark = "";
#endif
	};

#pragma endregion
}
