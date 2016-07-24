#include"maze.h"

int main()
{
	int array[5][6] =
	{
		{ 1, 1, 1, 1, 0, 1 },
		{ 0, 0, 1, 1, 0, 1 },
		{ 1, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0 },
		{ 1, 0, 1, 1, 0, 1 },
	};
	maze maze1((int*)array,5,6,1,0);
	maze1.PrintMaze();
	maze1.FindPath();
	maze1.PrintMaze();
	return 0;
}