/**Iterator**/

template <class T, std::size_t N>
Array<T, N>::RandomAccessIterator::RandomAccessIterator(value_type* ptr) : m_ptr(ptr) {}

template <class T, std::size_t N>
typename Array<T,N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator++() {
	++m_ptr;
	return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator++(int) {
	RandomAccessIterator tmp = *this;
	++(*this);
	return tmp;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator--() {
	--m_ptr;
	return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator--(int) {
	RandomAccessIterator tmp = *this;
	--(*this);
	return tmp;
}

template <class T, std::size_t N>
typename Array<T,N>::RandomAccessIterator::reference Array<T, N>::RandomAccessIterator::operator*() {
	return *m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator::pointer Array<T, N>::RandomAccessIterator::operator->() {
	return m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator::reference Array<T,N>::RandomAccessIterator::operator[](difference_type index) {
	return *(m_ptr + index);
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::RandomAccessIterator::operator+(difference_type other) const {
	return RandomAccessIterator(m_ptr + other);
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::RandomAccessIterator::operator-(difference_type other) const {
	return RandomAccessIterator(m_ptr - other);
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator+=(difference_type ptr) {
	m_ptr += ptr;
	return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator-=(difference_type ptr) {
	m_ptr -= ptr;
	return *this;
}

template <class T, std::size_t N>
bool Array<T, N>::RandomAccessIterator::operator==(const RandomAccessIterator& other) const {
	return m_ptr == other.m_ptr;
}

template <class T, std::size_t N>
bool Array<T, N>::RandomAccessIterator::operator!=(const RandomAccessIterator& other) const {
	return m_ptr != other.m_ptr;
}

/**Reverse Iterator**/

template <class T, std::size_t N>
Array<T, N>::ReverseRandomAccessIterator::ReverseRandomAccessIterator(value_type* ptr) : m_ptr(ptr) {}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator::reference Array<T, N>::ReverseRandomAccessIterator::operator[](difference_type index) {
	return *(m_ptr - index);
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator::pointer Array<T, N>::ReverseRandomAccessIterator::operator->() {
	return *m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator::reference Array<T, N>::ReverseRandomAccessIterator::operator*() {
	return m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator++() {
	--m_ptr;
	return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator++(int) {
	ReverseRandomAccessIterator tmp = *this;
	--(*this);
	return tmp;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator--() {
	++m_ptr;
	return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator--(int) {
	ReverseRandomAccessIterator tmp = *this;
	++(*this);
	return tmp;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::ReverseRandomAccessIterator::operator-(difference_type other) const {
	return m_ptr + other.m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::ReverseRandomAccessIterator::operator+(difference_type other) const {
	return m_ptr - other.m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator+=(difference_type other) {
	return m_ptr -= other.m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator-=(difference_type other) {
	return m_ptr += other.m_ptr;
}

template <class T, std::size_t N>
bool Array<T, N>::ReverseRandomAccessIterator::operator==(const ReverseRandomAccessIterator& other) const {
	return m_ptr == other.m_ptr;
}

template <class T, std::size_t N>
bool Array<T, N>::ReverseRandomAccessIterator::operator!=(const ReverseRandomAccessIterator& other) const {
	return m_ptr != other.m_ptr;
}

	
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
//	for (auto it = begin(); it != end(); ++it) {
//		delete it;
//	}
//}

/**Functions**/

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::front() const {
	return m_data[0];
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::back() const {
	return m_data[m_size - 1];
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::begin() const {
	return m_data[0];
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::end() const {
	return m_data[m_size];
}

template <class T, std::size_t N>
bool Array<T, N>::empty() const {
	if (m_size == 0) { return true; }
	return false;
}

template <class T, std::size_t N>
std::size_t Array<T, N>::size() const {
	return m_size;
}

template <class T, std::size_t N>
void Array<T, N>::fill(const T& value) {
	for (std::size_t i = 0; i < m_size; i++) {
		m_data[i] = value;
	}
}

template <class T, std::size_t N>
T& Array<T, N>::at(std::size_t position) const {
	if (position < 0 || position > m_size) {
		std::cout << "Out of range.";
	}
	else {
		return m_data[position];
	}
}

template <class T, std::size_t N>
T* Array<T, N>::data() const {
	if (m_size == 0) { return nullptr; }

	return &m_data;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::rbegin() const {
	return m_data[m_size - 1];
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::rend() const {
	return m_data[0];
}

/**Operators**/

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(Array<T, N>&& other_array) {
	if (&other_array == this) {
		return *this;
	}

	*this = std::move(other_array);
	return *this;
}

template <typename T, std::size_t N>
class Array;
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, Array<T, N>& other) {
	for (std::size_t i = 0; i < other.m_size; ++i) {
		out << other.m_data[i] << " ";
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
T& Array<T, N>::sum() const {
	if (m_size == 0) {
		return 0;
	}

	T result = T();
	for (std::size_t i = 0; i < m_size; ++i) {
		result += m_data[i];
	}

	return result;
}