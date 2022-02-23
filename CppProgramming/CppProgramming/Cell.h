#pragma once
#include "utils.h"
#include "Table.h"

class Cell {
protected:
	int x, y;
	Table* table;

	std::string data;

public:
	Cell(std::string data, int x, int y, Table* table) : data(data), x(x), y(y), table(table) {};

	// 가상 함수로 셀 값을 문자열로 변환한다.
	virtual std::string stringify();

	// 셀 값을 정수 데이터로 변환한다.
	virtual int to_numeric();
};