#include <iostream>

class my_exception : public std::exception
{
private:
	int indexState;
public:
	my_exception(const char* msg, int index) : std::exception(msg)
	{
		indexState = index;
	}
	int getIndexState() { return indexState; }
};

void showArray(int* ar, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << ar[i] << "  ";
	}
	std::cout << std::endl;
}

void setElement(int * ar, int size)
{
	int index, value;
	std::cout << "Index: ";
	std::cin >> index;
	if (index < 0 || index > size-1)
	{
		throw my_exception("index out of range", index);
	}
	std::cout << "Value: ";
	std::cin >> value;
	ar[index] = value;
}

void getElement(int * ar, int size)
{
	int index, value;
	std::cout << "Index: ";
	std::cin >> index;
	if (index < 0 || index > size-1)
	{
		throw my_exception("index out of range", index);
	}
	std::cout << ar[index] << std::endl;
}

int main()
{
	int size_array;
	std::cout << "Input size array: ";
	std::cin >> size_array;
	int *array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		array[i] = i+i*i;
	}

	while (true)
	{
		std::cout << "1)Show array" << std::endl << "2)Set element" << std::endl << "3)Get element" << std::endl;
		int choice;
		std::cin >> choice;
		while (!std::cin.good())
		{
			std::cin.ignore();
			std::cin.clear();
			std::cout << "Input correct number!" << std::endl;
			std::cin >> choice;
		}
		switch (choice)
		{
		case 1: showArray(array, size_array);
			break;
		case 2:
		try 
		{
			setElement(array, size_array);
		}
		catch (my_exception &ex)
		{
			std::cout << ex.what() << " index:" << ex.getIndexState() << std::endl;
		}
			break;
		case 3: 
		try
		{
			getElement(array, size_array);
		}
		catch (my_exception &ex)
		{
			std::cout << ex.what() << " index:" << ex.getIndexState() << std::endl;
		}
			break;
		default: std::cout << "Input correct number!" << std::endl;
		}
	}
}