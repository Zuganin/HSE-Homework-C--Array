In this README file, I want to talk about the task that needed to be completed, my solution is in the array.h files. In the file main.cpp there are a couple of simple tests for the task.

Implementation Details

You need to implement the template class Array, a simplified analogue of std::array.
Your class must be parameterized by the type of stored elements, as well as the size of the array. As mentioned earlier, this class must have exactly one field - a C-style array of the required type and size.
The important point is that this field must be public! 

To pass the tests correctly, your class must implement the following methods (think about which methods should be constant, which ones should be non-constant, and which ones should have both versions):
Operation [] to access an array element by index;
The At(size_t idx) method, which provides secure (boundary-checked) access to an element by index. In case of going out of bounds, you need to throw an exception of the ArrayOutOfRange type, which has already been written for you (see notes);
Methods Front() and Back() to access the first and last element, respectively;
The Data() method, which returns a pointer to the beginning of the array;
Size() methods and Empty();
The Fill(const T& value) method, which fills the array with value values;
Method Swap(Array<T, N>& other), exchanging the contents of arrays of the same size.
