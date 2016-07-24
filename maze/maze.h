#ifndef _MAZE_H_
#define _MAZE_H_

#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

//坐标
struct Pos
{
	int _x;
	int _y;

	Pos(int x, int y)
		:_x(x)
		,_y(y)
	{}
};

//迷宫类
class maze
{
public:
	//用数组初始化，并告知数组行列
	maze(int* mazeArray,int xLength,int yLength,int xEnter,int yEnter)
		:_mazeArray(new int[xLength*yLength])
		, _xLength(xLength)
		, _yLength(yLength)
		, _enterPose(xEnter,yEnter)
	{
		memcpy(_mazeArray,mazeArray,sizeof(int)*xLength*yLength);
	}

	//打印迷宫
	void PrintMaze()
	{
		for (int x = 0; x < _xLength; ++x)
		{
			for (int y = 0; y < _yLength; ++y)
			{
				printf("%3d", _mazeArray[x*_yLength + y]);
			}
			cout << endl;
		}
		cout << endl;
	}


	//走过的节点赋值为-1，可通路径赋值2，最优路径赋值3
	void FindPath()
	{
		//一个保存全部路径，一个保存当前路径
		vector<vector<Pos>> allPath;
		vector<Pos> path;

		//入口有误
		if (_mazeArray[_yLength*_enterPose._x + _enterPose._y] == 1)
		{
			cout << "入口有误" << endl;
			return;
		}

		_mazeArray[_yLength*_enterPose._x + _enterPose._y] = -1;
		path.push_back(_enterPose);
		_FindPath(allPath, path);
		//弹出最后一条入口节点通路
		allPath.pop_back();

		//标记路径
		MarkPath(allPath);
	}
	
	void _FindPath(vector<vector<Pos>> &allPath, vector<Pos> path)
	{
		struct Pos upPos = path.back();
		upPos._x -= 1;
		struct Pos downPos = path.back();
		downPos._x += 1;
		struct Pos leftPos = path.back();
		leftPos._y -= 1;
		struct Pos rightPos = path.back();
		rightPos._y += 1;
		

		//上方路径判断
		if (!IsFinded(upPos) && !IsOut(upPos))
		{
			_mazeArray[upPos._x*_yLength + upPos._y] = -1;
			path.push_back(upPos);
			_FindPath(allPath, path);
		}

		//下方路径判断
		if (!IsFinded(downPos) && !IsOut(downPos))
		{
			_mazeArray[downPos._x*_yLength + downPos._y] = -1;
			path.push_back(downPos);
			_FindPath(allPath, path);
		}

		//左边路径判断
		if (!IsFinded(leftPos) && !IsOut(leftPos))
		{
			_mazeArray[leftPos._x*_yLength + leftPos._y] = -1;
			path.push_back(leftPos);
			_FindPath(allPath, path);
		}

		//右边路径判断
		if (!IsFinded(rightPos) && !IsOut(rightPos))
		{
			_mazeArray[rightPos._x*_yLength + rightPos._y] = -1;
			path.push_back(rightPos);
			_FindPath(allPath, path);
		}

		//有一个出口超出界限就记下路径
		if (IsOut(upPos) || IsOut(downPos) || IsOut(leftPos) || IsOut(rightPos))
		{
			allPath.push_back(path);
		}
	}

	//标记走过的路径
	//走过的节点赋值为-1，可通路径赋值2，最优路径赋值3
	void MarkPath(vector<vector<Pos>> &allPath)
	{
	    //标记可走通路径为2
		if (allPath.size() == 0)
		{
			cout << "没有通路" << endl;
			return;
		}
		else if(allPath.size() == 1)//一条路必为最优
		{
			for (int i = 0; i < allPath[0].size(); ++i)
				_mazeArray[allPath[0][i]._x*_yLength + allPath[0][i]._y] = 3;
		}
		else
		{
			//假设第0条路最优
			//最少步数为零
			int bestPath = 0;
			int bestFoot = 0;
			
			for (int i = 0; i < allPath.size(); ++i)
			{
				//求最优路径
				if (bestFoot>allPath[i].size())
				{
					bestPath = i;
					bestFoot = allPath[i].size();
				}
				//所有可通路径赋值为2
				for (int j = 0; j < allPath[i].size(); ++j)
				{
					_mazeArray[allPath[i][j]._x*_yLength + allPath[i][j]._y] = 2;
				}
			}
			
			for (int i = 0; i < allPath[bestPath].size(); ++i)
			{
				_mazeArray[allPath[bestPath][i]._x*_yLength + allPath[bestPath][i]._y] = 3;
			}
			
		}
	}

	//是否已经走过
	//是否是墙
	bool IsFinded(Pos curPos)
	{
		if (IsOut(curPos))
			return true;
		if (_mazeArray[curPos._x*_yLength + curPos._y] == -1 || _mazeArray[curPos._x*_yLength + curPos._y]==1)
			return true;
		return false;
	}

	//是否已经超出边界
	bool IsOut(Pos curPos)
	{
		if (curPos._y<0 || curPos._y>=_yLength || curPos._x<0 || curPos._x>=_xLength)
			return true;
		return false;
	}

	~maze()
	{
		delete[] _mazeArray;
	}
	
private:
	int* _mazeArray;//迷宫指针
	int _xLength;   //迷宫行数
	int _yLength;   //迷宫列数
	struct Pos _enterPose; //迷宫入口
};

#endif