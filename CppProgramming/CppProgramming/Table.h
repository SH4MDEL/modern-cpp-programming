#pragma once
#include "utils.h"
#include "Cell.h"

namespace MyExcel {
	class Table {
	protected:
		int max_row_size, max_col_size;

		// Cell*을 보관하는 2차원 배열
		Cell*** data_table;
	public:
		Table(int max_row_size, int max_col_size);
		~Table();

		// 새로운 셀을 row행 col 열에 등록한다.
		void reg_cell(Cell* c, int row, int col);

		// 해당 셀의 정수값을 반환한다.
		// s : 셀 이름 (Ex. A3, B6 등)
		int to_numeric(const std::string s);
		// 행 및 열 번호로 셀을 호출한다.
		int to_numeric(int row, int col);

		// 해당 셀의 문자열을 반환한다.
		std::string stringify(const std::string& s);
		std::string stringify(int row, int col);

		virtual std::string print_table() = 0;
	};
}