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
	Dynamic_Array(Dynamic_Array& input_array)
	{
		m_array = new t_template[input_array.m_capacity];
		
		for (size_t index = 0; index < input_array.m_capacity; ++index)
		{
			m_array[index] = input_array[index];
		}
	}

	// destructor to delete the array
	~Dynamic_Array()
	{
		delete[] m_array;
		m_array = nullptr;
	}

	// adds a value to the array, but...
	void push(t_template a_input)
	{
		// if the count is equal to the current capacity...
		if (m_count == m_capacity)
		{
			// make capacity larger...
			m_capacity *= 2;
			// make a new array with the new current capacity...
			t_template* m_new_array = new t_template[m_capacity];
			// copy over the old array's contents to the new array
			for (int index; index < m_count; ++index)
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
	void insert(t_template a_input, int a_location)
	{
		// same check as above to increase the size of the array if there's too little space...
		if (m_count == m_capacity)
		{
			m_capacity *= 2;
			t_template* m_new_array = new t_template[m_capacity];

			for (int index; index < m_count; ++index)
			{
				m_new_array[index] = m_array[index];
			}
			delete[] m_array;
			m_array = m_new_array;
		}
		// start at the current count of the array (the last value of the array)...
		for (int index = m_count; index > a_location; --index )
		{
			// ...shift every variable over by one (towards the current count) to make space for the new variable
			m_array[index - 1] = m_array[];
		}
		// slap that shit in (a_input @ a_location)
		m_array[a_location] = a_input;
		++m_count;

	}

	// decrement count to haphazzardly """"""remove"""""" the last value (it's still there though)
	void pop()
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
			for (int index; index < m_count; ++index)
			{
				m_new_array[index] = m_array[index];
			}
			// delete the old array
			delete[] m_array;
			// old array now points to the new array, effectively making the new array the old array
			m_array = m_new_array;
		}
	}

	// 1 or more elements of type t_template
	void insert(const t_template& a_data, size_t a_index)
	{
		if (m_count == m_capacity) 
		{
			grow();
		}

		for (size_t i = m_count - 1; i >= a_index ; i++)
		{
			m_data[i + 1] = m_data[i];
		}

		m_data[a_index];
	}

private:
	// declaring variables here (but initiating the default capacity here because it is never needed to change)
	int m_count;
	int m_capacity;
	const int m_default_capacity = 8;
	int* m_array;
};


#endif
