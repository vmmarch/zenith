template <typename T>
class CircularQueue {
	public:
		void Add(T &t);
		void Poll(T &t);
		CircularQueue(int maxSizeIn) {
			dataArray = new T*[maxSizeIn];
			// TODO CHECK MAX_SIZE_IN
			maxSize = readPos = maxSizeIn;
			writePos = 0;
		}
	private:
		int maxSize;
		T **dataArray;
		int readPos, writePos;
};