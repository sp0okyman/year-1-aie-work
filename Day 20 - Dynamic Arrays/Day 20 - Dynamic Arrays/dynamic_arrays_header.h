#pragma once
#ifndef DYNAMIC_ARRAYS_HEADER
#define DYNAMIC_ARRAYS_HEADER
// template data-type
template <typename t_template>

class Dynamic_Array
{

public:

	// constructor that initiates variables with values
	Dynamic_Array() 
	{
		m_array = new t_template[m_default_capacity];
		m_count = 0;
		m_capacity = m_default_capacity;
	}

	// copy constructor that copies values
	Dynamic_Array(Dynamic_Array& a_input_array)
	{
		m_array = new t_template[a_input_array.m_capacity];
		
		for (size_t index = 0; index < a_input_array.m_capacity; ++index)
		{
			m_array[index] = a_input_array[index];
		}
	}

	// destructor to delete the array
	~Dynamic_Array()
	{
		delete[] m_array;
		m_array = nullptr;
	}

	// assignment operator
	Dynamic_Array& operator= (Dynamic_Array& a_input_array)
	{
		if (a_input_array == this)
		{
			return *this;
		}
		if (m_array)
		{
			delete[] m_array;
			m_array = nullptr;
		}
		m_count = a_input_array.m_count;
		m_capacity = a_input_array.m_capacity;

		m_array = new t_template[a_input_array.m_capacity];

		for (size_t index = 0; index < a_input_array.m_capacity; ++index)
		{
			m_array[index] = a_input_array[index];
		}
	}

	// adds a value to the array, but...
	void push_back(t_template a_input)
	{
		// if the count is equal to the current capacity...
		if (m_count == m_capacity)
		{
			// make capacity larger...
			m_capacity *= 2;
			// make a new array with the new current capacity...
			t_template* m_new_array = new t_template[m_capacity];
			// copy over the old array's contents to the new array
			for (int index = 0; index < m_count; ++index)
			{
				m_new_array[index] = m_array[index];
			}
			// delete the old array
			delete[] m_array;
			// old array now points to the new array, effectively making the new array the old array
			m_array = m_new_array;
		}
		// copy the new data at the count (which is at the end)
		m_array[m_count] = a_input;
		// increase count for new value
		++m_count;
	}

	// function to place a new value somewhere in the middle of the array
//void insert(t_template a_input, int a_location)
//{
//	grow();
//
//	// start at the current count of the array (the last value of the array)...
//	for (int index = m_count; index > a_location; --index )
//	{
//		// ...shift every variable over by one (towards the current count) to make space for the new variable
//		m_array[index - 1] = m_array[];
//	}
//	// slap that shit in (a_input @ a_location)
//	m_array[a_location] = a_input;
//
//	++m_count;
//}

	// decrement count to haphazzardly """"""remove"""""" the last value (it's still there though)
	void pop_back()
	{
		--m_count;
	}

	// doubles array capacity
	void grow()
	{
		if (m_count == m_capacity)
		{
			// make capacity larger...
			m_capacity *= 2;
			// make a new array with the new current capacity...
			t_template* m_new_array = new t_template[m_capacity];
			// copy over the old array's contents to the new array
			for (int index = 0; index < m_count; ++index)
			{
				m_new_array[index] = m_array[index];
			}
			// delete the old array
			delete[] m_array;
			// old array now points to the new array, effectively making the new array the old array
			m_array = m_new_array;
		}
	}

	//Write growToCapacity(int newCap)
	void growToCapacity(int a_newCap)
	{

	}

	void insert(const t_template& a_data, size_t a_index)
	{
		grow();
		 
		for (size_t i = m_count - 1; i >= a_index ; i--)
		{
			m_array[i + 1] = m_array[i];	//This loop is shifting things out of the way
		}

		m_array[a_index] = a_data;	//This line is copying the new element in

		++m_count; 
	}

	void insert(const Dynamic_Array<t_template>& a_data, size_t a_index)
	{
		//You need a special 'grow' function to grow this sufficiently
		//growToCapacity(m_capacity + a_data.size())

		//Once you have grown sufficiently, this will look a lot like the other 'insert' function,
		//but instead of shifting things by 1, we will shift them by a_data.size,
		//And instead of copying over a single element, we will have to copy all of a_data over, in a loop
	}

	// overloaded function of insert
	// 1 or more elements of type t_template
	/*void insert(const t_template a_data, size_t a_index, size_t& a_element_count)
	{
		grow();

		for (size_t i = m_count - 1; i >= a_index; i++)
		{
			m_data[i + 1] = m_data[i];
		}
		    
		m_data[a_index];

	}*/

	void remove(size_t a_index)
	{
		//Starting at a_index, we want to move to the right, copying elements one to the left (ie m_array[i] = m_array[i+1]
		//Then, decrement the count, and that's it.
		for (size_t i = a_index; i < m_count - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}
		m_count--;
	}

private:
	// declaring variables here (but initiating the default capacity here because it is never needed to change)
	int m_count;
	int m_capacity;
	const int m_default_capacity = 8;
	t_template* m_array;
};

#endif