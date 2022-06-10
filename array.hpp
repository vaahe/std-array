/**Constructors and Destructor**/

template <class T, std::size_t N>
Array<T, N>::Array() {
	m_size = 0;
}

template <class T, std::size_t N>
Array<T, N>::Array(const Array<T, N>& other_array) : m_size(other_array.m_size) {
	for (std::size_t i = 0; i < m_size; ++i) {
		m_data[i] = other_array.m_data[i];
	}
}

template <class T, std::size_t N>
Array<T, N>::Array(std::initializer_list<T>& other_array) {
	for (auto it = begin(); it != end(); ++it) {
		std::count << *it << " ";
	}
}

template <class T, std::size_t N>
Array<T, N>::Array(Array<T, N>&& other_array) :
	m_size(other_array.m_size),
	m_data(other_array.m_data) {
	other_array.m_size = 0;
	for (std::size_t i = 0; i < other_array.m_size; ++i) {
		other_array.m_data[i] = 0;
	}
}

//template <class T, std::size_t N>
//Array<T, N>::~Array() {
//	for ()
//}

/**Functions**/

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::front() {
	return m_data[0];
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::back() {
	return m_data[m_size - 1];
}

template <class T, std::size_t N>
RandomAccessIterator<T> Array<T, N>::begin() {
	return m_data[0];
}

template <class T, std::size_t N>
RandomAccessIterator<T> Array<T, N>::end() {
	return m_data[m_size];
}

template <class T, std::size_t N>
bool Array<T, N>::empty() {
	if (m_size == 0) { return true; }
	return false;
}

template <class T, std::size_t N>
std::size_t Array<T, N>::size() {
	return m_size;
}

//template <class T, std::size_t N>
//void Array<T, N>::fill(const T& other) {
//
//}

template <class T, std::size_t N>
T* Array<T, N>::data() {
	if (m_size == 0) { return nullptr; }

	return 
}

template <class T, std::size_t N>
ReverseRandomAccessIterator<T> Array<T, N>::rbegin() {
	return m_data[m_size - 1];
}

template <class T, std::size_t N>
ReverseRandomAccessIterator<T> Array<T, N>::rend() {
	retrun m_data[-1];
}

/**Operators**/

template <typename T, std::size_t N>
class Array;
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, Array<T, N>& other) {
	for (std::size_t i = 0; i < m_size; ++i) {
		out << m_data[i] << " ";
	}

	return out;
}

template <class T, std::size_t N>
T& Array<T, N>::operator[](int index) {
	if (m_size == 0) {
		return 0;
	}
	
	int counter = 0;
	while (counter != index) {
		counter++;
	}
	return m_data[index];
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator+(const Array<T, N>& other) {
	Array<T, N> array;
	this->operator+=(other);
	for (std::size_t i = 0; i < m_size; ++i) {
		array.m_size++;
		array.m_data[i] = m_data[i];
	}

	return array;
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator+=(const Array<T, N>& other) {
	if (m_size < other.m_size) {
		for (std::size_t i = 0; i < other.m_size; ++i) {
			for (std::size_t j = 0; j < m_size; ++j) {
				m_data[j] += other.m_data[i];
			}
			m_size++;
			m_data[m_size - 1] += other.m_data[i];
		}
	}
	else if (m_size > other.m_size) {
		for (std::size_t i = 0; i < m_size; ++i) {
			for (std::size_t j = 0; j < other.m_size; ++j) {
				m_data[i] += other.m_data[j];
			}
			m_data[i] += m_data[i];
		}
	}
	else {
		for (std::size_t i = 0, j = 0; i < m_size; ++i, ++j) {
			m_data[i] += other.m_data[j];
		}
	}

	return *this;
}

template <class T, std::size_t N>
bool Array<T, N>::operator<(const Array<T, N>& other) {
	return sum() < other.sum();
}

template <class T, std::size_t N>
bool Array<T, N>::operator<=(const Array<T, N>& other) {
	return sum() <= other.sum();
}

template <class T, std::size_t N>
bool Array<T, N>::operator>(const Array<T, N>& other) {
	return sum() > other.sum();
}

template <class T, std::size_t N>
bool Array<T, N>::operator >= (const Array<T, N>&other) {
	return sum() >= other.sum();
}

template <class T, std::size_t N>
bool Array<T, N>::operator==(const Array<T, N>& other) {
	return sum() == other.sum();
}

template <class T, std::size_t N>
bool Array<T, N>::operator!=(const Array<T, N>& other) {
	return sum() != other.sum();
}

/**Helper Functions**/

template <class T, std::size_t N>
T& Array<T, N>::sum() {
	if (m_size == 0) {
		return 0;
	}

	T result = T();
	for (std::size_t i = 0; i < m_size; ++i) {
		result += m_data[i];
	}

	return result;
}