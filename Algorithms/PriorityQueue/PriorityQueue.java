import java.util.ArrayList;

public class MaxPriority_Queue {

	private ArrayList<Integer> heap;
	
	//constructor
	public MaxPriority_Queue() {
		heap = new ArrayList<>();
	}

	boolean isEmpty(){
		return heap.size() == 0;
	}

	int getSize(){
		return heap.size();
	}

	int getMax() throws PriorityQueueException{
		if(isEmpty()){
			// Throw an exception
			throw new PriorityQueueException();
		}
		return heap.get(0);
	}

	void insert(int element){
		heap.add(element);
		int childIndex = heap.size() - 1;
		int parentIndex = (childIndex - 1) / 2;

		while(childIndex > 0){
			if(heap.get(childIndex) > heap.get(parentIndex)){
				int temp = heap.get(childIndex);
				heap.set(childIndex, heap.get(parentIndex));
				heap.set(parentIndex, temp);
				childIndex = parentIndex;
				parentIndex = (childIndex - 1) / 2;
			}else{
				return;
			}
		}
	}
	
	int removeMax() throws PriorityQueueException {
		// Throws the exception PriorityQueueException if queue is empty
		if(heap.size()==0) {
			throw new PriorityQueueException();
		}
		int ans = heap.get(0);
		heap.set(0, heap.get(heap.size()-1));
		heap.remove(heap.size()-1);
		int i=0;
		int lC = 2*i + 1;
		int rC = 2*i + 2;
		while(lC<heap.size() && rC<heap.size()) {
			if(heap.get(i) >= Math.max(heap.get(lC), heap.get(rC))) {
				return ans;
			}
			else {
				if(heap.get(lC) == Math.max(heap.get(i), Math.max(heap.get(lC), heap.get(rC)))) {
					int temp = heap.get(i);
					heap.set(i, heap.get(lC));
					heap.set(lC, temp);
					i = lC;
					lC = 2*i + 1;
					rC = 2*i + 2;
				}
				else {
					int temp = heap.get(i);
					heap.set(i, heap.get(rC));
					heap.set(rC, temp);
					i = rC;
					lC = 2*i + 1;
					rC = 2*i + 2;
				}
			}
		}
		return ans;
	}


}








