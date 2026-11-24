#pragma once

template<class T>
class Grid{
private:
	std::vector< std::vector<T> > grid;

public:
	int rows, colls;

	Grid(std::vector< std::vector<T> > _grid) : grid{_grid}{
		this->rows = _grid.size();
		this->colls = _grid.size() > 0 ? _grid[0].size() : 0;
	};

	Grid(int rows, int colls){
		resize(rows, colls);
	}

	Grid(){
		this->rows = 0;
		this->colls = 0;
	}
	std::vector<T>& operator[] ( int i ) {
		return this->grid[i];
	}

	void resize( int rows, int colls ){
		this->rows = rows;
		this->colls = colls;

		grid.resize( rows );
		for (std::vector<T>& row : grid){
			row.resize(colls);
		}
	}

	std::vector<int>::iterator begin(){
		return grid.begin();
	}

	std::vector<int>::iterator end(){
		return grid.end();
	}
};
