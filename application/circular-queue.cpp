#include "circular-queue.h"

#define CIRCULAR_QUEUE_DISTANCE (readPos-writePos)

template <typename T>
void CircularQueue<T>::Add(T&t) {
	while(CIRCULAR_QUEUE_DISTANCE == 1);
	dataArray[writePos++] = &t;
	
}
template <typename T>
void CircularQueue<T>::Poll(T&t) {
	if(CIRCULAR_QUEUE_DISTANCE != -1) {
		readPos = readPos >= maxSize ? 0 : readPos+1;
		t = *dataArray[readPos++];
	}
}
#undef DISTANCE