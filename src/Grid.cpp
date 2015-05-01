/*--------------------------------------------------------------------------*/
#include <sstream>
/*--------------------------------------------------------------------------*/
#include "Grid.h"
#include "Cell.h"
/*--------------------------------------------------------------------------*/

/***********************************************/
Grid::Grid(const std::string& init)
{
	uint16_t colNum = 0;
	uint16_t rowNum = 0;
	std::stringstream ss(init);

	if(!(ss >> colNum >> rowNum))
		THROW("Error while reading size of grid");

	if(colNum == 0 || rowNum == 0)
		THROW("Invalid size of grid. cNum=" << colNum << ", rNum=" << rowNum);

	_grid.reserve(colNum);

	for(uint16_t col = 0; col < colNum; ++col)
	{
		_grid.at(col).reserve(rowNum);
		std::vector<pCell>& columnVecRef = _grid.at(col);

		for(uint16_t row = 0; row < rowNum; ++row)
		{
			pCell cell;
			uint8_t cellType;

			if(!(ss >> cellType))
				THROW("Error while reading grid");

			cell = pCell(new Cell(cellType));
			columnVecRef.push_back(cell);
		}
	}
}

/***********************************************/
Grid::~Grid()
{

}

/***********************************************/
uint16_t Grid::colNum() const
{
	return _grid.size();
}

/***********************************************/
uint16_t Grid::rowNum() const
{
	return _grid.at(0).size();
}