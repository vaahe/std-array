/**Iterator**/

template <class T, std::size_t N>
Array<T, N>::RandomAccessIterator::RandomAccessIterator(value_type* ptr) : m_ptr(ptr) {}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator++() {
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
typename Array<T, N>::RandomAccessIterator::reference Array<T, N>::RandomAccessIterator::operator*() {
	return *m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator::pointer Array<T, N>::RandomAccessIterator::operator->() {
	return m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator::reference Array<T, N>::RandomAccessIterator::operator[](RandomAccessIterator index) {
	return *(m_ptr + index);
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::RandomAccessIterator::operator+(RandomAccessIterator other) const {
	return RandomAccessIterator(m_ptr + other);
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::RandomAccessIterator::operator-(RandomAccessIterator other) const {
	return RandomAccessIterator(m_ptr - other);
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator+=(RandomAccessIterator ptr) {
	m_ptr += ptr;
	return *this;
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator& Array<T, N>::RandomAccessIterator::operator-=(RandomAccessIterator ptr) {
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
typename Array<T, N>::ReverseRandomAccessIterator::reference Array<T, N>::ReverseRandomAccessIterator::operator[](ReverseRandomAccessIterator index) {
	return *(m_ptr - index);
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator::pointer Array<T, N>::ReverseRandomAccessIterator::operator->() {
	return m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator::reference Array<T, N>::ReverseRandomAccessIterator::operator*() {
	return *m_ptr;
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
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::ReverseRandomAccessIterator::operator-(ReverseRandomAccessIterator other) const {
	return m_ptr + other.m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::ReverseRandomAccessIterator::operator+(ReverseRandomAccessIterator other) const {
	return m_ptr - other.m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator+=(ReverseRandomAccessIterator other) {
	return m_ptr -= other.m_ptr;
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator& Array<T, N>::ReverseRandomAccessIterator::operator-=(ReverseRandomAccessIterator other) {
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
	m_data = new T[N]();
	m_size = N;
}

template <class T, std::size_t N>
Array<T, N>::Array(const Array<T, N>& other_array) : m_size(other_array.m_size) {
	m_data = new T[N];
	for (std::size_t i = 0; i < m_size; ++i) {
		m_data[i] = other_array.m_data[i];
	}
}

template <class T, std::size_t N>
Array<T, N>::Array(const std::initializer_list<T>& other_array) {
	m_data = new T[N];
	int i = 0;
	for (auto it = other_array.begin(); it != other_array.end(); ++it) {
		m_data[i++] = *it;
	}

	m_size = other_array.size();
}

template <class T, std::size_t N>
Array<T, N>::Array(Array<T, N>&& other_array) :
	m_size(other_array.m_size),
	m_data(other_array.m_data) {
	other_array.fill(0);
}

template <class T, std::size_t N>
Array<T, N>::~Array() {
	delete[] m_data;
}

/**Functions**/

template <class T, std::size_t N>
T& Array<T, N>::front() const {
	return m_data[0];
}

template <class T, std::size_t N>
T& Array<T, N>::back() const {
	return m_data[m_size - 1];
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::begin() const {
	return RandomAccessIterator(&(m_data[0]));
}

template <class T, std::size_t N>
typename Array<T, N>::RandomAccessIterator Array<T, N>::end() const {
	return RandomAccessIterator(&(m_data[m_size]));
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

	return &m_data[0];
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::rbegin() const {
	return ReverseRandomAccessIterator(&(m_data[m_size - 1]));
}

template <class T, std::size_t N>
typename Array<T, N>::ReverseRandomAccessIterator Array<T, N>::rend() const {
	return ReverseRandomAccessIterator(&(m_data[-1]));
}

/**Operators**/

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(const Array<T, N>& other_array) {
	if (this == &other_array) {
		return *this;
	}

	if (m_size != 0) {
		delete[] m_data;
	}

	if (other_array.m_size == 0) {
		m_data = new T[0];
	}
	else {
		for (int i = 0; i < N; i++) {
			m_data[i] = other_array.m_data[i];
		}
	}

	return *this;
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator=(Array<T, N>&& other_array) {
	if (&other_array == this) {
		return *this;
	}

	if (m_size != 0) {
		fill(0);
	}

	*this = std::move(other_array);
	return *this;
}

template <typename T, std::size_t N>
class Array;
template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, const Array<T, N>& other) {
	for (auto it = other.begin(); it != other.end(); it++) {
		out << *it;
	}

	return out;
}

template <class T, std::size_t N>
T& Array<T, N>::operator[](int index) const {
	int counter = 0;
	while (counter != index) {
		++counter;
	}
	return m_data[index];
}

template <class T, std::size_t N>
Array<T, N>& Array<T, N>::operator+(const Array<T, N>& other) {
	this->operator+=(other);

	Array<T, N> array;
	for (std::size_t i = 0; i < m_size; i++) {
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
bool Array<T, N>::operator >= (const Array<T, N>& other) {
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
T Array<T, N>::sum() const {
	if (m_size == 0) {
		return T();
	}

	T result = T();
	for (std::size_t i = 0; i < m_size; ++i) {
		result += m_data[i];
	}

	return result;
}