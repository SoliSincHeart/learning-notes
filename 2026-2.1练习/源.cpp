vector<int> heap;

int top(){
	return heap[0];
}

void push(int k){
	heap.push_back(k);
	swim(heap.size() - 1);
}

void pop() {
	heap[0] = heap.back();
	heap.pop_back();
	sink(0);
}

void swim(int pos) {
	while(pos>1 && heap[pos/2] < heap[pos]) {
		swap(heap[pos/2], heap[pos]);
		pos /= 2;
	}
}

void sink(int pos) {
		while(pos*2 <= heap.size()-1) {
		int j = pos*2;
		if(j <= heap.size()-1 && heap[j] < heap[j+1]) ++j;
		if(heap[pos] >= heap[j]) break;
			swap(heap[pos], heap[j]);
			pos = j;
		}
}