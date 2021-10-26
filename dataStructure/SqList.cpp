#include<iostream>
#include<cstdlib>
using namespace std;

class SqList
{
public:
	// Constructor
	SqList()
	{
		size = 0;
		capacity = 0;
		arr = new int[100];
	}

	// destructor
	~SqList()
	{
		delete[] arr;
	}

	int getSize()
	{
		return size;
	}

	// insert item ai pos
	bool insertItem(int item, int pos)
	{
		if (checkIndex(pos))
		{
			for (int i = size - 1; i < pos; i++)
			{
				swap(arr[i], arr[i - 1]);	
			}
			size++;
			return true;
		}
		return false;
	}

	// delete item at pos
	bool deleteItem(int pos)
	{
		if (checkIndex(pos))
		{
			for (int i = pos - 1; i < size - 1; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			size--;
			return true;
		}
		return false;
	}

	// get item at pos
	int getItem(int pos)
	{
		if (checkIndex(pos))
		{
			return arr[pos];
		}
		return 0;
	}

	// change item at pos 
	bool changeItem(int item, int pos)
	{
		if (checkIndex(pos))
		{
			arr[pos] = item;
			return true;
		}
		return false;
	}


private:

	bool checkIndex(int pos)
	{
		if (pos > size || pos < 0)
		{
			return false;
		}
		return true;
	}

	int capacity;
	int size;
	int* arr;
};

int main()
{

}
