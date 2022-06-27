<h1>STD::ARRAY</h1>

<h4>The array is a collection of homogeneous objects and this array container is defined for constant size. This container is an aggregate type with the same semantics as a struct holding a C-style array T[N] as its only non-static data member. Unlike a C-style array, it doesn't decay to T* automatically. As an aggregate type, it can be initialized with aggregate-initialization given at most N initializers that are convertible to T: <code>std::array{int, 3} a = {1,2,3};</code>.
</h4>

<h5>This C++ STL array is a kind of sequential container and is not used extremely in regular programming or in competitive programming but sometimes its member function provides an upper edge to it over the regular normal array that we use in our daily life. So, we are discussing some of the important member function that is used with such kind of array:</h5>

<ul>
<li><b>[ ] Operator</b> : This is similar to the normal array, we use it to access the element store at index ‘i’ .</li>
<li><b>front( )</b> and <b>back( )</b>: These methods are used to access the first and the last element of the array directly.</li>
<li><b>empty( )</b>: This function is used to check whether the declared STL array is empty or not, if it is empty then it returns true else false.</li>
<li><b>at( )</b>: is used to access the element stored at a specific location, if we try to access the element which is out of bounds of the array size then it throws an exception. </li>
<li><b>fill( )</b>: is specially used to initialize or fill all the indexes of the array with a similar value.</li>
<li><b>size( )</b>: is used to get the maximum number of indexes in the array.</li>
<li><b>data( )</b>: returns the pointer to the first element of the array object. Because elements in the array are stored in contiguous memory locations. This data( ) function return us the base address of the string/char type object.</li>
<li><b>front( )</b>: returns a reference to the first element in the container.</li>
<li><b>back( )</b>: returns a reference to the last element in the container.</li>
<li><b>begin( )</b>: returns an iterator to the first element of the array.</li>
<li><b>end( )</b>: returns an iterator to the element following the last element of the array.</li>
<li><b>rbegin( )</b>: returns a reverse iterator to the first element of the reversed array. It corresponds to the last element of the non-reversed array. If the array is empty, the returned iterator is equal to rend().</li>
<li><b>rend( )</b>: returns a reverse iterator to the element following the last element of the reversed array.</li>
<li><b>operator<( )</b>: compares the contents of two arrays.</li>
<li><b>operator<=( )</b>: compares the contents of two arrays.</li>
<li><b>operator>( )</b>: compares the contents of two arrays.</li>
<li><b>operator>=( )</b>: compares the contents of two arrays.</li>
<li><b>operator==( )</b>: compares the contents of two arrays.</li>
<li><b>operator!=( )</b>: compares the contents of two arrays.</li>
<li><b>operator=( )</b>: Copy assignment operator - overwrites every element of the array with the corresponding element of another array.</li>
<li><b>operator( )</b>: Move assignment operator - typically "steal" the resources held by the argument (e.g. pointers to dynamically-allocated objects, file descriptors, TCP sockets, I/O streams, running threads, etc.), rather than make copies of them, and leave the argument in some valid but otherwise indeterminate state.</li>
<li><b>operator<<( )</b>: generates a sequence of characters with the representation of val , properly formatted according to the locale and other formatting settings selected in the stream, and inserts them into the output stream.</li>
<li><b>operator+( )</b>, <b>operator+=( )</b>: are used for adding sum of one array to another array. </li>

</ul>

<hr>

<h2>Here are how works begin() and end() functions:</h2>
<img src="https://upload.cppreference.com/mwiki/images/1/1b/range-begin-end.svg" alt="begin_end">
<br>

<h2>Here are how works rbegin() and rend() functions(with reverse iterators):</h2>
<img src="https://upload.cppreference.com/mwiki/images/3/39/range-rbegin-rend.svg" alt="rbegin_rend">
<br>

<h2>Contributing</h2>
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.