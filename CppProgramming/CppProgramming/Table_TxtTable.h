#pragma once
#include "utils.h"
#include "Table.h"

namespace MyExcel {
	class TxtTable : public Table {
		std::string repeat_char(int n, char c);

		// 숫자로 된 열 번호를 매겨준다.
		std::string col_num_to_str(int n);

	public:
		TxtTable(int row, int col);

		// 텍스트로 표를 깨끗하게 출력한다.
		std::string print_table();
	};
}

