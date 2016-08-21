//
// FILE: node.h
//

#ifndef NODE_H
#define NODE_H

#include <cstddef>

namespace std
{
	template <class DataType>
	class Node
	{
	public:
		Node(DataType newData)
		{
			data = newData;
			left = NULL;
			right = NULL;
		};

		Node()
		{
			left = NULL;
			right = NULL;
		};

		//~Node();

		void create_left(DataType newData);
		void create_left();
		void create_right(DataType newData);
		void create_right();
		void set_data(DataType newData);
		DataType getData() const;
		Node* getLeft() const;
		Node* getRight() const;

	private:
		DataType data;
		Node<DataType>* left;
		Node<DataType>* right;
	};

	/// IMPLIMENTATION ///

	template <class DataType>
	void Node<DataType>::create_left(DataType newData)
	{
		left = new Node(newData);
	};

	template <class DataType>
	void Node<DataType>::create_left()
	{
		left = new Node();
	};

	template <class DataType>
	void Node<DataType>::create_right(DataType newData)
	{
		right = new Node(newData);
	};

	template <class DataType>
	void Node<DataType>::create_right()
	{
		right = new Node();
	};

	template <class DataType>
	void Node<DataType>::set_data(DataType newData)
	{
		data = newData;
	};

	template <class DataType>
	DataType Node<DataType>::getData() const
	{
		return data;
	}

	template <class DataType>
	Node<DataType>* Node<DataType>::getLeft() const
	{
		return left;
	}

	template <class DataType>
	Node<DataType>* Node<DataType>::getRight() const
	{
		return right;
	}

}
#endif
