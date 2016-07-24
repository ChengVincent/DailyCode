#ifndef _MAZE_H_
#define _MAZE_H_

#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

//����
struct Pos
{
	int _x;
	int _y;

	Pos(int x, int y)
		:_x(x)
		,_y(y)
	{}
};

//�Թ���
class maze
{
public:
	//�������ʼ��������֪��������
	maze(int* mazeArray,int xLength,int yLength,int xEnter,int yEnter)
		:_mazeArray(new int[xLength*yLength])
		, _xLength(xLength)
		, _yLength(yLength)
		, _enterPose(xEnter,yEnter)
	{
		memcpy(_mazeArray,mazeArray,sizeof(int)*xLength*yLength);
	}

	//��ӡ�Թ�
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


	//�߹��Ľڵ㸳ֵΪ-1����ͨ·����ֵ2������·����ֵ3
	void FindPath()
	{
		//һ������ȫ��·����һ�����浱ǰ·��
		vector<vector<Pos>> allPath;
		vector<Pos> path;

		//�������
		if (_mazeArray[_yLength*_enterPose._x + _enterPose._y] == 1)
		{
			cout << "�������" << endl;
			return;
		}

		_mazeArray[_yLength*_enterPose._x + _enterPose._y] = -1;
		path.push_back(_enterPose);
		_FindPath(allPath, path);
		//�������һ����ڽڵ�ͨ·
		allPath.pop_back();

		//���·��
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
		

		//�Ϸ�·���ж�
		if (!IsFinded(upPos) && !IsOut(upPos))
		{
			_mazeArray[upPos._x*_yLength + upPos._y] = -1;
			path.push_back(upPos);
			_FindPath(allPath, path);
		}

		//�·�·���ж�
		if (!IsFinded(downPos) && !IsOut(downPos))
		{
			_mazeArray[downPos._x*_yLength + downPos._y] = -1;
			path.push_back(downPos);
			_FindPath(allPath, path);
		}

		//���·���ж�
		if (!IsFinded(leftPos) && !IsOut(leftPos))
		{
			_mazeArray[leftPos._x*_yLength + leftPos._y] = -1;
			path.push_back(leftPos);
			_FindPath(allPath, path);
		}

		//�ұ�·���ж�
		if (!IsFinded(rightPos) && !IsOut(rightPos))
		{
			_mazeArray[rightPos._x*_yLength + rightPos._y] = -1;
			path.push_back(rightPos);
			_FindPath(allPath, path);
		}

		//��һ�����ڳ������޾ͼ���·��
		if (IsOut(upPos) || IsOut(downPos) || IsOut(leftPos) || IsOut(rightPos))
		{
			allPath.push_back(path);
		}
	}

	//����߹���·��
	//�߹��Ľڵ㸳ֵΪ-1����ͨ·����ֵ2������·����ֵ3
	void MarkPath(vector<vector<Pos>> &allPath)
	{
	    //��ǿ���ͨ·��Ϊ2
		if (allPath.size() == 0)
		{
			cout << "û��ͨ·" << endl;
			return;
		}
		else if(allPath.size() == 1)//һ��·��Ϊ����
		{
			for (int i = 0; i < allPath[0].size(); ++i)
				_mazeArray[allPath[0][i]._x*_yLength + allPath[0][i]._y] = 3;
		}
		else
		{
			//�����0��·����
			//���ٲ���Ϊ��
			int bestPath = 0;
			int bestFoot = 0;
			
			for (int i = 0; i < allPath.size(); ++i)
			{
				//������·��
				if (bestFoot>allPath[i].size())
				{
					bestPath = i;
					bestFoot = allPath[i].size();
				}
				//���п�ͨ·����ֵΪ2
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

	//�Ƿ��Ѿ��߹�
	//�Ƿ���ǽ
	bool IsFinded(Pos curPos)
	{
		if (IsOut(curPos))
			return true;
		if (_mazeArray[curPos._x*_yLength + curPos._y] == -1 || _mazeArray[curPos._x*_yLength + curPos._y]==1)
			return true;
		return false;
	}

	//�Ƿ��Ѿ������߽�
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
	int* _mazeArray;//�Թ�ָ��
	int _xLength;   //�Թ�����
	int _yLength;   //�Թ�����
	struct Pos _enterPose; //�Թ����
};

#endif