#include <iostream>
#include <vector>
#include "Grid.hpp"
#include <fstream>

using namespace std;

Grid<int> grid;

int is_valid(Grid<int> grid, int x, int y){
	return (grid[x][y] == 0);
}

std::vector< std::pair<int, int> > path;
std::vector< std::vector< std::pair<int, int> > > paths;

void print_path(Grid<int> grid, std::vector<std::pair<int,int> > path){
	for(std::pair<int, int> point : path){
		grid[point.first][point.second] = 2;
	}

		for( int i = 0; i < grid.rows; i++ ){
			for( int j = 0; j < grid.colls; j ++ )
			{
				int cell = grid[i][j];

				if( cell == 1 ){
					cout << "# ";
				} else if( cell == 2 ){
					cout << "~ ";
				} else {
					cout << "  ";
				}
			}
		cout << "\n";
	}
}

void get_path(Grid<int> grid, int x, int y, int x1, int y1){
	path.push_back(make_pair(x, y));
	if ( x == x1 && y == y1 ){
		paths.push_back(path);
		print_path(grid, path);

		path.pop_back();
		return;
	}

	if ( x + 1 < grid.rows && is_valid( grid, x, y ) ){
		get_path( grid, x+1, y, x1, y1 );
	}

	if ( y + 1 < grid.colls && is_valid( grid, x, y ) ){
		get_path( grid, x, y+1, x1, y1 );
	}
	path.pop_back();
}

int main(){

	int n, m;

	ifstream f("grid.in");

	f >> n >> m;
	grid.resize(n, m);

	for( int i = 0; i < grid.rows; i++ ){
		for( int j = 0; j < grid.colls; j ++ )
			grid[i][j] = 0;
	}

	int x, y;
	while( f >> x >> y ){
		grid[x][y] = 1;
	}

	f.close();

	get_path(grid, 0, 0, grid.rows-1, grid.colls-1);

}
