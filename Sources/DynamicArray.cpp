#include "../Headers/DynamicArray.h"

DynamicArray::DynamicArray(int capacity) : m_Capacity(2), m_Size(0)
{
	while (capacity > m_Capacity)
	{
		m_Capacity *= 2;
	}

	m_pData = new int[m_Capacity];
}

DynamicArray::DynamicArray(DynamicArray const& that) : m_Capacity(that.m_Capacity), m_Size(that.m_Size)
{
	m_pData = new int[m_Capacity];
	memcpy(m_pData, that.m_pData, sizeof(int) * m_Size);
}

DynamicArray::~DynamicArray()
{
	delete[] m_pData;
}

DynamicArray& DynamicArray::operator= (DynamicArray const& that)
{
	m_Capacity = that.m_Capacity;
	m_Size = that.m_Size;

	delete[] m_pData;
	m_pData = new int[m_Capacity];
	memcpy(m_pData, that.m_pData, sizeof(int) * m_Size);

	return *this;
}

int& DynamicArray::At(int i)
{
	return m_pData[i];
}

int& DynamicArray::GetAt(int i) const
{
	return m_pData[i];
}

const int& DynamicArray::operator[](int i) const
{
	return m_pData[i];
}

int& DynamicArray::operator[](int i)
{
	return m_pData[i];
}

int DynamicArray::Size() const
{
	return m_Size;
}

int DynamicArray::UpperBound() const
{
	return m_Size - 1;
}

int DynamicArray::Capacity() const
{
	return m_Capacity;
}

int DynamicArray::Find(const int& value) const
{
	const int* p = m_pData;

	for (int i = 0; i < m_Size; ++i)	// look for matching element
		if (*p++ == value)
			return i;				// found it
	return -1;
}

void DynamicArray::Add(int const& value)
{
	if (m_Size < m_Capacity)
	{
		m_pData[m_Size] = value;
		++m_Size;
	}
	else
	{
		m_Capacity *= 2;

		int* newData_ = new int[m_Capacity];
		memcpy(newData_, m_pData, sizeof(int) * m_Size);

		delete[] m_pData;
		m_pData = newData_;

		m_pData[m_Size] = value;
		++m_Size;
	}
}

void DynamicArray::Insert(int index, int const& value)
{
	if (index < m_Size)
	{
		if (m_Size < m_Capacity)
		{
			memmove(m_pData + index, m_pData + index - 1, sizeof(int) * (m_Size - index + 1));
			m_pData[index - 1] = value;

			++m_Size;
		}
		else
		{
			m_Capacity *= 2;

			int* newData_ = new int[m_Capacity];
			memmove(newData_, m_pData, sizeof(int) * (index - 1));
			memmove(newData_ + index, m_pData + index - 1, sizeof(int) * (m_Size - index + 1));

			delete[] m_pData;
			m_pData = newData_;

			m_pData[index - 1] = value;
			++m_Size;
		}
	}
}

bool DynamicArray::IsEmpty() const
{
	return m_Size == 0;
}

void DynamicArray::Empty()
{
	m_Size = 0;
}

void DynamicArray::Remove(int index)
{
	if (index < m_Size)
	{
		memmove(m_pData + index - 1, m_pData + index, sizeof(int) * (m_Size - index));
		--m_Size;
	}
}

void DynamicArray::Reserve(int newCapacity)
{
	if (newCapacity > m_Capacity)
	{
		do
		{
			m_Capacity *= 2;
		} while (newCapacity > m_Capacity);

		int* newData_ = new int[m_Capacity];
		memcpy(newData_, m_pData, sizeof(int) * m_Size);

		delete[] m_pData;
		m_pData = newData_;
	}
}

void DynamicArray::Reverse()
{
	int size = m_Size / 2;
	int tmp;
	for (int i = 0; i < size; i++)
	{
		tmp = m_pData[i];
		m_pData[i] = m_pData[m_Size - i - 1];
		m_pData[m_Size - i - 1] = tmp;
	}
}

void DynamicArray::FreeExtra()
{
	if (m_Size != m_Capacity)
	{
		int *newData_ = NULL;
		if (m_Size != 0)
		{
			newData_ = new int[m_Size];
			for (int i = 0; i < m_Size; i++)
				newData_[i] = m_pData[i];
			//memcpy(newData_, m_pData, m_Size*sizeof(int));
		}
		delete[]m_pData;
		m_pData = newData_;
		m_Capacity = m_Size;
	}
}

int* DynamicArray::Begin()
{
	return m_pData;
}

int const* DynamicArray::Begin() const
{
	return m_pData;
}

int* DynamicArray::End()
{
	return m_pData + m_Size - 1;
}

int const* DynamicArray::End() const
{
	return m_pData + m_Size - 1;
}

ostream &operator <<(ostream &out, const DynamicArray& a)
{
	return out;
}
